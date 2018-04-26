#include "AdminScreen.h"
#include "Admin.h"
#include "SettingScreen.h"
#include <stdlib.h>
#include <ctime>
#pragma once

namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// This screen is used as access control for Administration. An Administrator's Employee ID and password are authenticted and if valid, the LoginScreen then opens either:
	/// - AdminScreen
	/// - SettingScreen
	/// </summary>
	public ref class LoginScreen : public System::Windows::Forms::Form
	{
	public:
		LoginScreen(System::String^ type_in, System::Windows::Forms::RichTextBox^ ev){
			type = type_in;
			eventLogTxt = ev;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::TextBox^  passwordTxt;
	private: System::Windows::Forms::TextBox^  usernameTxt;
	private: System::Windows::Forms::Label^  passwordLbl;
	private: System::Windows::Forms::Label^  usernameLbl;
	private: System::Windows::Forms::Button^  backBtn;
	private: System::Windows::Forms::Button^  loginBtn;
	private: System::String^ type;									//Controls which screen is to be opened next
	private: System::Windows::Forms::RichTextBox^  eventLogTxt;		//RichTextBox used to log events
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginScreen::typeid));
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->passwordTxt = (gcnew System::Windows::Forms::TextBox());
				 this->usernameTxt = (gcnew System::Windows::Forms::TextBox());
				 this->passwordLbl = (gcnew System::Windows::Forms::Label());
				 this->usernameLbl = (gcnew System::Windows::Forms::Label());
				 this->backBtn = (gcnew System::Windows::Forms::Button());
				 this->loginBtn = (gcnew System::Windows::Forms::Button());
				 this->panel1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->passwordTxt);
				 this->panel1->Controls->Add(this->usernameTxt);
				 this->panel1->Controls->Add(this->passwordLbl);
				 this->panel1->Controls->Add(this->usernameLbl);
				 this->panel1->Location = System::Drawing::Point(13, 13);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(464, 120);
				 this->panel1->TabIndex = 0;
				 // 
				 // passwordTxt
				 // 
				 this->passwordTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->passwordTxt->Location = System::Drawing::Point(106, 74);
				 this->passwordTxt->Name = L"passwordTxt";
				 this->passwordTxt->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
				 this->passwordTxt->Size = System::Drawing::Size(339, 23);
				 this->passwordTxt->TabIndex = 3;
				 this->passwordTxt->UseSystemPasswordChar = true;
				 // 
				 // usernameTxt
				 // 
				 this->usernameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->usernameTxt->Location = System::Drawing::Point(106, 26);
				 this->usernameTxt->Name = L"usernameTxt";
				 this->usernameTxt->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
				 this->usernameTxt->Size = System::Drawing::Size(339, 23);
				 this->usernameTxt->TabIndex = 2;
				 // 
				 // passwordLbl
				 // 
				 this->passwordLbl->AutoSize = true;
				 this->passwordLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->passwordLbl->Location = System::Drawing::Point(7, 77);
				 this->passwordLbl->Name = L"passwordLbl";
				 this->passwordLbl->Size = System::Drawing::Size(73, 17);
				 this->passwordLbl->TabIndex = 1;
				 this->passwordLbl->Text = L"Password:";
				 // 
				 // usernameLbl
				 // 
				 this->usernameLbl->AutoSize = true;
				 this->usernameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->usernameLbl->Location = System::Drawing::Point(4, 29);
				 this->usernameLbl->Name = L"usernameLbl";
				 this->usernameLbl->Size = System::Drawing::Size(91, 17);
				 this->usernameLbl->TabIndex = 0;
				 this->usernameLbl->Text = L"Employee ID:";
				 // 
				 // backBtn
				 // 
				 this->backBtn->FlatAppearance->BorderSize = 0;
				 this->backBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->backBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backBtn.Image")));
				 this->backBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->backBtn->Location = System::Drawing::Point(12, 145);
				 this->backBtn->Name = L"backBtn";
				 this->backBtn->Size = System::Drawing::Size(120, 50);
				 this->backBtn->TabIndex = 1;
				 this->backBtn->Text = L"CLOSE";
				 this->backBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->backBtn->UseVisualStyleBackColor = true;
				 this->backBtn->Click += gcnew System::EventHandler(this, &LoginScreen::backBtn_Click);
				 // 
				 // loginBtn
				 // 
				 this->loginBtn->FlatAppearance->BorderSize = 0;
				 this->loginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->loginBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loginBtn.Image")));
				 this->loginBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->loginBtn->Location = System::Drawing::Point(346, 145);
				 this->loginBtn->Name = L"loginBtn";
				 this->loginBtn->Size = System::Drawing::Size(131, 50);
				 this->loginBtn->TabIndex = 2;
				 this->loginBtn->Text = L"LOGIN";
				 this->loginBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->loginBtn->UseVisualStyleBackColor = true;
				 this->loginBtn->Click += gcnew System::EventHandler(this, &LoginScreen::loginBtn_Click);
				 // 
				 // LoginScreen
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->ClientSize = System::Drawing::Size(489, 207);
				 this->Controls->Add(this->loginBtn);
				 this->Controls->Add(this->backBtn);
				 this->Controls->Add(this->panel1);
				 this->ForeColor = System::Drawing::Color::White;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 this->MaximizeBox = false;
				 this->Name = L"LoginScreen";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Administrator Login ";
				 this->panel1->ResumeLayout(false);
				 this->panel1->PerformLayout();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void backBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~LoginScreen();
	}
	private: System::Void loginBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		MySqlConnection^ conDataBase;
		try{
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			if (usernameTxt->Text != "" && passwordTxt->Text != ""){		//Check if fields are empty
				MySqlCommand^ sql = gcnew MySqlCommand("SELECT * FROM emss_database.admin WHERE `employee_id` = " + Int32::Parse(usernameTxt->Text).ToString() + ";", conDataBase);
				MySqlDataReader^ reader = sql->ExecuteReader();
				if (reader->Read()){										//Employee ID found in DB
					if (reader->GetString("password") == passwordTxt->Text){	//Passwords match
						DateTime^ dt = reader->GetDateTime("date_of_birth");
						Admin^ authAdmin = gcnew Admin(reader->GetInt32("employee_id"), reader->GetString("password"), reader->GetInt32("pin"), reader->GetString("first_names"), reader->GetString("surname")->ToString(), dt->ToString("yyyy-MM-dd"), reader->GetString("physical_address"), reader->GetString("email_address"), reader->GetString("phone_number"), reader->GetString("position"));
						char str[100];
						time_t currTime = time(0);
						struct tm time_info;
						localtime_s(&time_info, &currTime);
						strftime(str, 100, " %d/%m/%y %H:%M:%S - ", &time_info);
						System::String^ timeLog = gcnew System::String(str);//Get the date and time
						if (type == "AdminScreen"){							//Opens AdminScreen and passes Admin Object with populated member fields 
							AdminScreen^ ad = gcnew AdminScreen(authAdmin);
							ad->Show();
							eventLogTxt->Text += timeLog + "Administration Screen accessed by " + reader->GetString("first_names") + "\n";
						}
						else if (type == "Settings"){						//Opens the Settings screen
							eventLogTxt->Text += timeLog + "Settings accessed by " + reader->GetString("first_names") + "\n";
							SettingScreen^ sett = gcnew SettingScreen();
							sett->Show();
						}
						else{
							MessageBox::Show("Invalid attempt to Login.");
						}
						reader->Close();
						conDataBase->Close();
						this->~LoginScreen();
					}
					else{		//Incorrect password
						MessageBox::Show("Invalid Login credentials.");
					}
					reader->Close();
				}
				else{		//Invalid employee id
					MessageBox::Show("Invalid Login credentials.");
				}
			}
			else{
				MessageBox::Show("Data field empty!");
			}
		}
		catch (System::Exception^ ex){
			MessageBox::Show("ERROR reading data.");
		}
		conDataBase->Close();
	}
	};
}
