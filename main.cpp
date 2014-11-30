#include <iostream>
#include <cstdlib>

#include "AICupApp.hpp"

using namespace std;

using namespace AICup;

int main(int argc, const char* argv[])
{
    cout << "PvP or Zassal Server!" << endl;

    if(argc < 2) {
        AICupApp cup(2517);

        return cup.Run();
    } else {
        AICupApp cup(atoi(argv[1]));

        return cup.Run();
    }

    return 1;
}

