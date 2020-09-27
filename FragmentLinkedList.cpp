#include <sstream>
#include <string>
#include <iostream>
#include <type_traits>
using namespace std;

#ifndef ILIST_H
#define ILIST_H

template <class T>
class IList
{
public:
    virtual void add(const T& element) = 0;
    virtual void add(int index, const T& element) = 0;
    virtual T& removeAt(int index) = 0;
    virtual bool removeItem(const T& item) = 0;
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
    virtual T& get(int index) = 0;
    virtual void set(int index, const T& element) = 0;
    virtual int indexOf(const T& item) = 0;
    virtual bool contains(const T& item) = 0;
    virtual string toString() = 0;
};

#endif

// STUDENT ANSWER
#ifndef FRAGMENT_LINKED_LIST
#define FRAGMENT_LINKED_LIST
template <class T>
class FragmentLinkedList : IList<T>
{
public:
    class Node;
    class Iterator;

protected:
    Node **fragmentPointers;
    int fragmentMaxSize;
    int count;

public:
    FragmentLinkedList(int fragmentMaxSize = 5)
    {
        this->count = 0;
        this->fragmentMaxSize = fragmentMaxSize;
        this->fragmentPointers = new Node *[2];
        this->fragmentPointers[0] = NULL;
        this->fragmentPointers[1] = NULL;
    }
    virtual ~FragmentLinkedList(){
        // delete fragmentPointers;
    }
    virtual void add(const T& element){
        // if(!fragmentPointers[0] && !fragmentPointers[1]){
        //     Node newNode = new Node(element, NULL, NULL);
        //     fragmentPointers[0] = newNode;
        //     fragmentPointers[1] = newNode;
        //     return;
        // }
    }
    virtual void add(int index, const T& element);
    virtual T& removeAt(int index);
    virtual bool removeItem(const T& item);
    virtual bool empty();
    virtual int size();
    virtual void clear();
    virtual T& get(int index);
    virtual void set(int index, const T& element);
    virtual int indexOf(const T& item);
    virtual bool contains(const T& item);
    virtual string toString();
    Iterator begin(int index = 0);
    Iterator end(int index = -1);

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *prev;
        friend class FragmentLinkedList<T>;

    public:
        Node()
        {
            next = 0;
            prev = 0;
        }
        Node(Node *next, Node *prev)
        {
            this->next = next;
            this->prev = prev;
        }
        Node(T data, Node *next, Node *prev)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    class Iterator
    {
    private:
        FragmentLinkedList<T> *pList;
        Node *pNode;

    public:
        Iterator(FragmentLinkedList<T> *pList = 0, Node *pNode){
            this->pList = pList;
            this->pNode = pNode;
        }
        Iterator &operator=(const Iterator &iterator){
            return iterator;
        }
        T &operator*(){
            return this->pNode.data;
        }
        bool operator!=(const Iterator &iterator){
            return this->pNode != iterator.pNode;
        }
        void remove(){
            this->pNode.prev.next = this->pNode.next;
            this->pNode.next.prev = this->pNode.prev;
            delete this->pNode;
        }
        void set(const T& element){
            this->pNode.data = element;
        }
        Iterator &operator++(){
            this->pNode = this->pNode.next;
            return *this;
        }
        Iterator operator++(int){
            operator++();
            return *this;
        }
    };
};

template <class T>
string FragmentLinkedList<T>::toString()
{
    stringstream ss;
    ss << "[";
    Node *ptr = this->fragmentPointers[0];

    if (this->count == 0)
        ss << "]";

    // TODO

    // END: TODO

    return ss.str();
}

#endif
// END: STUDENT ANSWER

int main()
{
    // TESTCASE INPUT
    // === Example
    // for(int i = 0; i < 20 ; i++)
    //     fList.add(i, i * i);

    // for(FragmentLinkedList<int>::Iterator it = fList.begin(); it != fList.end(); it++)
    //     cout << *it << " ";
    // cout << endl;
    // === END: Example
    // END: TESTCASE INPUT

    return 0;
}
