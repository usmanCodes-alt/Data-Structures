#include <iostream>
using namespace std;
class List;
class node
{
private:
    char character;
    node* nextPointer;
    node* previousPointer;
    friend class List;
public:
    explicit node(const char argCharacter)
    : character{argCharacter}, nextPointer{nullptr}, previousPointer{nullptr}
    {}
};
class List
{
private:
    node* headPointer{nullptr};
    node* tailPointer{nullptr};
    node* getNewNode(const char argCharacter)
    {
        return new node(argCharacter);
    }
public:
    void insertAtFront(char argCharacter)
    {
        node* newNode{getNewNode(argCharacter)};
        if(isEmpty())
        {
            headPointer = tailPointer = newNode;
        }
        else
        {
            newNode->nextPointer = headPointer;
            headPointer->previousPointer = newNode;
            headPointer = newNode;
        }
    }
    void copyReverse()
    {
        if(isEmpty())
        {
            cout <<"the list is empty\n";
            return;
        }
        else
        {
            node* currentPointer{tailPointer};
            node* newNode{getNewNode(currentPointer->character)};
            node* tempHead{newNode};        //for new list's head
            node* tempPtr{tempHead};          //for iterating over new list
            cout <<"copying reverse\n";
            cout <<tempPtr->character <<"\t";
            currentPointer = currentPointer->previousPointer;
            delete newNode;
            while(currentPointer != nullptr)
            {
                node* newNode{getNewNode(currentPointer->character)};
                tempPtr->nextPointer = newNode;
                newNode->previousPointer = tempPtr;
                tempPtr = newNode;
                cout <<tempPtr->character <<"\t";
                currentPointer = currentPointer->previousPointer;
                delete newNode;
            }
            delete currentPointer;
            delete tempPtr;
        }
    }
    bool isEmpty()
    {
        return headPointer == nullptr;
    }
};
int main()
{
    List charList;
    charList.insertAtFront('c');
    charList.insertAtFront('b');
    charList.insertAtFront('a');
    charList.copyReverse();
}
