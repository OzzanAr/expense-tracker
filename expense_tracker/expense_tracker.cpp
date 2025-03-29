#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    bool isRunning = true;
    std::string inputCommand;
    std::string description;
    int amount;


    while (isRunning) {
		std::cin >> inputCommand;

        if (inputCommand == "exit") {
            std::cout << "Shutting down...";
            isRunning = false;
            break;
        }

        if (inputCommand.substr(0, 15) != "expanse-tracker") {
            std::cout << "Incorrect format for command.\nCorrect format is expanse-tracker.\n";
        }

        std::cout << inputCommand.substr(0, 15) << std::endl;
    }


    return 0;
}
