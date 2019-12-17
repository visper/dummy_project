#include "rental_factory.h"
#include "utils.h"

RentalFactory::RentalFactory(const MovieRepo& movie_repo) :
  movie_repo_(movie_repo){}

Rental RentalFactory::getRental(const std::string& input) const {
  std::vector<std::string> rental_data = Split(input, ' ');
  const auto movie_index = std::stoi(rental_data[0]);
  const auto movie = movie_repo_.getMovie(movie_index);
  const auto days_rented = std::stoi(rental_data[1]);
  return Rental(movie, days_rented);
}
