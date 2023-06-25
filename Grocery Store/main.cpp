#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "program.h"
using namespace std;

int main() {

	InventoryCount GroceryList; //Creates new class member
	GroceryList.ReadItems(); //Reads file first to create map of items
	GroceryList.WriteToNewFile(); //Creates backup file, user will not be aware of this operation
	
	while (true) { //loop will continue to prompt user for input until 4 "exit" is entered
		
		int result = GroceryList.PrintMenu();
		if (result < 1 && result > 4) { //Input validation ensuring 1-4 is entered
			GroceryList.PrintMenu();
		}
		else if (result == 1) { //Option 1 allows user to search list for an item
			GroceryList.GetInput();
			cout << endl;
			GroceryList.ItemSearch();
			cout << endl;
		}
		else if (result == 2) { //Option 2 prints the entire list with their frequency values
			GroceryList.PrintItemCount();
			cout << endl;
		}
		else if (result == 3) { //Option 3 prints the list formatted into a histogram
			GroceryList.PrintHistogram();
			cout << endl;
		}
		else if (result == 4) { //Exits program
			break;
		}
	}
	return 0;
}