//
// test.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 14:51:25 2014 Lacazedieu
// Last update Wed May 21 11:40:56 2014 blondeel julien
//

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "GameEngine.hh"
#include "Player.hh"
#include "ABomb.hh"
#include "Cube.hh"
#include "MapEditor.hh"

int main()
{
  GameEngine	engine;
  Audio	back("./music/");

  back.load("main_theme.mp3");
  back.setMode(Audio::Background);
  back.setVolume(0.5);
  back.play();
  if (engine.initialize() == false)
    {
      std::cout << "exit" << std::endl;
      return (EXIT_FAILURE);
    }
  engine.addObject(new Player());  
  while (engine.update() == true)
    {
      usleep(30000);
      engine.draw();
    }
  return EXIT_SUCCESS;
}
