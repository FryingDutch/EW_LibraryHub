#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class EW_File
{
private:
	const char* location;

public:
	std::stringstream data;

public:
	EW_File() = default;
	EW_File(const char* _path) :
		location(_path) 
	{
		std::ifstream __file(_path);
		if (__file)
		{
			data << __file.rdbuf();
			__file.close();
		}
	}

	const char* getLocation() { return location; }
};

class EW_LibraryHub
{
private:
	std::vector<EW_File> files;

public:
	EW_LibraryHub() = default;

	void createFile(const char* _path)
	{
		std::ofstream __newFile(_path);

		if (__newFile)
			__newFile.close();
		else std::cerr << "Error creating File\n";
	}

	void copyFile(const char* _sourcePath, const char* _destinationPath)
	{
		std::stringstream __data;
		std::ifstream __file(_sourcePath);

		if (__file)
		{
			__data << __file.rdbuf();
			__file.close();

			std::ofstream __newFile(_destinationPath);

			if (__newFile)
				__newFile << __data.rdbuf() << std::endl;
		}
	}

	void readFile(size_t _index)
	{
		if (_index < files.size() && _index >= 0) 
			std::cout << files[_index].data.str() << "\n\n";
		else 
			std::cout << "Index out of bounds\n\n";
	}

	void removeFile(const char* _path)
	{
		if (remove(_path) != 0) std::cerr << "Error Deleting File " << _path << "\n";
		else std::cout << _path << " removed succesfully\n";
	}
};

int main(int argc, char* argv[])
{
	EW_LibraryHub libHub;
	libHub.removeFile("C:/dev/data2.txt");
	libHub.createFile("C:/dev/data2.txt");
	libHub.removeFile("C:/dev/data2.txt");
}