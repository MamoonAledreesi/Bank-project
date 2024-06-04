#pragma once
#include <iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsClintListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterscreen.h"
#include"Global.h"
#include"clsCurrencyExhangeMainScreen.h"

using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOPtion {
		eListClients=1,eAddNewClient=2,eDleteClient=3,eUpdateClient=4,
		eFindClient=5,eShowTransactionMenue=6,eManageUsers=7,eLoginRegister=8,eCurrencyExhange=9,eLogout=10
	
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "\n\t\t\t\t\tChoose What do you want to do[1-10]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 10,"Choose Number Between[1-10]? ");
		return Choise;
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientsScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientsScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientsScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenueScreen()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	 }
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterscreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExhageScreen()
	{
		clsCurrencyExhangeMainScreen::ShowCurrencyMainScrren();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	 
	static void _PerformMainMenueOption(enMainMenueOPtion MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOPtion::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOPtion::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOPtion::eDleteClient:
		{
			system("cls");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOPtion::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientsScreen();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenueOPtion::eFindClient:
		{
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOPtion::eShowTransactionMenue:
		{
			
				system("cls");
				_ShowTransactionsMenueScreen();
				_GoBackToMainMenue();
				break;
			
		}
		case enMainMenueOPtion::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
		}
		case enMainMenueOPtion::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
		}

		case enMainMenueOPtion::eCurrencyExhange:
		{
			system("cls");
			_ShowCurrencyExhageScreen();
			_GoBackToMainMenue();
		}
		case enMainMenueOPtion::eLogout:
			system("cls");
			_Logout();
			break;

		
		}
	}
	static void _GoBackToMainMenue()
	{
		cout << "\nPress any key to back to main menue screen "; system("pause");

		ShowMainMenue();
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\tMain screen");
		

		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[1] show client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Cient.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users \n";
		cout << setw(37) << left << "" << "\t[8] Login Register. \n";
		cout << setw(37) << left << "" << "\t[9] Currency Exhange. \n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "==============================================\n";

		_PerformMainMenueOption((enMainMenueOPtion)_ReadMainMenueOption());
	}
};

