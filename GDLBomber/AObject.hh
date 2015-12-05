//
// AObject.hh for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 15:37:49 2014 blondeel julien
// Last update Wed May  7 13:52:52 2014 blondeel julien
//

#ifndef	_AOBJECT_HH_
#define	_AOBJECT_HH_

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "AShader.hh"
#include "Texture.hh"
#include "Geometry.hh"
#include "Model.hh"

class	AObject
{
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;

public:
  AObject();
  virtual ~AObject();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void translate(glm::vec3 const &v);
  void rotate(glm::vec3 const& axis, float angle);
  void scale(glm::vec3 const& scale);
  glm::mat4 getTransformation();
};

#endif
