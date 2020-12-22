#include <iostream>
using namespace std;
class DoublyLinkedList;
class Node {
private:
    Node* previousPointer;
    int data;
    Node* nextPointer;
    friend class DoublyLinkedList;
public:
    Node(int data) {
        previousPointer = nullptr;
        this->data = data;
        nextPointer = nullptr;
    }
};
class DoublyLinkedList {
private:
    Node* headPointer;
    Node* tailPointer;

    Node* getNewNode(const int data) {
        return new Node(data);
    }
public:
    DoublyLinkedList() {
        headPointer = tailPointer = nullptr;
    }
    DoublyLinkedList(int data) {
        insertAtTail(data);
    }
    void createCycle() {
        tailPointer->nextPointer = headPointer->nextPointer;
    }
    bool isEmpty() {
        return (headPointer == nullptr || tailPointer == nullptr);
    }
    void insertAtHead(int data) {
        Node* newNode{getNewNode(data)};
        if(isEmpty()) {
            headPointer = tailPointer = newNode;
            newNode = nullptr;
            return;
        }
        else {
            newNode->nextPointer = headPointer;
            headPointer->previousPointer = newNode;
            headPointer = newNode;
            newNode = nullptr;
        }
    }
    void insertAtTail(int data) {
        Node* newNode{getNewNode(data)};
        if(isEmpty()) {
            headPointer = tailPointer =newNode;
            newNode= nullptr;
            return;
        }
        else {
            tailPointer->nextPointer = newNode;
            newNode->previousPointer = tailPointer;
            tailPointer = newNode;
            newNode = nullptr;
        }
    }
    bool removeFromFront() {
        if(isEmpty()) {
            return false;
        }
        else {
            Node* tempPointer{headPointer};
            if(headPointer == tailPointer) {
                //if first node is the only node to delete in the linked list
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                return true;
            }
            headPointer = headPointer->nextPointer;
            headPointer->previousPointer = nullptr;
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
            Node* tempPointer{tailPointer};
            if(headPointer == tailPointer) {
                headPointer = tailPointer = nullptr;
                delete tempPointer;
                return true;
            }
            tailPointer = tailPointer->previousPointer;
            tailPointer->nextPointer = nullptr;
            tempPointer->previousPointer = nullptr;
            delete tempPointer;
            return true;
        }
    }

    bool equality(DoublyLinkedList& List) {
        bool equal = false;
        Node* thisCurrentPointer{headPointer};
        while(thisCurrentPointer != nullptr) {
            //iterate till the end of the 'this' list
            Node* parameterList{List.headPointer};
            while(parameterList != nullptr) {
                //look for the value
                if(thisCurrentPointer->data == parameterList->data) {
                    equal = true;
                    break;
                }
                else if (parameterList->nextPointer == nullptr and equal == false) {
                    return false;
                }
                parameterList = parameterList->nextPointer;
            }
            thisCurrentPointer = thisCurrentPointer->nextPointer;
            equal = false;
        }
        return true;
    }

    bool findCycle() {
        if(isEmpty()) {
            return false;
        }
        else if(headPointer == tailPointer) {
            return false;
        }
        else {
            createCycle();
            Node* rabbit{headPointer->nextPointer->nextPointer};
            Node* tortoise{headPointer->nextPointer};
            //print();
            while(true) {
                //creating a cycle intentionally for demonstration
                if (rabbit == nullptr || tortoise == nullptr) {
                    return false;
                }
                if(rabbit == tortoise) {
                    cout <<"starting point of loop is: ";
                    startingPointOfLoop(rabbit, tortoise);
                    return true;
                }
                if(rabbit->nextPointer == nullptr) {
                    return false;
                }
                rabbit = rabbit->nextPointer->nextPointer;
                tortoise = tortoise->nextPointer;
            }
        }
    }
    void startingPointOfLoop(Node*& rabbit, Node*& tortoise) {
        rabbit = headPointer;
        while(rabbit != tortoise) {
            rabbit = rabbit->nextPointer;
            tortoise = tortoise->nextPointer;
        }
        cout <<rabbit->data <<endl;
    }
    void print() {
        if(isEmpty()) {
            return;
        }
        else {
            Node* currentPointer{headPointer};
            while(currentPointer != nullptr) {
                cout <<currentPointer->data <<"\t";
                currentPointer = currentPointer->nextPointer;
                if(currentPointer == headPointer) {
                    break;
                }
            }
            currentPointer = nullptr;
            delete currentPointer;
        }
    }
};
int main() {
    DoublyLinkedList List;
    List.insertAtHead(14);
    List.insertAtHead(13);
    List.insertAtHead(12);
    List.insertAtHead(11);
    List.insertAtHead(10);
    //List.createCycle();
    if(List.findCycle()) {
        cout <<"cycle found";
    }
    else {
        cout <<"cycle not found\n";
    }
    /*List2.insertAtHead(10);
    List2.insertAtHead(11);
    List2.insertAtHead(12);
    //List2.insertAtHead(13);
    List2.insertAtHead(13);
    List2.insertAtHead(14);
    if(List.equality(List2)) {
        cout<<"the lists are equal";
    }
    else {
        cout<<"the lists are not equal";
    }*/
}
