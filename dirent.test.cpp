#include <vector>
#include <string>
#include <dirent.h> // only work g++
#include <iostream>

int main(void){
  // cmdline args]
  std::vector<std::string> modules;
  DIR *dp = opendir("./src/");
  if(dp == NULL) return 255;
  dirent* entry = readdir(dp);
  while(entry != NULL){
    std::cout << "./src/" << entry->d_name << std::endl;
    // printf("%s : %s\n", path, entry->d_name);
    modules.push_back(std::string(entry->d_name));
    entry = readdir(dp);
  }

  auto itr = modules.begin();
  do{
    std::cout << *itr << std::endl;
  } while(itr != modules.end());

  return 0;
}

// build : g++ sd-make.c -o sd-make.exe
