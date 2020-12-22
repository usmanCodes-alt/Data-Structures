#include <iostream>
using namespace std;
class doublyLinkedList;
class node
{
private:
    node* previousPointer;
    int data;
    node* nextPointer;
    friend class doublyLinkedList;
public:
    explicit node(const int argData)
    : previousPointer{nullptr}, data{argData}, nextPointer{nullptr}
    {}
};
class doublyLinkedList
{
private:
    node* headPointer{nullptr};
    node* tailPointer{nullptr};
    node* getNewNode(const int argData)
    {
        return new node(argData);
    }
public:
    void addAtBack(const int argData)
    {
        node* newNode{getNewNode(argData)};
        if(isEmpty())
        {
            headPointer = tailPointer = newNode;
        }
        else
        {
            tailPointer->nextPointer = newNode;
            newNode->previousPointer = tailPointer;
            tailPointer = tailPointer->nextPointer;
        }
    }
    void print()
    {
        if(isEmpty())
        {
            cout <<"list is empty";
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
        }
    }
    void reverseList()
    {
        node* beforeMidPoint{headPointer};
        node* afterMidPoint{tailPointer};
        int midPoint = getCount() / 2;
        int i = 1;
        while(i != midPoint)
        {
            swap(beforeMidPoint->data, afterMidPoint->data);
            beforeMidPoint = beforeMidPoint->nextPointer;
            afterMidPoint = afterMidPoint->previousPointer;
            i++;
            if(i == midPoint)
            {
                swap(beforeMidPoint->data, afterMidPoint->data);
            }
        }
        beforeMidPoint = nullptr;
        afterMidPoint = nullptr;
        delete beforeMidPoint;
        delete afterMidPoint;
    }
    int getCount()
    {
        int counter = 0;
        if(isEmpty())
        {
            return 1;
        }
        else
        {
            node* currentPointer{headPointer};
            while(currentPointer != nullptr)
            {
                currentPointer = currentPointer->nextPointer;
                counter++;
            }
            return counter;
        }
    }
    bool isEmpty()
    {
        return headPointer == nullptr? true : false;
    }
};
int main()
{
    doublyLinkedList intList;
    intList.addAtBack(1);
    intList.addAtBack(2);
    intList.addAtBack(3);
    intList.addAtBack(4);
    intList.addAtBack(5);
    intList.addAtBack(6);
    intList.addAtBack(7);
    intList.addAtBack(8);
    intList.addAtBack(9);
    intList.addAtBack(10);
    intList.addAtBack(11);
    intList.print();
    intList.reverseList();
    cout <<endl;
    intList.print();
}
