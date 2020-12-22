#include <iostream>
using namespace std;
class LinkedList;
class Node {
private:
    Node* nextPointer;
    int data;
    friend class LinkedList;
public:
    Node (int argData) : nextPointer{nullptr}, data{argData}
    {}
};
class LinkedList {
private:
    Node* headPointer;
    Node* tailPointer;

    Node* getNewNode(int argData) {
        return new Node(argData);
    }
public:
    LinkedList() {
        headPointer = tailPointer = nullptr;
    }
    bool isEmpty() {
        return (headPointer == nullptr || tailPointer == nullptr);
    }
    void insertSort(int data) {
        if (isEmpty()) {
            insertAtHead(data);
        }
        else if (headPointer->data > data) {
            insertAtHead(data);
        }
        else if (tailPointer->data < data) {
            insertAtTail(data);
        }
        else {
            Node* newNode{getNewNode(data)};
            Node* currentPointer{headPointer};
            while(currentPointer->nextPointer != nullptr) {
                if(currentPointer->data < data && currentPointer->nextPointer->data > data) {
                    newNode->nextPointer = currentPointer->nextPointer;
                    currentPointer->nextPointer = newNode;
                    break;
                }
                currentPointer = currentPointer->nextPointer;
            }
            newNode = nullptr;
        }
    }
    void insertAtHead(int data) {
        Node* newNode{getNewNode(data)};
        if (isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
        }
        else {
            newNode->nextPointer = headPointer;
            headPointer = newNode;
            newNode = nullptr;
        }
    }
    void insertAtTail(int data) {
        Node* newNode{getNewNode(data)};
        if (isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
        }
        else {
            tailPointer->nextPointer = newNode;
            tailPointer = newNode;
            newNode = nullptr;
        }
    }
    bool searchNode(int data) {
        if (isEmpty()) {
            return false;
        }
        else {
            Node* currentPointer{headPointer};
            while (currentPointer != nullptr) {
                if (currentPointer->data == data) {
                    return true;
                }
                currentPointer = currentPointer->nextPointer;
            }
            return false;
        }
    }
    bool removeNode(int data) {
        if (isEmpty()) {
            return false;
        }
        else {
            Node* currentPointer{headPointer};
            Node* tempPointer{headPointer};
            while (currentPointer->nextPointer != nullptr) {
                if (currentPointer->nextPointer->data == data) {
                    currentPointer->nextPointer = tempPointer->nextPointer;
                    tempPointer->nextPointer = nullptr;
                    delete tempPointer;
                    return true;
                }
                currentPointer = currentPointer->nextPointer;
                tempPointer = currentPointer->nextPointer;
            }
            return false;
        }
    }
    void print() {
        if (isEmpty()) {
            return;
        }
        else {
            Node* currentPointer{headPointer};
            while (currentPointer != nullptr) {
                cout <<currentPointer->data <<"\t";
                currentPointer = currentPointer->nextPointer;
            }
        }
    }
};
void menu() {
    cout <<"\nenter an option\n";
    cout <<"1) search for a number\n"
    <<"2) delete a number\n";
}
int main()
{
    LinkedList List;
    int data;
    int choice;
    for(int counter = 1; counter <= 10; counter++) {
        cout <<"enter value # " <<counter <<": ";
        cin >> data;
        List.insertSort(data);
    }
    do {
        menu();
        cout <<"?\n";
        cin >> choice;
        if (choice == 1) {
            cout <<"enter value you want to search: ";
            cin >> data;
            if(List.searchNode(data)) {
                cout <<"node found";
            }
            else {
                cout <<"node not found\n";
            }
        }
        else if (choice == 2) {
            cout <<"enter the node you want to delete: ";
            cin >> data;
            if (List.removeNode(data)) {
                cout <<"node deleted\n";
                cout <<"new list is\n";
                List.print();
            }
            else {
                cout <<"node not found\n";
            }
        }
        cout <<"want to perform another action?\n1) yes\n2) no\n?";
        cin >> choice;
    } while (choice != 2);
}
