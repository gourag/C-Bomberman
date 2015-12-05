//
// Button.hh for  in /home/lacaze_p/rendu/cpp_bomberman/Character
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 13 14:58:57 2014 Lacazedieu
// Last update Tue May 13 14:59:04 2014 Lacazedieu
//

#ifndef	_BUTTON_HH_
#define _BUTTON_HH_

#include "AObject.hh"

class	Button : public AObject
{
private:
  float _speed;

public:
  Button(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 0.1, float scY = 0.1, float scZ = 0.1);
  virtual ~Button();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);

  virtual void	doPrimaryAction();
  virtual void	doSound(const std::string &) const;
};

#endif
