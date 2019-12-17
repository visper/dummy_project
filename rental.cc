#include "rental.h"


Rental::Rental(const IMovie& movie, int days_rented) :
  movie_(movie),
  days_rented_(days_rented) {

}

const std::string Rental::getMovieName() const {
  return movie_.getName();
}

int Rental::GetFrequentRenterPoints() const {
  if (movie_.getType() == "NEW_RELEASE" && days_rented_ > 1) {
    return 2;
  }
  return 1;
}

double Rental::GetAmount() const {
  if (movie_.getType() == "NEW_RELEASE") {
    return days_rented_ * 3;
  }
  if (movie_.getType() == "REGULAR") {
    if (days_rented_ > 2) {
      return 2 + (days_rented_ - 2) * 1.5;
    }
    return 2;
  }
  if (movie_.getType() == "CHILDRENS") {
    if (days_rented_ > 3) {
      return 1.5 + (days_rented_ - 3) * 1.5;
    }
    return 1.5;
  }
  return 0;
}
