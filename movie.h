#ifndef MOVIE_H
#define MOVIE_H
#include "imovie.h"

class Movie : public IMovie {
public:

  Movie( const std::string& type,
              const std::string& name);
  std::string getName() const override;
  std::string getType() const override;
private:
  const std::string type_;
  const std::string name_;
};

#endif // MOVIE_H
