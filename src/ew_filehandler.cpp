#include <sstream>
#include <fstream>
#include "EW_FileHandler.h"

std::string EW_FileHandler::workDir{ "/" };
std::ifstream EW_FileHandler::readFiles;
std::ofstream EW_FileHandler::writefiles;

void EW_FileHandler::setWorkDir(const char* _path)
{
	workDir = _path;
}

bool EW_FileHandler::checkExistence(const char* _name)
{
	std::string fullPath{ EW_FileHandler::workDir + _name };

	readFiles.open(fullPath);
	if (readFiles)
	{
		readFiles.close();
		return true;
	}
	return false;
}

void EW_FileHandler::createFile(const char* _path, const char* _msg)
{
	std::string fullPath{ workDir + _path };

	std::ofstream newFile(fullPath);
	if (newFile)
	{
		static const char* emptyString = "";
		if (_msg != emptyString)
			newFile << _msg;
		newFile.close();
	}
	else std::cerr << "Error creating File\n";
}

void EW_FileHandler::copyFile(const char* _sourcePath, const char* _destinationPath)
{
	std::string fullPath{ workDir + _sourcePath };

	std::ifstream file(fullPath.c_str());

	if (file)
	{
		std::ofstream copyFile(_destinationPath);

		if (copyFile)
		{
			copyFile << file.rdbuf();
			copyFile.close();
		}

		file.close();
	}
}

std::string EW_FileHandler::readFile(const char* _name)
{
	std::string fullPath{ workDir + _name };
	std::ostringstream ss;
	std::string result;

	std::ifstream fileToRead(fullPath);
	if (fileToRead)
	{
		ss << fileToRead.rdbuf();		
		fileToRead.close();
		return ss.str();
	}
	else
	{
		result = "file not found";
		return result;
	}
}

void EW_FileHandler::writeToFile(const char* _name, const char* _msg)
{
	std::string fullPath{ workDir + _name };

	if (checkExistence(fullPath.c_str()))
	{
		std::ofstream writeFile(fullPath);

		if (writeFile)
		{
			writeFile << _msg << "\n";
			writeFile.close();
		}
		else 
			std::cerr << "Error writing to file\n";
	}
	else 
		std::cerr << "File does not exist\n";
}

void EW_FileHandler::removeFile(const char* _name)
{
	std::string fullPath{ workDir + _name };
	if (remove(fullPath.c_str()) != 0) 
		std::cerr << "Error Deleting File " << fullPath << "\n";
	else 
		std::cout << fullPath << " removed succesfully\n";
}