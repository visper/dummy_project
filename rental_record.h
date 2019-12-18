#ifndef RENTALRECORD_H
#define RENTALRECORD_H

#include <vector>
#include "irental_record.h"

class RentalRecord : public IRentalRecord {
public:
  void addRental(std::unique_ptr<IRental>&& rental);

  double getTotalAmount() const override;

  double getTotalFrequentRenterPoints() const override;

    void print(std::ostream& out) const override;
private:
   std::vector<std::unique_ptr<IRental>> rentals_;
};

#endif // RENTALRECORD_H
