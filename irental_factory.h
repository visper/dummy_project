#ifndef IRENTALFACTORY
#define IRENTALFACTORY
#include <string>

#include "rental.h"

class IRentalFactory {
public:

  // TODO : rename to createRental
  /**
   * @brief getRental creates rental from user input
   * @param input user input
   * @return rental created from user input
   */
  virtual Rental getRental(const std::string& input) const =0;

};

#endif // IRENTALFACTORY

