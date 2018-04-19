#pragma once
#include "BST.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::cout;

class TranslatorApp {
public:
	void startProgram() {
		ifstream file;
		file.open("Convert.txt", std::ios::in);
		if (file.is_open()) {
			while (!file.eof()) {
				string line, transLine, output;
				BST translator;
				getline(file, line);
				for (int i = 0; i < line.length(); i++) {
					if (line[i] >= 97 && line[i] <= 122) {
						line[i] -= 32;
					}
					transLine = translator.search(line[i]);
					if (transLine != "null") {
						output = output + transLine + " ";
					}			
				}
				cout << output << "\n";
			}
		}
	}
};