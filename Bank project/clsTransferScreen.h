#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber(string Message="")
	{
		string AccountNumber;
		cout << "\n"<<Message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nPlease enter Transfer amount? ";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the Avalible Balance, Enter another Amount: ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

	
public:



	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber
		("Please Enter AcountNumber to transfer From: "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber
		("Please Enter AcountNumber to transfer To: "));
		_PrintClient(DestinationClient);

		float Amount=_ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this Operation? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount,DestinationClient))
			{
				
				cout << "\nTransfer done Successfully.\n";
				_PrintClient(SourceClient);
				_PrintClient(DestinationClient);
				
			}
			else
			{
				cout << "\nTransfer Failed.\n";

			}
		}
		else
		{

			cout << "\nOperation Canclled!!";
		}
		
		
	}


};

