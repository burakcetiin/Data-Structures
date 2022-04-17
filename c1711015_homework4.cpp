#include <iostream>
#include <sstream>

using namespace std;
#define MAX 100
typedef struct charNode {
	char data;
	struct charNode* next;
}CharNode;

typedef struct intNode {
	char data;
	struct intNode* next;
}IntNode;

class CharQueueLinkedList {
private:
	int count = 0;
	CharNode* front;
	CharNode* rear;
	CharNode* createNode(char data) {
		CharNode* newNode = new CharNode;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}
public:
	CharQueueLinkedList() :front(NULL), rear(NULL) {}

	bool isEmpty() {
		return front == NULL;
	}

	bool isFull() {
		return false;
	}

	bool enqueue(char data) {
		if (isFull())
			return false;
		CharNode* newNode = createNode(data);
		if (front == NULL)
			front = rear = newNode;
		else {
			rear->next = newNode;
			rear = newNode;
		}
		count++;
		return true;
	}

	bool dequeue(char& data) {
		if (isEmpty())
			return false;
		data = front->data;
		CharNode* temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete temp;
		count--;
		return true;
	}

	bool peek(char& data) {
		if (isEmpty())
			return false;
		data = front->data;
		return true;
	}

	int size() {
		return count;
	}
};

class IntQueueLinkedList {
private:
	int count = 0;
	IntNode* front;
	IntNode* rear;
	IntNode* createNode(int data) {
		IntNode* newNode = new IntNode;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}
public:
	IntQueueLinkedList() :front(NULL), rear(NULL) {}

	bool isEmpty() {
		return front == NULL;
	}

	bool isFull() {
		return false;
	}

	bool enqueue(int data) {
		if (isFull())
			return false;
		IntNode* newNode = createNode(data);
		if (front == NULL)
			front = rear = newNode;
		else {
			rear->next = newNode;
			rear = newNode;
		}
		count++;
		return true;
	}

	bool dequeue(int& data) {
		if (isEmpty())
			return false;
		data = front->data;
		IntNode* temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete temp;
		count--;
		return true;
	}

	bool peek(int& data) {
		if (isEmpty())
			return false;
		data = front->data;
		return true;
	}

	int size() {
		return count;
	}
};

int main() {

	CharQueueLinkedList phrase_que;
	IntQueueLinkedList key_que;

	char phrase = ' ';
	int key = 0, choice = 0;
	string encrypted = "";

	do
	{
		cout << "1. Encrypt Text" << endl
			<< "2. Decrypt Text" << endl
			<< "3. Exit" << endl
			<< "Your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			string line;
			cout << "Enter your text: ";
			cin.ignore(99999, '\n');
			getline(cin, line);
			istringstream iss(line);
			while (iss >> phrase) {
				phrase_que.enqueue(phrase);
			}

			int arr[MAX], i = 0, digit;
			cout << "Enter your key: ";
			cin >> key;
			while (key > 0)
			{
				digit = key % 10;
				arr[i] = digit;
				i++;
				key /= 10;
			}
			while (!key_que.isEmpty())
				key_que.dequeue(key);
			for (int j = i - 1; j > -1; j--)
				key_que.enqueue(arr[j]);


			cout << "Encrypted text: ";
			char encrypted;
			if (key_que.size() < phrase_que.size())
			{
				while (!phrase_que.isEmpty())
				{
					if (key_que.isEmpty())
					{
						for (int j = i - 1; j > -1; j--)
							key_que.enqueue(arr[j]);
					}
					else
					{
						encrypted = ' ';
						phrase_que.dequeue(phrase);
						key_que.dequeue(key);
						//Between A to Z according to ASCII table
						if ((phrase + key) > 90)
							encrypted = 64 + ((phrase + key) - 90);
						else
							encrypted = phrase + key;
						cout << encrypted;
					}
				}
			}
			else
			{
				while (!phrase_que.isEmpty())
				{
					encrypted = ' ';
					phrase_que.dequeue(phrase);
					key_que.dequeue(key);
					//Between A to Z according to ASCII table
					if ((phrase + key) > 90)
						encrypted = 64 + ((phrase + key) - 90);
					else
						encrypted = phrase + key;
					cout << encrypted;

				}
			}
			cout << "\n\n";
		}
		else if (choice == 2)
		{
			string line;
			cout << "Enter your text: ";
			cin.ignore(99999, '\n');
			getline(cin, line);
			istringstream iss(line);
			while (iss >> phrase) {
				phrase_que.enqueue(phrase);
			}

			int arr[MAX], i = 0, digit;
			cout << "Enter your key: ";
			cin >> key;
			while (key > 0)
			{
				digit = key % 10;
				arr[i] = digit;
				i++;
				key /= 10;
			}
			while (!key_que.isEmpty())
				key_que.dequeue(key);
			for (int j = i - 1; j > -1; j--)
				key_que.enqueue(arr[j]);


			cout << "Decrypted text: ";
			char decrypted;

			if (key_que.size() < phrase_que.size())
			{
				while (!phrase_que.isEmpty())
				{
					if (key_que.isEmpty())
					{
						for (int j = i - 1; j > -1; j--)
							key_que.enqueue(arr[j]);
					}
					else
					{
						encrypted = ' ';
						phrase_que.dequeue(phrase);
						key_que.dequeue(key);
						//Between A to Z according to ASCII table
						if ((phrase - key) < 65)
							encrypted = 91 - (65 - (phrase - key));
						else
							encrypted = phrase - key;
						cout << encrypted;
					}
				}
			}
			else
			{
				while (!phrase_que.isEmpty())
				{
					encrypted = ' ';
					phrase_que.dequeue(phrase);
					key_que.dequeue(key);
					//Between A to Z according to ASCII table
					if ((phrase - key) < 65)
						encrypted = 91 - (65 - (phrase - key));
					else
						encrypted = phrase - key;
					cout << encrypted;

				}
			}
			cout << "\n\n";
		}
		else if (choice == 3)
			cout << "Bye!";

	} while (choice != 3);

	return 0;
}