#include "mydatastore.h"
#include "util.h"

MyDataStore::~MyDataStore()
{

}

void MyDataStore::addProduct(Product* p)
{
	for (auto& keyword : p->keywords()) {
		if (d_keywordMapping.find(keyword) == d_keywordMapping.end())
			d_keywordMapping.emplace(keyword, std::set<Product*>());
		d_keywordMapping[keyword].insert(p);
	}
	d_products.insert(p);
}

void MyDataStore::addUser(User* u)
{
	std::string tmpName = u->getName();
	std::transform(tmpName.begin(), tmpName.end(), tmpName.begin(), [](unsigned char c) { return std::tolower(c); });

	d_user.emplace(tmpName, u);
	d_userCart.emplace(tmpName, std::queue<Product*>());
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
	for (auto userPair : d_user) {
		userPair.second->dump(ofile);
	}
	ofile << "</users>";
}

void MyDataStore::addToCart(std::string username, Product* p)
{
	d_userCart[username].push(p);
}

void MyDataStore::viewCart(std::string username, std::ostream& ofile)
{
	std::queue<Product*> tmp = d_userCart[username]; //copy the original queue to the temporary queue

	size_t i = 0;
	while (!tmp.empty()) {
		Product* product = tmp.front();
		ofile << i++ << ": " << product->displayString() << "\n";
		tmp.pop();
	}
}

void MyDataStore::buyCart(std::string username)
{
	std::queue<Product*> leftoverItems;
	while (!d_userCart[username].empty()) {
		Product* product = d_userCart[username].front();
		d_userCart[username].pop();
		if (product->getPrice() > d_user[username]->getBalance() || product->getQty() <= 0) {
			leftoverItems.push(product);
			continue;
		}
		d_user[username]->deductAmount(product->getPrice());
		product->subtractQty(1);
	}
	d_userCart[username] = leftoverItems;
}

bool MyDataStore::isValidUsername(std::string username)
{
	return (d_user.find(username) != d_user.end());
}