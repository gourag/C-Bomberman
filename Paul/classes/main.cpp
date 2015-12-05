//
// main.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/Character
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 13 15:04:59 2014 Lacazedieu
// Last update Tue May 13 15:12:29 2014 Lacazedieu
//

#include <iostream>
#include <string>
#include <unistd.h>
#include "Audio.hh"

int		main()
{
  std::string	str;
  Audio	backgroundMusic("./music/");
  Audio	test("./music/");

  backgroundMusic.load("main_theme.mp3");
  backgroundMusic.play();
  test.setMode(Audio::EFFECT);
  test.load("bomb.mp3");

  // std::cout << "Setting volume down to 0.5" << std::endl;
  // backgroundMusic.setVolume(0.5);
  // sleep(10);
  // std::cout << "Setting volume up to 0.8" << std::endl;
  // backgroundMusic.setVolume(0.8);
  // sleep(10);
  // std::cout << "Setting volume down to 0.1" << std::endl;
  // backgroundMusic.setVolume(0.1);
  // sleep(10);
  // std::cout << "Setting volume up to 1.0" << std::endl;
  // backgroundMusic.setVolume(1.0);
  // sleep(10);
  // std::cout << "Setting volume up to 12.0" << std::endl;
  // backgroundMusic.setVolume(12.0);
  // sleep(10);
  std::cout << "press enter to bomb to hear a bomb explosion" << std::endl;
  while (std::getline(std::cin, str))
    {
      if (str == "quit")
	break;
      else if (str == "")
	test.play();
    }
}
