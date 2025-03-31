#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

class Expense {
public:
	int id;
	int amount;
	std::string description;

	void AddExpense(std::string input) {
		this->id = 5;
		this->amount = stoi(input);
	}

	void PrintExpense() {
		std::cout << "ID" << " " << "Amount" << std::endl;
		std::cout << id << " " << amount << std::endl;
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

	int idTracker;

	while (isRunning) {
		std::cin >> inputCommand;

		if (inputCommand == "exit") {
			std::cout << "Shutting down...";
			isRunning = false;
			break;
		}

		if (!isExpense && inputCommand.substr(0, 15) != "expense-tracker") {
			std::cout << "Incorrect format for command.\nCorrect format is expanse-tracker.\n";
			isExpense = true;
			continue;
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
