#include "mySQLQueries.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace std;

mySQLQueries::mySQLQueries(){
}

bool mySQLQueries::setQuery(System::String^ stringSQL){
	MySqlConnection^ conDataBase;
	try{
		conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
		conDataBase->Open();
		MySqlCommand^ sql = gcnew MySqlCommand(stringSQL, conDataBase);
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
void mySQLQueriesgetQuery(System::String ^sql){

}