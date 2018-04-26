#ifndef ADDUSER_H_
#define ADDUSER_H_
#include "Employee.h"
#include "Admin.h"

namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// This screen is used when Adding or Updating an Administrator's record on the database.
	/// </summary>
	public ref class AddUserScreen : public System::Windows::Forms::Form{
	public:
		/*Default Constructor*/
		AddUserScreen(){
		}
		/*Constructor when updating an Admin User*/
		AddUserScreen(Admin^ ad){
			this->operationType = "update";
			this->userType = "admin";
			this->thisAd = ad;
			InitializeComponent();
		}
		/*Constructor when updating an Employee User*/
		AddUserScreen(Employee^ em){
			this->operationType = "update";
			this->userType = "employee";
			this->thisEmp = em;
			InitializeComponent();
		}
		/*Constructor when adding an Admin or Employee User*/
		AddUserScreen(System::String^ uType){
			this->operationType = "add";
			this->userType = uType;
			InitializeComponent();
		}

	protected:
		~AddUserScreen(){
			if (components)
				delete components;
			if (this->thisAd)
				this->thisAd->~Admin();
			if (this->thisEmp)
				this->thisEmp->~Employee();
		}
	private: System::String^ userType;		//Stores the type of user. Either Employee or Admin
			 System::String^ operationType;	//Stores the type of operation to be performed on the user. Either Add or Update
			 Admin^ thisAd;					//Admin Object to store Admin user details
			 Employee^ thisEmp;				//Employee Object to store Employee user details
	private: System::Windows::Forms::Label^  empIDlbl;
	private: System::Windows::Forms::TextBox^  empIDtxt;
	private: System::Windows::Forms::TextBox^  pinTxt;
	private: System::Windows::Forms::Label^  pinLbl;
	private: System::Windows::Forms::TextBox^  fnameTxt;
	private: System::Windows::Forms::Label^  fnameLbl;
	private: System::Windows::Forms::TextBox^  snameTxt;
	private: System::Windows::Forms::Label^  snameLbl;
	private: System::Windows::Forms::TextBox^  dobTxt;
	private: System::Windows::Forms::Label^  dobLbl;
	private: System::Windows::Forms::Label^  pAddLbl;
	private: System::Windows::Forms::TextBox^  eAddTxt;
	private: System::Windows::Forms::Label^  eAddLbl;
	private: System::Windows::Forms::TextBox^  phoneTxt;
	private: System::Windows::Forms::Label^  phoneLbl;
	private: System::Windows::Forms::TextBox^  posTxt;
	private: System::Windows::Forms::Label^  posLbl;
	private: System::Windows::Forms::Panel^  detPanel;
	private: System::Windows::Forms::Label^  conPinLbl;
	private: System::Windows::Forms::TextBox^  conPinTxt;
	private: System::Windows::Forms::Panel^  passPanel;
	private: System::Windows::Forms::Label^  conPassLbl;
	private: System::Windows::Forms::TextBox^  conPassTxt;
	private: System::Windows::Forms::Label^  passLbl;
	private: System::Windows::Forms::TextBox^  passTxt;
	private: System::Windows::Forms::Panel^  det2Panel;
	private: System::Windows::Forms::RichTextBox^  pAddTxt;
	private: System::Windows::Forms::Button^  backBtn;
	private: System::Windows::Forms::Button^  addBtn;
	private: System::Windows::Forms::Label^  pinNoticeLbl;
	private: System::Windows::Forms::Label^  passNoticeLbl;
	private: System::ComponentModel::Container ^components;
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
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddUserScreen::typeid));
				 this->empIDlbl = (gcnew System::Windows::Forms::Label());
				 this->empIDtxt = (gcnew System::Windows::Forms::TextBox());
				 this->pinTxt = (gcnew System::Windows::Forms::TextBox());
				 this->pinLbl = (gcnew System::Windows::Forms::Label());
				 this->fnameTxt = (gcnew System::Windows::Forms::TextBox());
				 this->fnameLbl = (gcnew System::Windows::Forms::Label());
				 this->snameTxt = (gcnew System::Windows::Forms::TextBox());
				 this->snameLbl = (gcnew System::Windows::Forms::Label());
				 this->dobTxt = (gcnew System::Windows::Forms::TextBox());
				 this->dobLbl = (gcnew System::Windows::Forms::Label());
				 this->pAddLbl = (gcnew System::Windows::Forms::Label());
				 this->eAddTxt = (gcnew System::Windows::Forms::TextBox());
				 this->eAddLbl = (gcnew System::Windows::Forms::Label());
				 this->phoneTxt = (gcnew System::Windows::Forms::TextBox());
				 this->phoneLbl = (gcnew System::Windows::Forms::Label());
				 this->posTxt = (gcnew System::Windows::Forms::TextBox());
				 this->posLbl = (gcnew System::Windows::Forms::Label());
				 this->detPanel = (gcnew System::Windows::Forms::Panel());
				 this->conPinLbl = (gcnew System::Windows::Forms::Label());
				 this->conPinTxt = (gcnew System::Windows::Forms::TextBox());
				 this->passPanel = (gcnew System::Windows::Forms::Panel());
				 this->conPassLbl = (gcnew System::Windows::Forms::Label());
				 this->conPassTxt = (gcnew System::Windows::Forms::TextBox());
				 this->passLbl = (gcnew System::Windows::Forms::Label());
				 this->passTxt = (gcnew System::Windows::Forms::TextBox());
				 this->det2Panel = (gcnew System::Windows::Forms::Panel());
				 this->pAddTxt = (gcnew System::Windows::Forms::RichTextBox());
				 this->backBtn = (gcnew System::Windows::Forms::Button());
				 this->addBtn = (gcnew System::Windows::Forms::Button());
				 this->pinNoticeLbl = (gcnew System::Windows::Forms::Label());
				 this->passNoticeLbl = (gcnew System::Windows::Forms::Label());
				 this->detPanel->SuspendLayout();
				 this->passPanel->SuspendLayout();
				 this->det2Panel->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // empIDlbl
				 // 
				 this->empIDlbl->AutoSize = true;
				 this->empIDlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->empIDlbl->Location = System::Drawing::Point(101, 12);
				 this->empIDlbl->Name = L"empIDlbl";
				 this->empIDlbl->Size = System::Drawing::Size(96, 17);
				 this->empIDlbl->TabIndex = 0;
				 this->empIDlbl->Text = L"Employee ID *";
				 // 
				 // empIDtxt
				 // 
				 this->empIDtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->empIDtxt->Location = System::Drawing::Point(206, 9);
				 this->empIDtxt->Name = L"empIDtxt";
				 this->empIDtxt->Size = System::Drawing::Size(254, 23);
				 this->empIDtxt->TabIndex = 1;
				 // 
				 // pinTxt
				 // 
				 this->pinTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->pinTxt->Location = System::Drawing::Point(206, 44);
				 this->pinTxt->Name = L"pinTxt";
				 this->pinTxt->Size = System::Drawing::Size(254, 23);
				 this->pinTxt->TabIndex = 3;
				 this->pinTxt->UseSystemPasswordChar = true;
				 // 
				 // pinLbl
				 // 
				 this->pinLbl->AutoSize = true;
				 this->pinLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->pinLbl->Location = System::Drawing::Point(158, 47);
				 this->pinLbl->Name = L"pinLbl";
				 this->pinLbl->Size = System::Drawing::Size(39, 17);
				 this->pinLbl->TabIndex = 2;
				 this->pinLbl->Text = L"PIN *";
				 // 
				 // fnameTxt
				 // 
				 this->fnameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->fnameTxt->Location = System::Drawing::Point(206, 120);
				 this->fnameTxt->Name = L"fnameTxt";
				 this->fnameTxt->Size = System::Drawing::Size(254, 23);
				 this->fnameTxt->TabIndex = 5;
				 // 
				 // fnameLbl
				 // 
				 this->fnameLbl->AutoSize = true;
				 this->fnameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->fnameLbl->Location = System::Drawing::Point(105, 123);
				 this->fnameLbl->Name = L"fnameLbl";
				 this->fnameLbl->Size = System::Drawing::Size(92, 17);
				 this->fnameLbl->TabIndex = 4;
				 this->fnameLbl->Text = L"First Names *";
				 // 
				 // snameTxt
				 // 
				 this->snameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->snameTxt->Location = System::Drawing::Point(206, 159);
				 this->snameTxt->Name = L"snameTxt";
				 this->snameTxt->Size = System::Drawing::Size(254, 23);
				 this->snameTxt->TabIndex = 7;
				 // 
				 // snameLbl
				 // 
				 this->snameLbl->AutoSize = true;
				 this->snameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->snameLbl->Location = System::Drawing::Point(123, 162);
				 this->snameLbl->Name = L"snameLbl";
				 this->snameLbl->Size = System::Drawing::Size(74, 17);
				 this->snameLbl->TabIndex = 6;
				 this->snameLbl->Text = L"Surname *";
				 // 
				 // dobTxt
				 // 
				 this->dobTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->dobTxt->Location = System::Drawing::Point(206, 196);
				 this->dobTxt->Name = L"dobTxt";
				 this->dobTxt->Size = System::Drawing::Size(254, 23);
				 this->dobTxt->TabIndex = 9;
				 // 
				 // dobLbl
				 // 
				 this->dobLbl->AutoSize = true;
				 this->dobLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->dobLbl->Location = System::Drawing::Point(-1, 199);
				 this->dobLbl->Name = L"dobLbl";
				 this->dobLbl->Size = System::Drawing::Size(198, 17);
				 this->dobLbl->TabIndex = 8;
				 this->dobLbl->Text = L"Date of Birth (YYYY-MM-DD) *";
				 // 
				 // pAddLbl
				 // 
				 this->pAddLbl->AutoSize = true;
				 this->pAddLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->pAddLbl->Location = System::Drawing::Point(15, 17);
				 this->pAddLbl->Name = L"pAddLbl";
				 this->pAddLbl->Size = System::Drawing::Size(116, 17);
				 this->pAddLbl->TabIndex = 10;
				 this->pAddLbl->Text = L"Physical Address";
				 // 
				 // eAddTxt
				 // 
				 this->eAddTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eAddTxt->Location = System::Drawing::Point(137, 90);
				 this->eAddTxt->Name = L"eAddTxt";
				 this->eAddTxt->Size = System::Drawing::Size(267, 23);
				 this->eAddTxt->TabIndex = 13;
				 // 
				 // eAddLbl
				 // 
				 this->eAddLbl->AutoSize = true;
				 this->eAddLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eAddLbl->Location = System::Drawing::Point(33, 93);
				 this->eAddLbl->Name = L"eAddLbl";
				 this->eAddLbl->Size = System::Drawing::Size(98, 17);
				 this->eAddLbl->TabIndex = 12;
				 this->eAddLbl->Text = L"Email Address";
				 // 
				 // phoneTxt
				 // 
				 this->phoneTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->phoneTxt->Location = System::Drawing::Point(137, 129);
				 this->phoneTxt->Name = L"phoneTxt";
				 this->phoneTxt->Size = System::Drawing::Size(267, 23);
				 this->phoneTxt->TabIndex = 15;
				 // 
				 // phoneLbl
				 // 
				 this->phoneLbl->AutoSize = true;
				 this->phoneLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->phoneLbl->Location = System::Drawing::Point(19, 132);
				 this->phoneLbl->Name = L"phoneLbl";
				 this->phoneLbl->Size = System::Drawing::Size(112, 17);
				 this->phoneLbl->TabIndex = 14;
				 this->phoneLbl->Text = L"Phone Number *";
				 // 
				 // posTxt
				 // 
				 this->posTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->posTxt->Location = System::Drawing::Point(206, 233);
				 this->posTxt->Name = L"posTxt";
				 this->posTxt->Size = System::Drawing::Size(254, 23);
				 this->posTxt->TabIndex = 17;
				 // 
				 // posLbl
				 // 
				 this->posLbl->AutoSize = true;
				 this->posLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->posLbl->Location = System::Drawing::Point(139, 236);
				 this->posLbl->Name = L"posLbl";
				 this->posLbl->Size = System::Drawing::Size(58, 17);
				 this->posLbl->TabIndex = 16;
				 this->posLbl->Text = L"Position";
				 // 
				 // detPanel
				 // 
				 this->detPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->detPanel->Controls->Add(this->conPinLbl);
				 this->detPanel->Controls->Add(this->conPinTxt);
				 this->detPanel->Controls->Add(this->empIDlbl);
				 this->detPanel->Controls->Add(this->posTxt);
				 this->detPanel->Controls->Add(this->empIDtxt);
				 this->detPanel->Controls->Add(this->pinLbl);
				 this->detPanel->Controls->Add(this->posLbl);
				 this->detPanel->Controls->Add(this->pinTxt);
				 this->detPanel->Controls->Add(this->fnameLbl);
				 this->detPanel->Controls->Add(this->fnameTxt);
				 this->detPanel->Controls->Add(this->snameLbl);
				 this->detPanel->Controls->Add(this->snameTxt);
				 this->detPanel->Controls->Add(this->dobLbl);
				 this->detPanel->Controls->Add(this->dobTxt);
				 this->detPanel->Location = System::Drawing::Point(12, 12);
				 this->detPanel->Name = L"detPanel";
				 this->detPanel->Size = System::Drawing::Size(465, 295);
				 this->detPanel->TabIndex = 18;
				 // 
				 // conPinLbl
				 // 
				 this->conPinLbl->AutoSize = true;
				 this->conPinLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->conPinLbl->Location = System::Drawing::Point(106, 85);
				 this->conPinLbl->Name = L"conPinLbl";
				 this->conPinLbl->Size = System::Drawing::Size(91, 17);
				 this->conPinLbl->TabIndex = 18;
				 this->conPinLbl->Text = L"Confirm PIN *";
				 // 
				 // conPinTxt
				 // 
				 this->conPinTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->conPinTxt->Location = System::Drawing::Point(206, 82);
				 this->conPinTxt->Name = L"conPinTxt";
				 this->conPinTxt->Size = System::Drawing::Size(254, 23);
				 this->conPinTxt->TabIndex = 19;
				 this->conPinTxt->UseSystemPasswordChar = true;
				 // 
				 // passPanel
				 // 
				 this->passPanel->Controls->Add(this->conPassLbl);
				 this->passPanel->Controls->Add(this->conPassTxt);
				 this->passPanel->Controls->Add(this->passLbl);
				 this->passPanel->Controls->Add(this->passTxt);
				 this->passPanel->Location = System::Drawing::Point(483, 12);
				 this->passPanel->Name = L"passPanel";
				 this->passPanel->Size = System::Drawing::Size(415, 97);
				 this->passPanel->TabIndex = 19;
				 // 
				 // conPassLbl
				 // 
				 this->conPassLbl->AutoSize = true;
				 this->conPassLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->conPassLbl->Location = System::Drawing::Point(2, 46);
				 this->conPassLbl->Name = L"conPassLbl";
				 this->conPassLbl->Size = System::Drawing::Size(130, 17);
				 this->conPassLbl->TabIndex = 22;
				 this->conPassLbl->Text = L"Confirm Password *";
				 // 
				 // conPassTxt
				 // 
				 this->conPassTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->conPassTxt->Location = System::Drawing::Point(138, 43);
				 this->conPassTxt->Name = L"conPassTxt";
				 this->conPassTxt->Size = System::Drawing::Size(267, 23);
				 this->conPassTxt->TabIndex = 23;
				 this->conPassTxt->UseSystemPasswordChar = true;
				 // 
				 // passLbl
				 // 
				 this->passLbl->AutoSize = true;
				 this->passLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->passLbl->Location = System::Drawing::Point(54, 13);
				 this->passLbl->Name = L"passLbl";
				 this->passLbl->Size = System::Drawing::Size(78, 17);
				 this->passLbl->TabIndex = 20;
				 this->passLbl->Text = L"Password *";
				 // 
				 // passTxt
				 // 
				 this->passTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->passTxt->Location = System::Drawing::Point(138, 10);
				 this->passTxt->Name = L"passTxt";
				 this->passTxt->Size = System::Drawing::Size(267, 23);
				 this->passTxt->TabIndex = 21;
				 this->passTxt->UseSystemPasswordChar = true;
				 // 
				 // det2Panel
				 // 
				 this->det2Panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->det2Panel->Controls->Add(this->pAddTxt);
				 this->det2Panel->Controls->Add(this->pAddLbl);
				 this->det2Panel->Controls->Add(this->eAddLbl);
				 this->det2Panel->Controls->Add(this->eAddTxt);
				 this->det2Panel->Controls->Add(this->phoneLbl);
				 this->det2Panel->Controls->Add(this->phoneTxt);
				 this->det2Panel->Location = System::Drawing::Point(483, 118);
				 this->det2Panel->Name = L"det2Panel";
				 this->det2Panel->Size = System::Drawing::Size(415, 190);
				 this->det2Panel->TabIndex = 20;
				 // 
				 // pAddTxt
				 // 
				 this->pAddTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pAddTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->pAddTxt->Location = System::Drawing::Point(137, 14);
				 this->pAddTxt->Name = L"pAddTxt";
				 this->pAddTxt->Size = System::Drawing::Size(267, 59);
				 this->pAddTxt->TabIndex = 16;
				 this->pAddTxt->Text = L"";
				 // 
				 // backBtn
				 // 
				 this->backBtn->FlatAppearance->BorderSize = 0;
				 this->backBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->backBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backBtn.Image")));
				 this->backBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->backBtn->Location = System::Drawing::Point(12, 327);
				 this->backBtn->Name = L"backBtn";
				 this->backBtn->Size = System::Drawing::Size(149, 50);
				 this->backBtn->TabIndex = 21;
				 this->backBtn->Text = L"BACK";
				 this->backBtn->UseVisualStyleBackColor = true;
				 this->backBtn->Click += gcnew System::EventHandler(this, &AddUserScreen::backBtn_Click);
				 // 
				 // addBtn
				 // 
				 this->addBtn->FlatAppearance->BorderSize = 0;
				 this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->addBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addBtn.Image")));
				 this->addBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->addBtn->Location = System::Drawing::Point(613, 327);
				 this->addBtn->Name = L"addBtn";
				 this->addBtn->Size = System::Drawing::Size(285, 50);
				 this->addBtn->TabIndex = 22;
				 this->addBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->addBtn->UseVisualStyleBackColor = true;
				 this->addBtn->Click += gcnew System::EventHandler(this, &AddUserScreen::addBtn_Click);
				 // 
				 // pinNoticeLbl
				 // 
				 this->pinNoticeLbl->AutoSize = true;
				 this->pinNoticeLbl->Location = System::Drawing::Point(216, 327);
				 this->pinNoticeLbl->Name = L"pinNoticeLbl";
				 this->pinNoticeLbl->Size = System::Drawing::Size(261, 13);
				 this->pinNoticeLbl->TabIndex = 23;
				 this->pinNoticeLbl->Text = L"NOTE: Enter old PIN if you do NOT wish to change it.";
				 // 
				 // passNoticeLbl
				 // 
				 this->passNoticeLbl->AutoSize = true;
				 this->passNoticeLbl->Location = System::Drawing::Point(216, 344);
				 this->passNoticeLbl->Name = L"passNoticeLbl";
				 this->passNoticeLbl->Size = System::Drawing::Size(289, 13);
				 this->passNoticeLbl->TabIndex = 24;
				 this->passNoticeLbl->Text = L"NOTE: Enter old Password if you do NOT wish to change it.";
				 // 
				 // AddUserScreen
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->ClientSize = System::Drawing::Size(910, 389);
				 this->Controls->Add(this->passNoticeLbl);
				 this->Controls->Add(this->pinNoticeLbl);
				 this->Controls->Add(this->addBtn);
				 this->Controls->Add(this->backBtn);
				 this->Controls->Add(this->det2Panel);
				 this->Controls->Add(this->passPanel);
				 this->Controls->Add(this->detPanel);
				 this->ForeColor = System::Drawing::Color::White;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximizeBox = false;
				 this->Name = L"AddUserScreen";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Load += gcnew System::EventHandler(this, &AddUserScreen::AddUserScreen_Load);
				 this->detPanel->ResumeLayout(false);
				 this->detPanel->PerformLayout();
				 this->passPanel->ResumeLayout(false);
				 this->passPanel->PerformLayout();
				 this->det2Panel->ResumeLayout(false);
				 this->det2Panel->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

			 //======================================== ADDED CODE ============================================================
			 /*Function called when screen loaded*/
	private: System::Void AddUserScreen_Load(System::Object^  sender, System::EventArgs^  e){
		if (this->operationType == "add"){
			this->passNoticeLbl->Enabled = false;				//When operation type is Add, hide the notices
			this->passNoticeLbl->Visible = false;
			this->pinNoticeLbl->Enabled = false;
			this->pinNoticeLbl->Visible = false;
			if (userType == "admin"){
				this->Text = "Add new Administrator record";
				this->addBtn->Text = "ADD NEW ADMINISTRATOR";
			}
			else if (userType == "employee"){
				this->Text = "Add new Employee record";
				this->addBtn->Text = "ADD NEW EMPLOYEE     ";
				this->passPanel->Visible = false;				//When Employee user, hide the password fields as it is not needed
				this->passPanel->Enabled = false;
			}
			else{
				System::Windows::Forms::MessageBox::Show("INVALID CALL TO SCREEN!");
				this->~AddUserScreen();
			}
		}
		else if (operationType == "update"){
			if (userType == "admin"){
				this->Text = "Update Administrator record";
				this->addBtn->Text = "UPDATE ADMINISTRATOR ";
				this->empIDtxt->Text = this->thisAd->employeeID->ToString();		//Load information from Admin Object
				this->fnameTxt->Text = this->thisAd->first_names;
				this->snameTxt->Text = this->thisAd->surname;
				this->dobTxt->Text = this->thisAd->date_of_birth;
				this->pAddTxt->Text = this->thisAd->physical_address;
				this->eAddTxt->Text = this->thisAd->email_address;
				this->phoneTxt->Text = this->thisAd->phone_number;
				this->posTxt->Text = this->thisAd->position;
			}
			else if (userType == "employee"){
				this->Text = "Update Employee record";
				this->addBtn->Text = "UPDATE EMPLOYEE      ";
				this->passPanel->Visible = false;									//Hide the password fields when employee user
				this->passPanel->Enabled = false;
				this->passNoticeLbl->Enabled = false;
				this->passNoticeLbl->Visible = false;
				this->empIDtxt->Text = this->thisEmp->employeeID->ToString();		//Load information from Employee object
				this->fnameTxt->Text = this->thisEmp->first_names;					//Display information on respective fields
				this->snameTxt->Text = this->thisEmp->surname;
				this->dobTxt->Text = this->thisEmp->date_of_birth;
				this->pAddTxt->Text = this->thisEmp->physical_address;
				this->eAddTxt->Text = this->thisEmp->email_address;
				this->phoneTxt->Text = this->thisEmp->phone_number;
				this->posTxt->Text = this->thisEmp->position;
			}
			else{
				System::Windows::Forms::MessageBox::Show("INVALID CALL TO SCREEN!");
				this->~AddUserScreen();
			}
		}
		else{
			MessageBox::Show("Invalid call to screen.");
			this->~AddUserScreen();
		}
	}

	private: System::Void backBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~AddUserScreen();
	}

			 /*When clicked, either Add an Admin or Employee or Update an Admin or Employee*/
	private: System::Void addBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (userType == "admin"){
			this->passLbl->ForeColor = System::Drawing::Color::White;		//Sets password and PIN labels to White font
			this->conPassLbl->ForeColor = System::Drawing::Color::White;
			this->pinLbl->ForeColor = System::Drawing::Color::White;
			this->conPinLbl->ForeColor = System::Drawing::Color::White;

			/*Check is all mandatory fields contain data*/
			if (this->empIDtxt->Text != "" && this->passTxt->Text != "" && this->pinTxt->Text != "" && this->fnameTxt->Text != "" && this->snameTxt->Text != "" && this->dobTxt->Text != "" && this->phoneTxt->Text != ""){
				if (this->pinTxt->Text == this->conPinTxt->Text){			//Check if PINs are the same
					if (this->passTxt->Text == this->conPassTxt->Text){		//Check if passwords are the same
						if (operationType == "add"){
							Admin^ newAd = gcnew Admin();
							//Adds a new Admin user to the database. Returns true if succeeded.
							if (newAd->addUser(Int32::Parse(this->empIDtxt->Text), this->passTxt->Text, Int32::Parse(this->pinTxt->Text), this->fnameTxt->Text, this->snameTxt->Text, this->dobTxt->Text, this->pAddTxt->Text, this->eAddTxt->Text, this->phoneTxt->Text, this->posTxt->Text)){
								newAd->~Admin();
								this->~AddUserScreen();
							}
						}
						else if (operationType == "update"){
							//Updates an existing Admin user on the database. Returns true if succeeded.
							if (thisAd->update(Int32::Parse(this->empIDtxt->Text), this->passTxt->Text, Int32::Parse(this->pinTxt->Text), this->fnameTxt->Text, this->snameTxt->Text, this->dobTxt->Text, this->pAddTxt->Text, this->eAddTxt->Text, this->phoneTxt->Text, this->posTxt->Text)){
								this->~AddUserScreen();
							}
						}
					}
					else{
						MessageBox::Show("Passwords do not match.");				//Passwords do not match. Indicate by turning the password labels font RED
						this->passLbl->ForeColor = System::Drawing::Color::Red;
						this->conPassLbl->ForeColor = System::Drawing::Color::Red;
					}
				}
				else{
					MessageBox::Show("PIN numbers do not match.");					//PINs do not match. Indicate by turning the PIN labels font RED
					this->pinLbl->ForeColor = System::Drawing::Color::Red;
					this->conPinLbl->ForeColor = System::Drawing::Color::Red;
				}
			}
			else{
				MessageBox::Show("Please fill in all mandatory fields.");
			}
		}
		else if (userType == "employee"){
			this->pinLbl->ForeColor = System::Drawing::Color::White;		//Changes PIN labels font to white
			this->conPinLbl->ForeColor = System::Drawing::Color::White;
			/*Check is all mandatory fields contain data*/
			if (this->empIDtxt->Text != "" && this->pinTxt->Text != "" && this->fnameTxt->Text != "" && this->snameTxt->Text != "" && this->dobTxt->Text != "" && this->phoneTxt->Text != ""){
				if (this->pinTxt->Text == this->conPinTxt->Text){
					if (operationType == "add"){
						Employee^ newEM = gcnew Employee();
						//Add a new Employee user to the database. Returns true if succeeded.
						if (newEM->addUser(Int32::Parse(this->empIDtxt->Text), Int32::Parse(this->pinTxt->Text), this->fnameTxt->Text, this->snameTxt->Text, this->dobTxt->Text, this->pAddTxt->Text, this->eAddTxt->Text, this->phoneTxt->Text, this->posTxt->Text)){
							newEM->~Employee();
							this->~AddUserScreen();
						}
					}
					else if (operationType == "update"){
						//Updates an existing Employee user on the database. Returns true if succeeded.
						if (thisEmp->update(Int32::Parse(this->empIDtxt->Text), Int32::Parse(this->pinTxt->Text), this->fnameTxt->Text, this->snameTxt->Text, this->dobTxt->Text, this->pAddTxt->Text, this->eAddTxt->Text, this->phoneTxt->Text, this->posTxt->Text)){
							this->~AddUserScreen();
						}
					}
				}
				else{
					MessageBox::Show("PIN numbers do not match.");				//If PIN numbers do not match. Turn Lables font red
					this->pinLbl->ForeColor = System::Drawing::Color::Red;
					this->conPinLbl->ForeColor = System::Drawing::Color::Red;
				}
			}
			else{
				MessageBox::Show("Please fill in all mandatory fields.");
			}
		}
		else{
			MessageBox::Show("Invalid loading of Screen.");
		}
	}
			 //=================================================================================================================
	};
}
#endif
