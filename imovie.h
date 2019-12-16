#ifndef IMOVIE_H
#define IMOVIE_H
#include <string>

class IMovie {
  virtual std::string getName() const = 0;
  virtual std::string getType() const = 0;
};

#endif // IMOVIE_H
