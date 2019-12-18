#ifndef IRENTALFACTORY
#define IRENTALFACTORY
#include <string>
#include <memory>

#include "rental.h"

class IRentalFactory {
public:

  // TODO : rename to createRental
  /**
   * @brief getRental creates rental from user input
   * @param input user input
   * @return rental created from user input
   */
  virtual std::unique_ptr<IRental> getRental(const std::string& input) const =0;

};

#endif // IRENTALFACTORY

