//
// ButtonManager.hh for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 20 11:52:18 2014 Lacazedieu
// Last update Wed May 21 12:32:34 2014 Lacazedieu
//

#ifndef _BUTTONMANAGER_HH_
#define _BUTTONMANAGER_HH_

#include "Button.hh"

class	ButtonManager : public AEntity
{
private:
  std::vector<Button*>	_buttons;
  unsigned int		_selected;
public:
  ButtonManager();
  virtual ~ButtonManager();

public:
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

public:
  void	addButton(Button * button);

public:
  virtual void	doPrimaryAction();
  virtual void	doSound(const std::string &sound) const;
};

#endif
