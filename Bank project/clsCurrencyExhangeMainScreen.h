#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include<iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListcurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyExhangeMainScreen:protected clsScreen
{
private:
	
	enum enCurrencyExhangeOption
	{
		eListCurrencies=1,eFindCurrency=2,eUpdateRate=3
		,eCurrencyClaculater=4,eMainMenue=5
	};
	static short _ReadCurrencyExhangeOption()
	{
		cout << setw(37) << left << "\n\t\t\t\t\tChoose What do you want to do[1-5]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 5, "Choose Number Between[1-5]? ");
		return Choise;
	}


	static void _ShowListCurrenciesScreen()
	{
		clsListcurrenciesScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyClaculaterScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToMainMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowCurrencyMainScrren();
	}

	static void _PerformcurrencyExhangeOption(enCurrencyExhangeOption CurrencyExhangeOption)
	{
		switch (CurrencyExhangeOption)
		{
		case enCurrencyExhangeOption::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyExhangeOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyExhangeOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyExhangeOption::eCurrencyClaculater:
		{
			system("cls");
			_ShowCurrencyClaculaterScreen();
			_GoBackToMainMenue();
			break;
		}

		case enCurrencyExhangeOption::eMainMenue:
		{

		}

		}

	}
public:
	static void ShowCurrencyMainScrren()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exhage Main screen");


		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exhage Menue\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Claculater.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "==============================================\n";
		_PerformcurrencyExhangeOption((enCurrencyExhangeOption)_ReadCurrencyExhangeOption());
	}
};

