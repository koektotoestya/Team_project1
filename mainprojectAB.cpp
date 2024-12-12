#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void add_note() {
	string file, line;
	cout << "Enter note name" << endl;
	cin >> file;
	ofstream out(file + ".txt", std::ios::app);
	out << file << endl;
	cout << "Enter today's date" << endl;
	cin >> line;
	out << line << endl;
	cout << "Enter description" << endl;
	cin >> line;
	out << line << endl;
	out << "0";
	out.close();
}
void is_complete() {

}

void edit_mainBody() {
	string file, line, buf;
	buf = "buf.txt";
	cout << "Enter note name" << endl;
	cin >> file;
	file += ".txt";
	ifstream in(file);
	if (in.is_open()) {
		ofstream out("buf.txt", std::ios::app);
		for (int i = 0; i < 2; i++) {
			getline(in, line);
			out << line << endl;
		}
		cout << "Enter new note description" << endl;
		cin >> line;
		out << line << endl;
		while (getline(in, line)) {}
		out << line;
		in.close();
		out.close();
		remove(file.c_str());
		rename(buf.c_str(), file.c_str());
	}
}

void delete228() {

}


void show_note() {
	string file, line;
	cout << "Enter note name" << endl;
	cin >> file;
	file += ".txt";
	ifstream in(file);
	for (int i = 0; i < 3;i++) {
		getline(in, line);
		cout << line << endl;
	}
	
}




int main() {
	string userCommand, line, fileName;
	cin >> userCommand;
	if ((userCommand == "add_note") || (userCommand == "Add_note")) {
		add_note();
	}
	else if ((userCommand == "is_complete") || (userCommand == "Is_complete")) {
		is_complete();
	}
	else if ((userCommand == "edit_mainbody") || (userCommand == "Edit_mainbody")) {
		edit_mainBody();
	}
	else if ((userCommand == "delete") || (userCommand == "Delete")) {
		delete228();
	}
	else if ((userCommand == "show_note") || (userCommand == "Show_note")) {
		show_note();
	}




	/*string file, line;
	char isComplete = '0';
	cin >> file;
	file += ".txt";
	ofstream out(file, std::ios::app);
	out.close();
	ifstream in(file);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}

	cout << line << endl;

	if (line == "1") {
		cout << "complete" << endl;
	}
	else if (line == "0") {
		cout << "net" << endl;
	}
	in.close();*/
}