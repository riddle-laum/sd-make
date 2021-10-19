#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <filesystem>

// https://cpprefjp.github.io/reference/filesystem.html

int main(int argc, char *argv[]){
  // cmdine args
  char update = 0;
  if(argc > 2){
    std::cout << "[sd-make] ERROR : too many commandline-arguments given" << std::endl;
    std::cout << "          usage : make (major|minor|patch)" << std::endl;
    return 255;
  }
  if(argc == 2){
    if(std::string(argv[1]) == "major") update = 'M';
    else if(std::string(argv[1]) == "minor") update = 'm';
    else if(std::string(argv[1]) == "patch") update = 'p';
    else{
      std::cout << "[sd-make] ERROR : unknown version selector given" << std::endl;
      std::cout << "          usage : make (major|minor|patch)" << std::endl;
      return 255;
    }
  }

  // load version
  unsigned int version[4] = {0}; // major, minor, patch, build.
  std::string version_text = ""; // M.m.p+b
  std::stringstream ss;
  auto ifs = std::ifstream("./version.txt");
  for(int i = 0; i < 4; i++){
    ifs >> version[i];
    ifs.ignore();
  }
  ifs.close();

  // build version update
  version[3]++;
  switch(update){
    case 'M':
    version[0]++;
    version[1] = 0;
    version[2] = 0;
    version[3] = 0;
    break;
    case 'm':
    version[1]++;
    version[2] = 0;
    version[3] = 0;
    break;
    case 'p':
    version[2]++;
    version[3] = 0;
    break;
  }
  ss << version[0] << "." << version[1] << "." << version[2] << "+" << version[3];
  version_text = ss.str();
  std::cout << "version: " << version_text << std::endl;

  // version feedback
  auto ofs = std::ofstream("./version.txt");
  ofs << version_text;
  ofs.close();

  // get file list
  std::vector<std::string> modules;
  for(const auto & file : std::filesystem::directory_iterator("./"))
    modules.push_back(file.path().string());

  // get main-src
  return 0;
}
