//
// mainEditor.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 14 09:24:53 2014 jonathan
// Last update Tue May 20 15:40:05 2014 jonathan
//

#include <cstdlib>
#include <iostream>
#include "GameEngine.hh"
#include "Player.hh"
#include "ABomb.hh"
#include "Cube.hh"
#include "MapEditor.hh"
#include <unistd.h>

int main()
{
   MapEditor	edit;
  // Audio	back("./music/");

  // back.load("editor_theme.mp3");
  // back.setMode(Audio::Background);
  // back.setVolume(0.5);
  // back.play();
  if (!edit.initialize())
    {
      std::cout << "exit editor" << std::endl;
      return (EXIT_FAILURE);
    }
  while (edit.update())
    {
      usleep(40000);
      edit.draw();
    }
  return EXIT_SUCCESS;
  // gdl::Model	model;
  // model.load("./assets/marvin.fbx");
}
