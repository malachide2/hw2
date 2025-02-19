#include "book.h"
#include <iostream>
#include <string>
#include <set>
#include "product.h"
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author) :
	Product("book", name, price, qty), d_ISBN(ISBN), d_author(author) {}

Book::~Book() {}

std::set<std::string> Book::keywords() const
{
	std::set<std::string> output = parseStringToWords(d_author);
	output.insert(d_ISBN);
	return output;
}

std::string Book::displayString() const
{
	return name_ + " (Book)\n" + d_author + "\nISBN: " + d_ISBN + "\nPrice: " + price_ + "\tQuantity: " + qty_;
}

void Book::dump(std::ostream& os) const
{
	os << "book\n" << name_ << "\n" << std::to_string(price_) << "\n" << std::to_string(qty_) << "\n" << d_ISBN << "\n" << d_author;
}