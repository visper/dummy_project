#include "rental_factory.h"
#include "utils.h"

RentalFactory::RentalFactory(const IMovieRepo& movie_repo) :
  movie_repo_(movie_repo){}

std::unique_ptr<IRental> RentalFactory::getRental(const std::string& input) const {
  std::vector<std::string> rental_data = Split(input, ' ');
  const auto movie_index = std::stoi(rental_data[0]);
  const auto& movie = movie_repo_.getMovie(movie_index);
  const auto days_rented = std::stoi(rental_data[1]);
  return std::make_unique<Rental>(movie, days_rented);
}
