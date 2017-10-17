#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string isValid(string s) {
	int alphaArray[26];
	for (int i = 0;i < 26;i++) {
		alphaArray[i] = 0;
	}

	// find out how many times each character appears in the string


	for (int i = 0; i < s.length(); i++) {
		alphaArray[s.at(i) - 97] ++;

		// Find minOccurence and maxOccurence
		// Not a good option as String may be as big as 1 million characters.

		// if (alphaArray[s.charAt(i)-97] > maxOccurence) maxOccurence = alphaArray[s.charAt(i)-97];
		// else if (alphaArray[s.charAt(i)-97] < minOccurence) minOccurence = alphaArray[s.charAt(i)-97];
	}
	int firstCharOccurence = 0, differentOccurence = 0, firstCharOccurenceCount = 0, differentOccurenceCount = 0;

	for (int i = 0; i < 26; i++) {

		// Check if the character does not appear at all. well and good. skip it. 

		// System.out.println(alphaArray[i] + "-" + firstCharOccurence + "-" + differentOccurence);

		if (alphaArray[i] > 0) {

			// Initialize firstOccurence

			if (firstCharOccurence == 0) {

				firstCharOccurence = alphaArray[i];
				firstCharOccurenceCount++;
			}

			// Check whether the number of occurences of current character same as firstCharOccurence

			else if (firstCharOccurence == alphaArray[i]) firstCharOccurenceCount++;

			// We have detected a character with a difference in occurence

			// Check whether we need to initialise it

			else if (differentOccurence == 0) {
				differentOccurence = alphaArray[i];
				differentOccurenceCount++;

			}

			// Check whether the current character appears the same times as differentOccurence

			else if (differentOccurence == alphaArray[i]) differentOccurenceCount++;

			// This is third variant. hence return "NO"

			else return ("NO");

			if ((firstCharOccurenceCount > 1) && (differentOccurenceCount > 1)) return ("NO");

		}
	}

	if (differentOccurence == 0) return ("YES");

	if (abs(firstCharOccurence - differentOccurence) > 1) {

		if ((firstCharOccurenceCount == 1) && (firstCharOccurence == 1)) return ("YES");
		else if ((differentOccurenceCount == 1) && (differentOccurence == 1)) return ("YES");
		else return ("NO");
	}
	else return ("YES");
}

int sherlockAndString() {

	string s;
	cin >> s;
	string result = isValid(s);
	cout << result;

	return 0;
}
