#pragma once

#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsUtil.h"
#include"Global.h"
#include"clsMainScreen.h"


class clsLoginScreen:protected clsScreen

{
private:
	static bool _Login()
	{
		
		bool LoginFaild = false;
		short FaliedLoginCount = 0;
		string UserName, Password;
		
		do
		{
			if (LoginFaild)
			{
				FaliedLoginCount++;
				cout << "\n Invalid UserName/Password!\n";
				cout << "You have "<<3-FaliedLoginCount<<" Trials\n\n";
				

			}
			if (FaliedLoginCount == 3)
			{
				cout << "\nYou are Locked after 3 Failed Trials\n";
				
				return false;
			}

			cout << "Enter UserName: ";
			cin >> UserName;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		
		return _Login();
	}
};

