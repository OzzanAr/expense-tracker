#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <ctime>

class Expense {
public:
	int id;
	int amount;
	std::string description;
	std::string formattedDate;

	time_t timestamp;
	struct tm datetime;

	void AddExpense(std::string input) {
		this->id = 5;
		this->amount = stoi(input);

		timestamp = time(nullptr);
		localtime_s(&datetime, &timestamp);

		formattedDate = std::to_string(datetime.tm_year + 1900) + '-' +
			std::to_string(datetime.tm_mon + 1) + '-' +
			std::to_string(datetime.tm_mday);
	}

	void PrintExpense() const {
		std::cout << "ID" << '\t' << "Date" << "\t\t" << "Amount" << std::endl;
		std::cout << id << '\t' << formattedDate << "\t" << amount << std::endl;
	}
};

int main()
{
	bool isRunning = true;
	bool isExpense = false;
	bool isAdd = false;

	// Type inputType;
	Expense userExpense;

	std::string inputCommand;
	std::string description;
	std::string initInput;

	int idTracker;

	while (isRunning) {
		std::cin >> inputCommand;

		if (inputCommand == "exit") {
			std::cout << "Shutting down...";
			isRunning = false;
			break;
		}

		if (!isExpense) {
			initInput = inputCommand.substr(0, 15);
			if (initInput == "expense-tracker") {
				isExpense = true;
			}
			else
			{
				std::cout << "Incorrect format for command.\nCorrect format is expanse-tracker.\n";
			}
		}

		if (inputCommand == "add"){ 
			std::cout << "Added expense\n";
			// inputType = ADD;
			isAdd = true;
			continue;
		}

		if (isAdd) {
			userExpense.AddExpense(inputCommand);
			isAdd = false;
			isExpense = false;
			continue;
		}

		if (inputCommand == "list"){ 
			userExpense.PrintExpense();
			isExpense = false;
		}
	}

	return 0;
}
