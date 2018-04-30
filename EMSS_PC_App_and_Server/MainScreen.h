#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#pragma once

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <ctime>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#include "LoginScreen.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include "DatabaseQueries.h"

#pragma comment (lib, "ws2_32.lib")

#define BUFF_SIZE 20

namespace EMSS_PC_App_and_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace Runtime::InteropServices;
	using namespace std;
	using namespace cv;
	extern bool stopVideo = false;				//Global variable used to control the starting and stopping of Video Recording
	extern bool vidThreadAlive = false;			//Global variable used to indicate whether the Video recording Thread is active
	time_t startTime;							//Used to hold the time the application was started.
	time_t currTime = time(0);					//Stores the current time;
	delegate void SetTextCallback(RichTextBox^ textBox, System::String^ text);	//Deleate required to access RichTextBox from different threads

	void SetText(RichTextBox^ textBox, System::String^ text){		//Function to allow Threads access to the RichTextBox
		if (textBox->InvokeRequired){
			SetTextCallback^ d = gcnew SetTextCallback(&SetText);
			array<System::Object^>^ tmp = { textBox, text };
			textBox->Invoke(d, tmp);
		}
		else{
			textBox->Text += text;
		}
	}
	/// <summary>
	/// Summary for MainScreen
	/// </summary>
	public ref class MainScreen : public System::Windows::Forms::Form
	{
	public:
		MainScreen(void){
			InitializeComponent();
			this->viewFeed = false;
			this->stopServ = false;
			stopVideo = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainScreen(){
			logEvent("[SHUTDOWN] System Shutdown.");
			stopVideo = true;
			waitKey(1000);
			shutdown(clientSocket, SHUTDOWN_FORCE_OTHERS);
			closesocket(serv);
			startServ->Abort();
			startVideo->Abort();
			WSACleanup();
			if (components)
			{
				delete components;
			}
			if (logFile != NULL){
				fclose(logFile);
			}
		}
	private:System::Windows::Forms::Panel^  panel1;
			System::Windows::Forms::Label^  eventLogLbl;
			System::Windows::Forms::Panel^  panel2;
			System::Windows::Forms::Button^  videoBtn;
			System::Windows::Forms::Button^  adminBtn;
			System::Windows::Forms::Button^  settingsBtn;
			System::Windows::Forms::Button^  exitBtn;

	public:	static System::Windows::Forms::Timer^ lblTimer = gcnew System::Windows::Forms::Timer;
	public: static System::Windows::Forms::Label^  timeLbl;
	public: static System::Windows::Forms::RichTextBox^  eventLogTxt;


	private: Thread^ startServ;						//Thread to host the Server
	private: Thread^ startVideo;					//Thread to control the Video Recording
	private: static bool viewFeed;					//Boolean vairable to control the viewing of the Video Feed
	private: static SOCKET serv;					//Socket used to listen for Clients
	private: static SOCKET clientSocket;
	private: static FILE *logFile;
	private: static short video_length;				//video recording length in seconds
	private: static long long video_max_size;		//Max video length in Bytes - Limit to under 4GB
	private: static long long video_age;			//2 * 2592000 seconds in 2 months
	private: static System::String^ camera_IP;		//string to keep the IP of the camera
	private: System::String^ etas_IP;				//string to keep the IP of the Equipment Taggaing and Authorization System
	private: static int server_port;				//Port Number for the Sever
	private: static bool stopServ = FALSE;			//Boolean variable to control when to stop the server
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
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainScreen::typeid));
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->eventLogLbl = (gcnew System::Windows::Forms::Label());
				 this->eventLogTxt = (gcnew System::Windows::Forms::RichTextBox());
				 this->timeLbl = (gcnew System::Windows::Forms::Label());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->videoBtn = (gcnew System::Windows::Forms::Button());
				 this->adminBtn = (gcnew System::Windows::Forms::Button());
				 this->settingsBtn = (gcnew System::Windows::Forms::Button());
				 this->exitBtn = (gcnew System::Windows::Forms::Button());
				 this->panel1->SuspendLayout();
				 this->panel2->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->eventLogLbl);
				 this->panel1->Controls->Add(this->eventLogTxt);
				 this->panel1->Location = System::Drawing::Point(13, 13);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(461, 346);
				 this->panel1->TabIndex = 0;
				 // 
				 // eventLogLbl
				 // 
				 this->eventLogLbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->eventLogLbl->AutoSize = true;
				 this->eventLogLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->eventLogLbl->ForeColor = System::Drawing::Color::White;
				 this->eventLogLbl->Location = System::Drawing::Point(3, 16);
				 this->eventLogLbl->Name = L"eventLogLbl";
				 this->eventLogLbl->Size = System::Drawing::Size(126, 29);
				 this->eventLogLbl->TabIndex = 1;
				 this->eventLogLbl->Text = L"Event Log:";
				 this->eventLogLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // eventLogTxt
				 // 
				 this->eventLogTxt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->eventLogTxt->BackColor = System::Drawing::Color::Black;
				 this->eventLogTxt->ForeColor = System::Drawing::Color::LawnGreen;
				 this->eventLogTxt->Location = System::Drawing::Point(0, 48);
				 this->eventLogTxt->Name = L"eventLogTxt";
				 this->eventLogTxt->ReadOnly = true;
				 this->eventLogTxt->Size = System::Drawing::Size(461, 298);
				 this->eventLogTxt->TabIndex = 0;
				 this->eventLogTxt->Text = L"";
				 this->eventLogTxt->TextChanged += gcnew System::EventHandler(this, &MainScreen::eventLogTxt_TextChanged);
				 // 
				 // timeLbl
				 // 
				 this->timeLbl->AutoSize = true;
				 this->timeLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->timeLbl->ForeColor = System::Drawing::Color::White;
				 this->timeLbl->Location = System::Drawing::Point(481, 39);
				 this->timeLbl->Name = L"timeLbl";
				 this->timeLbl->RightToLeft = System::Windows::Forms::RightToLeft::No;
				 this->timeLbl->Size = System::Drawing::Size(111, 17);
				 this->timeLbl->TabIndex = 1;
				 this->timeLbl->Text = L"CURRENT TIME";
				 // 
				 // panel2
				 // 
				 this->panel2->Controls->Add(this->videoBtn);
				 this->panel2->Controls->Add(this->adminBtn);
				 this->panel2->Controls->Add(this->settingsBtn);
				 this->panel2->Controls->Add(this->exitBtn);
				 this->panel2->Location = System::Drawing::Point(481, 61);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(214, 298);
				 this->panel2->TabIndex = 1;
				 // 
				 // videoBtn
				 // 
				 this->videoBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->videoBtn->FlatAppearance->BorderSize = 0;
				 this->videoBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->videoBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->videoBtn->ForeColor = System::Drawing::Color::White;
				 this->videoBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"videoBtn.Image")));
				 this->videoBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->videoBtn->Location = System::Drawing::Point(3, 28);
				 this->videoBtn->Name = L"videoBtn";
				 this->videoBtn->Size = System::Drawing::Size(207, 50);
				 this->videoBtn->TabIndex = 2;
				 this->videoBtn->Text = L"OPEN VIDEO FEED";
				 this->videoBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->videoBtn->UseVisualStyleBackColor = true;
				 this->videoBtn->Click += gcnew System::EventHandler(this, &MainScreen::videoBtn_Click);
				 // 
				 // adminBtn
				 // 
				 this->adminBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->adminBtn->FlatAppearance->BorderSize = 0;
				 this->adminBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->adminBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->adminBtn->ForeColor = System::Drawing::Color::White;
				 this->adminBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"adminBtn.Image")));
				 this->adminBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->adminBtn->Location = System::Drawing::Point(3, 84);
				 this->adminBtn->Name = L"adminBtn";
				 this->adminBtn->Size = System::Drawing::Size(207, 50);
				 this->adminBtn->TabIndex = 2;
				 this->adminBtn->Text = L"ADMINISTRATION  ";
				 this->adminBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->adminBtn->UseVisualStyleBackColor = true;
				 this->adminBtn->Click += gcnew System::EventHandler(this, &MainScreen::adminBtn_Click);
				 // 
				 // settingsBtn
				 // 
				 this->settingsBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->settingsBtn->FlatAppearance->BorderSize = 0;
				 this->settingsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->settingsBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->settingsBtn->ForeColor = System::Drawing::Color::White;
				 this->settingsBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsBtn.Image")));
				 this->settingsBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->settingsBtn->Location = System::Drawing::Point(3, 140);
				 this->settingsBtn->Name = L"settingsBtn";
				 this->settingsBtn->Size = System::Drawing::Size(207, 50);
				 this->settingsBtn->TabIndex = 1;
				 this->settingsBtn->Text = L"SETTINGS              ";
				 this->settingsBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->settingsBtn->UseVisualStyleBackColor = true;
				 this->settingsBtn->Click += gcnew System::EventHandler(this, &MainScreen::settingsBtn_Click);
				 // 
				 // exitBtn
				 // 
				 this->exitBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->exitBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->exitBtn->FlatAppearance->BorderSize = 0;
				 this->exitBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->exitBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->exitBtn->ForeColor = System::Drawing::Color::White;
				 this->exitBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitBtn.Image")));
				 this->exitBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->exitBtn->Location = System::Drawing::Point(3, 245);
				 this->exitBtn->Name = L"exitBtn";
				 this->exitBtn->Size = System::Drawing::Size(207, 50);
				 this->exitBtn->TabIndex = 0;
				 this->exitBtn->Text = L"SHUTDOWN SYSTEM";
				 this->exitBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->exitBtn->UseVisualStyleBackColor = false;
				 this->exitBtn->Click += gcnew System::EventHandler(this, &MainScreen::exitBtn_Click);
				 // 
				 // MainScreen
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->ClientSize = System::Drawing::Size(705, 371);
				 this->Controls->Add(this->timeLbl);
				 this->Controls->Add(this->panel2);
				 this->Controls->Add(this->panel1);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximizeBox = false;
				 this->Name = L"MainScreen";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Equipment Management and Surveillance System";
				 this->Load += gcnew System::EventHandler(this, &MainScreen::MainScreen_Load);
				 this->panel1->ResumeLayout(false);
				 this->panel1->PerformLayout();
				 this->panel2->ResumeLayout(false);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void MainScreen_Load(System::Object^  sender, System::EventArgs^  e) {
		char cDate[70];
		getStdStringTime("C:\\EMSS_video_recordings\\Logs\\%Y-%m-%d.txt", cDate, time(0));
		logFile = fopen(cDate, "a");
		if (logFile == NULL){
			logFile = fopen(cDate, "w");
			if (logFile == NULL){
				logEvent("ERROR opening log file");
			}
		}

		logEvent("[STARTUP] System started.");

		this->video_length = 30;							//Default system settings
		this->video_max_size = (long long)4294000000;
		this->video_age = (long long)(2 * 2592000);
		this->camera_IP = "";
		this->etas_IP = "";
		this->server_port = 54000;
		this->loadSettings();

		lblTimer->Tick += gcnew EventHandler(TimerEventProcessor);
		lblTimer->Interval = 1000;					// Sets the timer interval to 1 second.
		lblTimer->Start();

		startServ = gcnew Thread(gcnew ThreadStart(startServF));
		startServ->Start();
		waitKey(100);								//Wait to see if Server Thread started
		if (startServ->IsAlive){
			logEvent("Server Thread started.");
		}

		startVideo = gcnew Thread(gcnew ThreadStart(startVidF));
		stopVideo = false;							
		startVideo->Start();						//Starts Video Thread
		waitKey(100);
		if (startVideo->IsAlive){
			logEvent("Video Thread started.");
		}
	}

	public: static void startServF(){			//Function handles the operations of the Server - Communication with the ETAS
		WSADATA wsdata;
		int wsok = WSAStartup(MAKEWORD(2, 2), &wsdata);	//Initialise WinSock
		if (wsok != 0){
			logEvent("Winsock not initialized.");
		}
		serv = socket(AF_INET, SOCK_STREAM, 0);			//Create server socket
		if (serv == INVALID_SOCKET){
			logEvent("Winsock not created");
		}
		sockaddr_in sockAdd;
		sockAdd.sin_family = AF_INET;
		sockAdd.sin_port = htons(server_port);			//Use PORT 54000
		sockAdd.sin_addr.S_un.S_addr = INADDR_ANY;
		while (!stopServ){
			bind(serv, (sockaddr*)&sockAdd, sizeof(sockAdd));	//bind details to server socket
			listen(serv, SOMAXCONN);							//Server socket is listening for client

			sockaddr_in client;
			int clientSize = sizeof(client);
			clientSocket = accept(serv, (sockaddr*)&client, &clientSize); //Accept client connection

			char host[NI_MAXHOST];								//char array hold the host name
			char service[NI_MAXHOST];

			ZeroMemory(host, NI_MAXHOST);
			ZeroMemory(service, NI_MAXSERV);

			if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
				System::String^ tmp1 = gcnew System::String(service);
				System::String^ tmp = gcnew System::String(host);
				logEvent(tmp + " " + tmp1 + " connected on port " + server_port.ToString());
			}
			else{
				inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
				System::String^ tmp = gcnew System::String(host);
				logEvent(tmp + " connected on port " + ntohs(client.sin_port) + "");
			}

			System::String^ currEmployee = "";
			char inputData[BUFF_SIZE];					//char array of BUFF_SIZE
			char empPINBuff[BUFF_SIZE];					//Stores Employee PIN
			char response[BUFF_SIZE];					//Stores message to send to client
			System::String^ recvData = "";
			System::String^ equipmentStr = "";

			while (true){								//Loop when client connected.
				recvData = "";
				ZeroMemory(inputData, BUFF_SIZE);
				ZeroMemory(response, BUFF_SIZE);
				ZeroMemory(empPINBuff, BUFF_SIZE);

				int bytesR = recv(clientSocket, inputData, BUFF_SIZE, 0);  //Receive data from ETAS
				recvData = gcnew System::String(inputData);
				logEvent("Received " + recvData);
				
				if (bytesR == SOCKET_ERROR){
					logEvent("ERROR in receiving.");
					break;
				}
				if (bytesR == 0){
					logEvent("Client disconnected");
					break;
				}

				if (recvData->Length == 3){								//EquipID received
					Equipment^ scannedEQ = gcnew Equipment();
					ZeroMemory(inputData, BUFF_SIZE);
					equipmentStr = "";
					bytesR = recv(clientSocket, inputData, BUFF_SIZE, 0);	//Receive Equip ID
					if (bytesR == SOCKET_ERROR){
						logEvent("ERROR in receiving.");
						break;
					}
					if (bytesR == 0){
						logEvent("Client disconnected");
						break;
					}
					equipmentStr = gcnew System::String(inputData);
					short count = 0;
					while (equipmentStr->Length != 12 && count < 10){		//Wait till 12 digit message received, use 10 attempts
						ZeroMemory(inputData, BUFF_SIZE);
						equipmentStr = "";
						bytesR = recv(clientSocket, inputData, BUFF_SIZE, 0);		//Receive Equip ID
						if (bytesR == SOCKET_ERROR){
							logEvent("ERROR in receiving.");
							break;
						}
						if (bytesR == 0){
							logEvent("Client disconnected");
							break;
						}
						equipmentStr = gcnew System::String(inputData);
						count++;
					}

					if (scannedEQ->exists(equipmentStr)){					//Check if in the Database
						if (recvData == "LLL" && currEmployee == ""){		//Sound Alarm
							if (!scannedEQ->isBorrowed(equipmentStr) && scannedEQ->exists(equipmentStr)){
								logEvent("Sound Alarm");
							}
						}

						if (recvData == "LLL" && currEmployee != ""){		//Loan data
							logEvent("Receieved Equip ID is " + equipmentStr + " for Employee " + currEmployee);
							if (!scannedEQ->isBorrowed(equipmentStr) && scannedEQ->exists(equipmentStr)){	//If not loaned, loan now
								char currDate[100];
								getStdStringTime("%Y-%m-%d %H:%M:%S", currDate, time(0));
								try{
									if (scannedEQ->get_loaned_out(Int32::Parse(currEmployee), equipmentStr, gcnew System::String(currDate))){
										logEvent("Equipment " + equipmentStr + " loaned to Employee " + currEmployee);
									}
									else{
										logEvent("Cannot record Equipment " + equipmentStr + " loaned to Employee " + currEmployee);
									}
								}
								catch (System::Exception^ ex){
									MessageBox::Show("Error trying to loan out equipment.");
								}
							}
							else{
								logEvent("Equipment is already loaned.");
							}
						}
						else if (recvData == "RRR" && currEmployee != ""){			//Return equipment
							if (scannedEQ->isBorrowed(equipmentStr)){					//Already returned
								logEvent("Receieved Equip ID is " + equipmentStr + " for Employee " + currEmployee);
								char currDate[100];
								getStdStringTime("%Y-%m-%d %H:%M:%S", currDate, time(0));
								if (scannedEQ->return_equipment(Int32::Parse(currEmployee), equipmentStr, gcnew System::String(currDate))){
									logEvent("Equipment Returned");
								}
								else{
									logEvent("Could not return Equipment " + equipmentStr);
								}
							}
							else{
								logEvent("Equipment already returned.");
							}
						}
						else{
							logEvent("Did nothing with Equip ID " + equipmentStr);
						}
					}
					else{
						logEvent(equipmentStr + " not in the Database");
					}
				}
				if (recvData->Length == 6){												//EmpID received
					int pinBytes = recv(clientSocket, empPINBuff, BUFF_SIZE, 0);		//Get Employee PIN
					if (pinBytes == SOCKET_ERROR){
						logEvent("ERROR in receiving.");
						break;
					}
					if (pinBytes == 0){
						logEvent("Client disconnected");
						break;
					}
					System::String^ recPIN = gcnew System::String(empPINBuff);			//Save PIN
					short count = 0;
					while (recPIN->Length != 6 && count < 10){										//Wait till 6 digit PIN entered
						pinBytes = recv(clientSocket, empPINBuff, BUFF_SIZE, 0);		//Get Employee PIN
						if (pinBytes == SOCKET_ERROR){
							logEvent("ERROR in receiving.");
							break;
						}
						if (pinBytes == 0){
							logEvent("Client disconnected");
							break;
						}
						recPIN = gcnew System::String(empPINBuff);						//Save PIN
						count++;
					}
					
					System::String^ recEmp = gcnew System::String(inputData);			//Save Employee ID
					logEvent("Received again " + recPIN);
					logEvent("Received Employee ID is" + recEmp);
					logEvent("Received Employee PIN is" + recPIN);

					Employee^ emp;
					try{
						if (emp->request_authorization(Int32::Parse(recEmp), Int32::Parse(recPIN))){	//Check if PIN is valid
							char resp[13] = "************";
							send(clientSocket, resp, 13, 0);							//Send access granted response
							logEvent("Access Granted to Employee ID  = " + recEmp);
							currEmployee = recEmp;
						}
						else{
							char resp[13] = "############";								//Send access denied response
							send(clientSocket, resp, 13, 0);
							logEvent("Access Denied to Employee ID  = " + recEmp);
							currEmployee = "";
						}
					} 
					catch (System::Exception^ ex){
						MessageBox::Show(ex->Message);
					}
				}

				if (recvData->Length == 4){
					if (recvData == "LOCK"){
						logEvent("Employee " + currEmployee + " has exited the room.");
						currEmployee = "";
					}
				}
			}
			closesocket(clientSocket);
		}
		logEvent("Server has closed.");
	}

	public: static void startVidF(){	//Function handles the Video Feed
		vidThreadAlive = true;
		cleanOldVideos();				//Deletes old Videos

		const char * chars = (const char *)(Marshal::StringToHGlobalAnsi(camera_IP)).ToPointer();
		const cv::string camIPStd = chars;
		bool newVid = false;

		VideoCapture ipStream(camIPStd);		//Open Video Feed

		if (!ipStream.isOpened()){
			logEvent("Could not access camera at " + camera_IP + ". Stopping thread.");
			viewFeed = false;
			stopVideo = true;
			vidThreadAlive = false;
			return;
		}
		else{
			logEvent("Camera Successfully opened.");
		}
		Mat frame = Mat::zeros(ipStream.get(CV_CAP_PROP_FRAME_HEIGHT), ipStream.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC1);
		double fps = 10;
		fps = ipStream.get(CV_CAP_PROP_FPS);			//Get frames per second
		
		while (true){
			while (!stopVideo){							//Open a new file to write to
				time_t startVidTime;
				cv::VideoWriter writer;

				char fileStr[100];
				char currDate[100];
				getStdStringTime("C:/EMSS_video_recordings/EMSS_Recording_%d-%m-%y_%H-%M-%S.avi", fileStr, time(0));
				getStdStringTime("%Y-%m-%d %H:%M:%S", currDate, time(0));

				System::String^ cDate = gcnew System::String(currDate);
				std::string filepath(fileStr);
				cv::Size fSize(ipStream.get(CV_CAP_PROP_FRAME_WIDTH), ipStream.get(CV_CAP_PROP_FRAME_HEIGHT));
				writer = VideoWriter(filepath, CV_FOURCC('D', 'I', 'V', '3'), fps, fSize, true);
				if (!writer.isOpened()){
					logEvent("Error opening video writer.");
					return;
				}
				else{
					System::String^ nwSt = gcnew System::String(fileStr);
					logEvent("Video is being recorded to " + nwSt);
					DatabaseQueries^ msql = gcnew DatabaseQueries();
					msql->setQuery("INSERT INTO `emss_database`.`video_recording` (`filepath`, `date`) VALUES ('" + nwSt + "', '" + cDate + "');");
				}

				time(&startVidTime);
				time(&currTime);
				int size = 0;
				while (!stopVideo && difftime(currTime, startVidTime) < video_length && size < video_max_size){		//Write to file
					if (ipStream.read(frame)){
						writer.write(frame);
						if (viewFeed){
							imshow("Video Stream from IP camera", frame);			//Display feed
						}
						else{
							destroyWindow("Video Stream from IP camera");
						}
						if (waitKey(1000 / fps) >= 0) ;
					}
					time(&currTime);
					std::ifstream readSize(fileStr, std::ifstream::ate | std::ifstream::binary);
					size = readSize.tellg();
					if (stopVideo)
						logEvent("Video Recording Stopped.");
				}
				writer.release();
			}
		}
		ipStream.release();
		logEvent("Camera closed.");
	}
	
	private: void static TimerEventProcessor(Object^ myObject, EventArgs^ myEventArgs){	//TImer used to upate the display every second
		lblTimer->Stop();						//Stop the timer
		char str[100];
		getStdStringTime("%d %B %Y   %H:%M:%S", str, time(0));
		System::String^ tmp = gcnew System::String(str);
		timeLbl->Text = tmp;
		lblTimer->Enabled = true;			//Restart the timer
	}
	private: System::Void adminBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		LoginScreen^ ad = gcnew LoginScreen("AdminScreen", this->eventLogTxt);
		ad->ShowDialog();
	}
	private: System::Void settingsBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		LoginScreen^ ad = gcnew LoginScreen("Settings", this->eventLogTxt);
		ad->ShowDialog();
	}
	private: System::Void videoBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!stopVideo){
			viewFeed = (viewFeed + 1) % 2;
			if (viewFeed){
				this->videoBtn->Text = "CLOSE VIDEO FEED";
				System::ComponentModel::ComponentResourceManager^  res = (gcnew System::ComponentModel::ComponentResourceManager(MainScreen::typeid));
				this->videoBtn->Image = (cli::safe_cast<System::Drawing::Image^>(res->GetObject(L"videoBtnCLOSE.Image")));
				this->logEvent("Video Feed Opened");
			}
			else{
				this->videoBtn->Text = "OPEN VIDEO FEED";
				System::ComponentModel::ComponentResourceManager^  res = (gcnew System::ComponentModel::ComponentResourceManager(MainScreen::typeid));
				this->videoBtn->Image = (cli::safe_cast<System::Drawing::Image^>(res->GetObject(L"videoBtn.Image")));
				this->logEvent("Video Feed Closed");
			}
		}
		else{
			MessageBox::Show("Camera not accessible or Video Recording has stopped.");
		}
	}

	private: static void logEvent(System::String^ text){		//Function used to log events on RichTextBox
		char str[100];
		getStdStringTime(" %d/%m/%y %H:%M:%S - ", str, time(0));
		System::String^ timeLog = gcnew System::String(str);

		if (eventLogTxt->InvokeRequired){
			SetText(eventLogTxt, timeLog + text + "\n");
		}
		else{
			eventLogTxt->Text += timeLog + text + "\n";
		}
		if (logFile != NULL){			//Write to text file
			fprintf(logFile, (const char *)(Marshal::StringToHGlobalAnsi(timeLog + text + "\n")).ToPointer());
			fclose(logFile);
			char cDate[70];																		//Close to save content
			getStdStringTime("C:\\EMSS_video_recordings\\Logs\\%Y-%m-%d.txt", cDate, time(0));	//Reopen Textfile
			logFile = fopen(cDate, "a");
		}
	}
	public: static void getStdStringTime(char * text, char str[], time_t timer){
		struct tm time_info;
		localtime_s(&time_info, &timer);
		strftime(str, 100, text, &time_info);
	}
	public: static void cleanOldVideos(){					//Function to delete old videos
		//Cleaning all old videos (less than two months old)
		time_t limitDate = time(0) - (video_age);			//Get limit date
		char limitDateChar[100];
		//Convert to DateTime format
		getStdStringTime("%Y-%m-%d %H:%M:%S", limitDateChar, limitDate);
		System::String^ limitDateString = gcnew System::String(limitDateChar);
		MySqlConnection^ conDataBase;
		try{
			logEvent("Deleting old videos...");
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			//Find videos older than date limit
			MySqlCommand^ readSQL = gcnew MySqlCommand("SELECT * FROM `emss_database`.`video_recording` WHERE `video_recording`.`date` < '" + limitDateString + "';", conDataBase);
			MySqlDataReader^ readReader = readSQL->ExecuteReader();
			//Delete videos
			while (readReader->Read()){
				System::String^ filePathSys = readReader->GetString("filepath");
				const char * chars = (const char *)(Marshal::StringToHGlobalAnsi(filePathSys)).ToPointer();
				std::string filePathStd = chars;
				if (remove(filePathStd.c_str()) == 0){
					DatabaseQueries^ msql = gcnew DatabaseQueries();
					msql->setQuery("DELETE FROM `emss_database`.`video_recording` WHERE `video_recording`.`date` < '" + limitDateString + "';");
				}
			}
			readReader->Close();
			conDataBase->Close();
		}
		catch (System::Exception^ ex){
			MessageBox::Show("ERROR deleting old videos.");
		}
	}
	private: System::Void exitBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Are you sure you want to SHUTDOWN the system?", "ALERT!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
			this->~MainScreen();
		}
	}
	private: void loadSettings(){			//Reads and applies settings from the database
		MySqlConnection^ conDataBase;
		try{
			conDataBase = gcnew MySqlConnection(L"datasource=localhost; port = 3306; username = emss_admin; password = ENEL4CA-g5");
			conDataBase->Open();
			MySqlCommand^ readSQL = gcnew MySqlCommand("SELECT * FROM `emss_database`.`settings` WHERE `settings`.`settings_id` = 1;", conDataBase);
			MySqlDataReader^ reader = readSQL->ExecuteReader();
			if (reader->Read()){
				this->video_length = reader->GetInt32("video_length_s");
				this->video_max_size = (long long)(reader->GetInt32("video_max_size_m")) * (long long)1048576;
				this->video_age = (long long)(reader->GetInt32("video_age_m") * 2592000);
				this->camera_IP = reader->GetString("camera_ip");
				this->etas_IP = reader->GetString("etas_ip");
				this->server_port = reader->GetInt32("server_port");
				logEvent("Custom settings successfully loaded.");
			}
			else{
				logEvent("Cannot read custom settings. Reverting to default settings.");
			}
			reader->Close();
			conDataBase->Close();
		}
		catch (System::Exception^ ex){
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void eventLogTxt_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->eventLogTxt->Select(eventLogTxt->Text->Length - 1, 0);
		this->eventLogTxt->ScrollToCaret();
	}
};
}
#endif