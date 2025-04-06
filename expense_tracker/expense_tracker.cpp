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

std::vector<std::string> SplitCommand(const std::string &input, char delimiter) {
	std::vector<std::string> result;
	std::stringstream stringStream (input);
	std::string item;
	
	while (getline(stringStream, item, delimiter)) {
		result.push_back(item);
	}

	return result;
}

void DetermineInput(std::string command, Expense *userExpense) {
	std::vector<std::string> commandList;

	commandList = SplitCommand(command, ' ');

	if (commandList.at(0) != "expense-tracker") {
		std::cout << "Incorrect format; Please try again..." << std::endl;
		return;
	}

	if (commandList.at(1) == "add") {
		
	}
	else if (commandList.at(1) == "summary") {

	}
	else if (commandList.at(1) == "list") {

	}
	else if (commandList.at(1) == "delete") {

	}
	else if (commandList.at(1) == "print") {
		for (auto& i : commandList) std::cout << i << std::endl;
	}
	else {
		std::cout << "Incorrect input flag format; Please try again..." << std::endl;
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

		DetermineInput(inputCommand, &userExpense);
	}

	return 0;
}
