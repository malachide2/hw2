#include "movie.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include "product.h"
#include "util.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
	Product("movie", name, price, qty), d_genre(genre), d_rating(rating)
{
}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const
{
	std::string tmpName = name_;
	std::string tmpGenre = d_genre;
	std::transform(tmpName.begin(), tmpName.end(), tmpName.begin(), [](unsigned char c) { return std::tolower(c); });
	std::transform(tmpGenre.begin(), tmpGenre.end(), tmpGenre.begin(), [](unsigned char c) { return std::tolower(c); });

	std::set<std::string> output = parseStringToWords(tmpName);
	output.insert(tmpGenre);
	return output;
}

std::string Movie::displayString() const
{
	return name_ + "\Genre: " + d_genre + " Rating: " + d_rating + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
}

void Movie::dump(std::ostream& os) const
{
	os << "movie\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << d_genre << "\n" << d_rating << "\n";
}