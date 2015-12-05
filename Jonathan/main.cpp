//
// test.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May  6 14:51:25 2014 Lacazedieu
// Last update Fri May 23 11:09:41 2014 jonathan
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

void	printCoucou(__attribute__((unused))void *arg)
{
}

void	soloMenu(__attribute__((unused))void *arg)
{
  GameEngine	*engine = (GameEngine *)arg;
  MapEditor	edit(engine->getContext(), engine->getClock(), engine->getInput(), engine->getShader());

  edit.loadMap();
  engine->removeAllObjects();
  engine->setMap(edit.getMap());
  engine->setPlayers();
  std::cout << "end of soloMenu" << std::endl;
}
void	multiplayerMenu(__attribute__((unused))void *arg)
{
}
void	optionMenu(__attribute__((unused))void *arg)
{
}

void	quitGame(__attribute__((unused))void *arg)
{
  exit(42);
}

void	mainMenu(GameEngine &engine)
{
  ButtonManager	*manager = new ButtonManager;
  Button	*onePlayer = new Button("1 Joueur");
  Button	*twoPlayer = new Button("2 Joueur");
  Button	*option = new Button("Option");
  Button	*quit = new Button("Quitter");
  Loader	loader;

  onePlayer->setAction(soloMenu, &engine);
  twoPlayer->setAction(multiplayerMenu, NULL);
  option->setAction(&optionMenu, NULL);
  quit->setAction(&quitGame, NULL);

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

  if (engine.initialize() == false)
    {
      std::cout << "exit" << std::endl;
      return (EXIT_FAILURE);
    }
  mainMenu(engine);
  while (engine.update() == true)
    {
      usleep(30000);
      engine.draw();
    }
  return EXIT_SUCCESS;
}
