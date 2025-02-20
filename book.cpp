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
	std::string tmpName = name_;
	std::string tmpAuthor = d_author;
	std::string tmpISBN = d_ISBN;
	std::transform(tmpName.begin(), tmpName.end(), tmpName.begin(), [](unsigned char c) { return std::tolower(c); });
	std::transform(tmpAuthor.begin(), tmpAuthor.end(), tmpAuthor.begin(), [](unsigned char c) { return std::tolower(c); });
	std::transform(tmpISBN.begin(), tmpISBN.end(), tmpISBN.begin(), [](unsigned char c) { return std::tolower(c); });
	
	std::set<std::string> nameKeywords = parseStringToWords(tmpName);
	std::set<std::string> authorKeywords = parseStringToWords(tmpAuthor);
	std::set<std::string> output = setUnion(nameKeywords, authorKeywords);
	output.insert(tmpISBN);
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