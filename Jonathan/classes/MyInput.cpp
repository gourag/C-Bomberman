//
// MyInput.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 21 10:53:18 2014 jonathan
// Last update Wed May 21 11:45:20 2014 jonathan
//

#include "MyInput.hh"

MyInput::MyInput(gdl::Input input, gdl::SdlContext context, gdl::Clock clock)
{
  _input = input;
  _context = context;
  _clock = clock;
}

MyInput::MyInput(const MyInput &old)
{
}

MyInput &MyInput::operator=(const MyInput &old)
{
  return *this;
}

MyInput::~MyInput()
{
}

void	MyInput::addInput(int input)
{
  _inputs.push_back(input);
}
bool	MyInput::removeInput(int input)
{
  for (std::vector<int>::iterator it = _inputs.begin(); it != _inputs.end(); ++it)
    {
      if (*it == input)
	{
	  _inputs.erase(it);
	  return true;
	}
    }
  return false;
}
int	MyInput::getInput()
{
  for (std::vector<int>::iterator it = _inputs.begin(); it != _inputs.end(); ++it)
    {
      if (_input.getKey(*it))
	return *it;
      _context.updateClock(_clock);
      _context.updateInputs(_input);
    }
  return -1;
}
