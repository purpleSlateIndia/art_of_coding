#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <iterator>

using namespace std;

map<string, int> strings;
list<string> queries;

// get the list of strings from the user
// store it in the map with key as the string and the number of occurrences as the value
// e.g: 'aba', 'aba', 'xzxb' will be stored in the map
// { ('aba', 2), ('xzxb', 1) }
void getStrings(int n) {
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (strings.find(s) != strings.end()) {
			strings[s]++;
		}
		else {
			strings[s] = 1;
		}
	}
}

void getQueries(int q) {
	string s;
	for (int i = 0; i < q; i++)
	{
		cin >> s;
		queries.push_back(s);
	}
}

int sparseArrays() {
	int n = 0, q = 0;
	cin >> n;
	getStrings(n);
	cin >> q;
	getQueries(q);
	string s1 = "";
	int count = 0;
	for (list<string>::iterator s = queries.begin(); s != queries.end(); s++) {
		s1 = *s;
		count = strings[s1];
		cout << count <<endl;
	}
	return 0;
}