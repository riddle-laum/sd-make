#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

// https://cpprefjp.github.io/reference/filesystem.html

int main(void){
  for(const auto & file : std::filesystem::directory_iterator("./"))
    std::cout << file.path() << std::endl;
  return 0;
}
