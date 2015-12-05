//
// test.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 14:51:25 2014 Lacazedieu
<<<<<<< HEAD
// Last update Thu May 22 10:06:47 2014 jonathan
=======
// Last update Wed May 21 14:47:06 2014 Lacazedieu
>>>>>>> 673a27f9724b0f11682a4b0e941400bc3f23b133
//

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "GameEngine.hh"
#include "Player.hh"
#include "ABomb.hh"
#include "Cube.hh"
#include "MapEditor.hh"
#include "ButtonManager.hh"
#include "Loader.hh"

void	printCoucou()
{
  std::cout << "Coucou" << std::endl;
}

void	mainMenu(GameEngine &engine)
{
  ButtonManager	*manager = new ButtonManager;
  Button	*onePlayer = new Button("1 Joueur");
  Button	*twoPlayer = new Button("2 Joueur");
  Button	*option = new Button("Option");
  Button	*quit = new Button("Quitter");
  Loader	loader;

  onePlayer->setAction(&printCoucou);

  loader.load();
  loader.setObject(onePlayer, ButtonType);
  loader.setObject(twoPlayer, ButtonType);
  loader.setObject(option, ButtonType);
  loader.setObject(quit, ButtonType);
  manager->addButton(onePlayer);
  manager->addButton(twoPlayer);
  manager->addButton(option);
  manager->addButton(quit);
  engine.addObject(manager);
}

int main()
{
  GameEngine	engine;
<<<<<<< HEAD
  // Loader	loader;
  // ButtonManager	*manager = new ButtonManager;
  // Button	*object = new Button("test");
  // Button	*object1 = new Button("test1");
=======
  Loader	loader;
  ButtonManager	*manager = new ButtonManager;
  Button	*object = new Button("test");
  Button	*object1 = new Button("sound");
  Button	*object2 = new Button("luminosité");
  Button	*object3 = new Button("contraste");
>>>>>>> 673a27f9724b0f11682a4b0e941400bc3f23b133

  if (engine.initialize() == false)
    {
      std::cout << "exit" << std::endl;
      return (EXIT_FAILURE);
    }
<<<<<<< HEAD
  // loader.load();
  // loader.setObject(object, ButtonType);
  // loader.setObject(object1, ButtonType);
  // manager->addButton(object);
  // manager->addButton(object1);
  // engine.addObject(manager);
  mainMenu(engine);
=======
  loader.load();
  loader.setObject(object, ButtonType);
  loader.setObject(object1, ButtonType);
  loader.setObject(object2, ButtonType);
  loader.setObject(object3, ButtonType);
  manager->addButton(object);
  manager->addButton(object1);
  manager->addButton(object2);
  manager->addButton(object3);
  engine.addObject(manager);
>>>>>>> 673a27f9724b0f11682a4b0e941400bc3f23b133
  while (engine.update() == true)
    {
      usleep(30000);
      engine.draw();
    }
  return EXIT_SUCCESS;
}
