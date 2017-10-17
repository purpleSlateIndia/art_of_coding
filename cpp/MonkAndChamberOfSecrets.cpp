#include "stdafx.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int n = 0, x = 0, d = 0;
queue<pair<int, int>> p, q;

void readInputs() {
	int d;
	for (int i = 1; i <= n; i++)
	{
		cin >> d;
		q.push(make_pair(d, i));
	}
}

pair<int, int> extractXItemsAndGetMax() {
	pair<int, int> a, max;
	max.first = -1;
	for (int i = 0; i < x && !q.empty(); i++)
	{
		a = q.front();
		if (a.first > max.first) {
			max = a;
		}
		p.push(a);
		q.pop();
	}
	return max;
}

void decrementAllItemsExceptMax(pair<int,int> max) {
	pair<int, int> b;
	for (int i = 0; i < x && !p.empty(); i++)
	{
		b = p.front();
		if (max.second != b.second) {
			if (b.first > 0) {
				b.first--;
			}
			q.push(b);
		}
		p.pop();
	}
}

int monkAndChamberOfSecrets() {
	
	pair<int, int> a, b, max;
	cin >> n >> x;
	readInputs();

	for (int j = 0; j < x; j++)
	{
		max = extractXItemsAndGetMax();
		cout << max.second << " ";
		decrementAllItemsExceptMax(max);
	}
	return 0;
}