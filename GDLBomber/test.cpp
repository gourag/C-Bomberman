//
// test.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 14:51:25 2014 Lacazedieu
// Last update Tue May  6 15:42:32 2014 Lacazedieu
//

#include <cstdlib>
#include "GameEngine.hh"
#include <iostream>

int main()
{
  GameEngine engine;

  if (engine.initialize() == false)
    {
      std::cout << "exit" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
