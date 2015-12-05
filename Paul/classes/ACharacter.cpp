//
// Character.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 13:31:20 2014 jonathan
// Last update Mon May 12 15:54:11 2014 jonathan
//

#include "ACharacter.hh"

ACharacter::ACharacter(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scX, float scY, float scZ) : AEntity(posX, posY, posZ, rotX, rotY, rotZ, scX, scY, scZ)
{
}
// Character::Character(const Character &old)
// {
// }

// Character &Character::operator=(const Character &old)
// {
//   return (*this);
// }

ACharacter::~ACharacter()
{
}

bool	ACharacter::initialize()
{
  return (true);
}

void ACharacter::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}
void	ACharacter::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
void	ACharacter::setBomb(int num)
{
  _bomb += num;
}
void	ACharacter::setSpeed(float speed)
{
  _speed = speed;
}
void	ACharacter::setLife(bool positive)
{
  if (positive)
    _life++;
  else
    _life--;
}
int	ACharacter::getLife() const
{
  return _life;
}
int	ACharacter::getBomb() const
{
  return _bomb;
}
void	ACharacter::doPrimaryAction()
{
}
void	ACharacter::doSound(const std::string &) const
{
}
float	ACharacter::getSpeed() const
{
  return _speed;
}