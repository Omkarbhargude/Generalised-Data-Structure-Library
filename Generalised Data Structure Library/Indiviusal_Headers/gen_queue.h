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

typedef int        BOOL;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Queue
//
///////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct GEN_QUEUE
{
    T Data;
    struct GEN_QUEUE<T> *next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   Queue
//  Description      :   This class contains generic implementation of Queue
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   14/10/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public: 

        struct GEN_QUEUE<T> *first;
        int iCount;

        Queue();

        ~Queue();

        void EnqueueNode(
                            T no
                        );

        T DequeueNode();

        void DisplayNode();

        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Queue
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This is constructor of class Queue
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T>::Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name         :   ~Queue
//  Function Author       :   Omkar Mahadev Bhargude
//  Function Date         :   14/10/2025
//  Description           :   This is destructor of class Stack
//  Input Parameter       :   NONE
//  Returns               :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T>::~Queue()
{
    struct GEN_QUEUE<T> *temp;
    struct GEN_QUEUE<T> *wait;

    if(first != NULL)
    {
        temp = first;

        while(temp != NULL)
        {
            wait = temp->next;
            free(temp);
            temp = wait;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   EnqueueNode
//  Functon Author       :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description :   
//         This function inserts node at the end of queue
//
//  Input Parameter :   
//              T generic
//
//  Return  :   void
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::EnqueueNode(
                            T no
                        )
{
    struct GEN_QUEUE<T> *temp = NULL;
    struct GEN_QUEUE<T> *newn = NULL;

    newn = new GEN_QUEUE<T>();

    newn->Data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    iCount++;

}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DequeueNode
//  Functon Author       :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description :   
//         This function Delets the node from first position of queue
//
//  Input Parameter :   NONE
//
//  Return :   
//       If the function succeeds it return the dequeued element.
//       If the function fails it return NULL.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T>::DequeueNode()
{
    struct GEN_QUEUE<T> *temp = NULL;
    T Val;

    if(first == NULL)
    {
        cout<<"Unable to dequeue element as queue is empty\n";
        return NULL;
    }

    temp = first;

    first = first->next;

    Val = temp->Data;

    delete temp;

    iCount--;

    return Val;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name         :   DisplayNode
//  Function Author       :   Omkar Mahadev Bhargude
//  Function Date         :   14/10/2025
//  Description           :   This function displays all the elements present in Queue
//  Input Parameter       :   NONE
//  Returns               :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::DisplayNode()
{
    struct GEN_QUEUE<T> *temp = NULL;

    if(first == NULL)
    {
        cout<<"Queue is Empty\n";
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
//  Description           :   This function Counts all the elements present in Queue
//  Input Parameter       :   NONE
//  Returns               :   Count of elements persent in Queue
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>::CountNode()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////

//
//  End of Queue 
//