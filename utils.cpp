#include <functional>
#include <algorithm>
#include  "Calc.h"
#include "utils.h"
namespace utils {

bool IsOperator(char symbol) {
  std::vector<char> operators = { '+', '-', '*', '/' };
  bool contains = operators.end() != std::find(operators.begin(), operators.end(), symbol);
  return contains;
}

std::vector<char> ExtractOperators(const std::string& str) {
  std::vector<char> operators_vector;
  for(char symbol : str) {
    if (IsOperator(symbol)) {
      operators_vector.push_back(symbol);
    }
  }
  std::reverse(operators_vector.begin(), operators_vector.end());
  return operators_vector;
}

}  // namespace utils
