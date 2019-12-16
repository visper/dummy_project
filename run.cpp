#include "run.h"
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include "movie.h"
#include "rental.h"

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
        auto movie_index  = std::stoi(movie_data[0]);
        Movie movie {movie_index, movie_data[1], movie_data[2]};
        movies_.insert(std::make_pair(movie_index, movie));
      }
    }

    Movie getMovie(int index) const {
        return movies_.at(index);
    }

     void print(std::ostream& out) const {
        for (const auto& movie: movies_) {
            out << movie.first<< ": " << movie.second.getName()<< "\n";
        }
     }

 private:
    std::map<int, Movie> movies_;
 };

struct RentalFactory {
  RentalFactory(MovieRepo& movie_repo):movie_repo_(movie_repo) {

  };
  Rental createRental(const std::string& input) {
    std::vector<std::string> rental_data = Split(input, ' ');
    int key = std::stoi(rental_data[0]);
    int days = std::stoi(rental_data[1]);
    Movie movie = movie_repo_.getMovie(key);
    Rental rental (movie , days);
    return rental;
  }

  MovieRepo& movie_repo_;
};

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
