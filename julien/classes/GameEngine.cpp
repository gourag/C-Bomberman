//
// GameEngine.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 15:36:41 2014 Lacazedieu
// Last update Wed May 21 11:40:44 2014 blondeel julien
//

#include "Thread.hh"
#include "MapEditor.hh"
#include "GameEngine.hh"
#include "ACharacter.hh"

GameEngine::GameEngine()
{
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
  transformation = glm::lookAt(glm::vec3(0, 10, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
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
  for (size_t i = 0; i < _entities.size(); ++i)
    _entities[i]->update(_clock, _input);
  return true;
}

void GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
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

// /* Methode pour le test */
// void	GameEngine::getInput()
// {
//   Character	*c = (Character *) _objects[0];
//   if (_input.getKey(SDLK_LEFT))
//     c->move();
//   else if (_input.getKey(SDLK_RIGHT))
//     c->move();
//   else if (_input.getKey(SDLK_UP))
//     c->move();
//   else if (_input.getKey(SDLK_DOWN))
//     c->move();
//   else if (_input.getKey(SDLK_SPACE))
//     c->putBomb();
//   _context.updateClock(_clock);
//   _context.updateInputs(_input);
// }
