#include "datastore.h"

class MyDataStore : public DataStore
{
public:
	~MyDataStore();
	void AddProduct(Product* p) override;
	void AddUser(User* u) override;
	std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
	void dump(std::ostream& ofile) override;
};