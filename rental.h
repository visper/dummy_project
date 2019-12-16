#ifndef RENTAL_H
#define RENTAL_H

#include "irental.h"
#include "movie.h"

class Rental : IRental{
public:

  Rental(Movie movie,int days_rented);

  std::string MovieName() const  override ;

  int GetFrequentRenterPoints() const override ;

  double GetAmount() const override ;

private:
  const int days_rented_;
  Movie movie_;
};
#endif // RENTAL_H
