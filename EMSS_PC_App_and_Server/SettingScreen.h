#include "DatabaseQueries.h"
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
	/// This screen is used to display and update the Application settings
	/// </summary>
	public ref class SettingScreen : public System::Windows::Forms::Form
	{
	public:
		SettingScreen(void){
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::NumericUpDown^  vidAgeTxt;
	private: System::Windows::Forms::NumericUpDown^  vidSizeTxt;
	private: System::Windows::Forms::NumericUpDown^  vidLengthTxt;
	private: System::Windows::Forms::NumericUpDown^  serverPortTxt;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  vidLengthLbl;
	private: System::Windows::Forms::Label^  serverPortLbl;
	private: System::Windows::Forms::Label^  etasIPLbl;
	private: System::Windows::Forms::Label^  settingsLbl;
	private: System::Windows::Forms::Label^  camIPLbl;
	private: System::Windows::Forms::Button^  closeBtn;
	private: System::Windows::Forms::Button^  saveBtn;
	private: System::Windows::Forms::TextBox^  cameraIPTxt;
	private: System::Windows::Forms::TextBox^  etasIPTxt;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  camPassTxt;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  camUserTxt;
	private: System::Windows::Forms::Label^  camUserLbl;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  cameraPortTxt;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingScreen::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cameraPortTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->camPassTxt = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->camUserTxt = (gcnew System::Windows::Forms::TextBox());
			this->camUserLbl = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->settingsLbl = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cameraIPTxt = (gcnew System::Windows::Forms::TextBox());
			this->etasIPTxt = (gcnew System::Windows::Forms::TextBox());
			this->vidAgeTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->vidSizeTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->vidLengthTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->serverPortTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->vidLengthLbl = (gcnew System::Windows::Forms::Label());
			this->serverPortLbl = (gcnew System::Windows::Forms::Label());
			this->etasIPLbl = (gcnew System::Windows::Forms::Label());
			this->camIPLbl = (gcnew System::Windows::Forms::Label());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraPortTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidAgeTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidSizeTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidLengthTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->serverPortTxt))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->cameraPortTxt);
			this->panel1->Controls->Add(this->camPassTxt);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->camUserTxt);
			this->panel1->Controls->Add(this->camUserLbl);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->settingsLbl);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->cameraIPTxt);
			this->panel1->Controls->Add(this->etasIPTxt);
			this->panel1->Controls->Add(this->vidAgeTxt);
			this->panel1->Controls->Add(this->vidSizeTxt);
			this->panel1->Controls->Add(this->vidLengthTxt);
			this->panel1->Controls->Add(this->serverPortTxt);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->vidLengthLbl);
			this->panel1->Controls->Add(this->serverPortLbl);
			this->panel1->Controls->Add(this->etasIPLbl);
			this->panel1->Controls->Add(this->camIPLbl);
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(593, 412);
			this->panel1->TabIndex = 0;
			// 
			// cameraPortTxt
			// 
			this->cameraPortTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cameraPortTxt->Location = System::Drawing::Point(390, 141);
			this->cameraPortTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65536, 0, 0, 0 });
			this->cameraPortTxt->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 80, 0, 0, 0 });
			this->cameraPortTxt->Name = L"cameraPortTxt";
			this->cameraPortTxt->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cameraPortTxt->Size = System::Drawing::Size(188, 23);
			this->cameraPortTxt->TabIndex = 36;
			this->cameraPortTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->cameraPortTxt->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 80, 0, 0, 0 });
			// 
			// camPassTxt
			// 
			this->camPassTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->camPassTxt->Location = System::Drawing::Point(390, 198);
			this->camPassTxt->Name = L"camPassTxt";
			this->camPassTxt->Size = System::Drawing::Size(188, 23);
			this->camPassTxt->TabIndex = 35;
			this->camPassTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(262, 201);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 17);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Camera Password";
			// 
			// camUserTxt
			// 
			this->camUserTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->camUserTxt->Location = System::Drawing::Point(390, 169);
			this->camUserTxt->Name = L"camUserTxt";
			this->camUserTxt->Size = System::Drawing::Size(188, 23);
			this->camUserTxt->TabIndex = 33;
			this->camUserTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// camUserLbl
			// 
			this->camUserLbl->AutoSize = true;
			this->camUserLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->camUserLbl->Location = System::Drawing::Point(258, 172);
			this->camUserLbl->Name = L"camUserLbl";
			this->camUserLbl->Size = System::Drawing::Size(126, 17);
			this->camUserLbl->TabIndex = 32;
			this->camUserLbl->Text = L"Camera Username";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(243, 143);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 17);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Camera Port Number";
			// 
			// settingsLbl
			// 
			this->settingsLbl->AutoSize = true;
			this->settingsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingsLbl->Location = System::Drawing::Point(2, -1);
			this->settingsLbl->Name = L"settingsLbl";
			this->settingsLbl->Size = System::Drawing::Size(120, 26);
			this->settingsLbl->TabIndex = 3;
			this->settingsLbl->Text = L"SETTINGS";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(504, 354);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 17);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Month(s)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(504, 322);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(28, 17);
			this->label4->TabIndex = 28;
			this->label4->Text = L"MB";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(504, 288);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 27;
			this->label1->Text = L"seconds";
			// 
			// cameraIPTxt
			// 
			this->cameraIPTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cameraIPTxt->Location = System::Drawing::Point(390, 111);
			this->cameraIPTxt->Name = L"cameraIPTxt";
			this->cameraIPTxt->Size = System::Drawing::Size(188, 23);
			this->cameraIPTxt->TabIndex = 26;
			this->cameraIPTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// etasIPTxt
			// 
			this->etasIPTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->etasIPTxt->Location = System::Drawing::Point(390, 64);
			this->etasIPTxt->Name = L"etasIPTxt";
			this->etasIPTxt->Size = System::Drawing::Size(188, 23);
			this->etasIPTxt->TabIndex = 25;
			this->etasIPTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// vidAgeTxt
			// 
			this->vidAgeTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vidAgeTxt->Location = System::Drawing::Point(390, 352);
			this->vidAgeTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 24, 0, 0, 0 });
			this->vidAgeTxt->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->vidAgeTxt->Name = L"vidAgeTxt";
			this->vidAgeTxt->Size = System::Drawing::Size(108, 23);
			this->vidAgeTxt->TabIndex = 24;
			this->vidAgeTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->vidAgeTxt->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// vidSizeTxt
			// 
			this->vidSizeTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vidSizeTxt->Location = System::Drawing::Point(390, 320);
			this->vidSizeTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->vidSizeTxt->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->vidSizeTxt->Name = L"vidSizeTxt";
			this->vidSizeTxt->Size = System::Drawing::Size(108, 23);
			this->vidSizeTxt->TabIndex = 23;
			this->vidSizeTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->vidSizeTxt->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// vidLengthTxt
			// 
			this->vidLengthTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vidLengthTxt->Location = System::Drawing::Point(390, 286);
			this->vidLengthTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 14400, 0, 0, 0 });
			this->vidLengthTxt->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->vidLengthTxt->Name = L"vidLengthTxt";
			this->vidLengthTxt->Size = System::Drawing::Size(108, 23);
			this->vidLengthTxt->TabIndex = 22;
			this->vidLengthTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->vidLengthTxt->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// serverPortTxt
			// 
			this->serverPortTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->serverPortTxt->Location = System::Drawing::Point(390, 251);
			this->serverPortTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65536, 0, 0, 0 });
			this->serverPortTxt->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 80, 0, 0, 0 });
			this->serverPortTxt->Name = L"serverPortTxt";
			this->serverPortTxt->Size = System::Drawing::Size(108, 23);
			this->serverPortTxt->TabIndex = 21;
			this->serverPortTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->serverPortTxt->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 80, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(98, 354);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(286, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Delete Video Recordings that are older than";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(171, 322);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(213, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Video Recordings Maximum Size";
			// 
			// vidLengthLbl
			// 
			this->vidLengthLbl->AutoSize = true;
			this->vidLengthLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vidLengthLbl->Location = System::Drawing::Point(216, 288);
			this->vidLengthLbl->Name = L"vidLengthLbl";
			this->vidLengthLbl->Size = System::Drawing::Size(168, 17);
			this->vidLengthLbl->TabIndex = 6;
			this->vidLengthLbl->Text = L"Video Recordings Length";
			// 
			// serverPortLbl
			// 
			this->serverPortLbl->AutoSize = true;
			this->serverPortLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->serverPortLbl->Location = System::Drawing::Point(250, 253);
			this->serverPortLbl->Name = L"serverPortLbl";
			this->serverPortLbl->Size = System::Drawing::Size(134, 17);
			this->serverPortLbl->TabIndex = 5;
			this->serverPortLbl->Text = L"Server Port Number";
			// 
			// etasIPLbl
			// 
			this->etasIPLbl->AutoSize = true;
			this->etasIPLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->etasIPLbl->Location = System::Drawing::Point(9, 67);
			this->etasIPLbl->Name = L"etasIPLbl";
			this->etasIPLbl->Size = System::Drawing::Size(375, 17);
			this->etasIPLbl->TabIndex = 4;
			this->etasIPLbl->Text = L"Equipment Tagging and Authorizations System IP Address";
			// 
			// camIPLbl
			// 
			this->camIPLbl->AutoSize = true;
			this->camIPLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->camIPLbl->Location = System::Drawing::Point(255, 114);
			this->camIPLbl->Name = L"camIPLbl";
			this->camIPLbl->Size = System::Drawing::Size(129, 17);
			this->camIPLbl->TabIndex = 2;
			this->camIPLbl->Text = L"Camera IP Address";
			// 
			// closeBtn
			// 
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->closeBtn->Location = System::Drawing::Point(13, 431);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(133, 50);
			this->closeBtn->TabIndex = 1;
			this->closeBtn->Text = L"DISCARD";
			this->closeBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &SettingScreen::closeBtn_Click);
			// 
			// saveBtn
			// 
			this->saveBtn->FlatAppearance->BorderSize = 0;
			this->saveBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveBtn.Image")));
			this->saveBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->saveBtn->Location = System::Drawing::Point(489, 431);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(117, 50);
			this->saveBtn->TabIndex = 2;
			this->saveBtn->Text = L"SAVE";
			this->saveBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->saveBtn->UseVisualStyleBackColor = true;
			this->saveBtn->Click += gcnew System::EventHandler(this, &SettingScreen::saveBtn_Click);
			// 
			// SettingScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ClientSize = System::Drawing::Size(618, 493);
			this->Controls->Add(this->saveBtn);
			this->Controls->Add(this->closeBtn);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SettingScreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &SettingScreen::SettingScreen_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraPortTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidAgeTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidSizeTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidLengthTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->serverPortTxt))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		/*Function executes when screen is loaded*/
	private: System::Void SettingScreen_Load(System::Object^  sender, System::EventArgs^  e) {
		MySqlConnection^ conDataBase;
		try{
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			//Reads the Settings from the Database
			MySqlCommand^ readSQL = gcnew MySqlCommand("SELECT * FROM `emss_database`.`settings` WHERE `settings`.`settings_id` = 1;", conDataBase);
			MySqlDataReader^ reader = readSQL->ExecuteReader();
			if (reader->Read()){
				System::String^ camIP = reader->GetString("camera_ip");	//Reads the Camera IP
				int start = camIP->LastIndexOf('@');					//Finds the index of '@'. If not found, it means there is no password. Returns 0
				if (start < 1)
					start = 6;											//start after "http://"
				this->vidLengthTxt->Value = reader->GetInt32("video_length_s");
				this->vidSizeTxt->Value = reader->GetInt32("video_max_size_m");
				this->vidAgeTxt->Value = reader->GetInt32("video_age_m");
				this->cameraIPTxt->Text = camIP->Substring(start + 1, camIP->LastIndexOf(':') - start - 1);	//Extracts the camera IP address
				start = camIP->LastIndexOf(':');															//Finds where the port number starts
				this->cameraPortTxt->Value = Int32::Parse(camIP->Substring(start + 1, camIP->LastIndexOf('/') - start - 1));	//Extracts the camera port number
				this->etasIPTxt->Text = reader->GetString("etas_ip");
				this->serverPortTxt->Value = reader->GetInt32("server_port");
			}
			else{
				MessageBox::Show("Cannot read custom settings.");
			}
			reader->Close();
			conDataBase->Close();
		}
		catch (System::Exception^ ex){
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void closeBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Are you sure you want to DISCARD changes?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
			this->~SettingScreen();
		}
	}
			 /*Function saves the settings to the database*/
	private: System::Void saveBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (checkIP(this->cameraIPTxt->Text)){		//Check if valid IPs are entered
			if (checkIP(this->etasIPTxt->Text)){
				System::String^ camconn;
				if (this->camPassTxt->Text == "")		//Check if password is set
					camconn = "tcp://" + this->cameraIPTxt->Text + ":" + this->cameraPortTxt->Value + "/video?x.mjpeg";
				else									//If password set, save camera IP accordingly
					camconn = "tcp://" + this->camUserTxt->Text + ":" + this->camPassTxt->Text + "@" + this->cameraIPTxt->Text + ":" + this->cameraPortTxt->Text + "/video?x.mjpeg";

				DatabaseQueries^ msql = gcnew DatabaseQueries();
				if (msql->setQuery("UPDATE `emss_database`.`settings` SET `video_length_s` = '" + this->vidLengthTxt->Value + "', `video_max_size_m`='" + this->vidSizeTxt->Value + "', `video_age_m`='" + this->vidAgeTxt->Value + "', `camera_ip`='" + camconn + "', `etas_ip`='" + this->etasIPTxt->Text + "', `server_port`='" + this->serverPortTxt->Value + "' WHERE `settings_id`='1';")){
					MessageBox::Show("Settings Updated. Restart System for changes to take effect.");
					this->~SettingScreen();
				}
			}
			else{
				MessageBox::Show("Invalid Equipment Tagging and Authorization System IP Address");
			}
		}
		else{
			MessageBox::Show("Invalid Camera IP Address");
		}
	}
			 /*Receives and validates if text is an IP address */
	private: bool checkIP(System::String^ ipText){
		for (int i = 0; i < 3; i++){
			try{
				System::String^ checkStr = ipText->Substring(0, ipText->IndexOf("."));	//Extract number 
				int num = Int32::Parse(checkStr);
				if (num < 0 || num > 255)					//Check if extracted number is between 0 and 255
					return false;
			}
			catch (System::Exception^ ex){
				return false;
			}
			ipText = ipText->Substring(ipText->IndexOf(".") + 1);	//Remove the extracted number from the text
		}
		try{
			int num = Int32::Parse(ipText);					//Check the last number
			if (num < 0 || num > 255)
				return false;
		}
		catch (System::Exception^ ex){
			return false;
		}
		return true;
	}
	};
}
