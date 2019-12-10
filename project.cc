#include "project.h"
#include <iostream>
#include <sstream>
#include <vector>

namespace dev {

int Project::run() {
    return 0;
}

void Project::user_input() {
   std::getline(std::cin, user_input_);
}

std::string Project::parse_input() const {
  std::stringstream ss;

  /* Storing the whole string into string stream */
  ss << user_input_;

  /* Running loop till thestd::vector operands; end of the stream */
  std::string temp;
  int found;
  while (!ss.eof()) {

    /* extracting word by word from stream */
    ss >> temp;

    /* Checking the given word is integer or not */
    if (std::stringstream(temp) >> found)
      std::cout << found << " ";
      operands.push_back(found);
      /* To save from space at the end of string */
      temp = "";
   } else {

  }
 return std::string();
}

float Project::parse_input() const {

std::vector<int> int_operands;
std::vector<float> float_operands;

 for(std::string::size_type i = 0; i < user_input_.size(); ++i) {
     std::string temp;
     if(isdigit(str[i]) || "." == str[i]) {
        temp += str[i];
     } else if ( "+" == str[i] || "-" == str[i] || "*" == str[i] || ":" == str[i]) {

     } else if (" " == str[i]) {
       int_operands.push_back(std::stoi(temp));
     }
 }
 // if s.contains(".")
}


void Project::display_result(const std::string res) const {
    std::cout<< "\nResult: " << res << std::endl;
}

std::string Project::get_result() const {

}

std::string Project::get_user_input() const {
  return user_input_;
}


}  // namespace dev
