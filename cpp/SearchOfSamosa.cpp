#include<iostream>
using namespace std;

int searchOfSamsosa() {

	int noOfShops;
	cin >> noOfShops;
	int money;
	cin >> money;


	int *samosaPrice = new int [noOfShops];

	for (int i = 0; i < noOfShops; i++)
		cin >> samosaPrice[i];

	for (int i = 0; i < noOfShops; i++) {
		for (int j = i + 1; j < noOfShops; j++) {
			if (samosaPrice[i] > samosaPrice[j]) {
				int temp = samosaPrice[i];
				samosaPrice[i] = samosaPrice[j];
				samosaPrice[j] = temp;
			}
		}
	}

	// Try to keep original input in tact

	int moneyRemaining = money;
	int i = 0;
	int noOfSamosas = 0;

	// What condition goes first matters here in boundary condition. 
	// Change the condition sequence and try input like 4 5
	// followed by 0 0 0 0
	while ((i < noOfShops) && (moneyRemaining >= samosaPrice[i])) {
		noOfSamosas++;
		moneyRemaining -= samosaPrice[i];
		i++;
	}

	cout << noOfSamosas;
	return 0;
}