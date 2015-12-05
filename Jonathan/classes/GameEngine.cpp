//
// GameEngine.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 15:36:41 2014 Lacazedieu
// Last update Fri May 23 11:08:29 2014 jonathan
//

#include "Thread.hh"
#include "MapEditor.hh"
#include "GameEngine.hh"
#include "ACharacter.hh"
#include "Player.hh"

GameEngine::GameEngine()
{
  _map = NULL;
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _entities.size(); ++i)
    delete _entities[i];
}

bool	GameEngine::initialize()
{
  if (!_context.start(800, 600, "My bomberman!"))
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
  transformation = glm::lookAt(glm::vec3(0, 15, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  return true;
}

bool	GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  // if (_entities.empty())
  //   std::cout << "lol" << std::endl;
  for (size_t i = 0; i < _entities.size(); ++i)
    _entities[i]->update(_clock, _input);
  return true;
}

void GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  if (_map != NULL)
    _map->draw(_shader, _clock);
  for (size_t i = 0; i < _entities.size(); ++i)
    _entities[i]->draw(_shader, _clock);
  _context.flush();
}

bool	GameEngine::addObject(AEntity *obj)
{
  if (!obj->initialize())
    {
      std::cerr << "init failed" << std::endl;
      return false;
    }
  _entities.push_back(obj);
  return true;
}
gdl::SdlContext	&GameEngine::getContext()
{
  return _context;
}
gdl::Clock	&GameEngine::getClock()
{
  return _clock;
}
gdl::Input	&GameEngine::getInput()
{
  return _input;
}
gdl::BasicShader	&GameEngine::getShader()
{
  return _shader;
}
void	GameEngine::setMap(Map *map)
{
  _map = map;
}
void	GameEngine::removeAllObjects()
{
  while (!_entities.empty())
    _entities.pop_back();
  _entities.clear();
}
void	GameEngine::setPlayers()
{
  Player	*entity;

  entity = (Player *)_map->getPlayer();
  entity->setPlayer(false);
  _entities.push_back(entity);
}
