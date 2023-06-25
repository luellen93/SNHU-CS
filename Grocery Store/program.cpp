#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include "program.h"
using namespace std;


void InventoryCount::ReadItems() { //Method used to read in txt file
	ifstream itemsFS; //Used to open the file stream
	string itemLine; //Variable that will hold each line of the file
	

	itemsFS.open("CS210_Project_Three_Input_File.txt"); //Opens the text file

	if (!itemsFS.is_open()) { //Checks to see if the file opened correctly
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
	}

	while (!itemsFS.fail()) { //Makes sure each line is read properly
		getline(itemsFS, itemLine); //Reads each line of file
		for (int i = 0; i < itemLine.length(); ++i) { //Converts each word to lower for easier search later
			itemLine[i] = tolower(itemLine[i]);
		}
		
		if (this->items.count(itemLine) == 0) { //Determines if word is already in the map
			this->items.emplace(itemLine, 1); //Adds word to map if not already there and sets value to 1
		}
		else {
			this->items.at(itemLine) += 1; //Increments value of existing item in map
		}
	}
}

int InventoryCount::PrintMenu() { //Prints initial menu for the user to interract with

	int userOption;
	cout << "Option 1: Search for item frequency" << endl;
	cout << endl;
	cout << "Option 2: Print full list of items with frequencies" << endl;
	cout << endl;
	cout << "Option 3: Print histogram for all items" << endl;
	cout << endl;
	cout << "Option 4: Exit program" << endl;
	cout << endl;
	cout << "Please select an option: ";
	cin >> userOption;
	cout << endl;

	return userOption;
}

void InventoryCount::GetInput() { //Method used to get item name for search

	cout << "Enter an item name: " << endl;
	cin >> this->userInput; //Takes item name from user

	for (int i = 0; i < userInput.length(); ++i) { //Converts user input to lower case for easier search
		userInput[i] = tolower(userInput[i]);
	}

}

void InventoryCount::PrintItemCount() { //Prints item list with frequency seen for each item
	
	for (auto it = this->items.begin(); it != this->items.end(); ++it) { //For loop for iteration through list
		// Access the key and value of the current element
		string key = it->first; //String variable contains the item name and a pointer is used to point at each 
		int value = it->second; //Int variable contains the frequency each item is listed

		cout << key << " " << value << endl;
	}
}

void InventoryCount::ItemSearch() { //Method for searching through the map for item entered

	if (this->items.count(this->userInput) == 0) { //Determines if item is in the map at all
		cout << this->userInput << " " << 0 << endl; //If item not in map then input is returned with 0
	}

	else if (this->items.count(this->userInput) == 1) { //If item is in the map then item is printed with frequency value
		cout << this->userInput << " " << this->items.at(this->userInput) << endl;
	}
}

void InventoryCount::PrintHistogram() {
	for (auto it = this->items.begin(); it != this->items.end(); ++it) {
		// Access the key and value of the current element
		string key = it->first; //Same iterator is used in the PrintItemCount method but print format is different
		int value = it->second;

		cout << key << "| ";
		for (int j = 0; j < this->items.at(key); ++j) { //Nested for loop used to print * as many times as needed
			cout << "*";
		}
		cout << endl;
	}
}

void InventoryCount::WriteToNewFile() { //Method for writing to .dat file
	ofstream outFS; 

	outFS.open("frequency.dat"); //Opens file

	if (!outFS.is_open()) { //Checks to see if file opened successfully
		cout << "Could not open file frequency.dat." << endl;
	}

	for (auto it = this->items.begin(); it != this->items.end(); ++it) {
		// Access the key and value of the current element
		string key = it->first; //Same method used in PrintItemCount method
		int value = it->second;

		outFS << key << " " << value << endl;
	}

	outFS.close(); //Closes file
}