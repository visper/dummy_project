#include "project.h"
#include <iostream>

int main() {

  dev::Project obj;
  std::cout<< "Input string in format: \"number\"\"space\"\"number\"\"operation\"" << std::endl;
  obj.user_input();
  std::cout << obj.get_user_input() << std::endl;


  std::string res = obj.parse_input();

  return 0;
}
