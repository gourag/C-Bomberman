//
// Hero.hh for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 20:36:52 2014 blondeel julien
// Last update Fri May  9 11:24:48 2014 jonathan
//

#ifndef	_HERO_HH_
#define	_HERO_HH_

#include "AObject.hh"

class	Hero : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Model	_model;
  gdl::Geometry	_geometry;
  float		_speed;
  int		life;
  int		bomb;

public:
  Hero();
  virtual ~Hero();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
