#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void Print(Node* head) {

	while (head != NULL) {
		cout << head->data << endl;
		head = head->next;
	}
}

int readAndPrintLinkedList() {
	int n;
	cin >> n;

	Node *root = NULL, *prevNode = NULL;

	for (int i = 0; i < n; i++) {
		Node *curNode;
		curNode = new Node;
		cin >> curNode->data;
		curNode->next = NULL;
		if (i == 0) root = curNode;
		else {
			prevNode = root;
			while (prevNode->next != NULL)
				prevNode = prevNode->next;
			prevNode->next = curNode;
		}
	}

	Print(root);
	return 0;
}