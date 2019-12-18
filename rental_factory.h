#ifndef RENTALFACTORY_H
#define RENTALFACTORY_H

#include "irental_factory.h"
#include "imovie_repo.h"

class RentalFactory  : public  IRentalFactory {
public:
  RentalFactory (const IMovieRepo& movie_repo);

  std::unique_ptr<IRental> getRental(const std::string& input) const override;

private:
  const IMovieRepo& movie_repo_;
};

#endif // RENTALFACTORY_H
