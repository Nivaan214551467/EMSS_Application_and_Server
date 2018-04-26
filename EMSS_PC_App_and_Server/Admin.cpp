#include "Admin.h"
#include "Employee.h"
#include "Equipment.h"
#include "DatabaseQueries.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace std;

/*Default Constructor*/
Admin::Admin(){
}
/*Constructor used when populating members of the class*/
Admin::Admin(Int32^ employeeID, String^ pwrd, Int32^ pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position){
	this->employeeID = employeeID;
	this->password = pwrd;
	this->pin = pin;
	this->first_names = fname;
	this->surname = sname;
	this->date_of_birth = dob;
	this->physical_address = pAddress;
	this->email_address = email;
	this->phone_number = phone;
	this->position = position;
}
Admin::~Admin(void){
}
/*Function used to Add an Administrator to the Database. Returns true if succeeded.*/
bool Admin::addUser(Int32^ employeeID, String^ pwrd, Int32^ pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("INSERT INTO `emss_database`.`admin` (`employee_id`, `pin`, `password`, `first_names`, `surname`, `date_of_birth`, `physical_address`, `email_address`, `phone_number`, `position`) VALUES ('" + employeeID->ToString() + "', '" + pin->ToString() + "', '" + pwrd + "','" + fname + "', '" + sname + "', '" + dob + "', '" + pAddress + "', '" + email + "', '" + phone + "', '" + position + "');")){
		MessageBox::Show("Administrator successfully added");
		return true;
	}
	return false;
}
/*Function used to Update an Administrator record on the Database. Returns true if succeeded.*/
bool Admin::update(Int32^ employeeID, String^ pwrd, Int32^ pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("UPDATE `emss_database`.`admin` SET `employee_id` = '" + employeeID->ToString() + "', `pin` = '" + pin->ToString() + "', `password` = '" + pwrd + "', `first_names` = '" + fname + "', `surname` = '" + sname + "', `date_of_birth` = '" + dob + "', `physical_address` = '" + pAddress + "', `email_address` = '" + email + "', `phone_number` = '" + phone + "', `position` = '" + position + "' WHERE `employee_id` = '" + this->employeeID->ToString() + "';")){
		MessageBox::Show("Administrator successfully updated");
		return true;
	}
	return false;
}
/*Function used to Delete an Administrator record from the Database. Returns true if succeeded.*/
bool Admin::del(){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("DELETE FROM `emss_database`.`admin` WHERE `employee_id`='" + employeeID->ToString() + "';")){
		MessageBox::Show("Employee ID " + this->employeeID->ToString() + " data Deleted!");
		return true;
	}
	return false;
}
