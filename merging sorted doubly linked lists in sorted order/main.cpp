#include <iostream>
using namespace std;
class DoublyLinkedList;
class ListNode {
private:
    ListNode* previousPointer;
    int data;
    ListNode* nextPointer;
    friend class DoublyLinkedList;
public:
    ListNode(const int argData) {
        previousPointer = nullptr;
        data = argData;
        nextPointer = nullptr;
    }
};
class DoublyLinkedList {
private:
    ListNode* headPointer{nullptr};
    ListNode* tailPointer{nullptr};

    ListNode* getNewNode(const int argData) {
        return new ListNode(argData);
    }
public:
    bool isEmpty() {
        return (headPointer == nullptr || tailPointer == nullptr) ? true : false;
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
            headPointer->previousPointer = newNode;
            newNode->nextPointer = headPointer;
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

    void mergeSortedLists(DoublyLinkedList& List) {
        if(isEmpty()) {
            return;
        }
        ListNode* thisCurrentPointer{headPointer};
        ListNode* thisTempPointer{thisCurrentPointer->nextPointer};

        ListNode* currentPointer2{List.headPointer};
        ListNode* tempPointer2{currentPointer2->nextPointer};

        while(thisCurrentPointer != nullptr && currentPointer2 != nullptr) {

            if(thisCurrentPointer->data < currentPointer2->data) {

                if(thisTempPointer == nullptr) {
                    thisCurrentPointer->nextPointer = currentPointer2;
                    currentPointer2->previousPointer = thisCurrentPointer;

                    thisCurrentPointer = nullptr;
                    continue;
                }
                else if(currentPointer2->data < thisTempPointer->data) {
                    thisCurrentPointer->nextPointer = currentPointer2;
                    currentPointer2->previousPointer = thisCurrentPointer;
                }

                thisCurrentPointer = thisTempPointer;
                thisTempPointer = thisTempPointer->nextPointer;
            }
            else if(currentPointer2->data < thisCurrentPointer->data) {

                if(tempPointer2 == nullptr) {
                    currentPointer2->nextPointer = thisCurrentPointer;
                    thisCurrentPointer->previousPointer = currentPointer2;
                    thisCurrentPointer = nullptr;
                    continue;
                }
                else if(thisCurrentPointer->data < tempPointer2->data) {
                    currentPointer2->nextPointer = thisCurrentPointer;
                    thisCurrentPointer->previousPointer = currentPointer2;
                }

                currentPointer2 = tempPointer2;
                tempPointer2 = tempPointer2->nextPointer;
            }
        }
        thisCurrentPointer = thisTempPointer = nullptr;
        currentPointer2 = tempPointer2 = nullptr;

        delete thisCurrentPointer;
        delete thisTempPointer;
        delete currentPointer2;
        delete tempPointer2;
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
            cout <<endl <<endl;
            delete currentPointer;
        }
    }
};
int main()
{
    DoublyLinkedList List1;
    DoublyLinkedList List2;
    List1.addAtBack(1);
    List1.addAtBack(3);
    List1.addAtBack(6);
    cout <<"list 1:\n";
    List1.print();

    List2.addAtBack(2);
    List2.addAtBack(4);
    List2.addAtBack(5);
    cout <<"list 2:\n";
    List2.print();

    cout <<"merging lists in a sorted manner\n";
    List1.mergeSortedLists(List2);
    List1.print();
    return 0;
}
