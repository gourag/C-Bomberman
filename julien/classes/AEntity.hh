//
// AEntity.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 14:42:28 2014 jonathan
// Last update Tue May 20 13:51:27 2014 blondeel julien
//

#ifndef _AENTITY_H_
# define _AENTITY_H_

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include "AShader.hh"
#include "Texture.hh"
#include "Geometry.hh"
#include "Model.hh"

class AEntity
{
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;

  gdl::Texture	_texture;
  gdl::Model	_model;
  gdl::Geometry	_geometry;
  int		_life;

  std::string	_name;

public:
  AEntity(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 1, float scY = 1, float scZ = 1);
  virtual ~AEntity();

public:
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;

public:
  virtual void translate(glm::vec3 const &v);
  virtual void rotate(glm::vec3 const& axis, float angle);
  virtual void scale(glm::vec3 const& scale);

public:
  virtual glm::mat4 getTransformation();
  virtual const std::string &getName(void) const;

public:
  virtual void	setName(const std::string &);
  void		setGeometry(gdl::Geometry * geometry);
  void		setModel(gdl::Model * model);
  void		setTexture(gdl::Texture * texture);
  void		setX(float x);
  void		setY(float y);
  void		setZ(float z);
  float		getX(void);
  float		getY(void);
  float		getZ(void);
public:
  virtual void	doPrimaryAction() = 0;
  virtual void	doSound(const std::string &sound) const = 0;
};

#endif /* _AENTITY_H_ */
