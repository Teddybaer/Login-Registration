#include "Account.h"
#include <iostream>

Account::Account(const std::string& usersfile) : filename(usersfile)
{
	userdatei.open(filename);
	if (!userdatei)
	{
		std::ofstream userd(filename);
		userd.close();
	}

	Admins.insert({ "Krushna", "122161" });

	LeseUserfile();
}

Account::~Account()
{
	userdatei.clear();
	userdatei.trunc;

	AktuallisiereUser();

	userdatei.close();
}

void Account::AktuallisiereUser()
{
	for (auto UserMap : Users)
	{
		userdatei << UserMap.first << " " << UserMap.second << std::endl;
	}

}

void Account::LeseUserfile()
{
		std::string id, pw, zeile;
		std::stringstream openfilezeile;

		while (getline(userdatei, zeile))
		{
			openfilezeile.str(zeile);
			openfilezeile >> id >> pw;

			Users.insert({ id, pw });
		}
}

void Account::Add_Account(const std::string username, const std::string password)
{
	Users.insert({ username, password });
}

void Account::Remove_Account(const std::string& username)
{
	Users.erase(username);
}

