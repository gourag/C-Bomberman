//
// Button.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 20 11:55:13 2014 Lacazedieu
// Last update Thu May 22 10:09:08 2014 jonathan
//

#include "Button.hh"

Button::Button(const std::string & option)
{
  _action = NULL;
  _option = option;
  _scale.x = 5;
  _scale.y = 2;
}

Button::~Button()
{
}

bool	Button::initialize()
{
  return true;
}

void	Button::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  if (input.getKey(SDLK_RIGHT))
    std::cout << _option + ": +" << std::endl;
  if (input.getKey(SDLK_LEFT))
    std::cout << _option + ": -" << std::endl;
  if (input.getKey(SDLK_RETURN))
    doPrimaryAction();
}

void	Button::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Button::isFocused()
{
  _scale.x = 5.5;
  _scale.y = 2.2;
}

void	Button::isNotFocused()
{
  _scale.x = 5;
  _scale.y = 2;
}


void	Button::doPrimaryAction()
{
  if (_action != NULL)
    _action();
}

void	Button::doSound(const std::string &sound) const
{
  (void)sound;
}
void	Button::setAction(void (*ptr)())
{
  _action = ptr;
}
