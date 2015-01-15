#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include "Account.h"
#include "Menu.h"

class Login
{
public:
	Login(Account&);
	~Login();

	bool Anmelden();
	void Startseite();

private:

	// Admin befehle
	void addUser();
	void removeUser();
	void passwortAendern();
	void benutzersuche();
	void benutzerPasswortAendern();
	void notfallschalter();
	void abmelden();
	void DisplayAllUsers();

	// User befehle
	void removeMyAccount();
	bool isAdmin;

	std::string nickname;
	std::string passwort;

	Account& Accounts;
};

#endif
