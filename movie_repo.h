#ifndef MOVIEREPO_H
#define MOVIEREPO_H
#include <map>

#include "imovie_repo.h"

class MovieRepo : public IMovieRepo {
public:

   MovieRepo(std::ifstream& db_file) ;

   Movie getMovie(int index) const override ;

    void print(std::ostream& out) const override ;

private:
   std::map<int, Movie> movies_;
};

#endif // MOVIEREPO_H
