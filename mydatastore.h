#include "datastore.h"

class MyDataStore : public DataStore
{
public:
	~MyDataStore();
	void addProduct(Product* p) override;
	void addUser(User* u) override;
	std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
	void dump(std::ostream& ofile) override;
};