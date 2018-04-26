#include "Employee.h"
#include "DatabaseQueries.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace MySql::Data::MySqlClient;

/*Default constructor*/
Employee::Employee(void){
}
/*Constructor used to populate the Object's members*/
Employee::Employee(Int32^ employeeID, Int32^ pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position){
	this->employeeID = employeeID;
	this->pin = pin;
	this->first_names = fname;
	this->surname = sname;
	this->date_of_birth = dob;
	this->physical_address = pAddress;
	this->email_address = email;
	this->phone_number = phone;
	this->position = position;
}
Employee::~Employee(void){
}
/*Function used to Add an Employee to the database. Return true if succeeded*/
bool Employee::addUser(Int32^ employeeID, Int32^ pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("INSERT INTO `emss_database`.`employee` (`employee_id`, `pin`, `first_names`, `surname`, `date_of_birth`, `physical_address`, `email_address`, `phone_number`, `position`) VALUES ('" + employeeID->ToString() + "', '" + pin->ToString() + "', '" + fname + "', '" + sname + "', '" + dob + "', '" + pAddress + "', '" + email + "', '" + phone + "', '" + position + "');")){
		MessageBox::Show("Administrator successfully Added.");
		return true;
	}
	return false;
}
/*Function used to Update an Employee on the database. Return true if succeeded*/
bool Employee::update(Int32^ employeeID, Int32^ pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("UPDATE `emss_database`.`employee` SET `employee_id` = '" + employeeID->ToString() + "', `pin` = '" + pin->ToString() + "', `first_names` = '" + fname + "', `surname` = '" + sname + "', `date_of_birth` = '" + dob + "', `physical_address` = '" + pAddress + "', `email_address` = '" + email + "', `phone_number` = '" + phone + "', `position` = '" + position + "' WHERE `employee_id` = '" + this->employeeID->ToString() + "';")){
		MessageBox::Show("Administrator successfully Updated.");
		return true;
	}
	return false;
}
/*Function used to Delete an Employee from the database. Return true if succeeded*/
bool Employee::del(){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("DELETE FROM `emss_database`.`employee` WHERE `employee_id`='" + employeeID->ToString() + "';")){
		MessageBox::Show("Administrator successfully Deleted.");
		return true;
	}
	return false;
}

/*Function used when authorization is requested by an Employee. Returns true if authorization granted*/
bool Employee::request_authorization(Int32^ reqID, Int32^ reqPIN){
	bool res = false;
	MySqlConnection^ conDataBase;
	try{
		conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
		conDataBase->Open();
		//Get PIn from the database
		MySqlCommand^ sql = gcnew MySqlCommand("SELECT * FROM `emss_database`.`employee` WHERE `employee`.`employee_id` = '" + reqID + "';", conDataBase);
		MySqlDataReader^ reader = sql->ExecuteReader();
		if (reader->Read()){
			if ((int)reqPIN == reader->GetInt32("pin")){		//Check if PINs match
				res = true;
			}
		}
		reader->Close();
		conDataBase->Close();
	}
	catch (Exception^ ex){
		MessageBox::Show("ERROR authenticating.");
		res = false;
	}
	return res;
}

