#pragma once

#include <string>

namespace dev{

class IProject {
  virtual int run() = 0;
  virtual void user_input() = 0;
  virtual float parse_input() const = 0;
  virtual void display_result(const std::string res) const = 0;
  virtual std::string get_result() const = 0;
  virtual std::string get_user_input() const = 0;
};

}
