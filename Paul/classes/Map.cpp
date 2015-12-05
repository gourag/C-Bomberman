//
// Map.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 14 18:16:15 2014 jonathan
// Last update Tue May 20 10:19:51 2014 jonathan
//

#include "Cube.hh"
#include "Map.hh"
#include "MyException.hh"
#include "Player.hh"

Map::Map(int width, int height, bool newmap)
{
  if (newmap)
    {
      for (int x = 0; x < width; x++)
	{
	  for (int y = 0; y < height; y++)
	    _map[x][y][0] = None;
	}
    }
  _width = width;
  _height = height;
  _litteralType[CubeType] = "Cube";
  _litteralType[PlayerType] = "Player";
  _litteralType[GroundType] = "Floor";
  _types["Cube"] = CubeType;
  _types["Player"] = PlayerType;
  _types["Floor"] = GroundType;
  if (!_loader.load())
    throw MyException("Error when loading models");
}
Map::Map()
{
  _litteralType[CubeType] = "Cube";
  _litteralType[PlayerType] = "Player";
  _litteralType[GroundType] = "Floor";
  _types["Cube"] = CubeType;
  _types["Player"] = PlayerType;
  _types["Floor"] = GroundType;
  if (!_loader.load())
    throw MyException("Error when loading models");
}

Map::Map(const Map &old)
{
  _destr = old._destr;
  _indestr = old._indestr;
  _map = old._map;
  _width = old._width;
  _height = old._height;
  _litteralType = old._litteralType;
  _types = old._types;
  if (!_loader.load())
    throw MyException("Error when loading models");
}
Map &Map::operator=(const Map &old)
{
  _destr = old._destr;
  _indestr = old._indestr;
  _map = old._map;
  _width = old._width;
  _height = old._height;
  _litteralType = old._litteralType;
  _types = old._types;
  return (*this);
  if (!_loader.load())
    throw MyException("Error when loading models");
}

Map::~Map()
{
}
void	Map::draw(gdl::BasicShader shader, gdl::Clock clock)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  shader.bind();
  for (size_t i = 0; i < _destr.size(); ++i)
    _destr.at(i)->draw(shader, clock);
  for (size_t i = 0; i < _indestr.size(); ++i)
    _indestr.at(i)->draw(shader, clock);
}
bool	Map::addEntity(e_EType type, float X, float Y, float Z)
{
  AEntity	*entity;

  if (type != _map[(int)X][(int)Y][(int)Z])
    {
      if (type == CubeType || type == GroundType)
 	entity = new Cube(X, Z, Y);
      else
	entity = new Player(X, Y, Z);
      _loader.setObject(entity, type);
      if (entity->initialize())
	{
	  _map[(int)X][(int)Y][(int)Z] = type;
	  _indestr.push_back(entity);
	}
    }
  return true;
}
bool	Map::addEntity(AEntity *entity, e_EType type)
{
  std::cout << _litteralType[type] << std::endl;
  _loader.setObject(entity, type);
  if (entity->initialize())
    {
      // _map[(int)X][(int)Y][(int)Z] = type;
      _indestr.push_back(entity);
    }
  return true;
}
bool	Map::removeEntity(float x, float y, float z)
{
  (void)x;
  (void)y;
  (void)z;
  return false;
}
const std::map<int, std::map<int, std::map<int, enum e_EType> > >	&Map::getMap() const
{
  return _map;
}
int	Map::getWidth() const
{
  return _width;
}
int	Map::getHeight() const
{
  return _height;
}
const std::map<enum e_EType, std::string>	&Map::getTypes() const
{
  return _litteralType;
}
e_EType	Map::getType(const std::string &str)
{
  return _types[str];
}
