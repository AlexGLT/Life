#include "Application.h"

#include <iostream>

int main(int argc, char* args[])
{
    try
    {
        Application application;
        application.execute();
    }
    catch (const std::runtime_error& error)
    {
        std::cerr << error.what() << '\n';
    }

	return 0;
}
