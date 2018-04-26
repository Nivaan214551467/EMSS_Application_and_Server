#include <ctime>
#include "Equipment.h"

#pragma once
using namespace System;

public ref class Employee{
public:
	Int32^ employeeID;				//Stores the Employee ID  of the Employee
	Int32^ pin;						//Stores the PIN number  of the Employee
	String^ first_names;			//Stores the first names  of the Employee
	String^ surname;				//Stores the surname of the Employee
	String^ date_of_birth;			//Stores the date of birth of the Employee
	String^ physical_address;		//Stores the physical address of the Employee
	String^ email_address;			//Stores the email address of the Employee
	String^ phone_number;			//Stores the phone number of the Employee
	String^ position;				//Stores the employment position of the Employee
public:
	Employee(void);
	Employee(Int32^, Int32^, String^, String^, String^, String^, String^, String^, String^);
	bool addUser(Int32^, Int32^, String^, String^, String^, String^, String^, String^, String^);
	bool update(Int32^, Int32^, String^, String^, String^, String^, String^, String^, String^);
	bool del();
	bool request_authorization(Int32^, Int32^);
	~Employee(void);
};

