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
			case 'd':
				fh::removeFile(*argv[flag + 1]);
				break;

			case 'n':
				fh::createFile(*argv[flag + 1]);
				break;

			case 'r':
				fh::readFile(*argv[flag + 1]);
				break;

			default:
				break;
			}
		}

		else if (*argv[flag] == 'c')
		{
			fh::copyFile(*argv[flag + 1], *argv[flag + 2]);
		}

		else if (*argv[flag] == 'w')
		{
			fh::writeToFile(*argv[flag + 1], *argv[flag + 2]);
		}
	}
}