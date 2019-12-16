#include "movie.h"

Movie::Movie(int index, std::string name, std::string type) :
  index_(index),  name_(name), type_(type) {
}

std::string Movie::getType() const {
  return type_;
}

std::string Movie::getName() const {
  return name_;
}
