#include "utils.h"

std::vector<std::string> Split(const std::string& line, const char delimeter) {
  std::vector<std::string> movie;
 for (size_t first=0, last=0; last < line.length(); first=last+1) {
   last = line.find(delimeter, first);
   movie.push_back(line.substr(first, last-first));
 }
 return movie;
}
