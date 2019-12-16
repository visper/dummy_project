#ifndef IMOVIE_REPO_H
#define IMOVIE_REPO_H
#include "imovie.h"

class IMovieRepo {
public :
  /**
   * @brief getMovie provide movie by movie index
   * @param index index to search movie
   * @return movie from repository
   * @throw std::invalid_argument if movie not exist
   */
  virtual const IMovie& getMovie(int index) const = 0 ;

  /**
    * @brief print Print all movies to stream
    * @param out stream for output
    */
   virtual void print(std::ostream& out) const =0;
};

#endif // IMOVIE_REPO_H

