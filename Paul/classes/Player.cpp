//
// Player.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 13:47:48 2014 jonathan
// Last update Tue May 20 10:46:54 2014 jonathan
//

#include "Player.hh"
#include "ABomb.hh"

Player::Player(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scX, float scY, float scZ) : ACharacter(posX, posY, posZ, rotX, rotY, rotZ, scX, scY, scZ)
{
}
// Player::Player(const Player &old)
// {
// }

// Player &Player::operator=(const Player &old)
// {
//   return (*this);
// }

Player::~Player()
{
}
bool	Player::initialize()
{
  _speed = 10.0f;
  // if (_texture.load("./assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
  //   {
  //     std::cerr << "Cannot load the texture" << std::endl;
  //     return (false);
  //   }
  // if (_model.load("./assets/marvin.fbx") == false)
  //   {
  //     std::cerr << "Cannot load the model" << std::endl;
  //     return (false);
  //   }
  return (true);
}
void	Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
void	Player::putBomb()
{
  std::cout << "I plant a bomb !" << std::endl;
  ABomb	bomb;
  bomb.doPrimaryAction();
}
