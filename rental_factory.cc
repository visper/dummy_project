#include "rental_factory.h"
#include <vector>
#include "utils.h"

RentalFactory::RentalFactory(IMovieRepo& movie_repo):movie_repo_(movie_repo) {

};

Rental RentalFactory::createRental(const std::string& input) {
  std::vector<std::string> rental_data = Split(input, ' ');
  int key = std::stoi(rental_data[0]);
  int days = std::stoi(rental_data[1]);
  Movie movie = movie_repo_.getMovie(key);
  Rental rental (movie , days);
  return rental;
}

