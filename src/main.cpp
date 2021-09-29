#include "EW_FileHandler.h"


int main(int argc, char* argv[])
{
	typedef EW_FileHandler fh;

	enum : char
	{
		COPY = 'c', DELETE = 'd', NEW = 'n', READ = 'r', WRITE = 'w'
	};

	for (size_t flag = 0; flag < argc; flag = +2)
	{
		if (argc % 2 == 0)
		{
			switch (*argv[flag])
			{
			case DELETE:
				fh::removeFile(argv[flag + 1]);
				break;

			case NEW:
				fh::createFile(argv[flag + 1]);
				break;

			case READ:
				fh::readFile(argv[flag + 1]);
				break;

			default:
				break;
			}
		}

		else if (*argv[flag] == COPY)
		{
			fh::copyFile(argv[flag + 1], argv[flag + 2]);
			flag++;
		}
	}
}