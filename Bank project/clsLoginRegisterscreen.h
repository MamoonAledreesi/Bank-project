#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsString.h"
#include <iomanip>
#include "clsUtil.h"
class clsLoginRegisterscreen :protected clsScreen
{
private:
	static void _PrintLoginRegisterRecoredLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		
		
		 cout << setw(25) << left << "" << "| " << setw(27) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(15) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Permissions;
	}
	

public:
	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;// this will exit the function and it will not continue
		}

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetRegisterList();
	
		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Register(s).";

		_DrawScreenHeader(Title,SubTitle);

		cout << setw(30) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(27) << "Date/Time";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permission";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo  login Registers Available In the System!";
		else
		for (clsUser::stLoginRegisterRecord LoginRegisterRecord : vLoginRegisterRecord)
		{
			_PrintLoginRegisterRecoredLine(LoginRegisterRecord);
			cout << endl;
		}
		
	}
};

