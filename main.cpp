/*
*   Filename: main.cpp
*   Created on: Jan. 26, 2023
*   Authors: Veenkamp, James, Brooks
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "header.h"
#include "LoginTest.h"
using namespace std;

int main()
{
  std::cout << "Please enter 1 to login, or 2 to create an account." << std::endl;
	std::cin >> loginChoice;
	//Ensure that loginChoice is a number
	while(validInput(loginChoice) == false) {
		std::cout << "Invalid selection. Please enter 1 to login, or 2 to create an account." << std::endl;
		std::cin.clear();
		std::cin >> loginChoice;
		continue;
	}
	//Convert validated input to integer
	loginNumber = stoi(loginChoice);
	//Select login or new user
	while(loginNumber != 0){
		switch(loginNumber){
		//Returning user login
		case 1:
		    cout << "Enter username: ";
		    cin >> username;
		    cout << "Enter password: ";
		    cin >> password;
		    //Greet user on success, or allow them to make a new selection upon failure
		    if (returningUserLogin(username, password)) {
		        cout << "Welcome back, " << username << "." << endl;
		    }
		    else {
		        cout << "Incorrect username or password. Please enter 1 to login, or 2 to create an account." << endl;
		        std::cin.clear();
		        std::cin >> loginNumber;
		        break;
		    }
		    std::cin.clear();
		    loginNumber = 0;
		    break;
		//New user account creation
		case 2:
			std::cout << "Create a username: ";
			std::cin >> nUsername;
			std::cout << "Create a password: ";
			std::cin >> nPassword;
			//Write new user info to login.csv
			createNewAccount(CSVfilename, nUsername, nPassword);
			std::cin.clear();
			loginNumber = 0;
			break;
		//If user did not enter 1 or 2
		default:
			std::cout << "Invalid selection. Please enter 1 to login, or 2 to create an account." << std::endl;
			std::cin.clear();
			loginNumber = 0;
			std::cin >> loginNumber;
			break;
		}
	}

  rapidcsv::Document doc("");
  vector<string> col = doc.GetColumn<string>("ISBN");
  cout << "Read " << col.size() << " values." << endl;
}
