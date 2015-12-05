//
// GameEngine.hpp for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:02:23 2014 blondeel julien
// Last update Fri May 23 09:35:22 2014 jonathan
//

#ifndef	_GAMEENGINE_HH_
#define	_GAMEENGINE_HH_

#include <Game.hh>
#include <vector>
#include <SdlContext.hh>
#include <iostream>
#include "OpenGL.hh"
#include "BasicShader.hh"
#include "AEntity.hh"
#include "Map.hh"

class GameEngine : public gdl::Game
{
private:
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AEntity*> _entities;
  Map	*_map;

public:
  GameEngine();
  ~GameEngine();

public:
  bool initialize();
  bool update();
  void draw();
  bool addObject(AEntity *);

  void	setMap(Map *);

  gdl::SdlContext	&getContext();
  gdl::Clock		&getClock();
  gdl::Input		&getInput();
  gdl::BasicShader	&getShader();

  void	removeAllObjects();
  void	setPlayers();
};

#endif
