//
// AOject.cpp for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:41:45 2014 blondeel julien
// Last update Thu May  8 20:50:59 2014 blondeel julien
//

#include "AObject.hh"

AObject::AObject() : _position(0, 0, 0),  _rotation(0, 0, 0),  _scale(0.1, 0.1, 0.1)
{
}

AObject::~AObject(){}

bool	AObject::initialize()
{
  return (true);
}

void	AObject::translate(glm::vec3 const &v)
{
  _position += v;
}
void	AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}
void	AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4	AObject::getTransformation()
{
  glm::mat4 transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}

void AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}
