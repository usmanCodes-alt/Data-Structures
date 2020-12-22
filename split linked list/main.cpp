#include <iostream>
using namespace std;
class linkedList;
class listNode {
private:
    int data;
    listNode* nextPointer;
    friend class linkedList;
public:
    listNode(const int argData) : data{argData}, nextPointer{nullptr}
    {}
};
class linkedList {
    listNode* headPointer;
    listNode* tailPointer;

    listNode* getNewNode(const int argData) {
        return new listNode(argData);
    }

public:
    linkedList() {
        headPointer = tailPointer = nullptr;
    }
    bool isEmpty() {
        return headPointer == nullptr;
    }
    bool searchNode(int argData) {
        if(isEmpty()) {
            return false;
        }
        else {
            listNode* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                if(currentPointer->data == argData) {
                    return true;
                }
                currentPointer = currentPointer->nextPointer;
            }
            return false;
        }
    }
    listNode* getHeadReference() {
        return headPointer;
    }
    void addAtFront(int argData) {
        listNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
            return;
        }
        else {
            newNode->nextPointer = headPointer;
            headPointer = newNode;
            newNode = nullptr;
            delete newNode;
        }
    }
    void addAtBack(int argData) {
        listNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
            return;
        }
        else {
            tailPointer->nextPointer = newNode;
            tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
        }
    }
    bool removeFromFront() {
        if(isEmpty()) {
            return false;
        }
        else {
            listNode* tempPointer{headPointer};
            if(headPointer->nextPointer == nullptr) {
                headPointer = tailPointer = nullptr;
            }
            else {
                headPointer = headPointer->nextPointer;
                tempPointer->nextPointer = nullptr;
            }
            delete tempPointer;
            return true;
        }
    }
    bool removeFromBack() {
        if(isEmpty()) {
            return false;
        }
        else {
            listNode* tempPointer{tailPointer};
            if(headPointer == tailPointer) {
                headPointer = tailPointer = nullptr;
            }
            else {
                listNode* currentPointer{headPointer};
                while(currentPointer->nextPointer != tailPointer) {
                    currentPointer = currentPointer->nextPointer;
                }
                tailPointer = currentPointer;
                tailPointer->nextPointer = nullptr;
                currentPointer = nullptr;
                delete currentPointer;
            }
            delete tempPointer;
        }
    }
    void splitList(int dataToSplitUpon) {
        if(!searchNode(dataToSplitUpon)) {
            cout <<"node to split upon not found\n";
            return;
        }
        else {
            linkedList tempList;
            listNode* tempPointer{headPointer};
            while(tempPointer->data != dataToSplitUpon) {
                tailPointer = tempPointer;
                tempPointer = tempPointer->nextPointer;
            }
            tailPointer->nextPointer = nullptr;
            //original list broken up till here

            tempList.headPointer = tempPointer;
            while(tempPointer != nullptr) {
                tempList.tailPointer = tempPointer;
                tempPointer = tempPointer->nextPointer;
            }
            cout <<endl <<endl;
            print();
            cout <<endl <<endl;
            tempList.print();
        }
    }
    void print() {
        if(isEmpty()) {
            return;
        }
        else {
            listNode* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                cout <<currentPointer->data <<"\t";
                currentPointer = currentPointer->nextPointer;
            }
            currentPointer = nullptr;
            delete currentPointer;
        }
    }
};
int main()
{
    linkedList intList;
    intList.addAtBack(10);
    intList.addAtBack(12);
    intList.addAtBack(13);
    intList.addAtFront(5);
    intList.addAtFront(9);
    intList.addAtFront(4);
    intList.print();
    intList.splitList(5);
    return 0;
}
