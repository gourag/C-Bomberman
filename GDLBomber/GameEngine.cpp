//
// GameEngine.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 15:36:41 2014 Lacazedieu
// Last update Sat May 10 18:34:35 2014 jonathan
//

#include "GameEngine.hh"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
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
  transformation = glm::lookAt(glm::vec3(0, 10, -200), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  AObject *cube = new Cube();
  if (cube->initialize() == false)
    {
      std::cout << "init failed" << std::endl;
      return (false);
    }
  _objects.push_back(cube);
  return true;
}

bool	GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return true;
}

void GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}
