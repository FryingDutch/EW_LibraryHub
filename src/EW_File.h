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