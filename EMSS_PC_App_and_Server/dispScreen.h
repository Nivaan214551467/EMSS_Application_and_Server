#include "AddUserScreen.h"
#include "EquipScreen.h"
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
	/// This screen contains two Tabs each with their own data table.
	/// - dispTab displays either the Employee records or the Equipment records.
	/// - loanHistTab displays the Loan History records. This is disabled when dispTab has the Employee records.
	/// </summary>
	public ref class dispScreen : public System::Windows::Forms::Form
	{
	public:
		/*Default Constructor*/
		dispScreen(void){
			InitializeComponent();
		}
		/*Constructor used when specifying the type of information to display*/
		dispScreen(System::String^ type){
			this->dispType = type;
			this->search = false;
			InitializeComponent();
		}
	protected:
		~dispScreen(){
			if (components)
				delete components;
		}

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  closeBtn;
	private: System::Windows::Forms::TabControl^  dispTabPanel;
	private: System::Windows::Forms::TabPage^  dispTab;
	private: System::Windows::Forms::TabPage^  loanHistoryTab;
	private: System::Windows::Forms::DataGridView^  loanHistGrid;
	private: System::Windows::Forms::DataGridView^  dispGrid;
	private: System::Windows::Forms::DataGridViewButtonColumn^  updateCol;
	private: System::Windows::Forms::DataGridViewButtonColumn^  delCol;
	private: System::Windows::Forms::TextBox^  equipIDTxt;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  employeeIDTxt;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DateTimePicker^  borrowDateText;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  checkDate;
	private: System::String^ dispType;						//Stores the type of data to be displayed. Either Employee or Equipment records
	private: bool search;									//Controls when the data is to be filtered
	private:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(dispScreen::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->dispTabPanel = (gcnew System::Windows::Forms::TabControl());
			this->dispTab = (gcnew System::Windows::Forms::TabPage());
			this->dispGrid = (gcnew System::Windows::Forms::DataGridView());
			this->updateCol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delCol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->loanHistoryTab = (gcnew System::Windows::Forms::TabPage());
			this->checkDate = (gcnew System::Windows::Forms::CheckBox());
			this->borrowDateText = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->equipIDTxt = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->employeeIDTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->loanHistGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dispTabPanel->SuspendLayout();
			this->dispTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dispGrid))->BeginInit();
			this->loanHistoryTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->employeeIDTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loanHistGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// closeBtn
			// 
			this->closeBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeBtn->ForeColor = System::Drawing::Color::White;
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->closeBtn->Location = System::Drawing::Point(13, 659);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(180, 50);
			this->closeBtn->TabIndex = 1;
			this->closeBtn->Text = L"CLOSE";
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &dispScreen::closeBtn_Click);
			// 
			// dispTabPanel
			// 
			this->dispTabPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dispTabPanel->Controls->Add(this->dispTab);
			this->dispTabPanel->Controls->Add(this->loanHistoryTab);
			this->dispTabPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dispTabPanel->Location = System::Drawing::Point(13, 13);
			this->dispTabPanel->Name = L"dispTabPanel";
			this->dispTabPanel->SelectedIndex = 0;
			this->dispTabPanel->Size = System::Drawing::Size(1325, 640);
			this->dispTabPanel->TabIndex = 2;
			// 
			// dispTab
			// 
			this->dispTab->Controls->Add(this->dispGrid);
			this->dispTab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dispTab->Location = System::Drawing::Point(4, 33);
			this->dispTab->Name = L"dispTab";
			this->dispTab->Padding = System::Windows::Forms::Padding(3);
			this->dispTab->Size = System::Drawing::Size(1317, 603);
			this->dispTab->TabIndex = 0;
			this->dispTab->UseVisualStyleBackColor = true;
			// 
			// dispGrid
			// 
			this->dispGrid->AllowUserToAddRows = false;
			this->dispGrid->AllowUserToDeleteRows = false;
			this->dispGrid->AllowUserToResizeColumns = false;
			this->dispGrid->AllowUserToResizeRows = false;
			this->dispGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dispGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dispGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dispGrid->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dispGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dispGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dispGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dispGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->updateCol, this->delCol });
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dispGrid->DefaultCellStyle = dataGridViewCellStyle3;
			this->dispGrid->Location = System::Drawing::Point(0, 6);
			this->dispGrid->Name = L"dispGrid";
			this->dispGrid->ReadOnly = true;
			this->dispGrid->Size = System::Drawing::Size(1317, 597);
			this->dispGrid->TabIndex = 0;
			this->dispGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &dispScreen::dispGrid_CellContentClick);
			// 
			// updateCol
			// 
			this->updateCol->HeaderText = L"UPDATE";
			this->updateCol->Name = L"updateCol";
			this->updateCol->ReadOnly = true;
			this->updateCol->Text = L"UPDATE";
			this->updateCol->UseColumnTextForButtonValue = true;
			// 
			// delCol
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Red;
			this->delCol->DefaultCellStyle = dataGridViewCellStyle2;
			this->delCol->HeaderText = L"DELETE";
			this->delCol->Name = L"delCol";
			this->delCol->ReadOnly = true;
			this->delCol->Text = L"DELETE";
			this->delCol->UseColumnTextForButtonValue = true;
			// 
			// loanHistoryTab
			// 
			this->loanHistoryTab->Controls->Add(this->checkDate);
			this->loanHistoryTab->Controls->Add(this->borrowDateText);
			this->loanHistoryTab->Controls->Add(this->label3);
			this->loanHistoryTab->Controls->Add(this->button1);
			this->loanHistoryTab->Controls->Add(this->equipIDTxt);
			this->loanHistoryTab->Controls->Add(this->label2);
			this->loanHistoryTab->Controls->Add(this->employeeIDTxt);
			this->loanHistoryTab->Controls->Add(this->label1);
			this->loanHistoryTab->Controls->Add(this->loanHistGrid);
			this->loanHistoryTab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loanHistoryTab->Location = System::Drawing::Point(4, 33);
			this->loanHistoryTab->Name = L"loanHistoryTab";
			this->loanHistoryTab->Padding = System::Windows::Forms::Padding(3);
			this->loanHistoryTab->Size = System::Drawing::Size(1317, 603);
			this->loanHistoryTab->TabIndex = 1;
			this->loanHistoryTab->Text = L"LOAN HISTORY";
			this->loanHistoryTab->UseVisualStyleBackColor = true;
			// 
			// checkDate
			// 
			this->checkDate->AutoSize = true;
			this->checkDate->Location = System::Drawing::Point(573, 21);
			this->checkDate->Name = L"checkDate";
			this->checkDate->Size = System::Drawing::Size(15, 14);
			this->checkDate->TabIndex = 9;
			this->checkDate->UseVisualStyleBackColor = true;
			// 
			// borrowDateText
			// 
			this->borrowDateText->Location = System::Drawing::Point(675, 17);
			this->borrowDateText->Name = L"borrowDateText";
			this->borrowDateText->Size = System::Drawing::Size(174, 21);
			this->borrowDateText->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(594, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Borrow Date";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(928, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(190, 36);
			this->button1->TabIndex = 6;
			this->button1->Text = L"FILTER SEARCH";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &dispScreen::button1_Click);
			// 
			// equipIDTxt
			// 
			this->equipIDTxt->Location = System::Drawing::Point(104, 17);
			this->equipIDTxt->Name = L"equipIDTxt";
			this->equipIDTxt->Size = System::Drawing::Size(147, 21);
			this->equipIDTxt->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Equipment ID";
			// 
			// employeeIDTxt
			// 
			this->employeeIDTxt->Location = System::Drawing::Point(382, 18);
			this->employeeIDTxt->Name = L"employeeIDTxt";
			this->employeeIDTxt->Size = System::Drawing::Size(152, 21);
			this->employeeIDTxt->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(299, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Employee ID";
			// 
			// loanHistGrid
			// 
			this->loanHistGrid->AllowUserToAddRows = false;
			this->loanHistGrid->AllowUserToDeleteRows = false;
			this->loanHistGrid->AllowUserToResizeColumns = false;
			this->loanHistGrid->AllowUserToResizeRows = false;
			this->loanHistGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loanHistGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->loanHistGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->loanHistGrid->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->loanHistGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->loanHistGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->loanHistGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->loanHistGrid->DefaultCellStyle = dataGridViewCellStyle5;
			this->loanHistGrid->Location = System::Drawing::Point(0, 51);
			this->loanHistGrid->Name = L"loanHistGrid";
			this->loanHistGrid->ReadOnly = true;
			this->loanHistGrid->Size = System::Drawing::Size(1319, 554);
			this->loanHistGrid->TabIndex = 1;
			// 
			// dispScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ClientSize = System::Drawing::Size(1350, 721);
			this->Controls->Add(this->dispTabPanel);
			this->Controls->Add(this->closeBtn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"dispScreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Activated += gcnew System::EventHandler(this, &dispScreen::dispScreen_Activated);
			this->Load += gcnew System::EventHandler(this, &dispScreen::dispScreen_Load);
			this->dispTabPanel->ResumeLayout(false);
			this->dispTab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dispGrid))->EndInit();
			this->loanHistoryTab->ResumeLayout(false);
			this->loanHistoryTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->employeeIDTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loanHistGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		//==================================== ADDED CODE =================================================================================

	private: System::Void dispScreen_Load(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState = FormWindowState::Maximized;
		loadData();
	}
			 /*Function called when button in the display grid is pressed. Either Update or Delete an Employee or Equipment record*/
	private: System::Void dispGrid_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->RowIndex >= 0 && (e->ColumnIndex == 0 || e->ColumnIndex == 1)){
			int currRow = dispGrid->CurrentCell->RowIndex;			//Gets row of button press
			if (this->dispType == "employees"){						//Employee records are displayed
				DateTime^ dt = DateTime::Parse(dispGrid->Rows[currRow]->Cells["DATE OF BIRTH"]->Value->ToString());
				//Create Employee Object and fill members with data
				Employee^ upEmp = gcnew Employee(Int32::Parse(dispGrid->Rows[currRow]->Cells["EMPLOYEE ID"]->Value->ToString()), nullptr, dispGrid->Rows[dispGrid->CurrentCell->RowIndex]->Cells["FIRST NAMES"]->Value->ToString(), dispGrid->Rows[currRow]->Cells["SURNAME"]->Value->ToString(), dt->ToString("yyyy-MM-dd"), dispGrid->Rows[currRow]->Cells["PHYSICAL ADDRESS"]->Value->ToString(), dispGrid->Rows[currRow]->Cells["EMAIL ADDRESS"]->Value->ToString(), dispGrid->Rows[currRow]->Cells["PHONE NUMBER"]->Value->ToString(), dispGrid->Rows[currRow]->Cells["EMPLOYMENT POSITION"]->Value->ToString());
				if (e->ColumnIndex == 0){							//Update button pressed
					AddUserScreen^ up = gcnew AddUserScreen(upEmp);	//Open the AddUserScreen. Send Employee object to specify that the AddUserScreen is used to update an Employee
					up->Show();
				}
				if (e->ColumnIndex == 1)							//Delete button pressed
					if (MessageBox::Show("Are you sure you want to delete Employee ID " + upEmp->employeeID->ToString() + " from the database?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
						if (upEmp->del())
							this->loadData();
				upEmp->~Employee();
			}
			else if (this->dispType == "equip"){				//Equipment records Displayed
				Equipment^ eq = gcnew Equipment(dispGrid->Rows[currRow]->Cells["EQUIPMENT ID"]->Value->ToString(), dispGrid->Rows[currRow]->Cells["EQUIPMENT NAME"]->Value->ToString(), dispGrid->Rows[currRow]->Cells["DESCRIPTION"]->Value->ToString());
				if (e->ColumnIndex == 0){						//Update button pressed
					EquipScreen^ up = gcnew EquipScreen(eq);	//Open the EquipScreen. Send Equipment object to specify that the EquipScreen is used to update an Equipment record
					up->Show();
				}
				if (e->ColumnIndex == 1)						//Delete button pressed
					if (MessageBox::Show("Are you sure you want to delete Employee ID " + eq->equipID + " from the database?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
						if (eq->del())
							this->loadData();
			}
		}
	}

			 /*Function used to fill data to the data tables*/
	private: void loadData(){
		MySqlConnection^ conDataBase;
		try{
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			MySqlCommand^ sql;								//sql stores the SQL to get the Employee or Equipment records
			MySqlCommand^ histSQL;							//histSQL stores the SQL to get the loan history records
			MySqlDataAdapter^ myAdpt = gcnew MySqlDataAdapter();
			DataTable^ empDT = gcnew DataTable();
			DataTable^ histDT = gcnew DataTable();
			if (this->dispType == "employees"){				//Display Employee records 
				sql = gcnew MySqlCommand("SELECT `employee`.`employee_id` AS 'EMPLOYEE ID', `employee`.`first_names` AS 'FIRST NAMES', `employee`.`surname` AS 'SURNAME', `employee`.`date_of_birth` AS 'DATE OF BIRTH', `employee`.`physical_address` AS 'PHYSICAL ADDRESS', `employee`.`email_address` AS 'EMAIL ADDRESS', `employee`.`phone_number` AS 'PHONE NUMBER' , `employee`.`position` AS 'EMPLOYMENT POSITION', (GROUP_CONCAT(`equipment`.`equip_id` ORDER BY `equipment`.`equip_id` ASC SEPARATOR ', ')) AS 'CURRENT EQUIPMENT LOANED OUT' FROM `emss_database`.`employee` LEFT JOIN `emss_database`.`equipment` ON `employee`.`employee_id` = `equipment`.`loaned_out_to`	GROUP BY 1;", conDataBase);
				this->Text = "Employee Records";
				this->dispTabPanel->TabPages->Remove(this->loanHistoryTab);		//Remove the loanHistory Tab
				this->dispTab->Text = "EMPLOYEE RECORDS";
			}
			else if (this->dispType == "equip"){			//Display Equipment records
				sql = gcnew MySqlCommand("SELECT `equipment`.`equip_id` AS 'EQUIPMENT ID', `equipment`.`name` AS 'EQUIPMENT NAME', `equipment`.`description` AS 'DESCRIPTION', `equipment`.`loaned_out_to` AS 'CURRENT EMPLOYEE LOANED OUT TO' FROM `emss_database`.`equipment`;", conDataBase);
				this->Text = "Equipment Records";
				this->dispTab->Text = "EQUIPMENT RECORDS";
				System::String^ stSql = "SELECT `loan_tracking`.`loan_id` AS 'LOAN ID', `loan_tracking`.`equip_id` AS 'EQUIPMENT ID', `loan_tracking`.`employee_id` AS 'EMPLOYEE ID', `loan_tracking`.`loan_date` AS 'DATE LOANED OUT', `loan_tracking`.`return_date` AS 'DATE RETURNED' FROM emss_database.loan_tracking";
				//If fields are empty, do not filter records
				if (employeeIDTxt->Value == 0 && equipIDTxt->Text == "" && checkDate->Checked == false)
					this->search = false;

				//Filter records
				if (search){
					stSql += " WHERE";

					if (employeeIDTxt->Value > 0){		//Filter Employee ID
						stSql += "`loan_tracking`.`employee_id` = '" + this->employeeIDTxt->Value.ToString() + "' AND ";
					}
					if (equipIDTxt->Text != ""){		//Filter Equipment ID
						stSql += "`loan_tracking`.`equip_id` = '" + this->equipIDTxt->Text + "' AND ";
					}
					if (checkDate->Checked){			//Filter Borrow Date
						DateTime^ chDate = this->borrowDateText->Value;
						System::String^ tmp = chDate->Date.ToString("yyyy-MM-dd");
						stSql += "`loan_tracking`.`loan_date` >= '" + tmp + " 00:00:00' AND `loan_tracking`.`loan_date` <= '" + tmp + " 23:59:59' AND ";
					}

					stSql = stSql->Substring(0, stSql->Length - 5);		//Remove the last 'AND' clause
				}
				stSql += ";";
				histSQL = gcnew MySqlCommand(stSql, conDataBase);
				myAdpt->SelectCommand = histSQL;
				myAdpt->Fill(histDT);					//Fill loan history data to the table
				loanHistGrid->DataSource = histDT;
			}
			else{
				MessageBox::Show("Error loading data.");
			}
			myAdpt->SelectCommand = sql;
			myAdpt->Fill(empDT);						//Fill either the Employee or Eqiupment records to the table
			dispGrid->DataSource = empDT;
			conDataBase->Close();
		}
		catch (System::Exception^ ex){
			MessageBox::Show("Error loading data.");
		}
	}

	private: System::Void dispScreen_Activated(System::Object^  sender, System::EventArgs^  e) {
		this->loadData();
	}
	private: System::Void closeBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~dispScreen();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->search = true;
		loadData();
	}
			 //=============================================================================================================

	};
}
