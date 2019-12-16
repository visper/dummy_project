#ifndef RENTALFACTORY_H
#define RENTALFACTORY_H

#include "irental_factory.h"
#include "movie_repo.h"

class RentalFactory : public IRentalFactory {
public:
  RentalFactory(MovieRepo& movie_repo);
  Rental createRental(const std::string& input) override;
private:
  MovieRepo& movie_repo_;
};

#endif // RENTALFACTORY_H
