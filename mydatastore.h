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
private:
	std::unordered_map<User*, std::queue<Product*>> d_userCart;
	std::set<Product*> d_products;
	std::unordered_map<std::string, std::set<Product*>> d_keywordMapping;
};