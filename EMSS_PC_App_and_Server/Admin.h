#include <string>
#include <ctime>
#include "Employee.h"
#include "Equipment.h"

#pragma once

public ref class Admin{
public:
	Int32^ employeeID;				//The Employee ID of an Administrator
	String^ password;				//The Password of an Administrator
	Int32^ pin;						//The PIN number of an Administrator
	String^ first_names;			//The first names of an Administrator
	String^ surname;				//The surname of an Administrator
	String^ date_of_birth;			//The date of birth of an Administrator
	String^ physical_address;		//The physical address of an Administrator
	String^ email_address;			//The email address of an Administrator
	String^ phone_number;			//The phone number of an Administrator
	String^ position;				//The employment position of an Administrator
public:
	Admin();
	Admin(Int32^, String^, Int32^, String^, String^, String^, String^, String^, String^, String^);
	bool addUser(Int32^, String^, Int32^, String^, String^, String^, String^, String^, String^, String^);
	bool update(Int32^, String^, Int32^, String^, String^, String^, String^, String^, String^, String^);
	bool del();
	~Admin(void);
};

