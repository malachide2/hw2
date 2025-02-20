#include <unordered_map>
#include <queue>
#include "datastore.h"

class MyDataStore : public DataStore
{
public:
	~MyDataStore();
	void addProduct(Product* p) override;
	void addUser(User* u) override;
	std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
	void dump(std::ostream& ofile) override;
	void addToCart(std::string username, Product* p);
	void viewCart(std::string username);
	void buyCart(std::string username);
private:
	std::unordered_map<std::string, User*>				  d_user;
	std::unordered_map<std::string, std::queue<Product*>> d_userCart;
	std::set<Product*>									  d_products;
	std::unordered_map<std::string, std::set<Product*>>	  d_keywordMapping;
};