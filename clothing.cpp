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
	std::set<std::string> nameKeywords = parseStringToWords(convToLower(name_));
	std::set<std::string> brandKeywords = parseStringToWords(convToLower(d_brand));
	for (auto& keyword : nameKeywords) {
		std::cout << keyword << "\n";
	}
	for (auto& keyword : brandKeywords) {
		std::cout << keyword << "\n";
	}
	std::cout << std:endl << std::endl;
	return setUnion(nameKeywords, brandKeywords);
}

std::string Clothing::displayString() const
{
	return name_ + "\nSize: " + d_size + " Brand: " + d_brand + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
}

void Clothing::dump(std::ostream& os) const
{
	os << "clothing\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << d_size << "\n" << d_brand << "\n";
}