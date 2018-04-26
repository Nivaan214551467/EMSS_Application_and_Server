#include "AddUserScreen.h"
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
	/// Summary for dispEmployees
	/// </summary>
	public ref class dispEmployees : public System::Windows::Forms::Form
	{
	public:
		dispEmployees(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dispEmployees()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  employeeGrid;
	private: System::Windows::Forms::DataGridViewButtonColumn^  updateCol;
	private: System::Windows::Forms::DataGridViewButtonColumn^  delCol;
	private: System::ComponentModel::IContainer^  components;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->employeeGrid = (gcnew System::Windows::Forms::DataGridView());
			this->updateCol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delCol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->employeeGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// employeeGrid
			// 
			this->employeeGrid->AllowUserToAddRows = false;
			this->employeeGrid->AllowUserToDeleteRows = false;
			this->employeeGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->employeeGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->employeeGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->employeeGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->employeeGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->updateCol,
					this->delCol
			});
			this->employeeGrid->Location = System::Drawing::Point(13, 13);
			this->employeeGrid->Name = L"employeeGrid";
			this->employeeGrid->ReadOnly = true;
			this->employeeGrid->Size = System::Drawing::Size(839, 204);
			this->employeeGrid->TabIndex = 0;
			this->employeeGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &dispEmployees::employeeGrid_CellContentClick);
			// 
			// updateCol
			// 
			this->updateCol->HeaderText = L"Update";
			this->updateCol->Name = L"updateCol";
			this->updateCol->ReadOnly = true;
			this->updateCol->Text = L"UPDATE";
			this->updateCol->UseColumnTextForButtonValue = true;
			this->updateCol->Width = 65;
			// 
			// delCol
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Red;
			this->delCol->DefaultCellStyle = dataGridViewCellStyle2;
			this->delCol->HeaderText = L"Delete";
			this->delCol->Name = L"delCol";
			this->delCol->ReadOnly = true;
			this->delCol->Text = L"DELETE";
			this->delCol->UseColumnTextForButtonValue = true;
			this->delCol->Width = 60;
			// 
			// dispEmployees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(864, 317);
			this->Controls->Add(this->employeeGrid);
			this->Name = L"dispEmployees";
			this->Text = L"Employees";
			this->Load += gcnew System::EventHandler(this, &dispEmployees::dispEmployees_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->employeeGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dispEmployees_Load(System::Object^  sender, System::EventArgs^  e) {
		MySqlConnection^ conDataBase;
		try{
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			MySqlCommand^ sql = gcnew MySqlCommand("SELECT `employee`.`employee_id`, `employee`.`first_names`, `employee`.`surname`, `employee`.`date_of_birth`, `employee`.`physical_address`, `employee`.`email_address`, `employee`.`phone_number`, `employee`.`position`, (GROUP_CONCAT(`equipment`.`equip_id` ORDER BY `equipment`.`equip_id` ASC SEPARATOR ', ')) AS 'Equipment Loaned Out' FROM `emss_database`.`employee` LEFT JOIN `emss_database`.`equipment` ON `employee`.`employee_id` = `equipment`.`loaned_out_to`	GROUP BY 1;", conDataBase);
			MySqlDataAdapter^ myAdpt = gcnew MySqlDataAdapter();
			myAdpt->SelectCommand = sql;
			DataTable^ empDT = gcnew DataTable();
			myAdpt->Fill(empDT);
			employeeGrid->DataSource = empDT;
			conDataBase->Close();
		}
		catch (Exception^ ex){
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void employeeGrid_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->ColumnIndex == 0 || e->ColumnIndex == 1){
			int currRow = employeeGrid->CurrentCell->RowIndex;
			DateTime^ dt = DateTime::Parse(employeeGrid->Rows[currRow]->Cells["date_of_birth"]->Value->ToString());
			Employee^ upEmp = gcnew Employee(Int32::Parse(employeeGrid->Rows[currRow]->Cells["employee_id"]->Value->ToString()), nullptr, employeeGrid->Rows[employeeGrid->CurrentCell->RowIndex]->Cells["first_names"]->Value->ToString(), employeeGrid->Rows[currRow]->Cells["surname"]->Value->ToString(), dt->ToString("yyyy-MM-dd"), employeeGrid->Rows[currRow]->Cells["physical_address"]->Value->ToString(), employeeGrid->Rows[currRow]->Cells["email_address"]->Value->ToString(), employeeGrid->Rows[currRow]->Cells["phone_number"]->Value->ToString(), employeeGrid->Rows[currRow]->Cells["position"]->Value->ToString());
			if (e->ColumnIndex == 0){
				AddUserScreen^ up = gcnew AddUserScreen(upEmp);
				up->Show();
			}
			if (e->ColumnIndex == 1){
				if (MessageBox::Show("Are you sure you want to delete Employee ID " + upEmp->employeeID->ToString() + " from the database?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
					if (upEmp->del()){
//***********************figure out how to update the datagrid
					}
				}
			}
			upEmp->~Employee();
		}
	}
};
}
