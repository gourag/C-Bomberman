//
// Map.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 14 18:16:15 2014 jonathan
// Last update Fri May 23 11:02:50 2014 jonathan
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
  _litteralType[WallType] = "Wall";
  _litteralType[None] = "None";
  _types["Cube"] = CubeType;
  _types["Player"] = PlayerType;
  _types["Floor"] = GroundType;
  _types["Wall"] = WallType;
  _types["None"] = None;
  if (!_loader.load())
    throw MyException("Error when loading models");
}
Map::Map()
{
  _litteralType[CubeType] = "Cube";
  _litteralType[PlayerType] = "Player";
  _litteralType[GroundType] = "Floor";
  _litteralType[WallType] = "Wall";
  _types["Cube"] = CubeType;
  _types["Player"] = PlayerType;
  _types["Floor"] = GroundType;
  _types["Wall"] = WallType;
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

  if (_map[(int)X][(int)Y][(int)Z] == None)
    {
      if (type != PlayerType)
 	entity = new Cube(X, Z, Y);
      else
	entity = new Player(X, Y, Z);
      _loader.setObject(entity, type);
      if (entity->initialize())
	{
	  _map[(int)X][(int)Y][(int)Z] = type;
	  if (type == GroundType || type == WallType)
	    _indestr.push_back(entity);
	  else if (type == CubeType)
	    _destr.push_back(entity);
	  else
	    _players.push_back(entity);
	}
    }
  return true;
}
bool	Map::addEntity(AEntity *entity, e_EType type)
{
  if (_map[(int)entity->getX()][(int)entity->getY()][(int)entity->getZ()] == None)
    {
      _loader.setObject(entity, type);
      if (entity->initialize())
	{
	  _map[(int)entity->getX()][(int)entity->getY()][(int)entity->getZ()] = type;
	  if (type == GroundType || type == WallType)
	    _indestr.push_back(entity);
	  else if (type == CubeType)
	    _destr.push_back(entity);
	  else
	    _players.push_back(entity);
	}
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
void	Map::removeAllEntity()
{
  _map.erase(_map.begin(), _map.end());
  while (!_destr.empty())
    _destr.pop_back();
  _destr.clear();
  while (!_indestr.empty())
    _indestr.pop_back();
  _indestr.clear();
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
void	Map::setWidth(int num)
{
  if (num > 0)
      _width++;
  else
      _width += (_width - 1 < 5) ? 0 : 1;
}
void	Map::setHeight(int num)
{
  if (num > 0)
      _height++;
  else
    _height += (_height - 1 < 5) ? 0 : 1;
}
void	Map::setName(const std::string &name)
{
  _name = name;
}
const std::string	&Map::getName() const
{
  return _name;
}
bool	Map::hasPlayer()
{

  for (int x = 0; x < _width; x++)
    {
      for (int y = 0; y < _height; y++)
	{
	  if (_map[x][y][1] == PlayerType)
	    {
	      std::cout << "je suis un player" << std::endl;
	      return true;
	    }
	}
    }
  return false;
}
AEntity	*Map::getPlayer()
{
  AEntity	*entity;
  for (std::vector<AEntity *>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      entity = *it;
      _map[(int)(*it)->getZ()][(int)(*it)->getZ()][(int)(*it)->getZ()] = None;
      return entity;
    }
  return NULL;
}
