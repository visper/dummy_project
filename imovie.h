#ifndef IMOVIE_H
#define IMOVIE_H
#include <string>
/**
 * @brief The IMovie class interface for Movie
 */
class IMovie {
public:
  /**
   * @brief getName provide movie name
   * @return human readable name of the movie
   */
  virtual std::string getName() const = 0;

  /**
   * @brief getType provide movie type ( CHILDRENS, REGULAR, NEW_RELEASE, etc ...)
   * @return return human readable movie type
   */
  virtual std::string getType() const = 0;
};

#endif // IMOVIE_H
