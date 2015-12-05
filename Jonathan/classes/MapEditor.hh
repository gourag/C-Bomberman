//
// MapEditor.hh for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 13 16:20:00 2014 Lacazedieu
// Last update Thu May 22 10:47:40 2014 jonathan
//

#ifndef			_MAPEDITOR_HH_
#define			_MAPEDITOR__

#include <Game.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "OpenGL.hh"
#include "BasicShader.hh"
#include "Map.hh"
#include "Folder.hh"
#include "MyInput.hh"

class			MapEditor
{
private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  e_EType		_type;
  int			_X;
  int			_Y;
  int			_Z;
  int			_w;
  int			_h;
  Map			*_map;
  bool			_changed;
  AEntity		*_preview;
  Loader		_loader;
  Folder		*_folder;
  MyInput		*_listInput;
  std::map<int, void (MapEditor::*)()> _ptr;

  int	_testX;
  int	_testY;
  int	_testZ;
public:
  MapEditor();
  MapEditor(const gdl::SdlContext &context, const gdl::Clock &clock, const gdl::Input &input, const gdl::BasicShader &shader);
  ~MapEditor();

public:
  bool	initialize(const int width = 5, const int height = 5);
  bool	update();
  void	draw();

public:
  void	addEntity();
  void	removeEntity();
  void  changePreview();
  void	changeMapSize(int num);
  void	changeView();

  bool  ground();
  bool  wall();
  bool  block();

public:
  void	moveLeft();
  void	moveRight();
  void	moveUp();
  void	moveDown();
  void	raise();
  void	lower();

  void	loadMap();
  void	newMap();
  void	randomize();
  bool	saveMap();
  Map	*getMap(void);
};

#endif
