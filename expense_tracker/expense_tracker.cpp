#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <ctime>
#include <sstream>

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
		std::cout << "ID" << '\t' << "Date" << "\t" << "Description" <<  "\t\t" << "Amount" << std::endl;
		std::cout << id << '\t' << formattedDate << "\t" << description << "\t" << amount << std::endl;
	}
};

std::vector<std::string> SplitCommand(const std::string& s, char delimiter) {
	std::vector<std::string> result;
	std::stringstream stringStream (s);
	std::string item;
	
	while (std::getline(stringStream, item, delimiter)) {
		result.push_back(item);
	}

	return result;
}

void DetermineInput(std::string command) {
	std::vector<std::string> commandList;

	commandList = SplitCommand(command, ' ');


	for (int i = 0; i < commandList.size(); i++) {
		std::cout << command.at(i) << ' ';
	}
}

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

	std::vector<Expense> userExpenses;

	while (isRunning) {
		std::getline(std::cin, inputCommand);

		if (inputCommand == "exit") {
			std::cout << "Shutting down...";
			isRunning = false;
			break;
		}

		// DetermineInput(inputCommand);

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
