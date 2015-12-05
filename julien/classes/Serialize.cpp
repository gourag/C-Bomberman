//
// Serialize.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 14 19:18:20 2014 jonathan
// Last update Tue May 20 15:54:02 2014 jonathan
//

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "AEntity.hh"
#include "Serialize.hh"
#include "AEntityFactory.hh"
#include "MyException.hh"

Serialize::Serialize(Map *map)
{
  _map = map;
  _types["Cube"] = CubeType;
  _types["Floor"] = GroundType;
  _types["Player"] = PlayerType;
}
Serialize::Serialize()
{
  _types["Cube"] = CubeType;
  _types["Floor"] = GroundType;
  _types["Player"] = PlayerType;
}
Serialize::Serialize(const Serialize &old)
{
  (void)old;
}
Serialize &Serialize::operator=(const Serialize &old)
{
  (void)old;
  return (*this);
}
Serialize::~Serialize()
{
}

void	Serialize::pack(const std::string &file)
{
  std::ofstream	f;
  std::string	str = "./maps/" + file;
  int	w = _map->getWidth();
  int	h = _map->getHeight();
  int	z;
  std::map<int, std::map<int, std::map<int, enum e_EType> > >	map = _map->getMap();
  std::map<enum e_EType, std::string> types = _map->getTypes();

  f.open(str.c_str(), std::ifstream::out | std::ifstream::trunc);
  if (f.good())
    {
      f << "< name=\"" << file.substr(0, file.find(".")) << "\" width=\"" << w << "\" height=\"" << h << "\" >" << std::endl;;
      for (int x = 0; x < w; x++)
	{
	  for (int y = 0; y < h; y++)
	    {
	      z = 0;
	      if (map[x][y][z] != None)
		{
		  f << "< type=\"" << types[map[x][y][z]] << "\" posX=\"" << x << "\" posY=\"" << y << "\" posZ=\"" << z << "\" >" << std::endl;
		}
	      z++;
	      if (map[x][y][z] != None)
		{
		  f << "< type=\"" << types[map[x][y][z]] << "\" posX=\"" << x << "\" posY=\"" << y << "\" posZ=\"" << z << "\" >" << std::endl;
		}
	    }
	}
    }
}
bool	Serialize::getMapSize(const std::string &str, int *w, int *h)
{
  std::size_t	idxBegin;
  std::size_t	idxEnd;
  std::stringstream	ss;

  idxBegin = str.find("width=\"");
  idxEnd = str.find("\"", idxBegin + 7);
  ss << str.substr(idxBegin + 7, idxEnd - idxBegin - 7);
  ss >> *w;
  ss.clear();
  idxBegin = str.find("height=\"");
  idxEnd = str.find("\"", idxBegin + 8);
  ss << str.substr(idxBegin + 8, idxEnd - idxBegin - 8);
  ss >> *h;
  ss.clear();
  return true;
}
bool	Serialize::getElement(const std::string &str, __attribute__((unused))AEntity **entity, std::string *type)
{
  std::size_t	idxBegin;
  std::size_t	idxEnd;
  std::stringstream	ss;
  int	posX, posY, posZ;
  AEntityFactory	factory;

  idxBegin = str.find("type=\"");
  idxEnd = str.find("\"", idxBegin + 6);
  *type = str.substr(idxBegin + 6, idxEnd - idxBegin - 6);

  idxBegin = str.find("posX=\"");
  idxEnd = str.find("\"", idxBegin + 6);
  ss.clear();
  ss << str.substr(idxBegin + 6, idxEnd - idxBegin - 6);
  ss >> posX;

  idxBegin = str.find("posY=\"");
  idxEnd = str.find("\"", idxBegin + 6);
  ss.clear();
  ss << str.substr(idxBegin + 6, idxEnd - idxBegin - 6);
  ss >> posY;

  idxBegin = str.find("posZ=\"");
  idxEnd = str.find("\"", idxBegin + 6);
  ss.clear();
  ss << str.substr(idxBegin + 6, idxEnd - idxBegin - 6);
  ss >> posZ;

  *entity = factory.generateObject(type->c_str(), posX, posZ, posY);
  return true;
}
Map	*Serialize::unpack(const std::string &file)
{
  std::ifstream	f(file.c_str());
  std::string	str, type;
  AEntity	*entity;
  std::vector<std::map<std::string, AEntity *> > entities;
  std::map<std::string, AEntity *> mapy;
  int	width, height;

  if (f.good())
    {
      std::getline(f, str);
      if (!getMapSize(str, &width, &height))
      	throw MyException("Invalid file: First line must be map name, width and height definition");
      while (std::getline(f, str))
	{
	  if (getElement(str, &entity, &type))
	    {
	      mapy[type] = entity;
	      entities.push_back(mapy);
	      mapy.clear();
	    }
	}
      _map = new Map(width, height, false);
      while (!entities.empty())
	{
	  mapy = entities.back();
	  std::map<std::string, AEntity *>::iterator it = mapy.begin();
	  _map->addEntity(it->second, _map->getType(it->first));
	  entities.pop_back();
	  mapy.clear();
	}
    }
  return _map;
}
