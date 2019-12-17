#include "movie_repo.h"
#include "utils.h"

MovieRepo::MovieRepo(std::ifstream& db_file) {
  for (std::string line; std::getline(db_file, line);) {
    auto movie_data = Split(line, ';');
    const int movie_index = std::stoi(movie_data[0]);
    const std::string movie_name = movie_data[1];
    const std::string movie_type = movie_data[2];
    Movie movie (movie_type, movie_name);
    movies_.insert(std::make_pair(movie_index, movie));
  }
}

Movie MovieRepo::getMovie(int index) const {
  return movies_.at(index);
}

void MovieRepo::print(std::ostream& out) const {
  for (const auto& movie: movies_) {
    out << movie.first<< ": " << movie.second.getName()<< "\n";
  }
}
