//
// MapEditor.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 13 16:20:03 2014 Lacazedieu
// Last update Tue May 20 10:12:13 2014 jonathan
//

#include "Cube.hh"
#include "Serialize.hh"
#include "MapEditor.hh"
#include "MyException.hh"
#include "Player.hh"

MapEditor::MapEditor()
{
  _changed = false;
  _map = NULL;
}

MapEditor::~MapEditor()
{
}

bool	MapEditor::initialize(const int width, const int height)
{
  if (!_context.start(800, 600, "My bomberman! Edit mode"))
    {
      std::cout << "start failed" << std::endl;
      return false;
    }
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./Shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./Shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  _w = width;
  _h = height;
  _X = 0;
  _Y = 0;
  _Z = 0;
  if (!_loader.load())
    throw MyException("Error while loading models");
  _type = CubeType;
  _preview = NULL;
  changePreview();
  return (true);
}

bool	MapEditor::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (_changed == true) ? (saveMap()) : false;
  if (_input.getKey(SDLK_UP))
    moveDown();
  if (_input.getKey(SDLK_DOWN))
    moveUp();
  if (_input.getKey(SDLK_LEFT))
    moveRight();
  if (_input.getKey(SDLK_RIGHT))
    moveLeft();
  if (_input.getKey(SDLK_z))
    raise();
  if (_input.getKey(SDLK_s))
    lower();
  if (_input.getKey(SDLK_c))
    _type = CubeType;
  if (_input.getKey(SDLK_g))
    _type = GroundType;
  if (_input.getKey(SDLK_p))
    _type = PlayerType;
  if (_input.getKey(SDLK_SPACE))
    addEntity();
  if (_input.getKey(SDLK_n))
    newMap();
  if (_input.getKey(SDLK_l))
    loadMap();
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  changePreview();
  return true;
}

void	MapEditor::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  if (_map != NULL)
    _map->draw(_shader, _clock);
  _preview->draw(_shader, _clock);
  _context.flush();
}

void	MapEditor::changePreview()
{
  if (_preview != NULL)
    {
      _preview->setX(_X);
      _preview->setY(_Z);
      _preview->setZ(_Y);
      _loader.setObject(_preview, _type);
    }
  else if (_type == CubeType || _type == GroundType)
    {
      _preview = new Cube(_X, _Z, _Y);
      _loader.setObject(_preview, _type);
      _preview->initialize();
    }
  else if (_type == PlayerType)
    {
      _preview = new Player(_X, _Z, _Y);
      _loader.setObject(_preview, _type);
      _preview->initialize();
    }
}

void	MapEditor::moveLeft()
{
  _X = ((_X) < 1) ? (_w - 1) : (_X - 1);
  // std::cout << "moved left (" << _X << "," << _Y << ")" << std::endl;
  changePreview();
}

void	MapEditor::moveRight()
{
  _X = ((_X + 1) >= _w) ? (0) : (_X + 1);
  // std::cout << "moved right (" << _X << "," << _Y << ")" << std::endl;
  changePreview();
}

void	MapEditor::moveUp()
{
  _Y = ((_Y) < 1) ? (_h - 1) : (_Y - 1);
  // std::cout << "moved up (" << _X << "," << _Y << ")" << std::endl;
  changePreview();
}


void	MapEditor::moveDown()
{
  _Y = ((_Y + 1) >= _h) ? (0) : (_Y + 1);
  // std::cout << "moved up (" << _X << "," << _Y << ")" << std::endl;
  changePreview();
}

void	MapEditor::raise()
{
  _Z += ((_Z + 1) > 1) ? (0) : (1);
  changePreview();
}

void	MapEditor::lower()
{
  _Z -= ((_Z - 1) < 0) ? (0) : (1);
  changePreview();
}

void	MapEditor::addEntity()
{
  _changed = true;
  _map->addEntity(_type, _X, _Y, _Z);
  // Cube	*entity;

  // if (_type != _map[_X][_Y])
  //   {
  //     if (_type == CubeType)
  // 	entity = new Cube(_X, _Z, _Y);
  //     if (entity->initialize())
  // 	{
  // 	  _entities.push_back(entity);
  // 	}
  //   }
}
bool	MapEditor::loadMap()
{
  Serialize	ser;

  _map = ser.unpack("./maps/mapTest.map");
  return true;
}
void	MapEditor::newMap()
{
  Map	*mapy = new Map(_w, _h, true);

  _map = mapy;
}
bool	MapEditor::saveMap()
{
  Serialize	ser(_map);

  ser.pack("mapTest.map");
  return false;
}
