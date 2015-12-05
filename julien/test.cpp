//
// test.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 14:51:25 2014 Lacazedieu
// Last update Wed May 14 19:11:29 2014 jonathan
//

#include <cstdlib>
#include <iostream>
#include "GameEngine.hh"
#include "Player.hh"
#include "ABomb.hh"
#include "Cube.hh"
#include "MapEditor.hh"

// void	launchMapEditor(gdl::Input &input, gdl::SdlContext &context)
// {
//   std::cout << "Launching Map Editor" << std::endl;
//   MapEditor	edit;

//   if (!edit.editMap("map01.map", input, context))
//     {
//       std::cout << "Map: map01.map doesn't seams to exist. Creating it" << std::endl;
//       if (!edit.createMap("map01.map"))
// 	{
// 	  std::cerr << "Error: cannot create map: map01.map" << std::endl;
// 	  return ;
// 	}
//       else
// 	edit.editMap("map01.map", input, context);
//     }
// }

int main(int ac, char **av)
{
  GameEngine	engine;
  MapEditor	edit;
  Audio	back("./music/");

  if ((ac == 2))
    {
      if (std::string(av[1]) == "-e")
	{
	  if (!edit.initialize())
	    {
	      std::cout << "exit editor" << std::endl;
	      return (EXIT_FAILURE);
	    }
	  while (edit.update())
	    {
	      edit.draw();
	    }
	}
    }
  else
    {
      back.load("main_theme.mp3");
      back.setMode(Audio::Background);
      back.setVolume(0.2);
      back.play();
      if (engine.initialize() == false)
	{
	  std::cout << "exit" << std::endl;
	  return (EXIT_FAILURE);
	}
      engine.addObject(new Player(0,0,0,0,0,0,0.1,0.1,0.1));
      while (engine.update() == true)
	{
	  engine.draw();
	}
    }
  return EXIT_SUCCESS;
}
