#include "MainScreen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread] void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	EMSS_PC_App_and_Server::MainScreen form;
	Application::Run(%form);
}
