//
// Bomb.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 14:50:37 2014 jonathan
// Last update Wed May 21 11:33:14 2014 blondeel julien
//

#include "ABomb.hh"

ABomb::ABomb(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scX, float scY, float scZ) : AObject(posX, posY, posZ, rotX, rotY, rotZ, scX, scY, scZ)
{
}

// ABomb::ABomb(const ABomb &old)
// {
//   copy
// }

// ABomb &ABomb::operator=(const ABomb &old)
// {
//   copy
//   return (*this);
// }

ABomb::~ABomb()
{
}
bool	ABomb::initialize()
{
  Audio	*explosion = new Audio("./music/");
  explosion->setMode(Audio::Effect);
  explosion->load("bomb.mp3");
  explosion->setName("explosion");
  explosion->setVolume(1.0);
  _sounds.push_back(explosion);
  if (_model.load("./assets/Dynamite/dinamite.obj") == false)
    {
      std::cerr << "Cannot load the model" << std::endl;
      return (false);
    }
  if (_texture.load("./assets/Dynamite/D.tga") == false)
    {
      std::cerr << "Cannot load the texture" << std::endl;
      return (false);
    }
  return (true);
}
void	ABomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	ABomb::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}

void	ABomb::doPrimaryAction()
{
  std::cout << "I'm a bomb and...";
  // sleep(1);
  std::cout << " I... ";
  // sleep(3);
  std::cout << " Explooooooode !!!" << std::endl;
  doSound("explosion");
}
void	ABomb::doSound(const std::string &sound) const
{
  for (unsigned int i = 0; i < _sounds.size(); i++)
    {
      if (_sounds[i]->getName() == sound)
  	{
  	  _sounds[i]->play();
  	  break;
  	}
    }
}
