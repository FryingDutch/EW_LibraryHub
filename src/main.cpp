#define CROW_MAIN
#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/hello")([]() {
        return "Hello world";
    });

    app.port(8000).run();
}