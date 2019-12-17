#include "run.h"
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>

#include "utils.h"

#include "movie_repo.h"
#include "rental_factory.h"
#include "rental_record.h"

 std::vector<std::string> UserInput(std::istream& in) {
   std::vector<std::string> user_input;
   while (true) {
     std::string line;
     std::getline(in, line);
     if (line.empty()) {
       break;
     }
     user_input.push_back(line);
   }
   return user_input;
 }

 void run(std::istream& in, std::ostream& out){
  using namespace std::literals;
  // read movies from file
  std::ifstream movieStream{"movies.csv"};
  MovieRepo movie_repo (movieStream);
  movie_repo.print(out);
  out << "Enter customer name: ";
  std::string customerName;
  getline(in, customerName);
  out << "Choose movie by number followed by rental days, just ENTER for bill:\n";
  std::ostringstream result;
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + customerName + "\n";
  std::vector<std::string> user_input = UserInput(in);
  const RentalFactory rental_facotory(movie_repo);
  RentalRecord rental_record;
  for (const auto& line : user_input) {
      auto&& rental = rental_facotory.getRental(line);
      rental_record.addRental(std::move(rental));
  }

  double totalAmount = rental_record.getTotalAmount();
  int frequentRenterPoints = rental_record.getTotalFrequentRenterPoints();

  rental_record.print(result);
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints << " frequent renter points\n";
  out << result.str();
}





