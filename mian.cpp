#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "BinaryTree.h"
using namespace std;

bool checkInput(string input);
bool isNum(string str);

int main() {
	fstream fin;
	string temp;
	BinaryTree tree;
	bool continue_loop = true;
	string input = "";
	char option = ' ';

	fin.open("tree.txt", ios::in);

	if (!fin) {
		cout << "The file can't open!!!" << endl;
		exit(1);
	}

	/*get the key from txt*/
	while (fin >> temp) {
		if (isNum(temp)) {
			tree.insert(stod(temp));
		}
		else {
			cout << "Error input: ";
		}
		cout << temp << endl;
	}

	cout << "-----------------------" << endl;
	tree.show();
	cout << endl << endl;

	do {
		cout << "1.Insert a key   2.Delete a key   3.Find a key   4.Show tree   5.Quit\n=>";
		cin >> input;
		if (!checkInput(input)) {
			cout << "Please enter the correct option!!!" << endl << endl;
			continue;
		}
		else {
			option = input[0];
		}

		switch (option) {
		case'1':
			cout << "\nPlease enter the number you want to insert \n=>";
			cin >> input;
			if (isNum(input)) {
				tree.insert(stod(input));
				tree.show();
				cout << endl << endl;
			}
			else {
				cout << "Please enter a correct number!!!" << endl << endl;
			}
			break;
		case'2':
			cout << "\nPlease enter the number you want to delete \n=>";
			cin >> input;
			if (isNum(input)) {
				tree.delete_key(stod(input));
				tree.show();
				cout << endl << endl;
			}
			else {
				cout << "Please enter a correct number!!!" << endl << endl;
			}
			break;
		case'3':
			cout << "\nPlease enter the number you want to find \n=>";
			cin >> input;
			if (isNum(input)) {
				if (tree.IsExist(stod(input))) {
					cout << "Number: " << input << " is " << tree.find(stod(input)) << " least";
				}
				else {
					cout << "Number: " << input << " is not exist";
				}
				
				cout << endl << endl;
			}
			else {
				cout << "Please enter a correct number!!!" << endl << endl;
			}
			break;
		case'4':
			cout << endl;
			tree.show();
			cout << endl;
			cout << endl;
			break;
		case'5':
			cout << endl;
			tree.clear();
			cout << "Bye Bye ^_^" << endl << endl;
			continue_loop = false;
			break;
		default:
			break;
		}

	} while (continue_loop);

	fin.close();		//close the file
	system("PAUSE");
	return 0;
}

bool checkInput(string input) {
	if (input.length() != 1) {
		return false;
	}
	else {
		if (input[0] == '1' || input[0] == '2' || input[0] == '3' || input[0] == '4' || input[0] == '5') {
			return true;
		}
		else {
			return false;
		}
	}
}

bool isNum(string str) {
	stringstream sin(str);
	double d;
	char c;

	/*ex: a123 , 123a , 123*/
	if (!(sin >> d)) {
		return false;	/*a123 return false*/
	}

	if (sin >> c) {
		return false;	/*123a return false*/
	}

	return true;		/*123 return true*/
}
