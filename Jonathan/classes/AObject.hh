//
// AObject.hh for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:37:49 2014 blondeel julien
// Last update Mon May 12 15:10:41 2014 jonathan
//

#ifndef	_AOBJECT_HH_
#define	_AOBJECT_HH_

#include "AEntity.hh"

class	AObject : public AEntity
{
protected:
  float		_speed;

public:
  AObject(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 0.1, float scY = 0.1, float scZ = 0.1);
  virtual ~AObject();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
};

#endif
