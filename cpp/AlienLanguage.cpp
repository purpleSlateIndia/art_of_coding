#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int alienLanguage() {
	string text = "", pattern = "";
	int nbrTest = 0;
	cin >> nbrTest;
	for (int i = 0; i < nbrTest; i++)
	{
		cin >> text;
		cin >> pattern;
		string temp = "";
		bool found = false;
		for (int i = 0; i < pattern.length(); i++)
		{
			temp = pattern.substr(i, 1);
			//cout << "temp: " << temp << " ";
			if (text.find(temp) != string::npos) {
				found = true;
				break;
			}
		}
		if (found) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}