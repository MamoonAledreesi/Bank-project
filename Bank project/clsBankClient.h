#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;
    struct stTransferRegisterRecord;
  static  struct stTransferRegisterRecord _ConvertTransferRegisterLine(string Line, string Seperator = "#//#")
    {
        stTransferRegisterRecord TransfterRegisterRecord;

        vector <string>TransfterRegisterDataLine = clsString::Split(Line, Seperator);
        TransfterRegisterRecord.DateTime = TransfterRegisterDataLine[0];
        TransfterRegisterRecord.SAcountNumber= TransfterRegisterDataLine[1];
        TransfterRegisterRecord.DAcountNumber = TransfterRegisterDataLine[2];
        TransfterRegisterRecord.Amount = stoi( TransfterRegisterDataLine[3]);
        TransfterRegisterRecord.SAccountBlance = stoi( TransfterRegisterDataLine[4]);
        TransfterRegisterRecord.DAccountBlance = stoi( TransfterRegisterDataLine[5]);
        TransfterRegisterRecord.UserName =  TransfterRegisterDataLine[6];

        return TransfterRegisterRecord;
    }

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }
   

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }
    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

     string _PrepareTransferLogRecord( float Amount, clsBankClient DestieationClient,string UserName, string Seperator = "#//#")
    {
        string TransferRecord = "";
        TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferRecord += AccountNumber() + Seperator;
        TransferRecord += DestieationClient.AccountNumber() + Seperator;
        TransferRecord += to_string(Amount) + Seperator;
        TransferRecord += to_string(AccountBalance) + Seperator;
        TransferRecord += to_string( DestieationClient.AccountBalance) + Seperator;
        TransferRecord +=UserName;

        return TransferRecord;
    }
   	void _RegisterTransferLog(float Amount, clsBankClient destieationClient,string UserName )
    {

        string stDataLine = _PrepareTransferLogRecord(Amount, destieationClient,UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

public:

    struct stTransferRegisterRecord
    {
        string DateTime;
        string SAcountNumber;
        string DAcountNumber;
        float Amount;
        float SAccountBlance;
        float DAccountBlance;
        string UserName;

    }; 
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svAccountNumberExists=2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddNewMode:
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }


        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient>_vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
            return true;

    }

    bool Transfer(float Amount, clsBankClient& DestinationClient)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }
        else
        {
            Withdraw(Amount);
            DestinationClient.Deposit(Amount);
            _RegisterTransferLog(Amount, DestinationClient, CurrentUser.UserName);
            return true;
        }
    }
    static double GetTotalBalances()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        for (clsBankClient Client : vClients)
        {
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances;
    }

    static vector<stTransferRegisterRecord> GetTransferRegisterList()
    {
        vector<stTransferRegisterRecord> vTransferRegisterRecord;
        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            stTransferRegisterRecord TransferRegisterRecord;

            while (getline(MyFile, Line))
            {
                TransferRegisterRecord = _ConvertTransferRegisterLine(Line);

                vTransferRegisterRecord.push_back(TransferRegisterRecord);
            }

            MyFile.close();
        }

        return vTransferRegisterRecord;

    }
};

