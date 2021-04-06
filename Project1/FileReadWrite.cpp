#include "FileReadWrite.h"

void FileReadWrite::DisplayFile(string filePath)
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
