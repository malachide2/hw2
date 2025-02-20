#include "book.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include "product.h"
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author) :
	Product("book", name, price, qty), d_ISBN(ISBN), d_author(author) {}

Book::~Book() {}

std::set<std::string> Book::keywords() const
{
	std::set<std::string> nameKeywords = parseStringToWords(convToLower(name_));
	std::set<std::string> authorKeywords = parseStringToWords(convToLower(d_author));
	std::set<std::string> output = setUnion(nameKeywords, authorKeywords);
	output.insert(convToLower(d_ISBN));
	return output;
}

std::string Book::displayString() const
{
	return name_ + "\nAuthor: " + d_author + " ISBN: " + d_ISBN + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
}

void Book::dump(std::ostream& os) const
{
	os << "book\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << d_ISBN << "\n" << d_author << "\n";
}