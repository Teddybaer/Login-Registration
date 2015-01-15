#include "Register.h"
#include <iostream>

Register::Register(Account& Accs) : Accounts(Accs)
{
	
}

Register::~Register()
{

}

void Register::Registrieren()
{
	std::string id, pw;
	std::cout << "Account ID:";
	std::cin >> id;

	auto user = Accounts.Users.find(id);
	if (user == Accounts.Users.end())
	{
		user = Accounts.Admins.find(id);
		if (user == Accounts.Admins.end())
		{
			std::cout << "Account PW:";
			std::cin >> pw;

			Accounts.Add_Account(id, pw);
			std::cout << "Sie haben sich erfolgreich registriert" << std::endl;
		}
		else
		{
			std::cout << "Account gibt es bereits" << std::endl;
		}
	}
	else
	{
		std::cout << "Account gibt es bereits" << std::endl;
	}

	std::cin.sync(); std::cin.clear();
}
