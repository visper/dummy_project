#ifndef IMOVIE_H
#define IMOVIE_H
#include <string>
class IMovie {
public:
  /**
   * @brief getName provide Movie name
   * @return movie name
   */
  virtual std::string getName() const = 0;

  /**
   * @brief getType provide movie type
   * @return movie type
   */
  virtual std::string getType() const = 0;
};
#endif // IMOVIE_H

