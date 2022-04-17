#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct node {
    int data;
    struct node* next;
}Node;

class StudentNode
{
public:
    StudentNode() {
        id = 0;
        name = "empty";
    }
    StudentNode(int id, string name) {
        this->id = id;
        this->name = name;
    }
    ~StudentNode() {
    }

    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void enrollStudent(int code) {
        Node* newNode = createNode(code);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void unenrollStudent(int id) {
        if (head == NULL)
            return;

        if (head->data == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && curr->data != id) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            delete curr;
        }
    }

    bool searchStudent(Node* head, int x)
    {
        Node* current = head; 
        while (current != NULL)
        {
            if (current->data == x)
                return true;
            current = current->next;
        }
        return false;
    }

private:    
    int id;
    string name;
    StudentNode* next;
    Node* head;

    Node* createNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
};

class CourseNode
{
public:
    string code;    

	CourseNode() {
        code = "empty";
	}
    CourseNode(string code) {
        this->code = code;
    }
	~CourseNode() {
	}

    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void addCourse(int code) {
        Node* newNode = createNode(code);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void deleteCourse(int code) {
        if (head == NULL)
            return;

        if (head->data == code) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && curr->data != code) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            delete curr;
        }
    }

private:
    CourseNode* next;
    StudentNode* stHead;
    Node* head;

    Node* createNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
};

int main()
{
	int choice = 0;
    string name;
    CourseNode course;
    StudentNode student;

	cout << "1. Display courses" << endl
		<< "2. Add new course" << endl
		<< "3. Delete existing course" << endl
		<< "4. Enroll student" << endl
		<< "5. Unenrol student" << endl
		<< "6. Search student" << endl
		<< "7. Save and exit" << endl;

    ifstream myfile("file.txt");    

	do
	{
		cout << "\nYour choice: ";
		cin >> choice;

		if (choice == 1)
		{
            if (myfile.is_open()) {
                while (getline(myfile, name)) {                                      
                   if(name != "END")
                        cout << name << endl;
                }
            }
            else {
                cerr << "Failed to open file!\n";
                return -1;
            }
		}
		else if (choice == 2)
		{
            int code;
            cout << "Enter integer course code: ";
            cin >> code;
            course.addCourse(code);
		}
		else if (choice == 3)
		{
            int code;
            cout << "Enter integer course code: ";
            cin >> code;
            course.deleteCourse(code);
		}
		else if (choice == 4)
		{
            int id;
            cout << "Enter id: ";
            cin >> id;
            student.enrollStudent(id);
		}
		else if (choice == 5)
		{
            int id;
            cout << "Enter id: ";
            cin >> id;
            student.unenrollStudent(id);
		}
		else if (choice == 6)
		{
            int id;
            Node* head = NULL;
            cout << "Enter id: ";
            cin >> id;
            student.searchStudent(head, id);
		}
		else		
			break;
	} while (choice != 7);	

    myfile.close();
}