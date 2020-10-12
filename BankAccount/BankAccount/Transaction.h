// Transaction class definition

#include <string>


class Transaction
{
private:
	int amount;
	std::string type;

public:

	// Class constructor

	Transaction(int amt, std::string kind);

	// Class member functions 

	std::string Report();
};