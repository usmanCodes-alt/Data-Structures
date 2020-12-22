#include <iostream>
using namespace std;
class List;
class ListNode {
private:
    int data;
    ListNode* nextPointer;
    friend class List;
public:
    ListNode(const int argData) {
        data = argData;
        nextPointer = nullptr;
    }
};
class List {
private:
    ListNode* headPointer;
    ListNode* tailPointer;

    ListNode* getNewNode(const int argData) {
        return new ListNode(argData);
    }
    void recursiveReverse(ListNode*& headPointer) {
        if(headPointer->nextPointer == nullptr) {
            return;
        }
        else {
            /** we are not swapping the node, we are simply reversing the
            next links of the nodes **/
            recursiveReverse(headPointer->nextPointer);
            headPointer->nextPointer->nextPointer = headPointer;
            headPointer->nextPointer = nullptr;
            return;
        }
    }
public:
    List() {
        headPointer = tailPointer = nullptr;
    }
    bool isEmpty() {
        return (headPointer == nullptr || tailPointer == nullptr) ? true : false;
    }
    void insertAtHead(int argData) {
        ListNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
        }
        else {
            newNode->nextPointer = headPointer;
            headPointer = newNode;
            newNode = nullptr;
            delete newNode;
        }
    }
    void insertAtTail(int argData) {
        ListNode* newNode{getNewNode(argData)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            delete newNode;
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
            ListNode* tempPointer{headPointer};
            if(headPointer == tailPointer) {
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                return true;
            }
            headPointer = headPointer->nextPointer;
            tempPointer->nextPointer = nullptr;
            delete tempPointer;
            return true;
        }
    }
    bool removeFromBack() {
        if(isEmpty()) {
            return false;
        }
        else {
            ListNode* tempPointer{tailPointer};
            if(tailPointer == headPointer) {
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                return true;
            }
            ListNode* currentPointer{headPointer};
            while(currentPointer->nextPointer != tailPointer) {
                currentPointer = currentPointer->nextPointer;
            }
            tailPointer = currentPointer;
            tailPointer->nextPointer = nullptr;
            delete tempPointer;
            currentPointer = nullptr;
            delete currentPointer;
            return true;
        }
    }
    void reverseList() {
        ListNode* auxiliaryHeadPointer{headPointer};
        ListNode* auxiliaryTailPointer{tailPointer};
        recursiveReverse(headPointer);
        headPointer = auxiliaryTailPointer;
        tailPointer = auxiliaryHeadPointer;
        auxiliaryHeadPointer = auxiliaryTailPointer = nullptr;
        delete auxiliaryTailPointer;
        delete auxiliaryHeadPointer;
    }
    void print() {
        if(isEmpty()) {
            return;
        }
        else {
            ListNode* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                cout <<currentPointer->data <<" ";
                currentPointer = currentPointer->nextPointer;
            }
            currentPointer = nullptr;
            delete currentPointer;
        }
    }
};
int main()
{
    List intList;
    intList.insertAtHead(10);
    intList.insertAtHead(12);
    intList.insertAtHead(13);
    intList.insertAtTail(20);
    intList.insertAtTail(15);
    intList.insertAtTail(8);
    intList.insertAtHead(9);
    intList.print();
    intList.reverseList();
    cout <<endl;
    intList.print();
}
