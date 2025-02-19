#include <iostream>
#include <string>
#include <set>
#include "product.h"

class Movie : public Product
{
public:
	Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
	~Movie();
	std::set<std::string> keywords() const override;
	std::string displayString() const override;
	void dump(std::ostream& os) const override;
protected:
	std::string d_genre;
	std::string d_rating;
};