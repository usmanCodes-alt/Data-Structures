#include <iostream>
using namespace std;
class LinkedList;
class ListNode {
private:
    ListNode* previousPointer;
    int data;
    ListNode* nextPointer;
    friend class LinkedList;
public:
    ListNode(const int argData) {
        previousPointer = nullptr;
        data = argData;
        nextPointer = nullptr;
    }
};
class LinkedList {
private:
    ListNode* headPointer;
    ListNode* tailPointer;
    ListNode* getNewNode(const int argData) {
        return new ListNode(argData);
    }
public:
    LinkedList () {
        headPointer = tailPointer = nullptr;
    }
    ListNode* getHeadReference() {
        return headPointer;
    }
    bool isEmpty() {
        return headPointer == nullptr;
    }
    bool searchNode(int argData) {
        bool isFound = false;
        if(isEmpty()) {
            return false;
        }
        else {
            ListNode* currentPointer{headPointer};
            while(currentPointer != nullptr){
                if(currentPointer->data == argData) {
                    isFound = true;
                }
                currentPointer = currentPointer->nextPointer;
            }
            currentPointer = nullptr;
            delete currentPointer;
            if(isFound) {
                return true;
            }
            return false;
        }
    }
    void addAtFront(int argData) {
        ListNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
            return;
        }
        else {
            newNode->nextPointer = headPointer;
            headPointer->previousPointer = newNode;
            headPointer = newNode;
            newNode = nullptr;
            delete newNode;
        }
    }
    void addAtBack(int argData) {
        ListNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
            return;
        }
        else {
            tailPointer->nextPointer = newNode;
            newNode->previousPointer = tailPointer;
            tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
        }
    }
    void addBeforeNode(int argData, int dataToAddBefore) {
        if(isEmpty()) {
            cout <<"the list is empty, this node would be added at front of the linked list\n";
            addAtFront(argData);
            return;
        }
        else if(headPointer->data == dataToAddBefore) {
            addAtFront(argData);
            return;
        }
        else if(searchNode(dataToAddBefore)) {
            ListNode* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                if(currentPointer->nextPointer->data == dataToAddBefore) {
                    break;
                }
                currentPointer = currentPointer->nextPointer;
            }
            ListNode* newNode{getNewNode(argData)};
            newNode->nextPointer = currentPointer->nextPointer;
            newNode->previousPointer = currentPointer;
            currentPointer->nextPointer = newNode;
            newNode->nextPointer->previousPointer = newNode;
            currentPointer = newNode = nullptr;
            delete newNode;
            delete currentPointer;
        }
        else {
            cout <<"node not found\n";
        }
    }
    bool removeFromFront() {
        if(isEmpty()) {
            return false;
        }
        else {
            ListNode* tempPointer{headPointer};
            if(headPointer == tailPointer) {
                //if the last node is being deleted.
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                return true;
            }
            else {
                headPointer = headPointer->nextPointer;
                headPointer->previousPointer = nullptr;
                tempPointer->nextPointer = nullptr;
                delete tempPointer;
                return true;
            }
        }
    }
    bool removeFromBack() {
        if(isEmpty()) {
            return false;
        }
        else {
            ListNode* tempPointer{tailPointer};
            if(headPointer == tailPointer) {
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                return true;
            }
            else {
                tailPointer = tailPointer->previousPointer;
                tailPointer->nextPointer = nullptr;
                tempPointer->previousPointer = nullptr;
                delete tempPointer;
                return true;
            }
        }
    }
    void intersectionLists(LinkedList& argList) {
        //LinkedList intersectionList;
        bool common = false;
        ListNode* thisCurrentPointer{headPointer};
        ListNode* argCurrentPointer;
        cout <<"common elements between both lists are:\n";

        while(thisCurrentPointer != nullptr) {

            argCurrentPointer = argList.getHeadReference();
            while(argCurrentPointer != nullptr){

                if(thisCurrentPointer->data == argCurrentPointer->data) {
                    cout <<thisCurrentPointer->data;
                    common = true;
                    break;
                }
                argCurrentPointer = argCurrentPointer->nextPointer;
            }
            thisCurrentPointer = thisCurrentPointer->nextPointer;
            argCurrentPointer = argList.getHeadReference();
        }
        if(!common) {
            cout <<"none\n";
        }
        thisCurrentPointer = nullptr;
        argCurrentPointer = nullptr;
        delete thisCurrentPointer;
        delete argCurrentPointer;
    }
    void print() {
        if(isEmpty()) {
            cout <<"nothing to print, the list is empty\n";
            return;
        }
        else {
            ListNode* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                cout <<currentPointer->data <<"\t";
                currentPointer = currentPointer->nextPointer;
            }
            currentPointer = nullptr;
            delete currentPointer;
            cout <<endl;
        }
    }
    ~LinkedList() {
        while(!isEmpty()) {
            removeFromFront();
        }
    }
};
int main()
{
    LinkedList intList;
    LinkedList intList2;
    intList.addAtFront(1);
    intList.addAtFront(3);
    intList.addAtFront(5);
    intList.addBeforeNode(4, 5);
    cout <<"list number 1 is:\n";
    intList.print();


    intList2.addAtBack(2);
    intList2.addAtBack(2);
    intList2.addAtBack(2);
    intList2.addAtBack(5);
    cout <<"list number 2 is:\n";
    intList2.print();

    intList.intersectionLists(intList2);
}
