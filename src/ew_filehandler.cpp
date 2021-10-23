#include "EW_FileHandler.h"

std::string EW_FileHandler::workDir{ "" };
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
	std::ifstream file(_sourcePath);

	if (file)
	{
		std::ofstream newFile(_destinationPath);

		if (newFile)
		{
			newFile << file.rdbuf();
			newFile.close();
		}

		file.close();
	}
}

void EW_FileHandler::readFile(const char* _name)
{
	std::string fullPath{ workDir + _name };

	std::ifstream file(fullPath);
	if (file)
		std::cout << file.rdbuf() << "\n\n";
	else
		std::cerr << fullPath << " not found.\n\n";
}

void EW_FileHandler::writeToFile(const char* _name, const char* _msg)
{
	std::string fullPath{ workDir + _name };

	std::ifstream searchFile(fullPath);
	if (searchFile)
	{
		searchFile.close();
		std::ofstream newFile(fullPath);

		if (newFile)
		{
			newFile << _msg << "\n";
			newFile.close();
		}
		else std::cerr << "Error writing to file\n";
	}
	else std::cerr << "File does not exist\n";
}

void EW_FileHandler::removeFile(const char* _name)
{
	std::string fullPath{ workDir + _name };
	if (remove(fullPath.c_str()) != 0) std::cerr << "Error Deleting File " << fullPath << "\n";
	else std::cout << fullPath << " removed succesfully\n";
}