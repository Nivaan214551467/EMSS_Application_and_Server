#include "Equipment.h"

#pragma once

namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// This screen is used to either Add or Update an Equipment
	/// </summary>
	public ref class EquipScreen : public System::Windows::Forms::Form
	{
	public:
		/*Constructor used when Adding an Equipment to the database*/
		EquipScreen(void){
			this->operationType = "add";
			InitializeComponent();
		}
		/*Constructor used when Updating an Equipment on the database. An Equipment Object is passed to the screen*/
		EquipScreen(Equipment^ equip){
			this->operationType = "update";
			this->eq = equip;
			InitializeComponent();
		}
	protected:
		~EquipScreen(){
			if (this->eq){
				this->eq->~Equipment();
			}
			if (components)
				delete components;
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: Equipment^ eq;					//Stores an Equipment object. Used when updating equipment
	private: String^ operationType;			//Controls whether to Add or Update and Equipment
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RichTextBox^  eqDescTxt;
	private: System::Windows::Forms::Label^  eqDescLbl;
	private: System::Windows::Forms::TextBox^  eqNameTxt;
	private: System::Windows::Forms::TextBox^  eqIDTxt;
	private: System::Windows::Forms::Label^  eqNameLbl;
	private: System::Windows::Forms::Label^  eqIDLbl;
	private: System::Windows::Forms::Button^  backBtn;
	private: System::Windows::Forms::Button^  proceedBtn;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EquipScreen::typeid));
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->eqDescTxt = (gcnew System::Windows::Forms::RichTextBox());
				 this->eqDescLbl = (gcnew System::Windows::Forms::Label());
				 this->eqNameTxt = (gcnew System::Windows::Forms::TextBox());
				 this->eqIDTxt = (gcnew System::Windows::Forms::TextBox());
				 this->eqNameLbl = (gcnew System::Windows::Forms::Label());
				 this->eqIDLbl = (gcnew System::Windows::Forms::Label());
				 this->backBtn = (gcnew System::Windows::Forms::Button());
				 this->proceedBtn = (gcnew System::Windows::Forms::Button());
				 this->panel1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->eqDescTxt);
				 this->panel1->Controls->Add(this->eqDescLbl);
				 this->panel1->Controls->Add(this->eqNameTxt);
				 this->panel1->Controls->Add(this->eqIDTxt);
				 this->panel1->Controls->Add(this->eqNameLbl);
				 this->panel1->Controls->Add(this->eqIDLbl);
				 this->panel1->Location = System::Drawing::Point(13, 13);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(504, 237);
				 this->panel1->TabIndex = 0;
				 // 
				 // eqDescTxt
				 // 
				 this->eqDescTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eqDescTxt->Location = System::Drawing::Point(160, 87);
				 this->eqDescTxt->Name = L"eqDescTxt";
				 this->eqDescTxt->Size = System::Drawing::Size(341, 142);
				 this->eqDescTxt->TabIndex = 7;
				 this->eqDescTxt->Text = L"";
				 // 
				 // eqDescLbl
				 // 
				 this->eqDescLbl->AutoSize = true;
				 this->eqDescLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eqDescLbl->Location = System::Drawing::Point(4, 90);
				 this->eqDescLbl->Name = L"eqDescLbl";
				 this->eqDescLbl->Size = System::Drawing::Size(150, 17);
				 this->eqDescLbl->TabIndex = 6;
				 this->eqDescLbl->Text = L"Equipment Descirption";
				 // 
				 // eqNameTxt
				 // 
				 this->eqNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eqNameTxt->Location = System::Drawing::Point(160, 52);
				 this->eqNameTxt->Name = L"eqNameTxt";
				 this->eqNameTxt->Size = System::Drawing::Size(341, 23);
				 this->eqNameTxt->TabIndex = 4;
				 // 
				 // eqIDTxt
				 // 
				 this->eqIDTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eqIDTxt->Location = System::Drawing::Point(160, 16);
				 this->eqIDTxt->Name = L"eqIDTxt";
				 this->eqIDTxt->Size = System::Drawing::Size(341, 23);
				 this->eqIDTxt->TabIndex = 3;
				 // 
				 // eqNameLbl
				 // 
				 this->eqNameLbl->AutoSize = true;
				 this->eqNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eqNameLbl->Location = System::Drawing::Point(29, 55);
				 this->eqNameLbl->Name = L"eqNameLbl";
				 this->eqNameLbl->Size = System::Drawing::Size(125, 17);
				 this->eqNameLbl->TabIndex = 1;
				 this->eqNameLbl->Text = L"Equipment Name *";
				 // 
				 // eqIDLbl
				 // 
				 this->eqIDLbl->AutoSize = true;
				 this->eqIDLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eqIDLbl->Location = System::Drawing::Point(53, 19);
				 this->eqIDLbl->Name = L"eqIDLbl";
				 this->eqIDLbl->Size = System::Drawing::Size(101, 17);
				 this->eqIDLbl->TabIndex = 0;
				 this->eqIDLbl->Text = L"Equipment ID *";
				 // 
				 // backBtn
				 // 
				 this->backBtn->FlatAppearance->BorderSize = 0;
				 this->backBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->backBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backBtn.Image")));
				 this->backBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->backBtn->Location = System::Drawing::Point(12, 267);
				 this->backBtn->Name = L"backBtn";
				 this->backBtn->Size = System::Drawing::Size(130, 50);
				 this->backBtn->TabIndex = 1;
				 this->backBtn->Text = L"CLOSE   ";
				 this->backBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->backBtn->UseVisualStyleBackColor = true;
				 this->backBtn->Click += gcnew System::EventHandler(this, &EquipScreen::backBtn_Click);
				 // 
				 // proceedBtn
				 // 
				 this->proceedBtn->FlatAppearance->BorderSize = 0;
				 this->proceedBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->proceedBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->proceedBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"proceedBtn.Image")));
				 this->proceedBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->proceedBtn->Location = System::Drawing::Point(282, 267);
				 this->proceedBtn->Name = L"proceedBtn";
				 this->proceedBtn->Size = System::Drawing::Size(235, 50);
				 this->proceedBtn->TabIndex = 2;
				 this->proceedBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->proceedBtn->UseVisualStyleBackColor = true;
				 this->proceedBtn->Click += gcnew System::EventHandler(this, &EquipScreen::proceedBtn_Click);
				 // 
				 // EquipScreen
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->ClientSize = System::Drawing::Size(529, 329);
				 this->Controls->Add(this->proceedBtn);
				 this->Controls->Add(this->backBtn);
				 this->Controls->Add(this->panel1);
				 this->ForeColor = System::Drawing::Color::White;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"EquipScreen";
				 this->Load += gcnew System::EventHandler(this, &EquipScreen::EquipScreen_Load);
				 this->panel1->ResumeLayout(false);
				 this->panel1->PerformLayout();
				 this->ResumeLayout(false);

			 }
#pragma endregion
			 /*Function called when screen is loaded*/
	private: System::Void EquipScreen_Load(System::Object^  sender, System::EventArgs^  e) {
		if (operationType == "add"){
			this->Text = "Add Equipment";
			this->proceedBtn->Text = "ADD EQUIPMENT       ";
		}
		else if (operationType == "update"){
			this->Text = "Update Equipment";
			this->proceedBtn->Text = "UPDATE EQUIPMENT";
			this->eqIDTxt->Text = this->eq->equipID;		//If operation is to update, display the Equipment object's data on respective fields
			this->eqNameTxt->Text = this->eq->name;
			this->eqDescTxt->Text = this->eq->description;
		}
		else{
			MessageBox::Show("Invalid call to screen");
		}
	}
	private: System::Void backBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~EquipScreen();
	}
			 /*Function calls appropriate functions to add or update Equipment*/
	private: System::Void proceedBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->eqIDTxt->Text != "" && this->eqNameTxt->Text != ""){		//Check if fields are not empty
			if (operationType == "add"){
				Equipment^ newEq = gcnew Equipment();
				//Adds an Equipment to the database via the addEquipment function in the equipment class
				if (newEq->addEquipment(this->eqIDTxt->Text, this->eqNameTxt->Text, this->eqDescTxt->Text)){
					this->~EquipScreen();
				}
				newEq->~Equipment();
			}
			else if (operationType == "update"){
				//Updates an Equipment on the database via the update function in the equipment class
				if (this->eq->update(this->eqIDTxt->Text, this->eqNameTxt->Text, this->eqDescTxt->Text)){
					this->~EquipScreen();
				}
			}
			else{
				MessageBox::Show("Invalid call to screen");
			}
		}
		else{
			MessageBox::Show("Please fill in all mandatory fields.");
		}
	}
	};
}
