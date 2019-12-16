#ifndef IRENTAL_FACTORY_H
#define IRENTAL_FACTORY_H
#include <string>
#include "rental.h"

class IRentalFactory {

  /**
   * @brief createRental create rental from user input
   * @param input user input
   * @return created rental facotry
   * @throw std::invalid_argument  if user input is not correct
   */
  virtual Rental createRental(const std::string& input) const =0;
};

#endif // IRENTAL_FACTORY_H

