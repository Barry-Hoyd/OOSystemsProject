#include "FileReadWrite.h"

void FileReadWrite::clearGameLog()
{
	ofstream gameLogFile;
	gameLogFile.open("C:\\Users\\boydh\\source\\repos\\Project1\\GameLog.txt", ofstream::out | ofstream::trunc);
	gameLogFile.close();
}

void FileReadWrite::displayFile(string filePath)
{
	ifstream Menuinput(filePath);
	if (Menuinput.is_open())
	{
		while (getline(Menuinput, line))
		{
			cout << line << "\n";
		}
	}
	else
	{
		cout << "could not find file path";
	}
	Menuinput.close();
}

void FileReadWrite::writeToFile(string message)
{
	ofstream gameLogFile;
	gameLogFile.open("C:\\Users\\boydh\\source\\repos\\Project1\\GameLog.txt", ios::app);
	if (gameLogFile.is_open())
	{
			gameLogFile << message << endl;	
	}
	gameLogFile.close();
}
