#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileReadWrite
{
private:
	string line = "";
	
public:
	void clearGameLog();

	void displayFile(string filePath);

	void writeToFile(string message);
};

