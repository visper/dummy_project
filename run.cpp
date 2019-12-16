#include "run.h"
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>


struct Movie {
  int index;
  std::string name;
  std::string type;
};

struct Rental {
  Movie movie;
  int days_rented;


  int GetFrequentRenterPoints() {
    if (movie.type == "NEW_RELEASE" && days_rented > 1) {
      return 2;
    }
    return 1;
  }


  double GetAmount() const {
    if (movie.type == "NEW_RELEASE") {
          return days_rented * 3;
    }
    if (movie.type == "REGULAR") {
      if (days_rented > 2) {
        return 2 + (days_rented - 2) * 1.5;
      }
      return 2;
    }
    if (movie.type == "CHILDRENS") {
        if (days_rented > 3) {
          return 1.5 + (days_rented - 3) * 1.5;
        }
        return 1.5;
    }
    return 0;
  }
};

 std::vector<std::string> Split(const std::string& line, const char delimeter) {
   std::vector<std::string> movie;
  for (size_t first=0, last=0; last < line.length(); first=last+1) {
    last = line.find(delimeter, first);
    movie.push_back(line.substr(first, last-first));
  }
  return movie;
}

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

 struct MovieRepo {
    MovieRepo(std::ifstream& db_file) {
      for (std::string line; std::getline(db_file, line);) {
        auto movie_data = Split(line, ';');
        Movie movie {std::stoi(movie_data[0]), movie_data[1], movie_data[2]};
        movies_.insert(std::make_pair(movie.index, movie));
      }
    }

    Movie getMovie(int index) const {
        return movies_.at(index);
    }

     void print(std::ostream& out) const {
        for (const auto& movie: movies_) {
            out << movie.first<< ": " << movie.second.name<< "\n";
        }
     }

 private:
    std::map<int, Movie> movies_;
 };

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
  double totalAmount = 0;
  int frequentRenterPoints = 0;


  for (const auto& line : user_input) {
      std::vector<std::string> rental_data = Split(line, ' ');
      Rental rental = {movie_repo.getMovie(std::stoi(rental_data[0])),
                                std::stoi(rental_data[1])};

      double thisAmount = rental.GetAmount();

      frequentRenterPoints += rental.GetFrequentRenterPoints();
      // show figures for this rental
      result << "\t" << rental.movie.name + "\t" << thisAmount << "\n";
      totalAmount += thisAmount;
  }


  // add footer lines
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints << " frequent renter points\n";

  out << result.str();
}
