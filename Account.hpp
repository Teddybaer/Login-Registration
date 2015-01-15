#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <fstream>
#include <map>
#include <sstream>

class Account
{
	friend class Login;
	friend class Register;

public:
	Account() = delete;
	Account(const std::string&);
	Account(const Account&) = delete;
	Account& operator=(const Account&) = delete;

	~Account();

	void Add_Account(const std::string, const std::string);
	void Remove_Account(const std::string&);

private:

	void AktuallisiereUser();
	void LeseUserfile();
	
	std::fstream userdatei;
	const std::string& filename;

	std::map<std::string, std::string> Admins;
	std::map<std::string, std::string> Users;
};

#endif
