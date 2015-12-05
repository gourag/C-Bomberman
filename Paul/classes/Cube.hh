//
// Cube.hh for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:43:57 2014 blondeel julien
// Last update Tue May 13 16:49:56 2014 Lacazedieu
//

#ifndef	_CUBE_HH_
#define _CUBE_HH_

#include "AObject.hh"

class	Cube : public AObject
{
private:
  float _speed;

public:
  Cube(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 1, float scY = 1, float scZ = 1);
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);

  virtual void	doPrimaryAction();
  virtual void	doSound(const std::string &) const;
};

#endif
