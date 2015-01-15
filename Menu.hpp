#ifndef MENUE_HPP
#define MENUE_HPP

#include <iostream>
namespace {
	void StartseiteMenu()
	{
		std::cout << "-----------Startseite------------" << std::endl;
		std::cout << "'[1]Anmelden                    '" << std::endl;
		std::cout << "'[2]Registrieren                '" << std::endl;
		std::cout << "'[3]Programm beenden            '" << std::endl;
		std::cout << "'-------------------------------'" << std::endl;

	}

	void LoginUsersStartseite()
	{
		std::cout << "-----------User Login Panel------------" << std::endl;
		std::cout << "'[1]Nach benutzer suchen              '" << std::endl;
		std::cout << "'[2]Meinen Account entfernen          '" << std::endl;
		std::cout << "'[3]Passwort aendern                  '" << std::endl;
		std::cout << "'[4]Abmelden                          '" << std::endl;
		std::cout << "'-------------------------------------'" << std::endl;
	}

	void LoginAdminsStartseite()
	{
		std::cout << "-----------Admin Login Panel------------" << std::endl;
		std::cout << "'[1]Nach benutzer suchen               '" << std::endl;
		std::cout << "'[2]Passwort aendern                   '" << std::endl;
		std::cout << "'[3]Users Passwort aendern             '" << std::endl;
		std::cout << "'[4]User Account hinzufuegen           '" << std::endl;
		std::cout << "'[5]User Account entfernen             '" << std::endl;
		std::cout << "'[6]Notfall schalter                   '" << std::endl;
		std::cout << "'[7]Abmelden                           '" << std::endl;
		std::cout << "'[8]Alle benutzer                      '" << std::endl;
		std::cout << "'--------------------------------------'" << std::endl;
	}

}
#endif
