//
// Player.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 13:47:48 2014 jonathan
// Last update Fri May 23 12:49:26 2014 blondeel julien
//

#include "Player.hh"
#include "ABomb.hh"

Player::Player(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scX, float scY, float scZ) : ACharacter(posX, posY, posZ, rotX, rotY, rotZ, scX, scY, scZ)
{
}

Player::~Player(){}

bool	Player::initialize()
{
  _speed = 1.0f;
  _anim = 30;
  _bomb = 10;
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
  _model.createSubAnim(0,"Stop", 60, 150);
  return (true);
}
void	Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  if (input.getKey(SDLK_UP, true))
    moveUp();
  if (input.getKey(SDLK_DOWN, true))
    moveDown();
  if (input.getKey(SDLK_LEFT, true))
    moveLeft();
  if (input.getKey(SDLK_RIGHT, true))
    moveRight();
  if (input.getKey(SDLK_SPACE, true))
    putBomb();
}

void	Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
  for (size_t i = 0; i < _bombs.size(); ++i)
    _bombs[i]->draw(shader, clock);
}
void	Player::putBomb()
{
  if (_bomb > 0)
    {
      addBombs(new ABomb(_position.x,_position.y,_position.z,_rotation.x,_rotation.y,_rotation.z));
      _bomb--;
    }
}

void	Player::player_anim()
{
  if (_anim > 60)
    _anim = 30;
  _model.createSubAnim(0, "Move", _anim, _anim);
  _model.setCurrentSubAnim("Move");
  _anim++;
}

void	Player::moveUp()
{
  translate(glm::vec3(0,0,_speed));
  _rotation.y = 0;
  player_anim();
}

void	Player::moveDown()
{
  translate(glm::vec3(0,0,-_speed));
  _rotation.y = 180;
  player_anim();
}

void	Player::moveRight()
{
  translate(glm::vec3(-_speed,0,0));
  _rotation.y = 270;
  player_anim();
}

void	Player::moveLeft()
{
  translate(glm::vec3(_speed,0,0));
  _rotation.y = 90;
  player_anim();
}

bool	Player::addBombs(AEntity *obj)
{
  if (!obj->initialize())
    {
      std::cerr << "init bomb failed" << std::endl;
      return false;
    }
  _bombs.push_back(obj);
  return true;
}
