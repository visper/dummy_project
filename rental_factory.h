#ifndef RENTALFACTORY_H
#define RENTALFACTORY_H

#include "irental_factory.h"
#include "movie_repo.h"

class RentalFactory  : public  IRentalFactory {
public:
  RentalFactory (const MovieRepo& movie_repo);

  Rental getRental(const std::string& input) const override;

private:
  const MovieRepo& movie_repo_;
};

#endif // RENTALFACTORY_H
