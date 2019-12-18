#ifndef IMOVIE_REPO_H
#define IMOVIE_REPO_H
#include "movie.h"

class IMovieRepo {
public:

  /**
    * @brief getMovie provide movie by index
    * @param index index to search movie
    * @return movie by index
    * @todo throw exeption on invalid index
    */
   virtual const  IMovie& getMovie(int index) const = 0;

  /**
    * @brief print prints all movies to output
    * @param out stream to print all movies
    */
   virtual void print(std::ostream& out) const = 0;

};
#endif // IMOVIE_REPO_H

