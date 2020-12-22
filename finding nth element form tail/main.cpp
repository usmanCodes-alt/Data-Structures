#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class SinglyLinkedList;
class ListNode {
private:
    int data;
    ListNode* nextPointer;
    friend class SinglyLinkedList;
public:
    ListNode(const int argData) : data{argData}, nextPointer{nullptr}
    {}
};
class SinglyLinkedList {
private:
    ListNode* headPointer;
    ListNode* tailPointer;

    int numberOfEntries;

    ListNode* getNewNode(const int argData) {
        return new ListNode(argData);
    }
public:
    SinglyLinkedList() {
        headPointer = tailPointer = nullptr;
        numberOfEntries = 0;
    }
    bool isEmpty() {
        return (headPointer ==  nullptr || tailPointer == nullptr) ? true : false;
    }
    int getNumberOfEntries() {
        return numberOfEntries;
    }
    void insertAtHead(int argData) {
        ListNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
        }
        else{
            newNode->nextPointer = headPointer;
            headPointer = newNode;
        }
        newNode = nullptr;
        delete newNode;
        numberOfEntries++;
    }
    void insertAtTail(int argData) {
        ListNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
        }
        else {
            tailPointer->nextPointer = newNode;
            tailPointer = newNode;
        }
        newNode = nullptr;
        delete newNode;
        numberOfEntries++;
    }
    bool deleteFromFront() {
        if(isEmpty()) {
            return false;
        }
        else {
            ListNode* tempPointer{headPointer};
            if(headPointer == tailPointer) {
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                numberOfEntries--;
                return true;
            }
            else {
                headPointer = headPointer->nextPointer;
                tempPointer->nextPointer = nullptr;
                delete tempPointer;
                numberOfEntries--;
                return true;
            }
        }
    }
    bool deleteFromTail() {
        if(isEmpty()) {
            return false;
        }
        else {
            ListNode* tempPointer{tailPointer};
            if(headPointer == tailPointer) {
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                numberOfEntries--;
                return true;
            }
            else {
                ListNode* currentPointer{headPointer};
                while(currentPointer->nextPointer != tailPointer) {
                    currentPointer = currentPointer->nextPointer;
                }
                tailPointer = currentPointer;
                tailPointer->nextPointer = nullptr;
                currentPointer = nullptr;
                numberOfEntries--;
                delete tempPointer;
                delete currentPointer;
                return true;
            }
        }
    }
    void kthElementFromTail(int numberOfElementFromTail) {
        if(isEmpty()) {
            return;
        }
        else {
            int numberOfEntry = numberOfEntries;
            ListNode* currentPointer{headPointer};
            while(numberOfEntry != numberOfElementFromTail) {
                currentPointer = currentPointer->nextPointer;
                numberOfEntry--;
            }
            cout <<numberOfElementFromTail <<" th entry from tail of linked list is "<<currentPointer->data;
        }
    }
    void print() {
        if(isEmpty()) {
            return;
        }
        else {
            ListNode* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                cout <<currentPointer->data <<"\t";
                currentPointer = currentPointer->nextPointer;
            }
            delete currentPointer;
            cout <<endl <<endl;
        }
    }
    ~SinglyLinkedList() {
        while(!isEmpty()) {
            deleteFromFront();
        }
    }
};
int main()
{
    SinglyLinkedList intList;
    intList.insertAtHead(10);
    intList.insertAtHead(11);
    intList.insertAtHead(12);
    intList.insertAtHead(13);
    intList.insertAtHead(14);
    intList.insertAtHead(15);
    intList.insertAtHead(16);
    intList.kthElementFromTail(3);
    return 0;
}
