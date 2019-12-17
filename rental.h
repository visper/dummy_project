#ifndef RENTAL_H
#define RENTAL_H
#include "irental.h"
#include "movie.h"

class Rental : public IRental {
public :
  Rental(Movie movie,  int days_rented);

  const std::string getMovieName() const override;
  int GetFrequentRenterPoints() const override;


  double GetAmount() const override;

private:
  const Movie movie_;
  const int days_rented_;
};

#endif // RENTAL_H
