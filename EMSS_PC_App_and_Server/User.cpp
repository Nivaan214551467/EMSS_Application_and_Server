#include "User.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

User::User(void){
}

User::~User(void){
}
void addUser(int employeeID, int pin, String^ fname, String^ sname,  String^ dob, String^ pAddress, String^ email, String^ phone, String^ position, String^ tblName){
	MySqlConnection^ conDataBase;
	try{
		conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
		conDataBase->Open();
		MySqlCommand^ sql = gcnew MySqlCommand("INSERT INTO `emss_database`.`" + tblName + "` (`employee_id`, `pin`, `first_names`, `surname`, `date_of_birth`, `physical_address`, `email_address`, `phone_number`, `position`) VALUES ('" + employeeID.ToString() + "', '" + pin.ToString() + "', '" + fname + "', '" + sname + "', '" + dob + "', '" + pAddress + "', '" + email + "', '" + phone + "', '" + position + "');", conDataBase);
		MySqlDataReader^ reader = sql->ExecuteReader();
		reader->Close();
		conDataBase->Close();
	}
	catch (Exception^ ex){
		MessageBox::Show(ex->Message);
	}
}
void update(int employeeID, int pin, String^ fname, String^ sname, String^ dob, String^ pAddress, String^ email, String^ phone, String^ position, String^ tblName){
	MySqlConnection^ conDataBase;
	try{
		conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
		conDataBase->Open();
		MySqlCommand^ sql = gcnew MySqlCommand("UPDATE `emss_database`.`" + tblName + "` SET `employee_id` = `" + employeeID.ToString() + "`, `pin` = `" + pin.ToString() + "`, `first_names` = `" + fname + "`, `surname` = `" + sname + "`, `date_of_birth` = `" + dob + "`, `physical_address` = `" + pAddress + "`, `email_address` = `" + email + "`, `phone_number` = `" + phone + "`, `position` = `" + position + "`;", conDataBase);
		MySqlDataReader^ reader = sql->ExecuteReader();
		reader->Close();
		conDataBase->Close();
	}
	catch (Exception^ ex){
		MessageBox::Show(ex->Message);
	}
}
void del(){

}
