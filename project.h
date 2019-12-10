#pragma once
#include "iproject.h"

#include <string>

namespace dev {

class Project : public IProject {
  // IProject interface
 public:
  int run();
  void user_input() override;
  float parse_input() const override;
  void display_result(const std::string res) const override;
  std::string get_result() const override;
  std::string get_user_input() const override;

 private:
  std::string user_input_;
  std::string result_;
};
}  // namespace dev
