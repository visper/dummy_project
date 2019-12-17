#ifndef IRENTAL_RECORD_H
#define IRENTAL_RECORD_H
#include <ostream>
#include "rental.h"
#include <memory>

class IRentalRecord {
public:

  /**
   * @brief addRental add rental to rental record
   * @param rental
   */
  virtual void addRental(std::unique_ptr<IRental>&& rental) = 0;

  /**
   * @brief getTotalAmount calculate amount of all rentals
   * @return total amount
   */
  virtual double getTotalAmount() const = 0;

  /**
   * @brief getTotalFrequentRenterPoints calculate amount of all rentals
   * @return total frequent renter points
   */
  virtual double getTotalFrequentRenterPoints() const = 0;

  /**
   * @brief print prints list of rentals as user output
   * @param out stream to print putput
   */
  virtual  void print(std::ostream& out) const = 0;

};


#endif // IRENTAL_RECORD_H

