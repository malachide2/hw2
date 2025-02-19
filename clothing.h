#include <iostream>
#include <string>
#include <set>
#include "product.h"

class Clothing : public Product
{
public:
	Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
	~Clothing();
	std::set<std::string> keywords() const override;
	std::string displayString() const override;
	void dump(std::ostream& os) const override;
protected:
	std::string d_size;
	std::string d_brand;
};