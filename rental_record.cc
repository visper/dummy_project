#include "rental_record.h"

void RentalRecord::addRental(const Rental& rental) {
  rentals_.push_back(rental);
}

double RentalRecord::getTotalAmount() const {
  double totalAmount = 0;
  for (const auto& rental: rentals_) {
    totalAmount += rental.GetAmount();
  }
  return totalAmount;
}

double RentalRecord::getTotalFrequentRenterPoints() const {
  int frequentRenterPoints = 0;
  for (const auto& rental: rentals_) {
    frequentRenterPoints += rental.GetFrequentRenterPoints();
  }
  return frequentRenterPoints;
}

void RentalRecord::print(std::ostream& out) const {
  for (const auto& rental: rentals_) {
    out << "\t" << rental.getMovieName() + "\t" << rental.GetAmount() << "\n";
  }
}


