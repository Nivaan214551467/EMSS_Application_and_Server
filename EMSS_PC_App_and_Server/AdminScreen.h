#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#pragma once

#include <ctime>
#include "Employee.h"
#include "Equipment.h"
#include "AddUserScreen.h"
#include "Admin.h"
#include "EquipScreen.h"
#include "dispScreen.h"
#include "VideoRecScreen.h"
#include "deleteConfirmScreen.h"
namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	extern bool stopVideo;				//Global variable used to control the starting and stopping of Video Recording
	extern bool vidThreadAlive;			//Global variable used to indicate whether the Video recording Thread is active
	/// <summary>
	/// Screen used as an interface for an Administrator. Contains buttons to perform the following tasks:
	/// - Open the screen to Add a new Administrator to the database
	/// - Open the screen to Update the logged in Administrator on the database
	/// - Delete the logged in Administrator from the database
	/// - Open Screen to Add a new Employee to the database
	/// - Open Screen to Display Employee records
	/// - Open Screen to Add a new Equipment to the database
	/// - Open Screen to Display Equipment records and loan hirtory
	/// - Open Screen to Display Video recordings
	/// - Stop Video recording
	/// </summary>
	public ref class AdminScreen : public System::Windows::Forms::Form
	{
	public:
		/*Default Constructor*/
		AdminScreen(){
			InitializeComponent();
		}
		/*Constructor used when an Admin Object is passed to it*/
		AdminScreen(Admin^ ad){
			this->adminUser = ad;
			InitializeComponent();
		}
	protected:
		~AdminScreen(){
			if (components)
				delete components;
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  delAdminBtn;
	private: System::Windows::Forms::Button^  editAdminBtn;
	private: System::Windows::Forms::Button^  newAdminBtn;
	private: System::Windows::Forms::Button^  ViewEmpBtn;
	private: System::Windows::Forms::Button^  addEmpBtn;
	private: System::Windows::Forms::Button^  viewEqBtn;
	private: System::Windows::Forms::Button^  addEqBtn;
	private: System::Windows::Forms::Button^  viewRecBtn;
	private: System::Windows::Forms::Button^  logoutBtn;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  stopVidBtn;
	private: Admin^ adminUser;									//Admin Object used to store information of an Admin user
			 /// <summary>
			 /// Required designer variable.
			 /// </summary>
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminScreen::typeid));
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->delAdminBtn = (gcnew System::Windows::Forms::Button());
				 this->editAdminBtn = (gcnew System::Windows::Forms::Button());
				 this->newAdminBtn = (gcnew System::Windows::Forms::Button());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->ViewEmpBtn = (gcnew System::Windows::Forms::Button());
				 this->addEmpBtn = (gcnew System::Windows::Forms::Button());
				 this->panel3 = (gcnew System::Windows::Forms::Panel());
				 this->viewEqBtn = (gcnew System::Windows::Forms::Button());
				 this->addEqBtn = (gcnew System::Windows::Forms::Button());
				 this->viewRecBtn = (gcnew System::Windows::Forms::Button());
				 this->logoutBtn = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->panel4 = (gcnew System::Windows::Forms::Panel());
				 this->stopVidBtn = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->panel1->SuspendLayout();
				 this->panel2->SuspendLayout();
				 this->panel3->SuspendLayout();
				 this->panel4->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->panel1->Controls->Add(this->delAdminBtn);
				 this->panel1->Controls->Add(this->editAdminBtn);
				 this->panel1->Controls->Add(this->newAdminBtn);
				 this->panel1->Location = System::Drawing::Point(13, 13);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(392, 553);
				 this->panel1->TabIndex = 0;
				 // 
				 // delAdminBtn
				 // 
				 this->delAdminBtn->FlatAppearance->BorderSize = 0;
				 this->delAdminBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->delAdminBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
				 this->delAdminBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delAdminBtn.Image")));
				 this->delAdminBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->delAdminBtn->Location = System::Drawing::Point(3, 425);
				 this->delAdminBtn->Name = L"delAdminBtn";
				 this->delAdminBtn->Size = System::Drawing::Size(386, 85);
				 this->delAdminBtn->TabIndex = 2;
				 this->delAdminBtn->Text = L"DELETE OWN RECORD                    ";
				 this->delAdminBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->delAdminBtn->UseVisualStyleBackColor = true;
				 this->delAdminBtn->Click += gcnew System::EventHandler(this, &AdminScreen::delAdminBtn_Click);
				 // 
				 // editAdminBtn
				 // 
				 this->editAdminBtn->FlatAppearance->BorderSize = 0;
				 this->editAdminBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->editAdminBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->editAdminBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editAdminBtn.Image")));
				 this->editAdminBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->editAdminBtn->Location = System::Drawing::Point(3, 245);
				 this->editAdminBtn->Name = L"editAdminBtn";
				 this->editAdminBtn->Size = System::Drawing::Size(386, 85);
				 this->editAdminBtn->TabIndex = 1;
				 this->editAdminBtn->Text = L"EDIT OWN RECORD                           ";
				 this->editAdminBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->editAdminBtn->UseVisualStyleBackColor = true;
				 this->editAdminBtn->Click += gcnew System::EventHandler(this, &AdminScreen::editAdminBtn_Click);
				 // 
				 // newAdminBtn
				 // 
				 this->newAdminBtn->FlatAppearance->BorderSize = 0;
				 this->newAdminBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->newAdminBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->newAdminBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newAdminBtn.Image")));
				 this->newAdminBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->newAdminBtn->Location = System::Drawing::Point(3, 68);
				 this->newAdminBtn->Name = L"newAdminBtn";
				 this->newAdminBtn->Size = System::Drawing::Size(386, 85);
				 this->newAdminBtn->TabIndex = 0;
				 this->newAdminBtn->Text = L"ADD NEW ADMINISTRATOR USER";
				 this->newAdminBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->newAdminBtn->UseVisualStyleBackColor = true;
				 this->newAdminBtn->Click += gcnew System::EventHandler(this, &AdminScreen::newAdminBtn_Click);
				 // 
				 // panel2
				 // 
				 this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->panel2->Controls->Add(this->ViewEmpBtn);
				 this->panel2->Controls->Add(this->addEmpBtn);
				 this->panel2->Location = System::Drawing::Point(469, 13);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(392, 354);
				 this->panel2->TabIndex = 1;
				 // 
				 // ViewEmpBtn
				 // 
				 this->ViewEmpBtn->FlatAppearance->BorderSize = 0;
				 this->ViewEmpBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->ViewEmpBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->ViewEmpBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ViewEmpBtn.Image")));
				 this->ViewEmpBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->ViewEmpBtn->Location = System::Drawing::Point(3, 246);
				 this->ViewEmpBtn->Name = L"ViewEmpBtn";
				 this->ViewEmpBtn->Size = System::Drawing::Size(386, 85);
				 this->ViewEmpBtn->TabIndex = 4;
				 this->ViewEmpBtn->Text = L"VIEW EMPLOYEE RECORDS             ";
				 this->ViewEmpBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->ViewEmpBtn->UseVisualStyleBackColor = true;
				 this->ViewEmpBtn->Click += gcnew System::EventHandler(this, &AdminScreen::ViewEmpBtn_Click);
				 // 
				 // addEmpBtn
				 // 
				 this->addEmpBtn->FlatAppearance->BorderSize = 0;
				 this->addEmpBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->addEmpBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->addEmpBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addEmpBtn.Image")));
				 this->addEmpBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->addEmpBtn->Location = System::Drawing::Point(3, 69);
				 this->addEmpBtn->Name = L"addEmpBtn";
				 this->addEmpBtn->Size = System::Drawing::Size(386, 85);
				 this->addEmpBtn->TabIndex = 3;
				 this->addEmpBtn->Text = L"ADD NEW EMPLOYEE                         ";
				 this->addEmpBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->addEmpBtn->UseVisualStyleBackColor = true;
				 this->addEmpBtn->Click += gcnew System::EventHandler(this, &AdminScreen::addEmpBtn_Click);
				 // 
				 // panel3
				 // 
				 this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->panel3->Controls->Add(this->viewEqBtn);
				 this->panel3->Controls->Add(this->addEqBtn);
				 this->panel3->Location = System::Drawing::Point(917, 13);
				 this->panel3->Name = L"panel3";
				 this->panel3->Size = System::Drawing::Size(392, 354);
				 this->panel3->TabIndex = 2;
				 // 
				 // viewEqBtn
				 // 
				 this->viewEqBtn->FlatAppearance->BorderSize = 0;
				 this->viewEqBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->viewEqBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->viewEqBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"viewEqBtn.Image")));
				 this->viewEqBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->viewEqBtn->Location = System::Drawing::Point(3, 246);
				 this->viewEqBtn->Name = L"viewEqBtn";
				 this->viewEqBtn->Size = System::Drawing::Size(386, 85);
				 this->viewEqBtn->TabIndex = 6;
				 this->viewEqBtn->Text = L"VIEW EQUIPMENT RECORDS          ";
				 this->viewEqBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->viewEqBtn->UseVisualStyleBackColor = true;
				 this->viewEqBtn->Click += gcnew System::EventHandler(this, &AdminScreen::viewEqBtn_Click);
				 // 
				 // addEqBtn
				 // 
				 this->addEqBtn->FlatAppearance->BorderSize = 0;
				 this->addEqBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->addEqBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->addEqBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addEqBtn.Image")));
				 this->addEqBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->addEqBtn->Location = System::Drawing::Point(3, 70);
				 this->addEqBtn->Name = L"addEqBtn";
				 this->addEqBtn->Size = System::Drawing::Size(386, 85);
				 this->addEqBtn->TabIndex = 5;
				 this->addEqBtn->Text = L"ADD NEW EQUIPMENT                      ";
				 this->addEqBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->addEqBtn->UseVisualStyleBackColor = true;
				 this->addEqBtn->Click += gcnew System::EventHandler(this, &AdminScreen::addEqBtn_Click);
				 // 
				 // viewRecBtn
				 // 
				 this->viewRecBtn->FlatAppearance->BorderSize = 0;
				 this->viewRecBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->viewRecBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->viewRecBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"viewRecBtn.Image")));
				 this->viewRecBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->viewRecBtn->Location = System::Drawing::Point(3, 49);
				 this->viewRecBtn->Name = L"viewRecBtn";
				 this->viewRecBtn->Size = System::Drawing::Size(386, 85);
				 this->viewRecBtn->TabIndex = 7;
				 this->viewRecBtn->Text = L"VIEW VIDEO RECORDINGS             ";
				 this->viewRecBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->viewRecBtn->UseVisualStyleBackColor = true;
				 this->viewRecBtn->Click += gcnew System::EventHandler(this, &AdminScreen::viewRecBtn_Click);
				 // 
				 // logoutBtn
				 // 
				 this->logoutBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->logoutBtn->FlatAppearance->BorderSize = 0;
				 this->logoutBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->logoutBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->logoutBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoutBtn.Image")));
				 this->logoutBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->logoutBtn->Location = System::Drawing::Point(12, 624);
				 this->logoutBtn->Name = L"logoutBtn";
				 this->logoutBtn->Size = System::Drawing::Size(339, 85);
				 this->logoutBtn->TabIndex = 3;
				 this->logoutBtn->Text = L"LOGOUT        ";
				 this->logoutBtn->UseVisualStyleBackColor = true;
				 this->logoutBtn->Click += gcnew System::EventHandler(this, &AdminScreen::logoutBtn_Click);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
					 static_cast<System::Int32>(static_cast<System::Byte>(30)));
				 this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(18, 9);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(200, 28);
				 this->label1->TabIndex = 3;
				 this->label1->Text = L"ADMINISTRATION";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
					 static_cast<System::Int32>(static_cast<System::Byte>(30)));
				 this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(484, 9);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(152, 28);
				 this->label2->TabIndex = 8;
				 this->label2->Text = L"EMPLOYEES";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
					 static_cast<System::Int32>(static_cast<System::Byte>(30)));
				 this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(931, 9);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(144, 28);
				 this->label3->TabIndex = 9;
				 this->label3->Text = L"EQUIPMENT";
				 // 
				 // panel4
				 // 
				 this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->panel4->Controls->Add(this->stopVidBtn);
				 this->panel4->Controls->Add(this->viewRecBtn);
				 this->panel4->Location = System::Drawing::Point(469, 389);
				 this->panel4->Name = L"panel4";
				 this->panel4->Size = System::Drawing::Size(840, 177);
				 this->panel4->TabIndex = 10;
				 // 
				 // stopVidBtn
				 // 
				 this->stopVidBtn->FlatAppearance->BorderSize = 0;
				 this->stopVidBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->stopVidBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->stopVidBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stopVidBtn.Image")));
				 this->stopVidBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->stopVidBtn->Location = System::Drawing::Point(447, 49);
				 this->stopVidBtn->Name = L"stopVidBtn";
				 this->stopVidBtn->Size = System::Drawing::Size(386, 85);
				 this->stopVidBtn->TabIndex = 8;
				 this->stopVidBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->stopVidBtn->UseVisualStyleBackColor = true;
				 this->stopVidBtn->Click += gcnew System::EventHandler(this, &AdminScreen::stopVidBtn_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
					 static_cast<System::Int32>(static_cast<System::Byte>(30)));
				 this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label4->Location = System::Drawing::Point(484, 379);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(239, 28);
				 this->label4->TabIndex = 9;
				 this->label4->Text = L"VIDEO RECORDINGS";
				 // 
				 // AdminScreen
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->ClientSize = System::Drawing::Size(1344, 721);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->panel4);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->logoutBtn);
				 this->Controls->Add(this->panel3);
				 this->Controls->Add(this->panel2);
				 this->Controls->Add(this->panel1);
				 this->ForeColor = System::Drawing::Color::White;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MinimumSize = System::Drawing::Size(1350, 726);
				 this->Name = L"AdminScreen";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Records Administration";
				 this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				 this->Load += gcnew System::EventHandler(this, &AdminScreen::AdminScreen_Load);
				 this->panel1->ResumeLayout(false);
				 this->panel2->ResumeLayout(false);
				 this->panel3->ResumeLayout(false);
				 this->panel4->ResumeLayout(false);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

			 //=================================== ADDED CODE ==========================================================

			 /*Function called when screen loaded*/
	private: System::Void AdminScreen_Load(System::Object^  sender, System::EventArgs^  e) {
		this->Text += " - Logged in as " + adminUser->first_names;
		if (vidThreadAlive){
			if (stopVideo){				//If video recording has stopped, set button text to START VIDEO RECORDING
				this->stopVidBtn->Text = "START VIDEO RECORDING              ";
			}
			else{						//If video recording is active, set button text to STOP VIDEO RECORDING
				this->stopVidBtn->Text = "STOP VIDEO RECORDING              ";
			}
		}
		else{
			this->stopVidBtn->Visible = false;		//Disable button if the Video recording thread is inactive.
			this->stopVidBtn->Enabled = false;
		}
	}
	private: System::Void logoutBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~AdminScreen();
	}

			 /*Button used to delete the current Admin's information from the database*/
	private: System::Void delAdminBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Are you sure you want to delete Employee ID " + this->adminUser->employeeID->ToString() + " from the database?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
			deleteConfirmScreen^ check = gcnew deleteConfirmScreen();	//Screen used to get the Admin's password and confirm deletion of record
			check->ShowDialog();
			if (check->password == this->adminUser->password){			//If Admin has enetered the correct password, delete the record from the database.
				check->~deleteConfirmScreen();
				this->adminUser->del();
				this->~AdminScreen();
			}
			else{
				MessageBox::Show("Invalid Password!");
				check->~deleteConfirmScreen();
			}
		}
	}
			 /*Button calls the AddUserScreen to Add a new Admin user to the database*/
	private: System::Void newAdminBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		AddUserScreen^ ad = gcnew AddUserScreen("admin");
		ad->Show();
	}
			 /*Button calls the AddUserScreen to Add a new Employee user to the database*/
	private: System::Void addEmpBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		AddUserScreen^ ad = gcnew AddUserScreen("employee");
		ad->Show();
	}
			 /*Button calls the EquipScreen to Add new Equipment to the database*/
	private: System::Void addEqBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		EquipScreen^ newEquip = gcnew EquipScreen();
		newEquip->Show();
	}
			 /*Button calls the AddUserScreen to Update the record of the current Admin user*/
	private: System::Void editAdminBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		AddUserScreen^ updateAd = gcnew AddUserScreen(this->adminUser);
		updateAd->Show();
	}
			 /*Buttons calls the dispScreen to display the Employee records*/
	private: System::Void ViewEmpBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		dispScreen^ empView = gcnew dispScreen("employees");
		empView->Show();
	}
			 /*Button calls the dispScreen to display the Equipment records*/
	private: System::Void viewEqBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		dispScreen^ eqView = gcnew dispScreen("equip");
		eqView->Show();
	}
			 /*Button calls the VideoRecScreen to display and play all video recordings*/
	private: System::Void viewRecBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		VideoRecScreen^ ad = gcnew VideoRecScreen();
		ad->Show();
	}
			 /*Button stops or restarts video recording*/
	private: System::Void stopVidBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (vidThreadAlive){			//Check if the Video Recording thread is alive
			if (stopVideo){
				this->stopVidBtn->Text = "STOP VIDEO RECORDING              ";
				stopVideo = false;		//If the Video Recording has been stopped, change the flag to flase in order to restart the recording
				/*Change the button image*/
				System::ComponentModel::ComponentResourceManager^  res = (gcnew System::ComponentModel::ComponentResourceManager(AdminScreen::typeid));
				this->stopVidBtn->Image = (cli::safe_cast<System::Drawing::Image^>(res->GetObject(L"stopVidBtn.Image")));
			}
			else{
				/*Change the Button image*/
				System::ComponentModel::ComponentResourceManager^  res = (gcnew System::ComponentModel::ComponentResourceManager(AdminScreen::typeid));
				this->stopVidBtn->Image = (cli::safe_cast<System::Drawing::Image^>(res->GetObject(L"stopVidBtnNoRec.Image")));
				this->stopVidBtn->Text = "START VIDEO RECORDING              ";
				stopVideo = true;		//If video is recording, change the flag to stop recording
			}
		}
		else{
			this->stopVidBtn->Visible = false;		//If the Video recroing thread is not active, disable the button
			this->stopVidBtn->Enabled = false;
		}
	}

			 //=====================================================================================================
	};
}

#endif