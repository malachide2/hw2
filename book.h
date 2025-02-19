#include <iostream>
#include <string>
#include <set>
#include "product.h"

class Book : public Product {
public:
	Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author);
	~Book();
	std::set<std::string> keywords() const override;
	std::string displayString() const override;
	void dump(std::ostream& os) const override;
protected:
	std::string d_ISBN;
	std::string d_author;
}