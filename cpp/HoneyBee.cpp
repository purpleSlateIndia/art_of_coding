#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int rows = 0, cols = 0;

void printHive(int** hive, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << hive[i][j];
		}
		cout << endl;
	}
}

int** readHive(int rows, int cols) {
	int amount = 0;
	int** hive = new int*[rows];
	for (int i = 0; i < rows; i++) {
		hive[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> amount;
			hive[i][j] = amount;
		}
	}
	//printHive(hive, rows, cols);
	return hive;
}

int processSingleHopEvenColumn(int x, int y, int** hive) {
	int honeyAmount = 0;
	bool decrementX = true, decrementY = true, incrementX = true, incrementY = true;
	if (x - 1 < 0) {
		decrementX = false;
	}
	if (x + 1 >= rows) {
		incrementX = false;
	}
	if (y - 1 < 0) {
		decrementY = false;
	}
	if (y + 1 >= cols) {
		incrementY = false;
	}

	/*cout << "decrementX: " << decrementX << endl;
	cout << "incrementX: " << incrementX << endl;
	cout << "decrementY: " << decrementY << endl;
	cout << "incrementY: " << incrementY << endl;*/

	if (decrementX) {
		honeyAmount += hive[x - 1][y];
	}
	if (decrementX && incrementY) {
		honeyAmount += hive[x - 1][y + 1];
	}
	if (incrementY) {
		honeyAmount += hive[x][y + 1];
	}
	if (incrementX) {
		honeyAmount += hive[x + 1][y];
	}
	if (decrementY) {
		honeyAmount += hive[x][y - 1];
	}
	if (decrementX && decrementY) {
		honeyAmount += hive[x - 1][y - 1];
	}
	return honeyAmount;
}

int processDoubleHopEvenColumn(int x, int y, int** hive) {
	int honeyAmount = 0;
	bool decrementX = true, doubleDecrementX = true, doubleDecrementY = true, decrementY = true,
		incrementX = true, doubleIncrementX = true, doubleIncrementY = true, incrementY = true;
	if (x - 1 < 0) {
		decrementX = false;
	}
	if (x - 2 < 0) {
		doubleDecrementX = false;
	}
	if (x + 1 >= rows) {
		incrementX = false;
	}
	if (x + 2 >= rows) {
		doubleIncrementX = false;
	}
	if (y - 1 < 0) {
		decrementY = false;
	}
	if (y - 2 < 0) {
		doubleDecrementY = false;
	}
	if (y + 1 >= cols) {
		incrementY = false;
	}
	if (y + 2 >= cols) {
		doubleIncrementY = false;
	}

	/*cout << "decrementX: " << decrementX << " || doubleDecrementX: " << doubleDecrementX << endl;
	cout << "incrementX: " << incrementX << " || doubleIncrementX: " << doubleIncrementX << endl;
	cout << "decrementY: " << decrementY << " || doubleDecrementY: " << doubleDecrementY << endl;
	cout << "incrementY: " << incrementY << " || doubleIncrementY: " << doubleIncrementY << endl;*/

	if (doubleDecrementX) {
		honeyAmount += hive[x - 2][y];
	}
	if (doubleDecrementX && incrementY) {
		honeyAmount += hive[x - 2][y + 1];
	}
	if (decrementX && doubleIncrementY) {
		honeyAmount += hive[x - 1][y + 2];
	}
	if (doubleIncrementY) {
		honeyAmount += hive[x][y + 2];
	}
	if (incrementX && doubleIncrementY) {
		honeyAmount += hive[x + 1][y + 2];
	}
	if (incrementX && incrementY) {
		honeyAmount += hive[x + 1][y + 1];
	}
	if (doubleIncrementX) {
		honeyAmount += hive[x + 2][y];
	}
	if (incrementX && decrementY) {
		honeyAmount += hive[x + 1][y - 1];
	}
	if (incrementX && doubleDecrementY) {
		honeyAmount += hive[x + 1][y - 2];
	}
	if (doubleDecrementY) {
		honeyAmount += hive[x][y - 2];
	}
	if (decrementX && doubleDecrementY) {
		honeyAmount += hive[x - 1][y - 2];
	}
	if (doubleDecrementX && decrementY) {
		honeyAmount += hive[x - 2][y - 1];
	}

	return honeyAmount;
}

int processSingleHopOddColumn(int x, int y, int** hive) {
	int honeyAmount = 0;
	bool decrementX = true, decrementY = true, incrementX = true, incrementY = true;
	if (x - 1 < 0) {
		decrementX = false;
	}
	if (x + 1 >= rows) {
		incrementX = false;
	}
	if (y - 1 < 0) {
		decrementY = false;
	}
	if (y + 1 >= cols) {
		incrementY = false;
	}
	/*cout << "decrementX: " << decrementX << endl;
	cout << "incrementX: " << incrementX << endl;
	cout << "decrementY: " << decrementY << endl;
	cout << "incrementY: " << incrementY << endl;*/

	if (decrementX) {
		honeyAmount += hive[x - 1][y];
	}
	if (incrementY) {
		honeyAmount += hive[x][y + 1];
	}
	if (incrementX && incrementY) {
		honeyAmount += hive[x + 1][y + 1];
	}
	if (incrementX) {
		honeyAmount += hive[x + 1][y];
	}
	if (incrementX && decrementY) {
		honeyAmount += hive[x + 1][y - 1];
	}
	if (decrementY) {
		honeyAmount += hive[x][y - 1];
	}
	return honeyAmount;
}

int processDoubleHopOddColumn(int x, int y, int** hive) {
	int honeyAmount = 0;
	bool decrementX = true, doubleDecrementX = true, doubleDecrementY = true, decrementY = true,
		incrementX = true, doubleIncrementX = true, doubleIncrementY = true, incrementY = true;
	if (x - 1 < 0) {
		decrementX = false;
	}
	if (x - 2 < 0) {
		doubleDecrementX = false;
	}
	if (x + 1 >= rows) {
		incrementX = false;
	}
	if (x + 2 >= rows) {
		doubleIncrementX = false;
	}
	if (y - 1 < 0) {
		decrementY = false;
	}
	if (y - 2 < 0) {
		doubleDecrementY = false;
	}
	if (y + 1 >= cols) {
		incrementY = false;
	}
	if (y + 2 >= cols) {
		doubleIncrementY = false;
	}

	/*cout << "decrementX: " << decrementX << " || doubleDecrementX: " << doubleDecrementX << endl;
	cout << "incrementX: " << incrementX << " || doubleIncrementX: " << doubleIncrementX << endl;
	cout << "decrementY: " << decrementY << " || doubleDecrementY: " << doubleDecrementY << endl;
	cout << "incrementY: " << incrementY << " || doubleIncrementY: " << doubleIncrementY << endl;*/

	if (doubleDecrementX) {
		honeyAmount += hive[x - 2][y];
	}
	if (decrementX && incrementY) {
		honeyAmount += hive[x - 1][y + 1];
	}
	if (decrementX && doubleIncrementY) {
		honeyAmount += hive[x - 1][y + 2];
	}
	if (doubleIncrementY) {
		honeyAmount += hive[x][y + 2];
	}
	if (incrementX && doubleIncrementY) {
		honeyAmount += hive[x + 1][y + 2];
	}
	if (doubleIncrementX && incrementY) {
		honeyAmount += hive[x + 2][y + 1];
	}
	if (doubleIncrementX) {
		honeyAmount += hive[x + 2][y];
	}
	if (doubleIncrementX && decrementY) {
		honeyAmount += hive[x + 2][y - 1];
	}
	if (incrementX && doubleDecrementY) {
		honeyAmount += hive[x + 1][y - 2];
	}
	if (doubleDecrementY) {
		honeyAmount += hive[x][y - 2];
	}
	if (decrementX && doubleDecrementY) {
		honeyAmount += hive[x - 1][y - 2];
	}
	if (decrementX && decrementY) {
		honeyAmount += hive[x - 1][y - 1];
	}
	return honeyAmount;
}


int processQuery(int hop, int x, int y, int** hive) {
	int honeyAmount = 0;
	if (hop == 1) {
		if (y % 2 == 0) {
			//cout << "in single hop even column" << endl;
			honeyAmount = processSingleHopEvenColumn(x, y, hive);
		}
		else {
			//cout << "in single hop odd column" << endl;
			honeyAmount = processSingleHopOddColumn(x, y, hive);
		}
	}
	else {
		if (y % 2 == 0) {
			honeyAmount = processDoubleHopEvenColumn(x, y, hive);
		}
		else {
			honeyAmount = processDoubleHopOddColumn(x, y, hive);
		}
	}
	return honeyAmount;
}

int processRow() {
	int x = 0, y = 0, q = 0, hop = 0, row = 0, col = 0;

	cin >> rows;
	cin >> cols;
	int amount = 0;
	int** hive = readHive(rows, cols);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> hop;
		cin >> x;
		cin >> y;
		amount = processQuery(hop, x, y, hive);
		cout << amount << endl;
	}
	return 0;
}

int honeyBee() {
	int t = 0, x = 0, y = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		processRow();
	}
	return 0;
}