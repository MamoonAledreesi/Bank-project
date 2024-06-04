#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include <vector>
#include <iomanip>
#include <fstream>
class clsListcurrenciesScreen:protected clsScreen
{
private:
    static void _PrintListcurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << Currency.Country();
        cout << "| " << setw(7) << left << Currency.CurrencyCode();
        cout << "| " << setw(30) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
        

    }

public:
    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string Title = "\t Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Country";
        cout << "| " << left << setw(7) << "Code";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(10) << "Rate/($1)";
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currencies Avalible In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                _PrintListcurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

