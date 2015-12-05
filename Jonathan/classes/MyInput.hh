//
// MyInput.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 21 10:48:47 2014 jonathan
// Last update Wed May 21 11:41:35 2014 jonathan
//

#ifndef _MYINPUT_H_
# define _MYINPUT_H_

#include <vector>
#include <SdlContext.hh>
#include "Clock.hh"
#include "Input.hh"

class MyInput
{
private:
  std::vector<int>	_inputs;
  gdl::Input		_input;
  gdl::SdlContext	_context;
  gdl::Clock		_clock;

public:
  MyInput(gdl::Input, gdl::SdlContext, gdl::Clock);
  MyInput(const MyInput &old);
  MyInput &operator=(const MyInput &old);
  virtual ~MyInput();

  void	addInput(int);
  bool	removeInput(int);
  int	getInput();
};


#endif /* _MYINPUT_H_ */
