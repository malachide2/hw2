#include "clothing.h"
#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include "util.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
	Product("clothing", name, price, qty), d_size(size), d_brand(brand)
{
}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const
{
	std::set<std::string> nameKeywords = parseStringToWords(name_);
	std::set<std::string> brandKeywords = parseStringToWords(d_brand);
	return setUnion(nameKeywords, brandKeywords);
}

std::string Clothing::displayString() const
{
	return name_ + " (Clothing)\n" + d_size + "\nISBN: " + d_brand + "\nPrice: " + std::to_string(price_) + "\tQuantity: " + std::to_string(qty_);
}

void Clothing::dump(std::ostream& os) const
{
	os << "clothing\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << d_size << "\n" << d_brand;
}