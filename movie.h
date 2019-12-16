#ifndef MOVIE_H
#define MOVIE_H
#include "imovie.h"

class Movie : public IMovie {
public:
  Movie(int index, std::string name, std::string type);
  std::string getName() const override;
  std::string getType() const override;
private:
  const int index_;
  const std::string name_;
  const std::string type_;
};

#endif // MOVIE_H
