#include <iostream>
using namespace std;
class List;
class node
{
private:
    node* previousPointer;
    int data;
    node* nextPointer;
    friend class List;
public:
    explicit node(const int argData)
    : previousPointer{nullptr}, data{argData}, nextPointer{nullptr}
    {}
};
class List
{
private:
    node* headPointer{nullptr};
    node* tailPointer{nullptr};
    node* getNewNode(const int argData)
    {
        return new node(argData);
    }
public:
    void insertAtBack(int argData)
    {
        node* newPointer{getNewNode(argData)};
        if(isEmpty())
        {
            headPointer = tailPointer = newPointer;
        }
        else
        {
            tailPointer->nextPointer = newPointer;
            newPointer->previousPointer = tailPointer;
            tailPointer = newPointer;
        }
    }
    void printList()
    {
        if(isEmpty())
        {
            cout <<"nothing to display, the list is empty\n";
            return;
        }
        else
        {
            node* currentPointer{headPointer};
            while(currentPointer != nullptr)
            {
                cout <<currentPointer->data <<"\t";
                currentPointer = currentPointer->nextPointer;
            }
            cout <<endl <<endl;
        }
    }
    void concatenateLists(List &argIntegerList)
    {
        this->tailPointer->nextPointer = argIntegerList.headPointer;
        printList();
        this->tailPointer->nextPointer = nullptr;
    }
    void splitList(int argNodePosition)
    {
        int nodePosition = 1;
        node* tempPtr{headPointer};
        node* currentPointer{headPointer};
        node* tempTailPointer{tailPointer};
        node* tempHead;
        while(nodePosition != argNodePosition + 1)
        {
            currentPointer = currentPointer->nextPointer;
            nodePosition++;
        }
        tempPtr = currentPointer->previousPointer;
        tailPointer = tempPtr;
        tempPtr->nextPointer = nullptr;
        node* newNode{getNewNode(currentPointer->data)};
        tempHead = newNode;
        tempPtr = newNode;
        cout <<tempHead->data <<"\t";
        currentPointer = currentPointer-> nextPointer;
        delete newNode;
        while(currentPointer != nullptr)
        {
            node* newNode{getNewNode(currentPointer->data)};
            tempPtr->nextPointer = newNode;
            newNode->previousPointer = tempPtr;
            tempPtr = tempPtr->nextPointer;
            cout <<tempPtr->data << "\t";
            currentPointer = currentPointer->nextPointer;
            delete newNode;
        }
        tempTailPointer = tempPtr;
        delete tempPtr;
        delete currentPointer;
    }
    bool deleteFromFront()
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            node* tempPointer{headPointer};
            headPointer = headPointer->nextPointer;
            tempPointer->nextPointer = nullptr;
            tempPointer->previousPointer = nullptr;
            delete tempPointer;
            return true;
        }
    }
    bool isEmpty()
    {
        return headPointer == nullptr;
    }
    ~List()
    {
        while(!isEmpty())
        {
            deleteFromFront();
        }
    }
};
int main()
{
    List intList;
    List intList2;
    for(int i = 0; i < 20; i++)
    {
        intList.insertAtBack(i);
    }
    cout <<"list 1: ";
    intList.printList();
    for(int i = 25; i < 45; i++)
    {
        intList2.insertAtBack(i);
    }
    cout <<"list 2: ";
    intList2.printList();

    cout <<"concatenating lists: ";
    intList.concatenateLists(intList2);

    cout <<"splitting list 1 at node 3: ";
    intList.splitList(3);
}
