# include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() {

	ifstream in;

	string path;

	cout << "Enter path: ";
	getline(cin, path);

	cout << path << endl;

	in.open(path, ios::in);


	int count = 0;
	int index = 0;
	char arrSymbol[256]{ 0 };

	if (in) {
		do {
			char character;

			in.get(character);

			if (character == '<' || character == '>')
				arrSymbol[index++] = character;

			cout << character;
		} while (in);

		in.close();
	}

	cout << endl;


	for (int i = 0; i < index; i++) {
		if (arrSymbol[i] != '<') {
			if (i == 0)
				count++;
			else if (arrSymbol[i - 1] == '>')
				count++;
		}

		if (arrSymbol[i] == '<')
			if (arrSymbol[++i] != '>')
				count++;
	}
	cout << endl;

	cout << "Errors: " << count << endl;

	return 0;
}