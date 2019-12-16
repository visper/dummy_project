#ifndef RENTALFACTORY_H
#define RENTALFACTORY_H

#include "irental_factory.h"
#include "imovie_repo.h"

class RentalFactory : public IRentalFactory {
public:
  RentalFactory(IMovieRepo& movie_repo);
  Rental createRental(const std::string& input) override;
private:
  IMovieRepo& movie_repo_;
};

#endif // RENTALFACTORY_H
