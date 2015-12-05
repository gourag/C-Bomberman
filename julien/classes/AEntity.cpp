//
// AEntity.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 15:10:15 2014 jonathan
// Last update Thu May 22 11:55:36 2014 blondeel julien
//

#include "AEntity.hh"

AEntity::AEntity(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scX, float scY, float scZ) : _position(posX, posY, posZ),  _rotation(rotX, rotY, rotZ),  _scale(scX, scY, scZ)
{
}

AEntity::~AEntity(){}

bool	AEntity::initialize()
{
  return (true);
}

void	AEntity::translate(glm::vec3 const &v)
{
  _position += v;
}
void	AEntity::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}
void	AEntity::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4	AEntity::getTransformation()
{
  glm::mat4 transform(1);

  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, _scale);
  return (transform);
}

void AEntity::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}
void	AEntity::setName(const std::string &name)
{
  _name = name;
}

const std::string	&AEntity::getName() const
{
  return _name;
}

void AEntity::setTexture(gdl::Texture * texture)
{
  _texture = *texture;
}

void AEntity::setGeometry(gdl::Geometry * geometry)
{
  _geometry = *geometry;
}

void AEntity::setModel(gdl::Model * model)
{
  (void)model;
   // _model = *model;
}

void		AEntity::setX(float x)
{
  _position.x = x;
}

void		AEntity::setY(float y)
{
  _position.y = y;
}

void		AEntity::setZ(float z)
{
  _position.z = z;
}

float		AEntity::getX(void)
{
  return _position.x;
}
float		AEntity::getY(void)
{
  return _position.y;
}
float		AEntity::getZ(void)
{
  return _position.z;
}
