//
// MapEditor.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 13 16:20:03 2014 Lacazedieu
// Last update Thu May 22 17:05:34 2014 jonathan
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
  _folder = new Folder("./maps/");
  _listInput = new MyInput(_input, _context, _clock);
}
MapEditor::MapEditor(const gdl::SdlContext &context, const gdl::Clock &clock, const gdl::Input &input, const gdl::BasicShader &shader)
{
  _context = context;
  _clock = clock;
  _input = input;
  _shader = shader;
  _folder = new Folder("./maps/");
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
  transformation = glm::lookAt(glm::vec3(0, 10, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _testX = 0;
  _testY = 0;
  _testZ = 0;
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
  // _listInput->addInput(SDLK_UP);
  // _listInput->addInput(SDLK_DOWN);
  // _listInput->addInput(SDLK_LEFT);
  // _listInput->addInput(SDLK_RIGHT);
  // _listInput->addInput(SDLK_n);
  // _listInput->addInput(SDLK_l);
  // _listInput->addInput(SDLK_g);
  // _listInput->addInput(SDLK_c);
  // _listInput->addInput(SDLK_p);
  // _listInput->addInput(SDLK_SPACE);
  // _listInput->addInput(SDLK_r);
  // _listInput->addInput(SDLK_KP_PLUS);
  // _listInput->addInput(SDLK_KP_MINUS);
  // _ptr[SDLK_UP] = &MapEditor::moveDown;
  // _ptr[SDLK_DOWN] = &MapEditor::moveUp;
  // _ptr[SDLK_LEFT] = &MapEditor::moveRight;
  // _ptr[SDLK_RIGHT] = &MapEditor::moveLeft;
  // _ptr[SDLK_p] = &MapEditor::nextType;
  // _ptr[SDLK_o] = &MapEditor::prevType;
  // _ptr[SDLK_r] = &MapEditor::randomize;
  // _ptr[SDLK_SPACE] = &MapEditor::addEntity;
  // _ptr[SDLK_l] = &MapEditor::loadMap;
  // _ptr[SDLK_KP_MINUS] = &MapEditor::changeMapSize;
  // _ptr[SDLK_KP_PLUS] = &MapEditor::changeMapSize;
  // _ptr[SDLK_n] = &MapEditor::newMap;
  return (true);
}
void	MapEditor::changeView()
{
  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(0, 20, -20), glm::vec3(_testX, _testZ, _testY), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
}
bool	MapEditor::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (_changed == true) ? (saveMap()) : false;
  if (_input.getInput(SDLK_UP, true))
    moveDown();
  if (_input.getInput(SDLK_DOWN, true))
    moveUp();
  if (_input.getInput(SDLK_LEFT, true))
    moveRight();
  if (_input.getInput(SDLK_RIGHT, true))
    moveLeft();
  if (_input.getInput(SDLK_z, true))
    raise();
  if (_input.getInput(SDLK_s, true))
    lower();
  if (_input.getInput(SDLK_c, true))
    _type = CubeType;
  if (_input.getInput(SDLK_g, true))
    _type = WallType;
  if (_input.getInput(SDLK_w, true))
    _type = GroundType;
  if (_input.getInput(SDLK_p, true))
    _type = PlayerType;
  if (_input.getInput(SDLK_SPACE, true))
    addEntity();
  if (_input.getInput(SDLK_n, true))
    newMap();
  if (_input.getInput(SDLK_l, true))
    loadMap();
  if (_input.getInput(SDLK_r, true))
    randomize();
  if (_input.getInput(SDLK_KP_PLUS, true))
    changeMapSize(1);
  if (_input.getInput(SDLK_KP_MINUS, true))
    changeMapSize(-1);
  // int i = _listInput->getInput();
  // if (i != -1)
  //   (this->*_ptr[i])();
  changeView();
  changePreview();
  _context.updateClock(_clock);
  _context.updateInputs(_input);
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
  else if (_type == CubeType || _type == GroundType || _type == WallType)
    {
      _preview = new Cube(_X, _Z, _Y);
      _loader.setObject(_preview, _type);
      _preview->initialize();
    }
  else if (_type == PlayerType)
    {
      _preview = new Player(_X, _Z, _Y);
      _preview->initialize();
    }
}

void	MapEditor::moveLeft()
{
  _X = ((_X - 1) < 0) ? (0) : (_X - 1);
}

void	MapEditor::moveRight()
{
  _X = ((_X + 1) >= _w) ? (_w) : (_X + 1);
}

void	MapEditor::moveUp()
{
  _Y = ((_Y - 1) < 0) ? (0) : (_Y - 1);
}


void	MapEditor::moveDown()
{
  _Y = ((_Y + 1) >= _h) ? (_h) : (_Y + 1);
}

void	MapEditor::raise()
{
  _Z += ((_Z + 1) > 1) ? (0) : (1);
}

void	MapEditor::lower()
{
  _Z -= ((_Z - 1) < 0) ? (0) : (1);
}

void	MapEditor::addEntity()
{
  _changed = true;
  _map->addEntity(_type, _X, _Y, _Z);
}
void	MapEditor::loadMap()
{
  Serialize	ser;
  int	i;
  bool		stop = false;
  std::string	str;
  std::vector<std::string> *vec = _folder->getFilesOfExtension("map");
  std::vector<std::string>::iterator it = vec->begin();

  for (i = 0; (unsigned int)i < vec->size(); ++i)
    std::cout << (*vec)[i] << std::endl;
  i = 0;
  while (!stop)
    {
      if (_input.getInput(SDLK_UP, true))
	{
	  it = (it != vec->begin()) ? (it - 1) : (vec->begin());
	  std::cout << "selected: " << *it << std::endl;
	}
      else if (_input.getInput(SDLK_DOWN, true))
	{
	  it = (it != (vec->end() - 1)) ? (it + 1) : (vec->end() - 1);
	  std::cout << "selected: " << *it << std::endl;
	}
      else if (_input.getInput(SDLK_RETURN, true))
	stop = true;
      _context.updateClock(_clock);
      _context.updateInputs(_input);
    }
  str = _folder->getFolder() + *it;
  _map = ser.unpack(str);
}
void	MapEditor::newMap()
{
  std::string	str;
  Map	*mapy = new Map(_w, _h, true);


  std::getline(std::cin, str);
  _map = mapy;
  _map->setName(str);
}
bool	MapEditor::saveMap()
{
  Serialize	ser(_map);

  ser.pack(_map->getName());
  return false;
}
void	MapEditor::changeMapSize(int num)
{
  if (num > 0)
    {
      _w++;
      _h++;
    }
  else
    {
      _w -= (_w - 1 < 5) ? 0 : 1;
      _h -= (_h - 1 < 5) ? 0 : 1;
    }
  _map->setWidth(num);
  _map->setHeight(num);
}
bool  MapEditor::ground()
{
  int a = 0;
  int b = 0;

  _Z = 0;
  while (a <= _w)
    {
      b = 0;
      while (b <= _h)
	{
	  _type = GroundType;
	  _X = b;
	  _Y = a;
	  _Z = 0;
	  this->addEntity();
	  b++;
	}
      a++;
    }
  return true;
}

bool  MapEditor::wall()
{
  int a = 0;

  _Z = 1;
  while (a <= _w)
    {
      _type = WallType;
      _X = 0;
      _Y = a;
      this->addEntity();
      a++;
    }
  a = 0;
  while (a <= _w)
    {
      _type = WallType;
      _X = _h;
      _Y = a;
      this->addEntity();
      a++;
    }
  a = 0;
  while (a <= _h)
    {
      _type = WallType;
      _X = a;
      _Y = 0;
      this->addEntity();
      a++;
    }
  a = 0;
  while (a <= _h)
    {
      _type = WallType;
      _X = a;
      _Y = _w;
      this->addEntity();
      a++;
    }
  return true;
}

bool  MapEditor::block()
{
  int	a = 0;
  int	x, y;

  srand(time(NULL));
  _type = WallType;
  _Z = 1;
  while (a < ((_h * _w) / 6))
    {
      _X = rand() % _h;
      _Y = rand() % _w;
      this->addEntity();
      a++;
    }
  _type = CubeType;
  a = 0;
  while (a < ((_h * _w) / 4))
    {
      x =  rand() % _h;
      y =  rand() % _w;
      if (((x != 0) || (x != _w)) && ((y != 0) || (y != _h)))
	{
	  _X = x;
	  _Y = y;
	  this->addEntity();
	}
      a++;
    }
  return true;
}

void  MapEditor::randomize()
{
  _changed = true;
  _map->removeAllEntity();
  this->ground();
  this->wall();
  this->block();
}
Map	*MapEditor::getMap()
{
  return _map;
}
