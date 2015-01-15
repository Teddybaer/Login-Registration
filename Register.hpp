#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "Account.h"

class Register
{
public:
	Register(Account&);
	~Register();

	void Registrieren();
private:
	Account& Accounts;
};

#endif
