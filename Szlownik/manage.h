#include <iostream>
#include <cctype>
#include <fstream>
#include "tools.h"

using namespace std;

void word(string definition, string name) {
	fstream file;
	file.open(name +".txt", ios::out | ios::app); //zmienna name powinna zostac zastapiona where(name);
	file << definition << endl;
	file.close();
	cout << "git gud";
};

void addWord() {
	bool a = true;
	string name, definition, git;

	while (a == true) {
		cout << "dawaj s�owo "; cin >> name;
		cout << "dawaj definicje "; cin >> definition;
		while (true) {
			cout << "Czy podane przez ciebie dane s� git gud? (Y/N) \n"; cin >> git;
			cout << "S�owo: " << name << "\n" << "Definicja: " << definition << "\n";
			if (git == "Y") {
				a = false;				
				word(definition, name);
				break;
			}
			else if (git == "N") {
				a = true;
				break;
			}
			else if (git == "a")
				cout << name;
			else
			{
				continue;
			}
		}
	}
}

string where(string name) {
	//za�o�eniem tej funkcji jest wyodr�bnienie n litery ze s�owa,
	//na podstawie czego, wybrany powinien zosta� folder do zapisu
	// np. z dupa robi /spis/d/dupa
	string adres = "/spis/" + name[0] + name;
	return adres;
}

void getDefin(string name) {
	fstream file;
	file.open(name + ".txt"); //zmienna name powinna zostac zastapiona where(name);
	if(!file.good()){ 
		cout << "Nie ma takiego pliku!" << endl;
		exit(0);
	}
	cout << "Oto definicja s�owa " << name << endl;

	string def, aa, bb;
	int n = 1;

	while (getline(file, def)) {
		
		cout << n << ": " << def << endl;
		n++;
	}

	file.close();	
};


