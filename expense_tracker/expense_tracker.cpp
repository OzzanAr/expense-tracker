#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <ctime>
#include <sstream>

std::string StripQuotes(const std::string& input) {
	if (input.length() >= 2 && input.front() == '"' && input.back() == '"') {
		return input.substr(1, input.length() - 2);
	}
	return input;
}

class Expense {
public:
	int id;
	int amount = 0;
	std::string description = "Empty";
	std::string formattedDate;

	time_t timestamp;
	struct tm datetime;

	void AddExpense(std::vector<std::string> &input) {
		this->id = 5;

		for (size_t i = 2; i + 1 < input.size(); i += 2) {
			const std::string& flag = input.at(i);
			const std::string& value = input.at(i + 1);

			try {
				if (flag == "--amount") {
					this->amount = stoi(value);
				}
				else if (flag == "--description") {
					this->description = StripQuotes(value);
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing value for " << flag << ": " << e.what() << std::endl;
			}
		}

		timestamp = time(nullptr);
		localtime_s(&datetime, &timestamp);

		formattedDate = std::to_string(datetime.tm_year + 1900) + '-' +
			std::to_string(datetime.tm_mon + 1) + '-' +
			std::to_string(datetime.tm_mday);
	}

	void PrintExpense() const {
		std::cout << "ID" << '\t' << "Date" << "\t\t" << "Description" <<  "\t\t" << "Amount" << std::endl;
		std::cout << id << '\t' << formattedDate << "\t" << description << "\t\t\t" << amount << std::endl;
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

void DetermineInput(std::string command, Expense &userExpense) {
	std::vector<std::string> commandList;

	commandList = SplitCommand(command, ' ');

	if (commandList.at(0) != "expense-tracker") {
		std::cout << "Incorrect format; Please try again..." << std::endl;
		return;
	}

	if (commandList.at(1) == "add") {
		userExpense.AddExpense(commandList);
	}
	else if (commandList.at(1) == "summary") {
		// TO-DO
	}
	else if (commandList.at(1) == "list") {
		userExpense.PrintExpense();
	}
	else if (commandList.at(1) == "delete") {
		// TO-DO
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

		DetermineInput(inputCommand, userExpense);
	}

	return 0;
}
