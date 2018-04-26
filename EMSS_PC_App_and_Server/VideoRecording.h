#include <string>
#include <ctime>
#pragma once

using namespace std;

public ref class VideoRecording{
private: 
	System::DateTime^ date;
	System::String^ filepath;
public:
	VideoRecording(void);
	void record();
	void playback();
	void del();
	~VideoRecording(void);
};

