#include <iostream>
#include <string.h>
#include <errno.h>
#include "MyException.hh"
#include "Folder.hh"

Folder::Folder(const std::string &folder)
{
  int	n;
  if ((n = scandir(folder.c_str(), &_dirFiles, NULL, alphasort)) == -1)
    throw MyException("Error with scandir in Folder class");
  while (n--)
    _files.push_back(_dirFiles[n]->d_name);
  _name = folder;
}
Folder::~Folder()
{
}

void	Folder::setFolder(const std::string &folder)
{
  int	n;

  // Clear the ancient file list
  while (!_files.empty())
    _files.pop_back();
  _files.clear();

  _name = folder;
  if ((n = scandir(folder.c_str(), &_dirFiles, NULL, alphasort)) == -1)
    throw MyException("Error with scandir in Folder class");
  while (n--)
    _files.push_back(_dirFiles[n]->d_name);
}
const std::string &Folder::getFolder() const
{
  return _name;
}
const std::vector<std::string> &Folder::getFiles() const
{
  return _files;
}
std::vector<std::string>	*Folder::getFilesOfExtension(const std::string &type) const
{
  std::string::size_type	idx;
  std::string			tmp;
  std::vector<std::string>	ret;

  for (unsigned int i = 0; i < _files.size(); i++)
    {
      idx = _files[i].rfind(".");
      tmp = _files[i].substr(idx+1);
      if (tmp == type)
	ret.push_back(_files[i]);
    }
  return new std::vector<std::string>(ret);
}

const std::vector<std::string>	*Folder::getFilesOfType(const std::string &type) const
{
  std::string::size_type	idx;
  std::string			tmp;
  std::vector<std::string>	ret;

  if (type == "shared")
    {
      for (unsigned int i = 0; i < _files.size(); i++)
	{
	  idx = _files[i].rfind(".");
	  tmp = _files[i].substr(idx+1);
	  if (tmp == "so")
	    ret.push_back(_files[i]);
	}
      return new std::vector<std::string>(ret);
    }
  else if (type == "audio")
    {
      for (unsigned int i = 0; i < _files.size(); i++)
	{
	  idx = _files[i].rfind(".");
	  tmp = _files[i].substr(idx+1);
	  if (tmp == "WAV" || tmp == "mp3" || tmp == "wav")
	    ret.push_back(_files[i]);
	}
      return new std::vector<std::string>(ret);
    }
  std::cerr << "type: " << type << " unrecognize" << std::endl;
  return NULL;
}
const std::string &Folder::getFirstFileFromType(const std::string &type) const
{
  std::string::size_type	idx;
  std::string			tmp;

  if (type == "audio")
    {
      for (unsigned int i = 0; i < _files.size(); i++)
	{
	  idx = _files[i].rfind(".");
	  tmp = _files[i].substr(idx+1);
	  if (tmp == "WAV" || tmp == "mp3" || tmp == "wav")
	    return _files[i];
	}
      std::cerr << "No audio file found" << std::endl;
    }
  return _name;
}
