#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

struct EW_FileHandler
{
private:
	static std::string workDir;
	static std::ifstream readFiles;
	static std::ofstream writefiles;

public:
	static void setWorkDir(const char* _path);
	static void createFile(const char* _name, const char* _msg = "");
	static void copyFile(const char* _sourcePath, const char* _destinationPath);
	static void readFile(const char* _name);
	static void writeToFile(const char* _name, const char* _msg);
	static void removeFile(const char* _name);

	static bool checkExistence(const char* _name);
}; 