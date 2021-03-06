#ifndef LISTBST
#define LISTBST
#include"node.h"

enum traversal_type {pre_order,post_order,in_order};
template<typename T>
class listBST
{

    public:
     listBST();
     listBST(const listBST<T> & tree_reference);//not writtten
     void insert(const T& data);


     // Traversals

     // abandoned functions
    // void preOrder(node<T>*& root_ ,Process<T>* f);
    // void postOrder(node<T>*& root_ ,void (listBST<T>::*ptr)(node<T>*&));//
    // void inOrder(node<T>*& root_ ,void (*ptr)(node<T>*&));//

     //  Member functions
    void printDebug();

    void print();// unwritten

    private:
     node<T>* root;
     traversal_type traversal;
    // Helper Functions , Recursive implementations, function processes
      void insert_data(node<T>*& parent,const T& data);
      void print_debug( node<T>* treeroot,unsigned int depth);
     //void  fprint(node<T>*& n);


};
template<typename T>
listBST<T>::listBST()
 {
    root=NULL;
    traversal=pre_order;

     //void (*funPtrArray[4]) (int x, int y);



//   result = (*p[op]) (i, j); // op being the index of one of the four functions
 }
template<typename T>
listBST<T>:: listBST(const listBST<T> &tree_reference)
 {

 }
// postcondition: if equal to root it goes to right subtree
 template<typename T>
 void  listBST<T>::printDebug()
 {
     print_debug(root,0);
 }
 template<typename T>
 void  listBST<T>::print()
 {


 }
  template<typename T>
 void listBST<T>::print_debug( node<T>* treeroot,unsigned int depth)
 {
     node<T>* walker=treeroot;
     cout<<setw(4*depth)<<""; //Indentation
     if(walker==NULL)
         cout<<"[empty]"<<endl;

     else if(walker->isleaf()){
         cout<<walker->getData();
         cout<<"[leaf]"<<endl;
     }
     else//non-leaf
     {
        cout<<treeroot->getData()<<endl;
         print_debug(treeroot->childPtr(RIGHT),(depth+1));
         print_debug(treeroot->childPtr(LEFT),(depth+1));
     }
 }
template<typename T>
void listBST<T>:: insert(const T& data)
{
   insert_data(root,data);
}
template<typename T>
 void  listBST<T>:: insert_data(node<T>*& parent,const T& data)
 {
     //cout<<"inside insert helper"<<endl;
    if(!parent)
        parent=new node<T>(data);
    else{
        if(*parent>data)
            insert_data(parent->childPtr(LEFT),data);
        else
            insert_data(parent->childPtr(RIGHT),data);
    }

 }
 //non wrking code
 //template<typename T>
 //void preOrder(node<T>*& root_ ,Process<T>* f)
 //{/*
 //    cout<<"in preorder"<<endl;
 //    if(root_)
 //    {
 //        ptr(root_);
 //        preOrder(root_->childPtr(LEFT),f);
 //        preOrder(root_->childPtr(RIGHT),f);
 //     }*/
 //}

 //template<typename T>
 //void postOrder(node<T>*& root_,void (*ptr)(node<T>*&))
 //{
 //    // 1. process the nodes in the left subtree
 //    // 2. process the nodes in the right subtree
 //    // 3. Process the root
 //}

 //template<typename T>
 //void inOrder(node<T>*& root_,void (*ptr)(node<T>*&))
 //{
 //    // 1. process the nodes in the left subtree
 //    // 2. Process the root
 //    // 3. process the nodes in the right subtree

 //}
// template<typename T>
//void listBST<T>::fprint(node<T>*& n)
//{
//    cout<<*n;
//}

//NOTES from varies sources regarding the things I have looked up
// Parameters that are functions
// Micheal Main and Walter Savitch pg 508
//RULES
//1. parameters in the nested parameter must be a reference
//2.
//Form
//void apply(void f(int&), )
//OR
// template <class Process, ,>
//void apply(Process f,,)

//TRAVERSAL TYPES
/* pre-order
 * 1. process the root
 * 2. process the nodes in left subtree
 * 3. process the nodes in right subtree
 */
/* post-order
 * 1. process the nodes in the left subtree
 * 2. process the nodes in the right subtree
 * 3. Process the root
 */
/* in-order
 * 1. process the nodes in the left subtree
 * 2. Process the root
 * 3. process the nodes in the right subtree
 */
/* learning more about cpp file structure
 * Additionally, when using C++, templates and inline functions usually need to be in the header file.
The quotes tell the compiler to look for your headers in the program directory first,
 rather than the compiler's standard headers
 */
//Since fn is a non-static member function, a lone fn is not a valid expression.
//The only thing you can do with non-qualified fn in this context is call it: fn(something).
//This is what the compiler is telling you.
//If you want to obtain a pointer to member function A::fn, you have to explcitly use operator & and supply a qualified member name: &A::fn.

//Its type is “int (*)(char,float)” if an ordinary function
//Its type is “int (Fred::*)(char,float)” if a non-static member function of class Fred

//First the easy case: pointers to static member functions. Since they
//don't depend on an object instance, they look like ordinary function
//pointers.
//Assume we have some class with a static function:
//class myclass
//{
//public:
//	static void myfunc(int x) { std::cout << x << std::endl; }
//};

//Now we declare a type for a pointer to the static member function:
//typedef void ( *STATICFUNC ) ( int );

//Now assigning a function pointer and calling the function with it is easy:
//void TestStatic()
//{
//	STATICFUNC f = myclass::myfunc;	// assign address of memberfunction
//	f ( 123 ); // call the function via function pointer
//}






#endif // LISTBST

