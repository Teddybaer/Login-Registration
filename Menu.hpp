#ifndef MENUE_HPP
#define MENUE_HPP
using namespace std;

#include <iostream>
namespace {
	void StartseiteMenu()
	{
		cout << "-----------Startseite------------" <<endl;
		cout << "'[1]Anmelden                    '" <<endl;
		cout << "'[2]Registrieren                '" <<endl;
		cout << "'[3]Programm beenden            '" <<endl;
		cout << "'-------------------------------'" <<endl;

	}

	void LoginUsersStartseite()
	{
		cout << "-----------User Login Panel------------" <<endl;
		cout << "'[1]Nach benutzer suchen              '" <<endl;
		cout << "'[2]Meinen Account entfernen          '" <<endl;
		cout << "'[3]Passwort aendern                  '" <<endl;
		cout << "'[4]Abmelden                          '" <<endl;
		cout << "'-------------------------------------'" <<endl;
	}

	void LoginAdminsStartseite()
	{
		cout << "-----------Admin Login Panel------------" <<endl;
		cout << "'[1]Nach benutzer suchen               '" <<endl;
		cout << "'[2]Passwort aendern                   '" <<endl;
		cout << "'[3]Users Passwort aendern             '" <<endl;
		cout << "'[4]User Account hinzufuegen           '" <<endl;
		cout << "'[5]User Account entfernen             '" <<endl;
		cout << "'[6]Notfall schalter                   '" <<endl;
		cout << "'[7]Abmelden                           '" <<endl;
		cout << "'[8]Alle benutzer                      '" <<endl;
		cout << "'--------------------------------------'" <<endl;
	}

}
#endif
