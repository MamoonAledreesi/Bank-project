#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsUpdateUserScreen:protected clsScreen
{

private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter firstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char answer = 'n';


		cout << "\n Do you Want to give full access y/n? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			return -1;
		}

		cout << "\n Do you Want to give full access to: \n ";


		cout << "\n Show Client List y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\n Add New Client  y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\n Dlete Client y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\n Update Client  y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\n Find Client  y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions  y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage users  y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "\nShow Login Register  y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}


		return Permissions;


	}
    static void _PrintUser(clsUser User)
	{

		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";


	}


	public:
		static void ShowUpdateUserScreen()
		{
			_DrawScreenHeader("\tUpdate User Screen");
			

			string UserName = "";
			
			cout << "\nPlease Enter  UserName: ";
			UserName = clsInputValidate::ReadString();

			while (!clsUser::IsUserExist(UserName))
			{
				cout << "\nUserName is not found, choose another one: ";
				UserName = clsInputValidate::ReadString();
			}

			clsUser User1 = clsUser::Find(UserName);
			_PrintUser(User1);

			cout << "\nAre you sure do you want to Update this User y/n? ";

			char Answer = 'n';
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{


				cout << "\n\nUpdate User Info:";
				cout << "\n____________________\n";

				_ReadUserInfo(User1);

				clsUser::enSaveResults SaveResult;

				SaveResult = User1.Save();

				switch (SaveResult)
				{
				case  clsUser::enSaveResults::svSucceeded:
				{
					cout << "\n____________________";
					cout << "\nUser Updated Successfully :-)\n";
					_PrintUser(User1);
					break;
				}
				case clsUser::enSaveResults::svFaildEmptyObject:
				{
					cout << "\nError UserName was not saved because it's Empty";
					break;

				}

				}
			}
		}
};

