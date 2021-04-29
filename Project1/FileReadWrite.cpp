#include "FileReadWrite.h"

void FileReadWrite::clearGameLog()
{
	//clears game log at start of the game
	ofstream gameLogFile;
	//PC filepath
	gameLogFile.open("C:\\Users\\boydh\\source\\repos\\Project1\\GameLog.txt", ofstream::out | ofstream::trunc);
	//Laptop filepath
	//gameLogFile.open("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\GameLog.txt", ofstream::out | ofstream::trunc);
	gameLogFile.close();
}

void FileReadWrite::displayFile(string filePath)
{
	//used to display the ASCII art for the player
	ifstream Menuinput(filePath);
	if (Menuinput.is_open()) //checks if the file path is valid
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
	//write stats to game log
	ofstream gameLogFile;
	//PC filepath
	gameLogFile.open("C:\\Users\\boydh\\source\\repos\\Project1\\GameLog.txt", ios::app);
	//Laptop filepath
	//gameLogFile.open("C:\\Users\\boydh\\source\\repos\\OOSystemsProject\\GameLog.txt", ios::app);
	if (gameLogFile.is_open())
	{
		gameLogFile << message << endl;
	}
	else
	{
		std::cout << "Cannot find file path!";
	}
	gameLogFile.close();
}
