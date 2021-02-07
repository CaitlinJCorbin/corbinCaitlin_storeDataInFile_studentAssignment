//////////////////////////////////////////////////
//	Caitlin J. Corbin							//
//	Nov. 7, 2020								//
//	M01 Programming Assignment - File I/O		//
//	"File based program to store data."			//
//////////////////////////////////////////////////

#include <iostream>		// Header files
#include <fstream>

using namespace std;	// Standard library

void showMenu() {									// Prints menu options when called
	cout << "*********MENU*********" << endl;
	cout << "1 - Add a pet" << endl;
	cout << "2 - View pets" << endl;
	cout << "3 - Exit" << endl;
	cout << "**********************" << endl;
}

void addPet(string name, string species, string breed, string color) {		// Adds data to a txt file
	ofstream myfile;
	myfile.open("petDatabase.txt", ios_base::app);

	myfile << name << " ";

	myfile << species << " ";

	myfile << breed << " ";

	myfile << color << endl;

	myfile.close();
}

void showPets() {			// Shows the contents of petDatabase to user
	string output;
	ifstream myFile;
	myFile.open("petDatabase.txt");

	while (!myFile.eof())
	{
		myFile >> output;
		cout << output << output<< output << output << endl;
	}
	myFile.close();
}

int main() {
	string name, species, breed, color;			// I initialize my variables here
	int choice;

	do {							// Do-While loop - user is trapped until they enter "3" to exit
		showMenu();
		cout << "Enter choice - " << endl;
		cin >> choice;
		system("cls");				// Clears system
		switch (choice) {
		case 1:						// Enter pet data
			cout << "Name: ";
			cin >> name;

			cout << "Species: ";
			cin >> species;

			cout << "Breed: ";
			cin >> breed;

			cout << "Color: ";
			cin >> color;

			addPet(name, species, breed, color);	// Calls addPet function
			break;
		case 2:
			showPets();			// calls showPets function
		}
	} while (choice != 3);

	system("pause");
};