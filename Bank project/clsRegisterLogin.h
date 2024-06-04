#pragma once
#include <iostream>
#include <string>
#include "clsUser.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>

class clsRegisterLogin :clsUser
{

    static string _ConverRegisrtObjectToLine(clsUser User ,string Seperator = "#//#")
    {
         clsDate Date;
        string RegisterRecord = "";
        RegisterRecord += Date.DateToString(Date) + " - ";
        RegisterRecord += Date.GetSystemTime() + Seperator;
        
       
        RegisterRecord += User.UserName +Seperator;
        RegisterRecord += to_string(User.Permissions);

        return RegisterRecord;

    }
    static  void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("RegistersLogin.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
 
public:
  static  void AddNewRegisterLogin()
    {

        _AddDataLineToFile(_ConverRegisrtObjectToLine(CurrentUser));
    }

  

   
};

