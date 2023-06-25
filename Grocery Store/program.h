#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class InventoryCount {

public:
	void ReadItems();
	void GetInput();
	int PrintMenu();
	void ItemSearch();
	void PrintItemCount();
	void PrintHistogram();
	void WriteToNewFile();

private:
	map<string, int> items; //Map variable used to store item and frequency value
	string userInput;
};

