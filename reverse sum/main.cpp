#include <iostream>
#include <sstream>
using namespace std;

int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}

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

    string getList() {
        string List = "";
        ListNode* currentPointer{headPointer};
        while(currentPointer != nullptr) {
            List = List + to_string(currentPointer->data);
            currentPointer = currentPointer->nextPointer;
        }
        delete currentPointer;
        return List;
    }

    void addLists(SinglyLinkedList& ListArg){

        SinglyLinkedList answerList;

        string stringNumber1 = getList();
        string stringNumber2 = ListArg.getList();
        int number1;
        int number2;
        int result;
        stringstream(stringNumber1) >> number1;
        stringstream(stringNumber2) >> number2;
        number1 = reverseDigits(number1);
        number2 = reverseDigits(number2);
        result = number1 + number2; //912
        cout <<"result: " <<result;
        while (result > 0)
        {
            int digit = result % 10;
            result /= 10;
            answerList.insertAtTail(digit);
        }
        cout <<endl <<endl;
        answerList.print();
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
    SinglyLinkedList intList2;
    intList.insertAtHead(6);
    intList.insertAtHead(1);
    intList.insertAtHead(7);
    //number 1 = 617
    intList2.insertAtHead(2);
    intList2.insertAtHead(9);
    intList2.insertAtHead(5);
    //number 2 = 592
    intList.addLists(intList2);
    return 0;
}
