// BankAccount:
//		Object-oriented programming is used to
//		create a set of simple classes and objects that allow
//		to deposit and withdraw money from a bank account
//		and show a list of the executed transactions.

//		This program doesn't permorm data validation. User
//		is expected to enter data type required:
//		intergers for transaction amounts and characters for 
//		responses to 'yes' or 'no' questions.


#include "Account.h"
#include <iostream>
using std::cout;
using std::cin;


int main()
{

	Account accountObject;
	char actionType; // To save the type of transaction to perform
	char moreTransactions; // To save input from user when asked if more trnasactions are desired
	int depositAmount; // To save amount to be deposited
	int withdrawalAmount; // To save amount to be withdrawn
	bool newTransaction = true; // To control exit from while loop


	// Welcome user

	cout << "Welcome to your bank account!" << '\n';


	// Let the user make transactions until they want to exit the application

	while (newTransaction)
	{
		cout << '\n' << "Your account balance is $" << accountObject.GetBalance();
		cout << ". What kind of transaction do you want to make?" << '\n' << '\n';
		cout << "[d] for Deposit" << '\n' << "[w] for Withdrawal" << '\n' << "[e] to Exit" << '\n';
		cin >> actionType;

		// Exit the application

		if (actionType == 'e')
		{
			newTransaction = false;

			return 0;
		}

		// Make a withdrawal

		if (actionType == 'w')
		{
			

			// Prevent a transaction when the required balance is not available 

			cout << '\n' << "How much do you want to withdraw? ";
			cin >> withdrawalAmount;

			if (accountObject.GetBalance() <= 0 || accountObject.GetBalance() < withdrawalAmount)
			{
				cout << '\n' << "You don't have enought balance. Please try again." << '\n' << '\n';
			}

			// Make a transaction 

			if (accountObject.GetBalance() > withdrawalAmount)
			{
				accountObject.Withdraw(withdrawalAmount);

				cout << '\n' << "After withdrawing $" << withdrawalAmount 
					 << " your account balance is $" << accountObject.GetBalance() << "." << '\n' << '\n';
				cout << "Transactions report:" << '\n' << "------------------" << '\n';

				for (auto s : accountObject.Report())
				{
					cout << s << '\n';
				}
			}			
		}

		// Make a deposit 

		if (actionType == 'd')
		{
			cout << '\n' << "How much do you want to deposit? ";
			cin >> depositAmount;

			accountObject.Deposit(depositAmount);

			cout << '\n' << "After depositing $" << depositAmount 
				 <<" your account balance is $" << accountObject.GetBalance() << "." << '\n' << '\n';
			cout << "Transactions report:" << '\n' << "------------------" << '\n';

			for (auto s : accountObject.Report())
			{
				cout << s << '\n';
			}

		}

		// Ask the user if they want to make more transactions

		cout << '\n' << "Do you want to make a new transaction? [y] Yes, [n] No" << '\n';
		cin >> moreTransactions;

		if (moreTransactions == 'n')
		{
			// Exit the while loop 

			newTransaction = false;
		}
	}

	return 0;

}

