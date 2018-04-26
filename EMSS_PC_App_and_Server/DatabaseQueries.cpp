#include "DatabaseQueries.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace std;

DatabaseQueries::DatabaseQueries(){
}
DatabaseQueries::~DatabaseQueries(){
}
/*Function used to execute a Query when no results are required*/
bool DatabaseQueries::setQuery(System::String^ text){
	MySqlConnection^ conDataBase;
	try{
		conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
		conDataBase->Open();
		MySqlCommand^ sql = gcnew MySqlCommand(text, conDataBase);
		MySqlDataReader^ reader = sql->ExecuteReader();
		reader->Close();
		conDataBase->Close();
	}
	catch (Exception^ ex){
		MessageBox::Show(ex->Message);
		return false;
	}
	return true;
}
