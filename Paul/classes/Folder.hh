#include <dirent.h>
#include <stdlib.h>
#include <string>
#include <vector>

class Folder
{
private:
  Folder(const Folder &old);
  Folder operator=(const Folder &old);

private:
  std::string			_name;
  std::vector<std::string>	_files;
  struct dirent			**_dirFiles;

public:
  Folder(const std::string &folder = "./");
  virtual ~Folder();

  void setFolder(const std::string &folder);
  const std::string &getFolder(void) const;

  const std::string &getFile(void) const;
  const std::string &getFirstFileFromType(const std::string &) const;
  const std::vector<std::string> &getFiles(void) const;
  const std::vector<std::string> *getFilesOfType(const std::string &) const;
};
