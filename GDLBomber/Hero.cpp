//
// Hero.cpp for  in /home/blonde_j/TEK2/C++/cpp_bomberman/GDLBomber
// 
// Made by blondeel julien
// Login   <blonde_j@epitech.net>
// 
// Started on  Tue May  6 20:40:19 2014 blondeel julien
// Last update Thu May  8 21:00:02 2014 blondeel julien
//

#include "Hero.hh"

Hero::Hero(){}

Hero::~Hero(){}

bool	Hero::initialize()
{
  _speed = 10.0f;
  if (_texture.load("./assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
    {
      std::cerr << "Cannot load the texture" << std::endl;
      return (false);
    }
  if (_model.load("./assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model" << std::endl;
      return (false);
    }
  return (true);
}

void	Hero::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Hero::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
