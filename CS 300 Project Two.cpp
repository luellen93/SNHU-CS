#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "CSVparser.hpp"


//Brandon Luellen

// Define the Course and Parser classes here (or include the appropriate headers)

// Function to load data from a file into the data structure.
void LoadDataStructure(Parser& parser) {
    std::string fileName;
    std::cout << "Enter the file name to load course data: ";
    std::cin >> fileName;

    try {
        parser = Parser(fileName, DataType::eFILE, ',');
        std::cout << "Data loaded successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to print an alphanumeric list of all courses in the Computer Science department.
void PrintCourseList(const Parser& parser) {
    // Implement this function to filter and print Computer Science courses.
    // You can use the parser to access course data.
    // Ensure the courses are sorted alphabetically.
}

// Function to print course information based on course number.
void PrintCourseInformation(const Parser& parser) {
    std::string courseNumber;
    std::cout << "Enter the course number: ";
    std::cin >> courseNumber;

    // Implement this function to retrieve and print course information.
    // You can use the parser to access course data.
    // Ensure you print the course title and prerequisites.
}

int main() {
    Parser parser; // Initialize an empty parser.

    while (true) {
        std::cout << "\nMenu Options:\n";
        std::cout << "1. Load Data Structure\n";
        std::cout << "2. Print Course List\n";
        std::cout << "3. Print Course Information\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                LoadDataStructure(parser);
                break;
            case 2:
                PrintCourseList(parser);
                break;
            case 3:
                PrintCourseInformation(parser);
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                std::cerr << "Invalid choice. Please enter a valid option (1-4).\n";
        }
    }

    return 0;
}
