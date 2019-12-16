#ifndef RENTAL_H
#define RENTAL_H

#include "irental.h"
#include "imovie.h"

class Rental : IRental{
public:

  Rental(const IMovie& movie,int days_rented);

  std::string MovieName() const  override ;

  int GetFrequentRenterPoints() const override ;

  double GetAmount() const override ;

private:
  const int days_rented_;
  const IMovie& movie_;
};
#endif // RENTAL_H
