#include "Account.h"
#include "Login.h"
#include "Register.h"

int main()
{

	Account  Accounts("Accs.txt");
	Login    Logins(Accounts);
	Register Registers(Accounts);
	int auswahl;

	while (true)
	{
		std::cin.sync(); std::cin.clear();
		system("cls");
		StartseiteMenu();
		std::cout << "Ihre Wahl:";
		std::cin >> auswahl;

		std::cin.sync(); std::cin.clear();

		switch (auswahl)
		{
		case 1:
			std::cout << "----------------Anmelden---------------" << std::endl;
			if (Logins.Anmelden())
			{
				Logins.Startseite();
			}
			else
			{
				std::cout << "Anmeldung war nicht erfolgerich..." << std::endl;
				std::cin.get();
				std::cin.sync(); std::cin.clear();
			}
			break;
		case 2:
			std::cout << "------------Registrieren---------------" << std::endl;
			Registers.Registrieren();
			break;
		case 3:
			system("cls");
			std::cout << "---------------Programm beenden------------------";
			return 0;
		default:
			continue;
		}
	}

}
