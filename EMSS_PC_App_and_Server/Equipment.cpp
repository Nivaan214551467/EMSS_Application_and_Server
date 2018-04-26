#include "Equipment.h"
#include "DatabaseQueries.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

/*Default constructor*/
Equipment::Equipment(void){
}
/*Constructor used when populating members*/
Equipment::Equipment(System::String^ eqID, String^ n, String^ d){
	this->equipID = eqID;
	this->name = n;
	this->description = d;
}
Equipment::~Equipment(void){
}
/*Function used when Equipment is being loaned out*/
bool Equipment::get_loaned_out(Int32^ reqID, System::String^ reqEqID, System::String^ dateTime){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("UPDATE `emss_database`.`equipment` SET `loaned_out_to` = '" + reqID->ToString() + "' WHERE `equip_id` = '" + reqEqID + "';")){
		if (msql->setQuery("INSERT INTO `emss_database`.`loan_tracking` (`equip_id`,`employee_id`,`loan_date`) VALUES ('" + reqEqID + "', '" + reqID->ToString() + "', '" + dateTime + "');")){
			return true;
		}
	}
	return false;
}
/*Function used when Equipment is being returned*/
bool Equipment::return_equipment(Int32^ reqID, System::String^ reqEqID, System::String^ dateTime){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("UPDATE `emss_database`.`equipment` SET `loaned_out_to` = '0' WHERE `equip_id` = '" + reqEqID + "';")){
		if (msql->setQuery("UPDATE `emss_database`.`loan_tracking` SET `loan_tracking`.`return_date` =  '" + dateTime + "' WHERE `loan_tracking`.`equip_id` = '" + reqEqID + "' AND `loan_tracking`.`employee_id` = '" + reqID + "' AND `loan_tracking`.`loan_date` is NULL;")){
			return true;
		}
	}
	return false;
}
/*Function used when Adding an Equipment to the database*/
bool Equipment::addEquipment(System::String^ eqID, String^ n, String^ d){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("INSERT INTO `emss_database`.`equipment` (`equip_id`, `name`, `description`) VALUES ('" + eqID + "', '" + n + "', '" + d + "');")){
		MessageBox::Show("Equipment successfully Added.");
		return true;
	}
	return false;
}
/*Function used when Updating an Equipment on the database*/
bool Equipment::update(System::String^ eqID, String^ n, String^ d){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("UPDATE `emss_database`.`equipment` SET `equip_id` = '" + eqID + "', `name` = '" + n + "', `description` = '" + d + "' WHERE `equip_id` = '" + this->equipID->ToString() + "';")){
		MessageBox::Show("Equipment successfully Updated.");
		return true;
	}
	return false;
}
/*Function used when Deleting an Equipment from the database*/
bool Equipment::del(){
	DatabaseQueries^ msql = gcnew DatabaseQueries();
	if (msql->setQuery("DELETE FROM `emss_database`.`equipment` WHERE `equip_id`='" + this->equipID + "';")){
		MessageBox::Show("Equipment successfully Deleted.");
		return true;
	}
	return false;
}

bool Equipment::isBorrowed(System::String^ recEqID){
	MySqlConnection^ conDataBase;
	try{
		conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
		conDataBase->Open();
		MySqlCommand^ sql = gcnew MySqlCommand("SELECT `equipment`.`loaned_out_to` FROM `emss_database`.`equipment` WHERE `equip_id` = '" + recEqID+ "';", conDataBase);
		MySqlDataReader^ reader = sql->ExecuteReader();
		if (reader->Read()){
			if (reader->GetString("loaned_out_to") == "0")			//Means equipment is not borrowed
				return false;
		}
		else{
			return false;
		}
		reader->Close();
	}
	catch (System::Exception^ ex){
		MessageBox::Show("ERROR processing ETAS data.");
	}
	return true;
}