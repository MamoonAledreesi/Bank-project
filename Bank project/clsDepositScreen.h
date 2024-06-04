#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsScreen.h"

class clsDepositScreen :protected clsScreen
{
private:
    static  void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        getline(cin >> ws, AccountNumber);
        return AccountNumber;
    }


public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("Deposit Screen");
        

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With Account number["<<AccountNumber<<" does not Found, choose another one : ";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount: "; 
        Amount = clsInputValidate::ReadDblNumber();


        cout << "\nAre you sure do you want to perform this transaction y/n? ";

        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount deposited Seccessfully.\n";
            cout << "\nNew total Balance: " << Client1.AccountBalance;
        }
        else
        {
            cout << "\nOperation Was Cancelled\n";
        }


    }

};

