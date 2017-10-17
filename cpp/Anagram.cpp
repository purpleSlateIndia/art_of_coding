#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int anagram() {
	long t, charsToBeDeleted =0;
	string s1, s2;
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> s1;
		cin >> s2;
		int s1Arr[26]{}, s2Arr[26]{};
		charsToBeDeleted = 0;

		for (int i = 0; i < s1.length(); i++)
		{
			s1Arr[s1[i] - 97]++;
		}
		for (int i = 0; i < s2.length(); i++)
		{
			s2Arr[s2[i] - 97]++;
		}
		for (int i = 0; i < 26; i++)
		{
			charsToBeDeleted += abs(s1Arr[i] - s2Arr[i]);
		}
		cout << charsToBeDeleted << endl;
	}
	return 0;
}