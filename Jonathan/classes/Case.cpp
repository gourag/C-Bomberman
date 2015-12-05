//
// Case.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character/classes
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Mon May 12 18:36:41 2014 jonathan
// Last update Tue May 13 12:48:31 2014 jonathan
//

#include "Case.hh"
#include "Cube.hh"
#include "Player.hh"

Case::Case(Case::EntityType type, int posX, int posY)
{
  _entityType = type;
  _posX = posX;
  _posY = posY;
  if ((_entityType == Case::Box) || (_entityType == Case::Ennemy))
    _isDestructible = true;
  else
    _isDestructible = false;
}

Case::Case(const Case &old)
{
  _entityType = old._entityType;
  _posX = old._posX;
  _posY = old._posY;
}

Case &Case::operator=(const Case &old)
{
  _entityType = old._entityType;
  _posX = old._posX;
  _posY = old._posY;
  return (*this);
}

Case::~Case()
{
}
bool	Case::initialize()
{
  _entity = new Cube(_posX, _posY);
  return _entity->initialize();
}
void	Case::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (_entity == NULL)
    {
      std::cout << "NULL" << std::endl;
      _entity = new Cube(_posX, _posY);
      _entity->initialize();
    }
  else
    _entity->update(clock, input);
}
void	Case::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
    _entity->draw(shader, clock);
}
int	Case::getPosX() const
{
  return _posX;
}
int	Case::getPosY() const
{
  return _posY;
}
Case::EntityType	Case::getEntityType() const
{
  return _entityType;
}
bool	Case::isDestructible()
{
  return _isDestructible;
}
