#include <string>
#include <ctime>

using namespace System;
using namespace std;
#pragma once
class User
{
private:
	int employeeID;
	int pin;
	string first_names;
	string surname;
	tm *date_of_birth;
	string physical_address;
	string email_address;
	string phone_number;
	string position;

public:
	User(void);
	void addUser(int, int, String^, String^, String^, String^, String^, String^, String^, String^);
	void update(int, int, string, string, tm *, string, string, string, string);
	void del();
	~User(void);
};

