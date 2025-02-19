#include "clothing.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include "product.h"
#include "util.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
	Product("clothing", name, price, qty), d_size(size), d_brand(brand)
{
}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const
{
	std::string tmpName = name_;
	std::string tmpBrand = d_brand;
	std::transform(tmpName.begin(), tmpName.end(), tmpName.begin(), std::tolower);
	std::transform(tmpBrand.begin(), tmpBrand.end(), tmpBrand.begin(), std::tolower);
	
	std::set<std::string> nameKeywords = parseStringToWords(tmpName);
	std::set<std::string> brandKeywords = parseStringToWords(tmpBrand);
	return setUnion(nameKeywords, brandKeywords);
}

std::string Clothing::displayString() const
{
	return name_ + " (Clothing)\n" + d_size + "\nBrand: " + d_brand + "\nPrice: " + std::to_string(price_) + "\tQuantity: " + std::to_string(qty_);
}

void Clothing::dump(std::ostream& os) const
{
	os << "clothing\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << d_size << "\n" << d_brand;
}