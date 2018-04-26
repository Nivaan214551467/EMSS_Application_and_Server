#pragma once
ref class mySQLQueries
{
public:
	mySQLQueries();
	~mySQLQueries();
	bool setQuery(System::String ^sql);
	void getQuery(System::String ^sql);

};

