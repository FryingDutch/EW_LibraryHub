#include <sstream>
#include <fstream>

class EW_File
{
private:
	std::string location = "files/";

public:
	std::stringstream data;

public:
	EW_File() = default;
	EW_File(const char* _path)
	{
		location += _path;
		std::ifstream __file(location);
		if (__file)
		{
			data << __file.rdbuf();
			__file.close();
		}
	}

	std::string getLocation() { return location; }
};