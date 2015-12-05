//
// ButtonManager.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 20 11:52:22 2014 Lacazedieu
// Last update Fri May 23 11:11:14 2014 jonathan
//

#include "ButtonManager.hh"

ButtonManager::ButtonManager()
{
  _selected = 0;
}

ButtonManager::~ButtonManager()
{
  while (!_buttons.empty())
    _buttons.pop_back();
}

bool	ButtonManager::initialize()
{
  return true;
}

void	ButtonManager::update(gdl::Clock const &clock, gdl::Input &input)
{
  // std::cout << "Manager update:" << std::endl << "Vector size: " << _buttons.size() << std::endl;
  // std::cout << "Selected:" << _selected << std::endl;
  if (!_buttons.empty())
    {
      _buttons.at(_selected)->isFocused();
      _buttons.at(_selected)->update(clock, input);
    }
  if (input.getInput(SDLK_DOWN, true) && _selected < _buttons.size() - 1)
    {
      _buttons.at(_selected)->isNotFocused();
      _selected++;
    }
  else if (input.getInput(SDLK_UP, true) && _selected > 0)
    {
      _buttons.at(_selected)->isNotFocused();
      _selected--;
    }
  else if (input.getInput(SDLK_RETURN, true))
    {
      _buttons.at(_selected)->doPrimaryAction();
    }
}

void	ButtonManager::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  for (unsigned int i = 0; i < _buttons.size(); i++)
    {
      _buttons.at(i)->draw(shader, clock);
    }
}

void	ButtonManager::addButton(Button * button)
{
  if (!_buttons.empty())
    button->setY(_buttons.at(_buttons.size() - 1)->getY() - 3);
  _buttons.push_back(button);
}

void	ButtonManager::doPrimaryAction()
{
}

void	ButtonManager::doSound(const std::string &sound) const
{
  (void)sound;
}
