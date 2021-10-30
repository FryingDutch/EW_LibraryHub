#define CROW_MAIN
#include "crow.h"
#include <cpr/cpr.h>
#include "EW_FileHandler.h"
#include <iostream>
#include <string>

bool dev = true;

int main(int argc, char* argv[])
{
    if (!dev)
    {
        crow::SimpleApp app;
        EW_FileHandler::setWorkDir("/files/");
        CROW_ROUTE(app, "/hello")([]()
        {
            EW_FileHandler::createFile("newFile.txt", "Hello buddy!");
            return EW_FileHandler::readFile("newFile.txt");
        });

        uint16_t port = std::stoi(argv[1]);

        for (size_t i = 0; i < argc; i++)
            std::cout << argv[i] << "\n";

        app.port(port).run();
    }

    else if (dev)
    {
        cpr::Response r = cpr::Get(cpr::Url{ "http://85.214.137.31:8000/hello" });
        std::cout << r.text << "\n"; 
    }
}