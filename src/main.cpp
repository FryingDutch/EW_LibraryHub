#define CROW_MAIN
#include "crow.h"
#include "EW_FileHandler.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    crow::SimpleApp app;
    EW_FileHandler::setWorkDir("/files/");
    CROW_ROUTE(app, "/hello")([]() 
    {
        EW_FileHandler::createFile("newFile.txt", "Hello buddy!");
        return EW_FileHandler::readFile("newFile.txt");
    });

    uint16_t port = std::stoi(argv[1]);

    for(size_t i = 0; i < argc; i++)
        std::cout << argv[i] << "\n";
    
    app.port(port).run();
}