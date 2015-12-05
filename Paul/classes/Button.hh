//
// Button.hh for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 20 11:55:10 2014 Lacazedieu
// Last update Thu May 22 10:07:24 2014 jonathan
//

#ifndef _BUTTON_HH_
#define _BUTTON_HH_

#include "Loader.hh"

class	Button : public AEntity
{
private:
  std::string	_option;
  void		(*_action)();

public:
  Button(const std::string & option);
  virtual ~Button();

public:
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

public:
  void	isFocused();
  void	isNotFocused();

public:
  void		setAction(void (*)());
  virtual void	doPrimaryAction();
  virtual void	doSound(const std::string &sound) const;
};

#endif
