#pragma once
#include<fstream>
#include<iostream>
#include<ctime>

using namespace std;

class Logger
{
private:
	ofstream logFile;	
	void logEntry(const char* msg)
	{
		struct tm newtime;
		__time32_t aclock;
		char buffer[32];
		errno_t errNum;
		_time32(&aclock);   // Get time in seconds.
		_localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.
		
		// write it to the buffer
		errNum = asctime_s(buffer, 32, &newtime);

		char theTime[9];
		memcpy(theTime, &buffer[11], 8);
		theTime[8] = '\0';

		char theDate[11];
		memcpy(theDate, &buffer[0], 10);
		theDate[10] = '\0';

		char theYear[5];
		memcpy(theYear, &buffer[20], 4);
		theYear[4] = '\0';

		int pad = 75 - strlen(msg);
		cout << theTime << " " << theDate << ", " << theYear << " - " << msg << endl;
		logFile << theTime << " " << theDate << ", " << theYear << " - " << msg << endl;
	}
public:
	Logger() 
	{	
		logFile.open("log.txt");
		logEntry("Logger initialized.");
	}
	~Logger() 
	{
		logEntry("Logger destroyed.");
		logFile.close();
	};
	void write(const char* msg)
	{
		logEntry(msg);
	}
};
