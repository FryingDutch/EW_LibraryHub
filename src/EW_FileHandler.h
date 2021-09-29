#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>

struct EW_FileHandler
{
public:
	static const char* workDir;
	static void createFile(const char* _path, const char* _msg = "")
	{
		std::ifstream __checkExistence(_path);
		if (!__checkExistence)
		{
			std::ofstream __newFile(_path);

			if (__newFile)
			{
				if (_msg != "")
					__newFile << _msg;
				__newFile.close();
			}
			else std::cerr << "Error creating File\n";
		}
		else std::cerr << "File already exists\n";
	}

	static void copyFile(const char* _sourcePath, const char* _destinationPath)
	{
		std::ifstream __file(_sourcePath);

		if (__file)
		{
			std::ofstream __newFile(_destinationPath);

			if (__newFile)
			{
				__newFile << __file.rdbuf();
				__newFile.close();
			}

			__file.close();
		}
	}

	static void readFile(const char* _path)
	{
		std::ifstream __file(_path);
		if (__file)
			std::cout << __file.rdbuf() << "\n\n";
		else
			std::cerr << _path << " not found.\n\n";
	}

	static void removeFile(const char* _path)
	{
		if (remove(_path) != 0) std::cerr << "Error Deleting File " << _path << "\n";
		else std::cout << _path << " removed succesfully\n";
	}
}; 