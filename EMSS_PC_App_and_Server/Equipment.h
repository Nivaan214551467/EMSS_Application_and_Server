#include <ctime>
#pragma once

using namespace System;

public ref class Equipment{
public:
	System::String^ equipID;			//Stores the Equipment's ID
	System::String^ name;				//Stores the Equipment's name
	System::String^ description;		//Stores the description of the Equipment
	Int32^ loaned_out_to;				//Stores the Employee ID of the Employee who loaned out the equipment
public:
	Equipment(void);
	Equipment(System::String^, String^, String^);
	bool get_loaned_out(Int32^, System::String^, System::String^);
	bool return_equipment(Int32^, System::String^, System::String^);
	bool addEquipment(System::String^, System::String^, System::String^);
	bool update(System::String^, System::String^, System::String^);
	bool del();
	bool isBorrowed(System::String^ recEqID);
	bool exists(System::String^ recEqID);
	~Equipment(void);
};

