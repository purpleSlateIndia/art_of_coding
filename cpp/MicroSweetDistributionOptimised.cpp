#include <iostream>
#include <string>
using namespace std;

bool isOdd(int x) {
	if (x % 2 != 0) {
		return true;
	}
	else {
		return false;
	}
}

string getMicroAction(int row, int column,
	int startRow, int startCol, int microX, int microY) {

	string startDirection, oppDirection, frontBackDirection, microColPos, result;

	bool isMicroInOddRowFromStart = isOdd(abs(startRow - microX));

	// cout << "StartRow " << startRow  << " - StartCol " << startCol << " - Micro Row " << microX << " - MicroColumn " << microY;

	if (startCol - 1 == 0) { startDirection = "Right"; oppDirection = "Left"; }
	else { startDirection = "Left"; oppDirection = "Right"; }

	if (startRow - 1 == 0) frontBackDirection = "Back";
	else frontBackDirection = "Front";

	if (microY == startCol) microColPos = "SameEdge";
	else if (abs(microY - startCol) + 1 == column) microColPos = "OppEdge";
	else microColPos = "Middle";

	// cout << microColPos < " " < abs(microY-startCol-1);


	if (microColPos == "Middle") {
		if (isMicroInOddRowFromStart) result = oppDirection;
		else result = startDirection;
	}

	if (microColPos == "SameEdge") {
		if (isMicroInOddRowFromStart) {
			if (abs(microX - startRow) + 1 == row) result = "Over";
			else result = frontBackDirection;
		}
		else result = startDirection;
	}

	if (microColPos == "OppEdge") {
		if (isMicroInOddRowFromStart) result = oppDirection;
		else if (abs(microX - startRow) + 1 == row) result = "Over";
		else result = frontBackDirection;
	}

	return (result);

}

int microSweetDistributionOptimised() {

	string line;
	int t, m, n, sX, sY, dX, dY;
	cin >> t;
	string *result = new string[t];

	for (int i = 0; i < t; i++)
	{
		cin >> m >> n;
		cin >> sX >> sY;
		cin >> dX >> dY;
		result[i] = getMicroAction(m, n, sX, sY, dX, dY);
	}
	for (int i = 0; i < t; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}