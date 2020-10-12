// Account class definition 

#include <vector>
#include <string>
#include "Transaction.h"


class Account
{
private:
	int balance; // To store the balance
	std::vector<Transaction> log; // To store the transactions

public:
	// Class constructor

	Account();									

	// Class member functions

	std::vector<std::string> Report();

	bool Deposit(int amount);

	bool Withdraw(int amount);

	int GetBalance() { return balance; }
};