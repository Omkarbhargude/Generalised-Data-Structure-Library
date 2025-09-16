//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Header Files Inclusion
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// User defined macros
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0
#define FAIL -1

//
//  New Data types
//
typedef int             BOOL;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Stack
//
///////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct GEN_STACK
{
    T Data;
    struct GEN_STACK<T> * next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   Stack
//  Description      :   This class contains generic implementation of stack
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   14/10/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:

        struct GEN_STACK<T> *first;
        int iCount;

        Stack();

        ~Stack();

        BOOL PushNode(
                            T no
                        );

        T PopNode();

        void DisplayNode();

        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Stack
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This is constructor of class Stack
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T>::Stack()
{
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name         :   ~Stack
//  Function Author       :   Omkar Mahadev Bhargude
//  Function Date         :   14/10/2025
//  Description           :   This is destructor of class Stack
//  Input Parameter       :   NONE
//  Returns               :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T>::~Stack()
{
    cout<<"Inside Destructor\n";

    struct GEN_STACK<T> *temp1 = NULL;
    struct GEN_STACK<T> *temp2 = NULL;

    if(first != NULL)
    {
        temp1 = first;
        while(temp1 != NULL)
        {
            temp2 = temp1->next;
            free(temp1);
            temp1 = temp2;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   PushNode
//  Functon Author       :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description :   
//         This function inserts node at the top of stack
//
//  Input Parameter :   
//              T generic
//
//  Return :   
//       BOOLEAN
//       If the functions succeeds, the return value is TRUE.
//       If the function Fails, the retunr value is FALSE.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Stack<T>::PushNode(
                        T no
                    )
{
    struct GEN_STACK<T> *newn = NULL;
    newn = new GEN_STACK<T>();

    newn->Data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;

    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   PopNode
//  Functon Author       :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description :   
//         This function Delets the node at the top of stack
//
//  Input Parameter :   NONE
//
//  Return :   
//       If the function succeeds it return the poped element.
//       If the function fails it return negative value.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T>::PopNode()
{
    struct GEN_STACK<T> *temp = NULL;
    T Val = 0;

    if(first == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty\n";
        return FAIL;
    }

    temp = first;
    Val = temp->Data;

    first = (temp)->next;

    delete temp;

    iCount--;

    return Val;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name         :   DisplayNode
//  Function Author       :   Omkar Mahadev Bhargude
//  Function Date         :   14/10/2025
//  Description           :   This function displays all the elements present in stack
//  Input Parameter       :   NONE
//  Returns               :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::DisplayNode()
{
    struct GEN_STACK<T> *temp = NULL;

    if(first == NULL)
    {
        cout<<"Warning > Stack is empty\n";
        return;
    }

    temp = first;

    while(temp != NULL)
    {
        cout<<temp->Data<<" -> ";

        temp = temp->next;
    }

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name         :   CountNode
//  Function Author       :   Omkar Mahadev Bhargude
//  Function Date         :   14/10/2025
//  Description           :   This function Counts all the elements present in stack
//  Input Parameter       :   NONE
//  Returns               :   Count of elements persent in Stack
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T>::CountNode()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////

//
//  End of Stack 
//