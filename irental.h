#ifndef IRENTAL_H
#define IRENTAL_H
#include <string>

class IRental {
  /**
   * @brief MovieName movie name assignet to rental
   * @return return movie name assignet to rental
   */
  virtual std::string MovieName() const = 0;

  /**
   * @brief GetFrequentRenterPoints  calculates amount of frequent points
   * @return amount of frequent points
   */
  virtual int GetFrequentRenterPoints() const = 0;

  /**
   * @brief GetAmount calculates cost of the rental
   * @return cost of the rental
   */
  virtual double GetAmount() const = 0;
};

#endif // IRENTAL_H

