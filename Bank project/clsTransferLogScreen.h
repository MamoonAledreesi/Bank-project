#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
class clsTransferLogScreen :protected clsScreen
{
private:
	static void _PrintTrasferLogRecoredLine(clsBankClient::stTransferRegisterRecord TransferRegisterRecord)
	{


		cout << setw(15) << left << "" << "| " << setw(20) << left << TransferRegisterRecord.DateTime;
		cout << "| " << setw(10) << left << TransferRegisterRecord.SAcountNumber;
		cout << "| " << setw(10) << left << TransferRegisterRecord.DAcountNumber;
		cout << "| " << setw(10) << left << TransferRegisterRecord.Amount;
		cout << "| " << setw(10) << left << TransferRegisterRecord.SAccountBlance;
		cout << "| " << setw(10) << left << TransferRegisterRecord.DAccountBlance;
		cout << "| " << setw(10) << left << TransferRegisterRecord.UserName;
	}

public:
	static void  ShowTransferLogScreen()
	{

		vector<clsBankClient::stTransferRegisterRecord> vTransferRegisterRecord = clsBankClient::GetTransferRegisterList();

		string Title = "\tTransfer Register List Screen";
		string SubTitle = "\t    (" + to_string(vTransferRegisterRecord.size()) + ") Register(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(30) << left << "" << "\n\t\t_______________________________________________________";
		cout << "________________________________________\n" << endl;

		cout << setw(15) << left << "" << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(10) << "S.Acct";
		cout << "| " << left << setw(10) << "D.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(15) << left << "" << "\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo  Transfer Registers Available In the System!";
		else
			for (clsBankClient::stTransferRegisterRecord TransferRegisterRecord : vTransferRegisterRecord)
			{
				_PrintTrasferLogRecoredLine(TransferRegisterRecord);
				cout << endl;
			}

	}
};

