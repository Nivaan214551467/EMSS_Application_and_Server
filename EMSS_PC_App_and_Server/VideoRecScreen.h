#ifndef VIDREC_H
#define VIDREC_H

#include <string>
#pragma once

namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// This screen lists the video recordings and allows the user tp play or delete videos.
	/// </summary>
	public ref class VideoRecScreen : public System::Windows::Forms::Form
	{
	public:
		VideoRecScreen(void){
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VideoRecScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  videoRecordGrid;
	private: AxWMPLib::AxWindowsMediaPlayer^  windows_player;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Play;
	private: System::Windows::Forms::DataGridViewButtonColumn^  delCol;
	private: System::Windows::Forms::Button^  closeBtn;
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
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VideoRecScreen::typeid));
				 this->videoRecordGrid = (gcnew System::Windows::Forms::DataGridView());
				 this->Play = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
				 this->delCol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
				 this->windows_player = (gcnew AxWMPLib::AxWindowsMediaPlayer());
				 this->closeBtn = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoRecordGrid))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->windows_player))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // videoRecordGrid
				 // 
				 this->videoRecordGrid->AllowUserToAddRows = false;
				 this->videoRecordGrid->AllowUserToDeleteRows = false;
				 this->videoRecordGrid->AllowUserToResizeColumns = false;
				 this->videoRecordGrid->AllowUserToResizeRows = false;
				 this->videoRecordGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->videoRecordGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
				 this->videoRecordGrid->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
					 static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
				 this->videoRecordGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
				 dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
				 dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
				 dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Cambria", 10, System::Drawing::FontStyle::Bold));
				 dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
				 dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				 dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				 dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				 this->videoRecordGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
				 this->videoRecordGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->videoRecordGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
					 this->Play,
						 this->delCol
				 });
				 dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				 dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
				 dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
				 dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				 dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				 dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				 this->videoRecordGrid->DefaultCellStyle = dataGridViewCellStyle2;
				 this->videoRecordGrid->Location = System::Drawing::Point(13, 13);
				 this->videoRecordGrid->Name = L"videoRecordGrid";
				 this->videoRecordGrid->ReadOnly = true;
				 this->videoRecordGrid->Size = System::Drawing::Size(572, 582);
				 this->videoRecordGrid->TabIndex = 0;
				 this->videoRecordGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &VideoRecScreen::videoRecordGrid_CellContentClick);
				 // 
				 // Play
				 // 
				 this->Play->HeaderText = L"PLAY";
				 this->Play->Name = L"Play";
				 this->Play->ReadOnly = true;
				 this->Play->Text = L"PLAY";
				 this->Play->UseColumnTextForButtonValue = true;
				 // 
				 // delCol
				 // 
				 this->delCol->HeaderText = L"DELETE";
				 this->delCol->Name = L"delCol";
				 this->delCol->ReadOnly = true;
				 this->delCol->Text = L"DELETE";
				 this->delCol->UseColumnTextForButtonValue = true;
				 // 
				 // windows_player
				 // 
				 this->windows_player->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				 this->windows_player->Enabled = true;
				 this->windows_player->Location = System::Drawing::Point(592, 13);
				 this->windows_player->Name = L"windows_player";
				 this->windows_player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"windows_player.OcxState")));
				 this->windows_player->Size = System::Drawing::Size(746, 582);
				 this->windows_player->TabIndex = 1;
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
				 this->closeBtn->Location = System::Drawing::Point(13, 599);
				 this->closeBtn->Name = L"closeBtn";
				 this->closeBtn->Size = System::Drawing::Size(188, 50);
				 this->closeBtn->TabIndex = 2;
				 this->closeBtn->Text = L"CLOSE";
				 this->closeBtn->UseVisualStyleBackColor = true;
				 this->closeBtn->Click += gcnew System::EventHandler(this, &VideoRecScreen::closeBtn_Click);
				 // 
				 // VideoRecScreen
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->ClientSize = System::Drawing::Size(1350, 661);
				 this->Controls->Add(this->closeBtn);
				 this->Controls->Add(this->windows_player);
				 this->Controls->Add(this->videoRecordGrid);
				 this->ForeColor = System::Drawing::Color::Black;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"VideoRecScreen";
				 this->Text = L"Video Recordings";
				 this->Activated += gcnew System::EventHandler(this, &VideoRecScreen::VideoRecScreen_Activated);
				 this->Load += gcnew System::EventHandler(this, &VideoRecScreen::VideoRecScreen_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoRecordGrid))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->windows_player))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void VideoRecScreen_Load(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState = FormWindowState::Maximized;
		this->loadData();
	}

			 /*Function used to fill data to the data tables*/
	private: void loadData(){
		MySqlConnection^ conDataBase;
		try{
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			MySqlCommand^ sql;
			//Get all recordings from the database
			sql = gcnew MySqlCommand("SELECT `video_recording`.`filepath` AS 'FILEPATH', `video_recording`.`date` AS 'DATE' FROM `emss_database`.`video_recording`;", conDataBase);
			MySqlDataAdapter^ myAdpt = gcnew MySqlDataAdapter();
			myAdpt->SelectCommand = sql;
			DataTable^ vidDT = gcnew DataTable();
			myAdpt->Fill(vidDT);							//Fill the table
			this->videoRecordGrid->DataSource = vidDT;
			conDataBase->Close();
		}
		catch (Exception^ ex){
			MessageBox::Show("ERROR loading data.");
		}
	}
			 /*Function used when button pressed. Either to play or delete a video*/
	private: System::Void videoRecordGrid_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->RowIndex >= 0 && (e->ColumnIndex == 0 || e->ColumnIndex == 1)){
			int currRow = videoRecordGrid->CurrentCell->RowIndex;		//Get current row
			if (e->ColumnIndex == 0){									//Play button pressed
				windows_player->URL = videoRecordGrid->Rows[currRow]->Cells["FILEPATH"]->Value->ToString();
				windows_player->Ctlcontrols->play();
			}
			else if (e->ColumnIndex == 1){								//Delete button pressed
				if (MessageBox::Show("Are you sure you want to delete " + videoRecordGrid->Rows[currRow]->Cells["FILEPATH"]->Value->ToString() + " from the database?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
					windows_player->URL = "";
					windows_player->Ctlcontrols->stop();				//Stop video player
					MySqlConnection^ conDataBase;
					System::String^ filepath = videoRecordGrid->Rows[currRow]->Cells["FILEPATH"]->Value->ToString();	//Gets filepath to video recording
					const char * chars = (const char *)(Marshal::StringToHGlobalAnsi(filepath)).ToPointer();
					std::string filePathStd = chars;
					Marshal::ZeroFreeGlobalAllocAnsi(IntPtr((void*)chars));
					try{
						conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
						conDataBase->Open();
						if (remove(filePathStd.c_str()) == 0){			//Check if video file was deleted, if so, delete the database entry
							MySqlCommand^ sql = gcnew MySqlCommand("DELETE FROM `emss_database`.`video_recording` WHERE `video_recording`.`filepath` = '" + filepath + "';", conDataBase);
							MySqlDataReader^ reader = sql->ExecuteReader();
							reader->Close();
							MessageBox::Show("Video Recording deleted.");
							this->loadData();
						}
						conDataBase->Close();
					}
					catch (System::Exception^ ex){
						MessageBox::Show("ERROR deleting the video file.");
					}
				}
			}
		}
	}
	private: System::Void closeBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~VideoRecScreen();
	}
	private: System::Void VideoRecScreen_Activated(System::Object^  sender, System::EventArgs^  e) {
		this->loadData();
	}
	};
}

#endif