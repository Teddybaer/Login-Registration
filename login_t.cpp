#include "Login.h"

Login::Login(Account& AccountsP) : Accounts(AccountsP)
{

}

Login::~Login()
{

}

bool Login::Anmelden()
{
	isAdmin = false;

	std::cout << "Geben sie Ihre ID ein:";
	std::cin >> nickname;

	std::cin.sync(); std::cin.clear();

	std::cout << "Geben sie Ihr Passwort ein:";
	std::cin >> passwort;

	std::cin.sync(); std::cin.clear();

	// Prüfe ob sich der Account in Admins befindet
	for (auto Admins : Accounts.Admins)
	{
		if (Admins.first == nickname && Admins.second == passwort)
		{
			isAdmin = true;
			return true;
		}
	}

	// Prüfe ob sich der Account in Users befindet
	for (auto Users : Accounts.Users)
	{
		if (Users.first == nickname && Users.second == passwort)
		{
			return true;
		}
	}

	return false; // True = Account gefunden | False = Account nicht gefunden
}

void Login::Startseite()
{

	short auswahl;

	if (isAdmin) // Falls es sich um einen Admin handelt admin panel öffnen
	{
		// Auswahlmenu öffnen und auswahl treffen
		while (true)
		{
			system("cls");
			LoginAdminsStartseite();

			std::cout << "Ihre Wahl:";
			std::cin >> auswahl;

			std::cin.sync(); std::cin.clear();

			switch (auswahl)
			{
			case 1:
				std::cout << "----------------Account Suche----------------" << std::endl;
				benutzersuche();
				break;
			case 2:
				std::cout << "--------------Eigenes Passwort aendern--------------" << std::endl;
				passwortAendern();
				break;
			case 3:
				std::cout << "----------Benutzer Passwort aendern----------" << std::endl;
				benutzerPasswortAendern();
				break;
			case 4:
				std::cout << "------------------Benutzer hinzufuegen------------------" << std::endl;
				addUser();
				break;
			case 5:
				std::cout << "--------------------Benutzer entfernen---------------------" << std::endl;
				removeUser();
				break;
			case 6:
				std::cout << "--------------Notfallschalter--------------" << std::endl;
				notfallschalter();
				break;
			case 7:
				std::cout << "--------------Account Abmelden--------------" << std::endl;
				abmelden();
				return;
			case 8:
				std::cout << "--------------Display All Users---------------" << std::endl;
				DisplayAllUsers();
				break;
			default:
				continue;
			}

		}
	}
	else
	{

		while (true)
		{
			system("cls");
			LoginUsersStartseite();

			std::cout << "Ihre Wahl:";
			std::cin >> auswahl;

			std::cin.sync(); std::cin.clear();

			switch (auswahl)
			{
			case 1:
				std::cout << "----------------Account Suche----------------" << std::endl;
				benutzersuche();
				break;
			case 2:
				std::cout << "--------------------Mein Account entfernen---------------------" << std::endl;
				removeMyAccount();
				std::cin.get(); std::cin.sync(); std::cin.clear();
				return;
			case 3:
				std::cout << "--------------Eigenes Passwort aendern--------------" << std::endl;
				passwortAendern();
				break;
			case 4:
				std::cout << "--------------Account Abmelden--------------" << std::endl;
				abmelden();
				return;
			default:
				continue;
			}
		}

	}

}

void Login::passwortAendern()
{
	std::string altesPasswort;
	system("cls");
	std::cout << "Geben sie ihr altes passwort ein:";
	std::cin >> altesPasswort;
	std::cin.sync(); std::cin.clear();
	if (altesPasswort == passwort)
	{
		std::cout << "Geben sie ihr neues passwort ein:";
		std::cin >> altesPasswort;
		std::cin.sync(); std::cin.clear();
		passwort = altesPasswort;

		auto user = Accounts.Users.find(nickname);

		if (user == Accounts.Users.end())
		{
			user = Accounts.Admins.find(nickname);
			user->second = passwort;
			Accounts.AktuallisiereUser();
			return;
		}
	}
	else
	{
		std::cout << "Eingabe war inkorret" << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();

	}
}

void Login::DisplayAllUsers()
{
	for (auto User : Accounts.Users)
	{
		std::cout << "Nickname: " << User.first << "\t" << "Passwort:" << User.second << std::endl;
	}

	std::cin.get();
}

void Login::benutzersuche()
{
	std::string benutzer;
	std::cout << "Benutzer namen eingeben:";
	std::cin >> benutzer;
	std::cin.sync(); std::cin.clear();

	auto user = Accounts.Users.find(benutzer);

	if (user == Accounts.Users.end())
	{
		std::cout << "Der Benutzer " << benutzer << " existiert nicht" << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
	else
	{
		std::cout << "Der Benutzer " << benutzer << " existiert" << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
}

void Login::benutzerPasswortAendern()
{
	std::string benutzer;
	std::string newPasswort;
	std::cout << "Geben sie den Benutzer namen ein:";
	std::cin >> benutzer;
	std::cin.sync(); std::cin.clear();

	auto user = Accounts.Users.find(benutzer);
	if (user != Accounts.Users.end())
	{
		std::cout << "Geben sie das neue Passwort ein:";
		std::cin >> newPasswort;
		std::cin.sync(); std::cin.clear();

		user->second = newPasswort;
		Accounts.AktuallisiereUser();
	}
	else
	{
		std::cout << "User " << benutzer << " gibt es nicht" << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
}

void Login::notfallschalter()
{
	const std::string geheimespasswort = "titikakasee";
	std::string trytogetin;
	std::cout << "Geben sie das Geheimpasswort ein:";
	std::cin >> trytogetin;
	std::cin.sync(); std::cin.clear();

	if (trytogetin == geheimespasswort)
	{
		Accounts.Users.clear();

		Accounts.AktuallisiereUser();
		std::cout << "Alles wurde entfernt." << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
	else
	{
		std::cout << "Geheimpasswort war falsch:";
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
}

void Login::abmelden()
{
	nickname = " ";
	passwort = " ";
}

void Login::removeMyAccount()
{
	std::string mypasswort;
	std::cout << "Geben sie ihr Passwort ein:";
	std::cin >> mypasswort;
	std::cin.sync(); std::cin.clear();

	if (mypasswort == passwort)
	{
		Accounts.Remove_Account(nickname);
		std::cout << "Ihr Account wurde erfolgreich entfernt...." << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
	else
	{
		std::cout << "Passwort eingabe war nicht korrekt..." << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
}

void Login::addUser()
{
	std::string username;
	std::string userpw;

	std::cout << "Username eingeben:";
	std::cin >> username;
	std::cin.sync(); std::cin.clear();


	auto user = Accounts.Admins.find(username);
	if (user == Accounts.Admins.end())
	{
		user = Accounts.Users.find(username);
		if (user == Accounts.Users.end())
		{
			std::cout << "Passwort eingeben:";
			std::cin >> userpw;
			std::cin.sync(); std::cin.clear();

			Accounts.Add_Account(username, passwort);
		}
		else
		{
			std::cout << "Account ist schon vergeben" << std::endl;
			std::cin.get();
			std::cin.sync(); std::cin.clear();
		}
	}
	else
	{
		std::cout << "Accountname ist schon vergeben" << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
}

void Login::removeUser()
{
	std::string username;

	std::cout << "Username eingeben:";
	std::cin >> username;
	std::cin.sync(); std::cin.clear();

	auto user = Accounts.Users.find(username);
	if (user != Accounts.Users.end())
	{
		Accounts.Remove_Account(username);
		std::cout << "Account wurde entfernt..." << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
	else
	{
		std::cout << "Account existiert nicht" << std::endl;
		std::cin.get();
		std::cin.sync(); std::cin.clear();
	}
}



