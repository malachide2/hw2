#include "movie.h"
#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include "util.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
	Product("movie", name, price, qty), d_genre(genre), d_rating(rating)
{
}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const
{
	std::set<std::string> output = parseStringToWords(name_);
	output.insert(d_genre);
	return output;
}

std::string Movie::displayString() const
{
	return name_ + " (Movie)\n" + d_genre + "\nISBN: " + d_rating + "\nPrice: " + std::to_string(price_) + "\tQuantity: " + std::to_string(qty_);
}

void Movie::dump(std::ostream& os) const
{
	os << "movie\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << d_genre << "\n" << d_rating;
}