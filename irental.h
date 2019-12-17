#ifndef IRENTAL_H
#define IRENTAL_H
#include <string>

class IRental {
public :
  /**
   * @brief getMovieName return name of the movie owned by rental
   * @return name of the movie owned by rental
   */
  virtual const std::string getMovieName() const = 0;

  /**
   * @brief GetFrequentRenterPoints calculate bonus points
   * @return frequent renter points
   */
  virtual int GetFrequentRenterPoints() const = 0;


  /**
   * @brief GetAmount calculate amount
   * @return amount
   */
  virtual double GetAmount() const = 0;

  virtual ~IRental() = default;
};
#endif // IRENTAL_H

