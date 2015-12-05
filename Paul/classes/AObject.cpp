//
// AOject.cpp for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:41:45 2014 blondeel julien
// Last update Tue May 20 10:47:01 2014 jonathan
//

#include "AObject.hh"

AObject::AObject(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scX, float scY, float scZ) : AEntity(posX, posY, posZ, rotX, rotY, rotZ, scX, scY, scZ)
{
}
// AObject::AObject(const AObject &old)
// {
//   copy
// }

// AObject &AObject::operator=(const AObject &old)
// {
//   copy
//   return (*this);
// }

AObject::~AObject()
{
}
bool	AObject::initialize()
{
  return (true);
}

void AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}
void	AObject::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
