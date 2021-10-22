#include "EW_FileHandler.h"
#include "crow.h"

bool isDigit(std::string& str)
{
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i])) return false;
		}
		return true;
	}
}

int main()
{ 
	crow::SimpleApp	app;
}