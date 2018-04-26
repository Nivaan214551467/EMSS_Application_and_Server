#ifndef DEL_CON_H
#define DEL_CON_H
#pragma once

namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// This screen gets the Password from the Administrator who wishes to delete their record.
	/// </summary>
	public ref class deleteConfirmScreen : public System::Windows::Forms::Form
	{
	public:
		deleteConfirmScreen(){
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~deleteConfirmScreen(){
			if (components)
				delete components;
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  passTxt;
	private: System::Windows::Forms::Button^  proceedBtn;
	public:	 String^ password;								//Public variable used by AdminScreen (caller). 

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->passTxt = (gcnew System::Windows::Forms::TextBox());
			this->proceedBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(325, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter password to confirm deletion of record.";
			// 
			// passTxt
			// 
			this->passTxt->Location = System::Drawing::Point(17, 59);
			this->passTxt->Name = L"passTxt";
			this->passTxt->Size = System::Drawing::Size(269, 20);
			this->passTxt->TabIndex = 1;
			this->passTxt->UseSystemPasswordChar = true;
			// 
			// proceedBtn
			// 
			this->proceedBtn->Location = System::Drawing::Point(292, 46);
			this->proceedBtn->Name = L"proceedBtn";
			this->proceedBtn->Size = System::Drawing::Size(148, 45);
			this->proceedBtn->TabIndex = 2;
			this->proceedBtn->Text = L"PROCEED";
			this->proceedBtn->UseVisualStyleBackColor = true;
			this->proceedBtn->Click += gcnew System::EventHandler(this, &deleteConfirmScreen::proceedBtn_Click);
			// 
			// deleteConfirmScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 120);
			this->Controls->Add(this->proceedBtn);
			this->Controls->Add(this->passTxt);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"deleteConfirmScreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Authorize Deletion";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*Saves the Entered password in the public variable which is to be used by the calling screen (AdminScreen)*/
	private: System::Void proceedBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->password = this->passTxt->Text;
		this->Hide();
	}
	};
}
#endif