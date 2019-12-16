#include "run.h"
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>

#include "utils.h"
#include "movie.h"
#include "rental.h"
#include "movie_repo.h"
#include "rental_factory.h"

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

double getTotalAmount(std::vector<Rental>& rentals) {
    double result = 0;
    for (const auto& rental: rentals) {
      result += rental.GetAmount();
    }
    return result;
}

int getTotalFrequentPoints(std::vector<Rental>& rentals) {
    int result = 0;
    for (const auto& rental: rentals) {
      result += rental.GetFrequentRenterPoints();
    }
    return result;
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

  RentalFactory rental_facotry_(movie_repo);
  std::vector<Rental> rentals;

  for (const auto& line : user_input) {
      rentals.push_back(rental_facotry_.createRental(line));
  }

  for (const auto& rental : rentals) {
    result << "\t" << rental.MovieName() + "\t" << rental.GetAmount()<< "\n";
  }
  // add footer lines
  result << "You owed " << getTotalAmount(rentals)<< "\n";
  result << "You earned " << getTotalFrequentPoints(rentals) << " frequent renter points\n";

  out << result.str();
}
