#include "Account.h"
#include "Login.h"
#include "Register.h"
using namespace std;

int main()
{

	Account  Accounts("Accs.txt");
	Login    Logins(Accounts);
	Register Registers(Accounts);
	int auswahl;

	while (true)
	{
		cin.sync(); 
		cin.clear();
		system("cls");
		StartseiteMenu();
		cout << "Ihre Wahl:";
		cin >> auswahl;

		cin.sync(); 
		cin.clear();

		switch (auswahl)
		{
		case 1:
			cout << "----------------Anmelden---------------" << endl;
			if (Logins.Anmelden())
			{
				Logins.Startseite();
			}
			else
			{
				cout << "Anmeldung war nicht erfolgerich..." <<endl;
				cin.get();
				cin.sync(); 
				cin.clear();
			}
			break;
		case 2:
			cout << "------------Registrieren---------------" <<endl;
			Registers.Registrieren();
			break;
		case 3:
			system("cls");
			cout << "---------------Programm beenden------------------";
			return 0;
		default:
			continue;
		}
	}

}
