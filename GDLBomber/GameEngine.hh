//
// GameEngine.hpp for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:02:23 2014 blondeel julien
// Last update Wed May  7 13:55:02 2014 blondeel julien
//

#ifndef	_GAMEENGINE_HH_
#define	_GAMEENGINE_HH_

#include <Game.hh>
#include <vector>
#include <SdlContext.hh>
#include <iostream>
#include "OpenGL.hh"
#include "BasicShader.hh"
#include "Cube.hh"
#include "Hero.hh"

class GameEngine : public gdl::Game
{
private:
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;

public:
  GameEngine();
  ~GameEngine();

public:
  bool initialize();
  bool update();
  void draw();
};

#endif
