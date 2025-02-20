#include "mydatastore.h"
#include "util.h"

MyDataStore::~MyDataStore()
{

}

void MyDataStore::addProduct(Product* p)
{
	for (auto& keyword : p->keywords()) {
		if (d_keywordMapping.find(keyword) == d_keywordMapping.end())
			d_keywordMapping.emplace(keyword, std::vector<Product*>);
		d_keywordMapping[keyword].insert(p);
	}
	d_products.insert(p);
}

void MyDataStore::addUser(User* u)
{
	d_userCart.emplace(u, std::deque<Product*>>);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	std::vector<Product*> output;
	std::set<Product*>	  outputSet;
	bool tmpFlag = false; // Used in intersection to see if at least one set has been found
	for (auto& term : terms) {
		if (d_keywordMapping.find(term) == d_keywordMapping.end())
			continue;
		if (type == 0) {
			if (!tmpFlag) {
				outputSet = d_keywordMapping[term];
				tmpFlag = true;
			}
			else {
				outputSet = setIntersection(outputSet, d_keywordMapping[term]);
			}
		}
		else {
			outputSet = setUnion(outputSet, d_keywordMapping[term]);
		}
	}

	for (auto product : outputSet) {
		output.push_back(product);
	}
	return output;
}

void MyDataStore::dump(std::ostream& ofile)
{
	ofile << "<products>\n";
	for (auto product : d_products) {
		product->dump(ofile);
	}
	ofile << "</products>\n<users>\n";
	for (auto userPair : d_userCart) {
		userPair.first->dump(ofile);
	}
	ofile << "</users>";
}