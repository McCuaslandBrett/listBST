#ifndef NODE
#define NODE

#define NODE
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

//funtions I need (isleaf)
enum WHICH_CHILD {LEFT,RIGHT};
enum Node_errors{Nullptr_node_error};
template<typename T>
class node
{

    public:
        // Constructor with defult arguments
         node(const T &d = T(), size_t c = 1);
         //CopyConstructor
         node(const node<T> &other);
         //Destructor
          ~node();

        //postcondition : node values overwritten
         void setNodeValue(const T &d = T(), size_t c = 1);
         //Accessors
        const T& getData() const;
        size_t getCount() const;
        bool isleaf();
        //postcondition: Returns pointer from array for value accesses
        const node<T>* getChildPtr(WHICH_CHILD child) const;
         // Count Increments and Decrements
         int operator++();
         int operator++(int);
         int operator--();
         int operator--(int);
         //postcondition: overwrites given parameters, returns *This
          node<T>& operator=(const node<T> &other);
          node<T>& operator+=(size_t v);
          node<T>& operator-=(size_t v);
        //postcondition: Returns pointer from array for manipulation
         node<T>*& childPtr(WHICH_CHILD child);

        //postcondition: Assigns ptr to childptr array adress location child
         void setChildPtr(node<T>* ptr, WHICH_CHILD child);

        //Node vs Node bool functions
         template<typename U>
         friend bool operator<(const node<U>& x, const node<U> &y);

         template<typename U>
         friend  bool operator<=(const node<U>& x, const node<U> &y);

         //postcondition: retuns true if it is the same node, copys will evaluate false, address comparision
         template<typename U>
         friend bool operator==(const node<U>& x, const node<U> &y);

         template<typename U>
         friend bool operator!=(const node<U>& x, const node<U> &y);

         template<typename U>
         friend bool operator>=(const node<U>& x, const node<U> &y);

         template<typename U>
         friend bool operator>(const node<U>& x, const node<U> &y);

         //Node vs Data

         template<typename U>
         friend bool operator<(const node<U>& x, const U &y);

         template<typename U>
         friend bool operator<=(const node<U>& x, const U &y);

         template<typename U>
         friend bool operator==(const node<U>& x, const U &y);

         template<typename U>
         friend bool operator!=(const node<U>& x, const U &y);

         template<typename U>
         friend bool operator>=(const node<U>& x, const U &y);

         template<typename U>
         friend bool operator>(const node<U>& x, const U &y);

        //Data vs Node
         template<typename U>
         friend bool operator<(const U& x, const node<U> &y);

         template<typename U>
         friend bool operator<=(const U& x, const node<U> &y);

         template<typename U>
         friend bool operator==(const U& x, const node<U> &y);

         template<typename U>
         friend bool operator!=(const U& x, const node<U> &y);

         template<typename U>
         friend bool operator>=(const U& x, const node<U> &y);

         template<typename U>
         friend bool operator>(const U& x, const node<U> &y);

        //Input / Output of Nodes
         template<typename U>
         friend  ostream& operator<<(ostream &out, const node<U> &other);

         template<typename U>
         friend istream& operator>>(istream &in, node<U> &other);

      private:
         T data;
         size_t count;
         node<T> *childPointer[2];
        //postcondition: overwrites calling node data and count, ptrs are unchanged
         void copy(const node<T> &other);
         void Delete();
};
// ----------added member funtion-----------------
template<typename T>
bool node<T>::isleaf()
{
    return (this->getChildPtr(LEFT) == NULL && this->getChildPtr(RIGHT)==NULL) ;
}
//------------------------------------------------
template<typename T>
node<T>::node(const T &d, size_t c)
{
    setNodeValue(d,c);
    childPointer[LEFT] = childPointer[RIGHT] = NULL;
}

template<typename T>
node<T>::~node()
{
    Delete();
}

template<typename T>
node<T>::node(const node<T> &other)
{
    copy(other);
}

template<typename T>
node<T>& node<T>::operator=(const node<T> &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
node<T>& node<T>::operator+=(size_t v)
{
    count += v;
    return *this;
}

template<typename T>
node<T>& node<T>::operator-=(size_t v)
{
    count -= v;
    return *this;
}

template<typename T>
void node<T>::setNodeValue(const T &d , size_t c )
{
    data = d;
    count = c;
}

template<typename T>
const T& node<T>::getData() const
{
    return data;
}

template<typename T>
size_t node<T>::getCount() const
{
    return count;
}

template<typename T>
int node<T>::operator++(int)
{
    cout<<"called :operator++(int) "<<endl;
    count++;
    return count;
}

template<typename T>
int node<T>::operator++()
{
    size_t temp = count;
    count++;
    return temp;
}
template<typename T>
int node<T>::operator--(int)
{
    return --count;
}

template<typename T>
int node<T>::operator--()
{
    size_t temp = count;
    --count;
    return temp;
}

template<typename T>
node<T>*& node<T>::childPtr(WHICH_CHILD child)
{
    return childPointer[child];
}
template<typename T>
const node<T>* node<T>::getChildPtr(WHICH_CHILD child) const
{
    return childPointer[child];
}
template<typename T>
void node<T>::setChildPtr(node<T>* ptr, WHICH_CHILD child)
{
    childPointer[child] = ptr;
}
template<typename T>
void node<T>::copy(const node<T> &other)
{
    data = other.data;
    count = other.count;
}

template<typename T>
void node<T>::Delete()
{
    data = T();
    count = 0;
    childPointer[LEFT] = childPointer[RIGHT] = NULL;
}

//Node vs Node bool functions
template<typename U>
bool operator<(const node<U>& x, const node<U> &y)
{
    return x.data < y.data;
}

template<typename U>
bool operator<=(const node<U>& x, const node<U> &y)
{
    return x.data <= y.data;
}

template<typename U>
bool operator==(const node<U>& x, const node<U> &y)
{
    return x.data == y.data;
}

template<typename U>
bool operator!=(const node<U>& x, const node<U> &y)
{
    return x.data != y.data;
}

template<typename U>
bool operator>=(const node<U>& x, const node<U> &y)
{
    return x.data >= y.data;
}

template<typename U>
bool operator>(const node<U>& x, const node<U> &y)
{
    return x.data > y.data;
}

//Node vs Data

template<typename U>
bool operator<(const node<U>& x, const U &y)
{
    return x.data < y;
}

template<typename U>
bool operator<=(const node<U>& x, const U &y)
{
    return x.data <= y;
}

template<typename U>
bool operator==(const node<U>& x, const U &y)
{
    return x.data == y;
}

template<typename U>
bool operator!=(const node<U>& x, const U &y)
{
    return x.data != y;
}

template<typename U>
bool operator>=(const node<U>& x, const U &y)
{
    return x.data >= y;
}

template<typename U>
bool operator>(const node<U>& x, const U &y)
{
    return x.data > y;
}

//Data vs Node
template<typename U>
bool operator<(const U& x, const node<U> &y)
{
    return x < y.data;
}

template<typename U>
bool operator<=(const U& x, const node<U> &y)
{
    return x <= y.data;
}

template<typename U>
bool operator==(const U& x, const node<U> &y)
{
    return x == y.data;
}

template<typename U>
bool operator!=(const U& x, const node<U> &y)
{
    return x != y.data;
}


template<typename U>
bool operator>=(const U& x, const node<U> &y)
{
    return x >= y.data;
}

template<typename U>
bool operator>(const U& x, const node<U> &y)
{
    return x > y.data;
}

//Input / Output of Nodes
template<typename U>
ostream& operator<<(ostream &out, const node<U> &other)
{
    out <<other.data<<"["<<other.count<<"] ";
    return out;
}

template<typename U>
istream& operator>>(istream &in, node<U> &other)
{
    char junk;
    in>>other.data>>junk>>other.count>>junk;
    return in;
}
#endif // NODE_H

#endif // NODE




