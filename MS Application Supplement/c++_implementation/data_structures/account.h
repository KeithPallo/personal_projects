// Homework 1 Header file

#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// For simplicity, this header file contains all the information for the account structure / class.

struct account
{
	// Create variables for structure account.
	 
	int id;               // Represents the id for the account. Must be of type integer
	std::string owner;    // Represents the name of the owner of the current account
	int balance;          // Represents the current balance in the account

	void credit(int credit)
		// Function to add credit to the account
	{
		// Increase the account's balance by the input credit ammount
		balance += credit; 

	};

	void transfer(account *recieve, int value)
		// Function to transfer credit from current account to account "recieve"
	{
		// Remove credit from current account. Implementation assumes unlimited debt allowance
		balance -= value; 

		// Place credit into new account
		recieve->credit(value); 

	};

	void display()
		// Function to display account information
	{
		// Print the appropriate information
		cout << "Account id: " << id << ", Owner: " << owner << ", Current Balance: " << balance << endl;
	};


};