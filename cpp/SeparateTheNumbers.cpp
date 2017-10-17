#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//create a new string using n digits at a time
//If s = "99100" n=1, it would create a new string taking the first digit and adding one at a time
//till the length of the created string is <= the actual string
//Iteration 1 -> derived = 9, len = 1
//Iteration 2 -> derived = 910, len = 3
//Iteration 3 -> derived = 91011, len = 5
//Since len(5) is equal to the length of original string, loop will exit and "91011" would be returned

string formStringUsingNDigits(string s, long n) {
	string ss = s.substr(0, n);
	long long nDigits = stoll(ss);
	long len = 0;
	string derived = "";
	while (len < s.length()) {
		derived += to_string(nDigits);
		nDigits++;
		len = derived.length();
	}
	return derived;
}

string processString(string s) {
	long len = s.length();
	string derived = "", result ="NO";
	if (len == 1) {
		return result;
	}
	for (long i = 1; i <= (len+1)/2; i++)
	{
		derived = formStringUsingNDigits(s, i);
		if (derived == s) {
			result = "YES " +s.substr(0, i);
			return result;
		}
	}
	return result;
}

int separateTheNumbers() {
	long q = 0;
	string s, result="";
	cin >> q;
	for (long i = 0; i < q; i++)
	{
		cin >> s;
		result = processString(s);
		cout << result << endl;
	}
	return 0;
}