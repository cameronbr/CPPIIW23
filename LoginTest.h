/*
 * LoginTest.h
 *
 *  Created on: Jan 29, 2023
 *      Author: Cameron Brooks
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#ifndef LOGINTEST_H_
#define LOGINTEST_H_

std::string username, password, nUsername, nPassword, loginChoice;
std::string CSVfilename = "login.csv";
std::ofstream myFile;
int loginNumber;

//Write new entry to CSV file
void createNewAccount(std::string file_name, std::string user_name, std::string pass_word) {
	//open csv file
	myFile.open(CSVfilename, std::ios_base::app);
	//Exception handling
	if(!myFile.is_open()){
		std::cerr << "Failed to open file " << file_name << std::endl;
		return;
	}
	//write username and password delimited by comma
	myFile << nUsername << "," << nPassword << std::endl;
	myFile.close();

	std::cout << "Thank you for creating an account with us." << std::endl;


}

//Search csv file for user information
bool returningUserLogin(std::string username, std::string password) {
    std::string line;
    std::ifstream file("login.csv");
    //Exception handling
    if (!file.is_open()) {
      std::cerr << "Failed to open file: login.csv" << std::endl;
      return false;
    }
    //Search csv file for username and password
    while (getline(file, line)) {
        int delimiterPos = line.find(',');
        std::string storedUsername = line.substr(0, delimiterPos);
        std::string storedPassword = line.substr(delimiterPos + 1);

        if (username == storedUsername && password == storedPassword) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

//Validate whether or not user input for login selection is number
bool validInput(std::string input) {

	for (int i = 0; i < input.length(); i++) {
		if (isdigit(input[i]) == false) {
			return false;
		}
	}
	if (input[0] == '0') {
		return false;
	}
	return true;
}


#endif /* LOGINTEST_H_ */
