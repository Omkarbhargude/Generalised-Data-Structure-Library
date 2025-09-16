/*
    This generic implementation of Linear and Non-Linear data structure using [T] class :

    -> Included Data Structure :
    
                                1.   Stack
                                2.   Queue
                                3.   Singly Linear LinkedList
                                4.   Singly Circular LinkedList
                                5.   Doubly Linear LinkedList
                                6.   Doubly Circular LinkedList
                                7.   Binar Search Tree (BST)

    -> Searching Algoritm : 

                            1.  LinearSearch
                            2.  BiDirectionalSearch
                            3.  BinarySearchInc
                            4.  BinarySearchEfficientInc
                            5.  BinarySearchDec
                            6.  BinarySearchEfficientDec
                            7.  CheckSortedInc
                            8.  CheckSortedDec

    -> Sorting Algorithm :

                            1.  BubblerSort
                            2.  BubbleSortEfficient
                            3.  Insertionsort
                            4.  SelectionSort
    
*/

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Header Files Inclusion
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
// User defined macros
//
//////////////////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0

//
//  New data type
//
typedef int        BOOL;

//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Stack
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct GEN_STACK
{
    T data;                         // [T] generic type data
    struct GEN_STACK<T> * next;     // Pointer to next node
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   Stack
//  Description      :   This is generic implementation of stack
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   14/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:

        struct GEN_STACK<T> *p_Head;         // Points at first node 
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

//////////////////////////////////////////////////////////////////////////////////////////////
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
    this->p_Head = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
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
    struct GEN_STACK<T> *tempNode1 = NULL;
    struct GEN_STACK<T> *tempNode2 = NULL;

    if(p_Head != NULL)
    {
        tempNode1 = p_Head;
        while(tempNode1 != NULL)
        {
            tempNode2 = tempNode1->next;
            free(tempNode1);
            tempNode1 = tempNode2;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

    newn->data = no;
    newn->next = NULL;

    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        newn->next = p_Head;
        p_Head = newn;
    }

    iCount++;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   PopNode
//  Functon Author       :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description :   
//         This function Delets the node at the top of stack working on [FIFO]
//
//  Input Parameter :   NONE
//
//  Return :   
//       If the function succeeds it return the poped element.
//       If the function fails it return NULL.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T>::PopNode()
{
    struct GEN_STACK<T> *temp = NULL;
    T Val;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Unable to Pop : Stack is empty\n";
        return NULL;
    }

    temp = p_Head;
    Val = temp->data;

    p_Head = (temp)->next;

    delete temp;

    iCount--;

    return Val;
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Display : Stack is empty\n";
        return;
    }

    temp = p_Head;

    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";

        temp = temp->next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  @ END OF STACK
//
//////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Queue
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct GEN_QUEUE
{
    T data;                         // [T] generic type data
    struct GEN_QUEUE<T> *next;      // Pointer to next node
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   Queue
//  Description      :   This is generic implementation of Queue
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   14/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public: 

        struct GEN_QUEUE<T> *p_Head;             // Points to first node 
        int iCount;

        Queue();

        void EnqueueNode(
                            T no
                        );

        T DequeueNode();

        void DisplayNode();

        int CountNode();
};

//////////////////////////////////////////////////////////////////////////////////////////////
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
    this->p_Head = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

    newn->data = no;
    newn->next = NULL;

    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        temp = p_Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

    if(p_Head == NULL)
    {
        cout<<"[WARN] Unable to Dequeue : Queue is empty\n";
        return NULL;
    }

    temp = p_Head;

    p_Head = p_Head->next;

    Val = temp->data;

    delete temp;

    iCount--;

    return Val;
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Display : Queue is Empty\n";
        return;
    }

    temp = p_Head;

    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";

        temp = temp->next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////
// 
//  @ END OF QUEUE
//
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Singly Linear Linked List 
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct GEN_SINGLYLIST
{
    T data;                                 // Generic data stored in node
    struct GEN_SINGLYLIST<T> *next;         // Pointer to next node 
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   Singly_LinkedList
//  Description      :   This is generic implementation of Singly Linear LinkedList
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Singly_LinkedList
{
    public:
        struct GEN_SINGLYLIST<T> *p_Head;        // Pointing to first node in List
        int iCount;

        Singly_LinkedList();

        void DisplayGenList();

        int CountNodes();

        BOOL InsertAtFirst(
                                T no
                        );

        BOOL InsertAtLast(
                            T no
                        );

        BOOL DeleteAtFirst();

        BOOL DeleteAtLast();

        BOOL InsertAtPosition(
                                    T no,
                                    int pos
                            );

        BOOL DeleteAtPosition(
                                    int pos
                            );

        BOOL SearchListNode(
                                T data
                            );

        int SearchFirstOuccurence(
                                    T data
                                );

        int SearchLastOuccurence(
                                    T data
                                );

        int SearchAllOuccurence(
                                    T data
                                );
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Singly_LinkedList
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is constructor of class Stack
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Singly_LinkedList<T>::Singly_LinkedList()
{
    this->p_Head = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DisplayGenList()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function displays all the elements from Linked List
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Singly_LinkedList<T>::DisplayGenList()
{
    struct GEN_SINGLYLIST<T> *tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Display : List is empty\n";
        return;
    }

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        cout<<tempNode->data<<" -> ";

        tempNode = tempNode -> next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   CountNodes
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function returns the count of nodes present in Linked list
//  Input Parameter      :   NONE
//  Returns              :   Numeric Value (integer) to the caller
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Singly_LinkedList<T>::CountNodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in linked list at first position 
//
//  Input Parameter      :   [T] Generic datatype
// 
//  Returns              :   BOOLEAN
//                           If the function succeeds it 
//                          
//                       
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::InsertAtFirst(
                                                        T no
                                                )
{
    struct GEN_SINGLYLIST<T> *newn = NULL;          // New node to be insert

    newn = new GEN_SINGLYLIST<T>();
    newn->data = no;
    newn->next = NULL;

    // If this linked list is empty
    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        newn->next = p_Head;
        p_Head = newn;
    }

    iCount++;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in linked list at Last position 
//
//  Input Parameter      :   [T] Generic datatype 
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::InsertAtLast(
                                                    T no
                                                )
{
    struct GEN_SINGLYLIST<T> * tempNode = NULL;
    struct GEN_SINGLYLIST<T> * newn = NULL;

    newn = new GEN_SINGLYLIST<T>();
    newn->data = no;
    newn->next = NULL;

    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        tempNode = p_Head;

        while(tempNode->next != NULL)
        {
            tempNode = tempNode -> next;
        }

        tempNode->next = newn;
    }

    iCount++;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in linked list at first position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::DeleteAtFirst()
{
    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if(p_Head == NULL)
    {
        return FALSE;
    }
    else if(p_Head -> next == NULL)
    {
        delete p_Head;
    }
    else
    {
        tempNode = p_Head;

        p_Head = p_Head->next;

        delete tempNode;
    }

    iCount--;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in linked list at Last position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::DeleteAtLast()
{
    struct GEN_SINGLYLIST<T> *tempNode = NULL;

    if(p_Head == NULL)
    {
        return FALSE;
    }
    else if(p_Head -> next == NULL)
    {
        delete p_Head;
    }
    else
    {
        tempNode = p_Head;

        while(tempNode -> next -> next != NULL)
        {
            tempNode = tempNode->next;
        }

        delete tempNode->next;

        tempNode->next = NULL;
    }

    iCount--;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function inserts the given node at given position in 
//                           Linked list 
//
//  Input Parameter      :   [T] Generic data, [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::InsertAtPosition(
                                                        T no,
                                                        int pos
                                                    )
{
    int i = 0;

    struct GEN_SINGLYLIST<T> * newn = NULL;
    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"[WARN] Cannot Insert : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        InsertAtFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertAtLast(no);
    }
    else
    {
        newn = new GEN_SINGLYLIST<T>();
        newn->data = no;
        newn->next = NULL;

        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode -> next;
        }

        newn->next = tempNode->next;
        tempNode->next = newn;

        iCount++;
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the  node at given position in 
//                           Linked list 
//
//  Input Parameter      :   [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::DeleteAtPosition(
                                                        int pos
                                                    )
{
    int i = 0;

    struct GEN_SINGLYLIST<T> *tempNode = NULL;
    struct GEN_SINGLYLIST<T> *targetNode = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"[WARN] Cannot Delete : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        DeleteAtFirst();
    }
    else if(pos == iCount)
    {
        DeleteAtLast();
    }
    else
    {
        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode->next;
        }

        targetNode = tempNode->next;

        tempNode->next = targetNode->next;

        delete targetNode;

        iCount--;
    }

    return TRUE;

}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchListNode ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches particular data in singly linear linked.
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   BOOLEAN
//                           If the function succeeds it return TRUE.
//                           If the function fails it return FALSE.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_LinkedList<T>::SearchListNode(
                                                T s_data
                                            )
{
    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot search: list is empty\n";
        return FALSE;
    }

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        if(tempNode->data == s_data)
        {
            return TRUE;
        }
        tempNode = tempNode->next;
    }

        return FALSE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchFirstOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in singly linear list
//                           and return the position of its first ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Singly_LinkedList<T>::SearchFirstOuccurence(
                                                    T s_data
                                                )
{
    int iPos = 0;

    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        iPos++;

        if(tempNode -> data == s_data)
        {
            return iPos;
        }
        tempNode = tempNode->next;
    }

    return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchLastOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in singly linear list
//                           and return the position of its last ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Singly_LinkedList<T>::SearchLastOuccurence(
                                                    T s_data
                                                )
{
    int iPos = 0;
    int iOucc = 0;

    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        iPos++;

        if(tempNode->data == s_data)
        {
            iOucc = iPos;
        }
        tempNode = tempNode->next;
    }

    if(iOucc == 0)
    {
        return -1;
    }
    else
    {
        return iOucc;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchAllOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches a particular data in singly linear list
//                           and returns total number of ouccurence  in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Total number of time the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Singly_LinkedList<T>::SearchAllOuccurence(
                                                    T s_data
                                                )
{
    int iCnt = 0;

    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Search : List is empty\n";
        return FALSE;
    }

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        if(tempNode -> data == s_data)
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  @ END OF SINGLY LINEAR LINKED LIST
//
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  This is generic Singly Circuler Linked List 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
 
template<class T>
struct GEN_SINGLYCLL
{
    T data;                                 // Generic data stored in node
    struct GEN_SINGLYCLL<T> *next;         // Pointer to next node 
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   SinglyCLL
//  Description      :   This is generic implementation of Singly circular LinkedList
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCLL
{
    public:
        struct GEN_SINGLYCLL<T> *p_Head;       // Pointing to first node in List
        struct GEN_SINGLYCLL<T> *p_Tail;
        int iCount;

        SinglyCLL();

        void DisplayGenList();

        int CountNodes();

        BOOL InsertAtFirst(
                                        T no
                                );

        BOOL InsertAtLast(
                                        T no
                                    );

        BOOL DeleteAtFirst();

        BOOL DeleteAtLast();

        BOOL InsertAtPosition(
                                            T no,
                                            int pos
                                        );

        BOOL DeleteAtPosition(
                                            int pos
                                    );

        BOOL SearchListNode(
                                T data
                            );

        int SearchFirstOuccurence(
                                    T data
                                );

        int SearchLastOuccurence(
                                    T data
                                );

        int SearchAllOuccurence(
                                    T data
                                );

};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SinglyCLL
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is constructor of class SinglyCLL
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    this->p_Head = NULL;
    this->p_Tail = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DisplayGenList()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function displays all the elements from singly circular list
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DisplayGenList()
{
    struct GEN_SINGLYCLL<T> *tempNode = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        cout<<"[WARN] Cannot Display : List is empty\n";
        return;
    }

    tempNode = p_Head;

    do
    {
        cout<<tempNode->data<<" -> ";

        tempNode = tempNode -> next;

    }while(tempNode != p_Head);

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   CountNodes
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function returns the count of nodes present in circular list
//  Input Parameter      :   NONE
//  Returns              :   Numeric Value (integer) to the caller
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::CountNodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in Circular list at first position 
//
//  Input Parameter      :   [T] Generic datatype
// 
//  Returns              :   BOOLEAN
//                           If the function succeeds it 
//                          
//                       
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::InsertAtFirst(
                                                        T no
                                                )
{
    struct GEN_SINGLYCLL<T> *newn = NULL;          // New node to be insert

    newn = new GEN_SINGLYCLL<T>();
    newn->data = no;
    newn->next = NULL;

    // If this linked list is empty
    if(p_Head == NULL && p_Tail == NULL)
    {
        p_Head = newn;
        p_Tail = newn;
    }
    else
    {
        newn->next = p_Head;
        p_Head = newn;
    }

    p_Tail -> next = p_Head;
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in singgly circular list at Last 
//                           position 
//
//  Input Parameter      :   [T] Generic datatype 
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::InsertAtLast(
                                                    T no
                                                )
{
    struct GEN_SINGLYCLL<T> * newn = NULL;

    newn = new GEN_SINGLYCLL<T>();
    newn->data = no;
    newn->next = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        p_Head = newn;
        p_Tail = newn;
    }
    else
    {
        p_Tail -> next = newn;

        p_Tail = newn;
    }

    p_Tail -> next = p_Head;
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in singly circular list at 
//                           first position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::DeleteAtFirst()
{

    if(p_Head == NULL)
    {
        return FALSE;
    }
    else if(p_Head == p_Tail)
    {
        delete p_Head;
        p_Head = NULL;
        p_Tail = NULL;
    }
    else
    {

        p_Head = p_Head->next;

        delete p_Tail -> next;
    }

    iCount--;
    p_Tail ->next = p_Head;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in singly circular linked list at 
//                           Last position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::DeleteAtLast()
{
    struct GEN_SINGLYCLL<T> *tempNode = NULL;

    if(p_Head == NULL)
    {
        return FALSE;
    }
    else if(p_Head == p_Tail)
    {
        delete p_Head;

        p_Head = NULL;
        p_Tail = NULL;
    }
    else
    {
        tempNode = p_Head;

        while(tempNode -> next -> next != p_Head)
        {
            tempNode = tempNode->next;
        }

        p_Tail = tempNode;
        delete tempNode->next;
    }

    iCount--;
    p_Tail -> next = p_Head;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function inserts the given node at given position in 
//                           singly circular Linked list 
//
//  Input Parameter      :   [T] Generic data, [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::InsertAtPosition(
                                                        T no,
                                                        int pos
                                                    )
{
    int i = 0;

    struct GEN_SINGLYCLL<T> * newn = NULL;
    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"[WARN] Cannot Insert : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        InsertAtFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertAtLast(no);
    }
    else
    {
        newn = new GEN_SINGLYCLL<T>();
        newn->data = no;
        newn->next = NULL;

        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode -> next;
        }

        newn->next = tempNode->next;
        tempNode->next = newn;

        iCount++;
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the  node at given position in 
//                           Linked list 
//
//  Input Parameter      :   [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::DeleteAtPosition(
                                                        int pos
                                                    )
{
    int i = 0;

    struct GEN_SINGLYCLL<T> *tempNode = NULL;
    struct GEN_SINGLYCLL<T> *targetNode = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"[WARN] Cannot Delete : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        DeleteAtFirst();
    }
    else if(pos == iCount)
    {
        DeleteAtLast();
    }
    else
    {
        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode->next;
        }

        targetNode = tempNode->next;

        tempNode->next = targetNode->next;

        delete targetNode;

        iCount--;
    }

    return TRUE;

}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchListNode ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches particular data in singly linear linked.
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   BOOLEAN
//                           If the function succeeds it return TRUE.
//                           If the function fails it return FALSE.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::SearchListNode(
                                                T s_data
                                            )
{
    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        cout<<"[WARN] Cannot search: list is empty\n";
        return FALSE;
    }
    
    if((p_Head->data == s_data) || (p_Tail->data == s_data))
    {
        return TRUE;
    }

    tempNode = p_Head;

    do
    {
        if(tempNode->data == s_data)
        {
            return TRUE;
        }

        tempNode = tempNode->next;
    }while(tempNode != p_Head);

        return FALSE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchFirstOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in singly circular list
//                           and return the position of its first ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::SearchFirstOuccurence(
                                                    T s_data
                                                )
{
    int iPos = 0;

    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    tempNode = p_Head;

    do
    {
        iPos++;

        if(tempNode -> data == s_data)
        {
            return iPos;
        }

        tempNode = tempNode->next;
    }while(tempNode != p_Head);

    return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchLastOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in singly circular list
//                           and return the position of its last ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::SearchLastOuccurence(
                                                    T s_data
                                                )
{
    int iPos = 0;
    int iOucc = 0;

    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    tempNode = p_Head;

    do
    {
        iPos++;

        if(tempNode->data == s_data)
        {
            iOucc = iPos;
        }

        tempNode = tempNode->next;
    }while(tempNode != p_Head);

    if(iOucc == 0)
    {
        return -1;
    }
    else
    {
        return iOucc;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchAllOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches a particular data in singly circular list
//                           and returns total number of ouccurence  in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Total number of time the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::SearchAllOuccurence(
                                                    T s_data
                                                )
{
    int iCnt = 0;

    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Search : List is empty\n";
        return FALSE;
    }

    tempNode = p_Head;

    do
    {
        if(tempNode -> data == s_data)
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }while(tempNode != p_Head);

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  END OF SINGLY CIRCULAR LINKED LIST
//
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  This is generic Doubly Linear Linked List 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct GEN_DOUBLYLIST
{
    T data;                                 // Generic data stored in node
    struct GEN_DOUBLYLIST<T> *prev;          // Previous pointer for node
    struct GEN_DOUBLYLIST<T> *next;         // Pointer to next node 
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   DoublyLinearList
//  Description      :   This is generic implementation of doubly Linear LinkedList
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
    public:
        struct GEN_DOUBLYLIST<T> *p_Head;       // Pointing to first node in List
        int iCount;

        DoublyLL();

        void DisplayGenList();

        int CountNodes();

        BOOL InsertAtFirst(
                                T no
                        );

        BOOL InsertAtLast(
                            T no
                        );

        BOOL DeleteAtFirst();

        BOOL DeleteAtLast();

        BOOL InsertAtPosition(
                                T no,
                                int pos
                            );

        BOOL DeleteAtPosition(
                                int pos
                            );

        BOOL SearchListNode(
                                T data
                            );

        int SearchFirstOuccurence(
                                    T data
                                );

        int SearchLastOuccurence(
                                    T data
                                );

        int SearchAllOuccurence(
                                    T data
                                );

};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DoublyLL
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is constructor of class DoublyLinearList
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::DoublyLL()
{
    this->p_Head = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DisplayGenList()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function displays all the elements from doubly linear list
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::DisplayGenList()
{
    struct GEN_DOUBLYLIST<T> *tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Display : List is empty\n";
        return;
    }

    tempNode = p_Head;

    cout<<"null <-> ";
    while(tempNode != NULL)
    {
        cout<<tempNode->data<<" <-> ";

        tempNode = tempNode -> next;

    }
    cout<<" null \n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   CountNodes
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function returns the count of nodes present in circular list
//  Input Parameter      :   NONE
//  Returns              :   Numeric Value (integer) to the caller
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::CountNodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in Circular list at first position 
//
//  Input Parameter      :   [T] Generic datatype
// 
//  Returns              :   BOOLEAN
//                           If the function succeeds it 
//                          
//                       
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::InsertAtFirst(
                                    T no
                             )
{
    struct GEN_DOUBLYLIST<T> *newn = NULL;          // New node to be insert

    newn = new GEN_DOUBLYLIST<T>();
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    // If this linked list is empty
    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        newn -> next = p_Head;
        p_Head -> prev = newn;
        p_Head = newn;
    }
    
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in singgly circular list at Last 
//                           position 
//
//  Input Parameter      :   [T] Generic datatype 
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::InsertAtLast(
                                    T no
                            )
{
    struct GEN_DOUBLYLIST<T> * tempNode = NULL;
    struct GEN_DOUBLYLIST<T> * newn = NULL;

    newn = new GEN_DOUBLYLIST<T>();
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        tempNode = p_Head;

        while(tempNode -> next != NULL)
        {
            tempNode = tempNode -> next;
        }

        tempNode -> next = newn;
        newn -> prev = tempNode;
    }

    iCount++;
    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in doubly linear list at 
//                           first position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::DeleteAtFirst()
{   

    if(p_Head == NULL)
    {
        return FALSE;
    }
    else if(p_Head -> next == NULL)
    {
        delete p_Head;
        p_Head = NULL;
    }
    else
    {
        p_Head = p_Head -> next;
        delete p_Head -> prev;
        p_Head -> prev = NULL;
    }

    iCount--;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in doubly linear linked list at 
//                           Last position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::DeleteAtLast()
{
    struct GEN_DOUBLYLIST<T> *tempNode = NULL;

    if(p_Head == NULL)
    {
        return FALSE;
    }
    else if(p_Head -> next == NULL)
    {
        delete p_Head;
        p_Head = NULL;
    }
    else
    {
        tempNode = p_Head;

        while(tempNode -> next -> next != p_Head)
        {
            tempNode = tempNode->next;
        }

        delete tempNode -> next;
        tempNode -> next = NULL;
    }

    iCount--;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function inserts the given node at given position in 
//                           doubly linear Linked list 
//
//  Input Parameter      :   [T] Generic data, [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::InsertAtPosition(
                                       T no,
                                       int pos
                                )
{
    int i = 0;

    struct GEN_DOUBLYLIST<T> * newn = NULL;
    struct GEN_DOUBLYLIST<T> * tempNode = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"[WARN] Cannot Insert : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        InsertAtFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertAtLast(no);
    }
    else
    {
        newn = new GEN_DOUBLYLIST<T>();
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode -> next;
        }

        newn->next = tempNode->next;
        tempNode -> next -> prev = newn;

        tempNode->next = newn;
        newn->prev = tempNode;
        iCount++;
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the  node at given position in 
//                           Linked list 
//
//  Input Parameter      :   [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::DeleteAtPosition(
                                       int pos
                                )
{
    int i = 0;

    struct GEN_DOUBLYLIST<T> *tempNode = NULL;
    struct GEN_DOUBLYLIST<T> *targetNode = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"[WARN] Cannot Delete : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        DeleteAtFirst();
    }
    else if(pos == iCount)
    {
        DeleteAtLast();
    }
    else
    {
        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode->next;
        }

        targetNode = tempNode->next;
        tempNode->next = targetNode->next;
        targetNode -> next -> prev = tempNode;

        delete targetNode;
        iCount--;
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchListNode ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches particular data in doubly linear list.
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   BOOLEAN
//                           If the function succeeds it return TRUE.
//                           If the function fails it return FALSE.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyLL<T>::SearchListNode(
                                    T s_data
                                )
{
    struct GEN_DOUBLYLIST<T> * tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot search: list is empty\n";
        return FALSE;
    }
    
    tempNode = p_Head;

    while(tempNode != NULL)
    {
        if(tempNode->data == s_data)
        {
            return TRUE;
        }

        tempNode = tempNode->next;
    }

        return FALSE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchFirstOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in doubly linear list
//                           and return the position of its first ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::SearchFirstOuccurence(
                                        T s_data
                                    )
{
    int iPos = 0;

    struct GEN_DOUBLYLIST<T> * tempNode = NULL;

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        iPos++;

        if(tempNode -> data == s_data)
        {
            return iPos;
        }

        tempNode = tempNode->next;
    }

    return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchLastOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in doubly linear list
//                           and return the position of its last ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::SearchLastOuccurence(
                                        T s_data
                                    )
{
    int iPos = 0;
    int iOucc = 0;

    struct GEN_DOUBLYLIST<T> * tempNode = NULL;

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        iPos++;

        if(tempNode->data == s_data)
        {
            iOucc = iPos;
        }

        tempNode = tempNode->next;
    }

    if(iOucc == 0)
    {
        return -1;
    }
    else
    {
        return iOucc;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchAllOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches a particular data in doubly linear list
//                           and returns total number of ouccurence  in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Total number of time the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::SearchAllOuccurence(
                                        T s_data
                                    )
{
    int iCnt = 0;

    struct GEN_DOUBLYLIST<T> * tempNode = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Search : List is empty\n";
        return FALSE;
    }

    tempNode = p_Head;

    while(tempNode != NULL)
    {
        if(tempNode -> data == s_data)
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  END OF DOUBLY LINEAR LINKED LIST
//
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  This is generic Doubly Circular Linked List 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

//
//  This is generic doubly circuler linked list of type T
//
template<class T>
struct GEN_DOUBLYCLL
{
    T data;                                 // Generic data stored in node
    struct GEN_DOUBLYCLL<T> *prev;          // previous pointer of node
    struct GEN_DOUBLYCLL<T> *next;         // Pointer to next node 
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   DoublyCLL
//  Description      :   This is generic implementation of doubly circular LinkedList
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCLL
{
    public:
        struct GEN_DOUBLYCLL<T> *p_Head;       // Pointing to first node in List
        struct GEN_DOUBLYCLL<T> *p_Tail;       // Pointing to last node in list
        int iCount;

        DoublyCLL();

        void DisplayGenList();

        int CountNodes();

        BOOL InsertAtFirst(
                               T no
                        );

        BOOL InsertAtLast(
                            T no
                        );

        BOOL DeleteAtFirst();

        BOOL DeleteAtLast();

        BOOL InsertAtPosition(
                                    T no,
                                    int pos
                            );

        BOOL DeleteAtPosition(
                                            int pos
                                    );

        BOOL SearchListNode(
                                T s_data
                            );

        int SearchFirstOuccurence(
                                    T s_data
                                );

        int SearchLastOuccurence(
                                    T s_data
                                );

        int SearchAllOuccurence(
                                    T s_data
                                );

};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DoublyCLL
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is constructor of class DoublyCLL
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    this->p_Head = NULL;
    this->p_Tail = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DisplayGenList()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function displays all the elements from doubly circular list
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DisplayGenList()
{
    struct GEN_DOUBLYCLL<T> *tempNode = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        cout<<"[WARN] Cannot Display : List is empty\n";
        return;
    }

    tempNode = p_Head;

    cout<<" <-> ";
    do
    {
        cout<<tempNode->data<<" <-> ";

        tempNode = tempNode -> next;

    }while(tempNode != p_Head);

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   CountNodes
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function returns the count of nodes present in circular list
//  Input Parameter      :   NONE
//  Returns              :   Numeric Value (integer) to the caller
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::CountNodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in doubly Circular list at first 
//                          position 
//
//  Input Parameter      :   [T] Generic datatype
// 
//  Returns              :   BOOLEAN
//                           If the function succeeds it 
//                          
//                       
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::InsertAtFirst(
                                    T no
                                )
{
    struct GEN_DOUBLYCLL<T> *newn = NULL;          // New node to be insert

    newn = new GEN_DOUBLYCLL<T>();
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    // If this linked list is empty
    if(p_Head == NULL && p_Tail == NULL)
    {
        p_Head = newn;
        p_Tail = newn;
    }
    else
    {
        newn->next = p_Head;
        p_Head -> prev = newn;
        p_Head = newn;
    }

    p_Tail -> next = p_Head;
    p_Head -> prev = p_Tail;
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in doubly circular list at Last 
//                           position 
//
//  Input Parameter      :   [T] Generic datatype 
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::InsertAtLast(
                                    T no
                            )
{
    struct GEN_DOUBLYCLL<T> * tempNode = NULL;
    struct GEN_DOUBLYCLL<T> * newn = NULL;

    newn = new GEN_DOUBLYCLL<T>();
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        p_Head = newn;
        p_Tail = newn;
    }
    else
    {
        p_Tail -> next = newn;
        p_Tail = newn;
    }

    p_Tail -> next = p_Head;
    p_Head -> prev = p_Tail;
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtFirst ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in doubly circular list at 
//                           first position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::DeleteAtFirst()
{

    if(p_Head == NULL && p_Tail == NULL)
    {
        return FALSE;
    }
    else if(p_Head == p_Tail)
    {
        delete p_Head;
        p_Head = NULL;
        p_Tail = NULL;
    }
    else
    {
        p_Head = p_Head->next;
        delete p_Tail -> next;
    }

    iCount--;
    p_Tail ->next = p_Head;
    p_Head ->prev = p_Tail;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtLast ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the node in doubly circular linked list at 
//                           Last position 
//
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::DeleteAtLast()
{
    struct GEN_DOUBLYCLL<T> *tempNode = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        return FALSE;
    }
    else if(p_Head == p_Tail)
    {
        delete p_Head;

        p_Head = NULL;
        p_Tail = NULL;
    }
    else
    {
        p_Tail = p_Tail -> prev;
        delete p_Head -> prev;
    }

    iCount--;
    p_Tail -> next = p_Head;
    p_Head -> prev = p_Tail;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function inserts the given node at given position in 
//                           doubly circular Linked list 
//
//  Input Parameter      :   [T] Generic data, [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::InsertAtPosition(
                                        T no,
                                        int pos
                                    )
{
    int i = 0;

    struct GEN_DOUBLYCLL<T> * newn = NULL;
    struct GEN_DOUBLYCLL<T> * tempNode = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"[WARN] Cannot Insert : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        InsertAtFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertAtLast(no);
    }
    else
    {
        newn = new GEN_DOUBLYCLL<T>();
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode -> next;
        }

        newn -> next = tempNode -> next;
        tempNode -> next -> prev = newn;

        newn -> prev = tempNode;
        tempNode -> next = newn;
        iCount++;
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   DeleteAtPosition ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Deletes the  node at given position in doubly
//                           Linked list 
//
//  Input Parameter      :   [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::DeleteAtPosition(
                                        int pos
                                        
                                    )
{
    int i = 0;

    struct GEN_DOUBLYCLL<T> *tempNode = NULL;
    struct GEN_DOUBLYCLL<T> *targetNode = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"[WARN] Cannot Delete : Position is invalid\n";
        return FALSE;
    }

    if(pos == 1)
    {
        DeleteAtFirst();
    }
    else if(pos == iCount)
    {
        DeleteAtLast();
    }
    else
    {
        tempNode = p_Head;

        for(i = 1; i < pos-1; i++)
        {
            tempNode = tempNode->next;
        }

        targetNode = tempNode -> next;

        tempNode -> next = targetNode -> next;
        targetNode -> next -> prev = tempNode;

        delete targetNode;

        iCount--;
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchListNode ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches particular data in doubly circular linked.
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   BOOLEAN
//                           If the function succeeds it return TRUE.
//                           If the function fails it return FALSE.
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL DoublyCLL<T>::SearchListNode(
                                       T s_data
                                )
{
    struct GEN_DOUBLYCLL<T> * tempNode = NULL;
    struct GEN_DOUBLYCLL<T> * itempNode = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        cout<<"[WARN] Cannot search: list is empty\n";
        return FALSE;
    }
    
    if((p_Head->data == s_data) || (p_Tail->data == s_data))
    {
        return TRUE;
    }

    tempNode = p_Head;
    itempNode = p_Tail;

    do
    {
        if((tempNode->data == s_data) || (itempNode->data == s_data))
        {
            return TRUE;
        }

        tempNode = tempNode->next;
        itempNode = itempNode -> prev;
    }while(tempNode != itempNode);

    return FALSE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchFirstOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in doubly circular list
//                           and return the position of its first ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::SearchFirstOuccurence(
                                           T s_data
                                        )
{
    int iPos = 0;

    struct GEN_DOUBLYCLL<T> * tempNode = NULL;

    tempNode = p_Head;

    do
    {
        iPos++;

        if(tempNode -> data == s_data)
        {
            return iPos;
        }

        tempNode = tempNode->next;
    }while(tempNode != p_Head);

    return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchLastOuccrence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searche a particular data in doubly circular list
//                           and return the position of its last ouccurence in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Position at which the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::SearchLastOuccurence(
                                           T s_data
                                    )
{
    int iPos = 0;
    int iOucc = 0;

    struct GEN_DOUBLYCLL<T> * tempNode = NULL;

    tempNode = p_Head;

    do
    {
        iPos++;

        if(tempNode->data == s_data)
        {
            iOucc = iPos;
        }

        tempNode = tempNode->next;
    }while(tempNode != p_Head);

    if(iOucc == 0)
    {
        return -1;
    }
    else
    {
        return iOucc;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   SearchAllOuccurence ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function searches a particular data in doubly circular list
//                           and returns total number of ouccurence  in list
//
//  Input Parameter      :   [T] Generic Type
//
//  Returns              :   int
//                           Total number of time the data found in generic list
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::SearchAllOuccurence(
                                        T s_data
                                    )
{
    int iCnt = 0;

    struct GEN_DOUBLYCLL<T> * tempNode = NULL;
    struct GEN_DOUBLYCLL<T> * itempNode = NULL;

    if(p_Head == NULL && p_Tail == NULL)
    {
        cout<<"[WARN] Cannot Search : List is empty\n";
        return FALSE;
    }

    tempNode = p_Head;
    itempNode = p_Tail;

    do
    {
        if((tempNode -> data == s_data))
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }while(tempNode != p_Head);

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  END OF DOUBLY CIRCULAR LINKED LIST
//
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  This is generic Binary Search Tree (BST)
//
//////////////////////////////////////////////////////////////////////////////////////////////

//
//  Structure of Node
//
template<class T>
struct GEN_BST
{
    T data;                                  // Generic data s tored in node
    struct GEN_BST<T> * rightchild;         // rightchild node
    struct GEN_BST<T> * leftchild;          // leftchild node
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   BST
//  Description      :   This is generic implementation of Binary Search Tree
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class BST
{
    public:

        struct GEN_BST<T> * p_Head;
        int iCount;

        BST();

        BOOL InsertNewNode(
                                T data
                             );
        
        void InorderTraversal(
                                GEN_BST<T> * first
                            );
        
        void PreorderTraversal(
                                GEN_BST<T> * first
                            );

        void PostorderTraversal(
                                GEN_BST<T> * first
                            );

        BOOL SearchNode(
                            T s_data
                         );

        int CountNode();

        BOOL CountLeafNode(
                                GEN_BST<T> *first
                          );

        BOOL CountParentNode(
                                GEN_BST<T> *first
                            );
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   BST
//  class Name           :   BinarySearchTree (BST)
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is constructor of class BST
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BST<T>::BST()
{
    this->p_Head = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertNewNode()
//  class Name           :   BinarySearchTree (BST)
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function insert new node in BST
//
//  Input Parameter      :   [T] generic data
//
//  Returns              :   BOOLEAN
//                           If the function succeeds then it return TRUE.
//                           If the function fails then it return FALSE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL BST<T>::InsertNewNode(
                                T no
                         )
{
    struct GEN_BST<T> * temp = NULL;
    struct GEN_BST<T> * newn = NULL;
    newn =  new GEN_BST<T>();

    newn->data =  no;
    newn->leftchild = NULL;
    newn->rightchild = NULL;

    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        temp = p_Head;

        while(1)
        {
            if(temp -> data == no)
            {
                cout<<"[WARN] Duplicate Data : Unable to insert data\n";
                delete newn;
                return FALSE;
            }

            else if(no > temp->data)
            {
                if(temp->rightchild == NULL)
                {
                    temp -> rightchild = newn;
                    iCount++;
                    break;
                }

                temp = temp -> rightchild;
            }

            else if(no < temp -> data)
            {
                if(temp -> leftchild == NULL)
                {
                    temp -> leftchild = newn;
                    iCount++;
                    break;
                }

                temp = temp-> leftchild;
            }
        }
    }

    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   InorderTraversal
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   Performs an in-order traversal** of the binary search tree.
//                          Visits the nodes  (Left → Node → Right)
//                          and displays the value stored in each node.
//
//  Input Parameter     :    Node<T>* node
//                         
//  Return              :    void   
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>::InorderTraversal(
                                GEN_BST<T> *first
                            )
{
    if(first != NULL)
    {
        InorderTraversal(first->leftchild);
        cout<<first->data<<" -> ";
        InorderTraversal(first->rightchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   PostorderTraversal
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   Performs an Psot-order traversal of the binary search tree.
//                          Visits the nodes (Left → Right → Node)
//                          and displays the value stored in each node.
//
//  Input Parameter     :    Node<T>* node
//                         
//  Return              :    void
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>::PostorderTraversal(
                                    GEN_BST<T> *first
                                )
{
    if(first != NULL)
    {
        PostorderTraversal(first->leftchild);
        PostorderTraversal(first->rightchild);
        cout<<first->data<<" -> ";
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   PreorderTraversal
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   Performs an in-order traversal** of the binary search tree.
//                          Visits the nodes  (Node → Left → Right)
//                          and displays the value stored in each node.
//
//  Input Parameter     :    Node<T>* node
//                         
//  Return              :    void   
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>::PreorderTraversal(
                                    GEN_BST<T> *first
                                )
{
    if(first != NULL)
    {
        cout<<first->data<<" -> ";
        PostorderTraversal(first->leftchild);
        PostorderTraversal(first->rightchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CountNode()
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function counts the number of nodes present in BST
//
//  Input Parameter     :    NONE
//                         
//  Return              :    int 
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountNode()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   SearchNode
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function searches the given data in BST
//
//  Input Parameter     :    [T] generic type
//                         
//  Return              :    BOOLEAN
//                           if the function succeeds it returns TRUE.
//                           if the function fails it returns FALSE.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL BST<T>::SearchNode(
                            T s_data
                        )
{
    struct GEN_BST<T> * temp = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Search : BST is empty\n";
        return FALSE;
    }

    temp = p_Head;

    while(temp != NULL)
    {
        if(s_data == temp->data)
        {
            return TRUE;
            break;
        }

        else if(s_data  < temp->data)
        {
            temp = temp->leftchild;
        }

        else if(s_data > temp->data)
        {
            temp = temp->rightchild;
        }
    }

    return FALSE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CountLeafNode ()
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function counts the total number of leaf nodes present in
//                          BinarySearchTree (BST)
//
//  Input Parameter     :   GEN_BST<T>* node
//                         
//  Return              :   int
//                          Returns the number total leaf nodes present
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountLeafNode(
                            GEN_BST<T> *first
                        )
{
    static int iCount = 0;

    if(p_Head == NULL)
    {
        cout<<"[WARN] : BST is empty\n";
        return FALSE;
    }

    if(first != NULL)
    {
        if((first->leftchild == NULL) && (first->rightchild == NULL))
        {
            iCount++;
        }
        CountLeafNode(first -> leftchild);
        CountLeafNode(first -> rightchild);
    }
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CountParentNode ()
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function counts the total number of Parent nodes present in
//                          BinarySearchTree (BST)
//
//  Input Parameter     :   GEN_BST<T>* node
//                         
//  Return              :   int
//                          Returns the number total parent nodes present
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountParentNode(
                            GEN_BST<T> *first
                        )
{
    static int iCount = 0;

    if(p_Head == NULL)
    {
        cout<<"[WARN] : BST is empty\n";
        return FALSE;
    }
    
    if(first != NULL)
    {
        if((first->leftchild != NULL) || (first->rightchild != NULL))
        {
            iCount++;
        }
        CountParentNode(first -> leftchild);
        CountParentNode(first -> rightchild);
    }

    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      END OF BINARY SEARCH TREE (BST)
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      SEARCHING ALGORITHMS :-
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class           :   Searching 
//  Description     :   Generic implemention of Searching algorithms.
//  Author          :   Omkar Mahadev Bhargude
//  Date            :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Searching
{
    public:

        int *Arr;
        int iSize;
        bool Sorted;

        Searching(
                    int A
                );

        ~Searching();

        void Accept();

        void Display();

        bool LinearSearch(
                            T data
                        );

        bool BiDirectionalSearch(
                                    T data
                                );
                    
        bool BinarySearchInc(
                                T data
                            );

        bool BinarySearchDec(
                                T data
                            );

        bool BinarySearchEfficientInc(
                                        T data
                                    );

        bool BinarySearchEfficientDec(
                                        T data
                                    );

        bool CheckSortedInc();

        bool CheckSortedDec();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Searching
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is parametrised constructor of class Searching
//  Input Parameter      :   s_dataNE
//  Returns              :   s_dataNE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Searching<T>::Searching(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
    this->Sorted = true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   ~Searching ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is destructor of class Searching
//  Input Parameter      :   s_dataNE
//  Returns              :   s_dataNE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Searching<T>::~Searching()
{
    delete []Arr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Accpet()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//
//  Description          :   This function accpets input from user and store it in array
//
//  Input Parameter      :   [T] generic type
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Searching<T>::Accept()
{
    int i = 0;
    cout<<"Enter "<<iSize<<" elements : \n";

    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter element s_data : "<<i+1<<"\n";
        cin>>Arr[i];

        // If the the current data is less then previous data then it s_datat sorted
        // data should be in asec order -> -> ->
        // [12,24,43,65,89] -> sorted data
        // [11,45,32,78,12,7] -> Unsorted data

        if((Arr[i] < Arr[i - 1]))
        {
            Sorted = false;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Display()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//
//  Description          :   This function displays the array
//
//  Input Parameter      :   [T] generic type
//
//  Returns              :   s_dataNE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Searching<T>::Display()
{   
    int i = 0;
    cout<<"Elements of the array are : \n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   LinearSearch
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   14/10/2025
//
//  Description         :   Searches for a given element in the given array using the Linear Search algorithm.
//                          It scans each element sequentially from the beginning until the given element is 
//                          found. if array is sorted it used efficient binary search algorithm
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
//  Time Complexity     :
//        Best Case    : O(1)   -> When the element is at the first position.
//        Worst Case   : O(n)   -> When the element is at the end or s_datat present.
//        Average Case : O(n)
//  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::LinearSearch(
                                    T s_data
                                )
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)
    {
        cout<<"[INFO] Data is Sorted : Using BinarySearchEfficientInc\n";
        return BinarySearchEfficientInc(s_data);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == s_data)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BiDirectionalSearch()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   14/10/2025
//
//  Description         :   Searches for a given element from both the end simultaneously
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BiDirectionalSearch(
                                            T s_data
                                    )
{
    int istart = 0, iend = 0;
    bool bFlag = false;

    if(Sorted == true)
    {
        cout<<"[INFO] Data is Sorted : Using BinarySearchEfficientInc\n";
        return BinarySearchEfficientInc(s_data);
    }

    for(istart = 0, iend = iSize -1; istart <= iend; istart++,iend--)
    {
        if((Arr[istart] == s_data) || (Arr[iend] == s_data))
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchInc()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   14/10/2025
//
//  Description         :   Searches for a given element in a sorted (increasing order) array using the
//                          Binary Search algorithm.
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchInc(
                                        T s_data
                                )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == s_data)
        {
            bFlag = true;
            break;
        }
        else if(s_data < Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data > Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchDec()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   14/10/2025
//
//  Description         :   Searches for a given element in a sorted (Decreaing order) array using the
//                          Binary Search algorithm.
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchDec(
                                        T s_data
                                    )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == s_data)
        {
            bFlag = true;
            break;
        }
        else if(s_data > Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data < Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchEfficientInc()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   14/10/2025
//
//  Description         :   Efficiently searches for a given element in a sorted (increasing order) array
//                          using the Binary Search algorithm. Uses an mid-point calculation to
//                          avoid overflow and reduces the search .
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchEfficientInc(
                                                T s_data
                                            )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted == false)       // New
    {
        cout<<"[INFO] Data is s_datat sorted : Using Linear Search Algorithm\n";
        
        return LinearSearch(s_data);            // IMP Change
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == s_data || Arr[iStart] == s_data || Arr[iEnd] == s_data))         // Change
        {
            bFlag = true;
            break;
        }
        else if(s_data < Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data > Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchEfficientDec()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   14/10/2025
//
//  Description         :   Efficiently searches for a given element in a sorted (Decreasing order) array
//                          using the Binary Search algorithm. Uses an mid-point calculation to
//                          avoid overflow and reduces the search .
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchEfficientDec(
                                                T s_data
                                            )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == s_data || Arr[iStart] == s_data || Arr[iEnd] == s_data))         // Change
        {
            bFlag = true;
            break;
        }
        else if(s_data > Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data < Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CheckSortedInc()
//  Function Date       :   14/10/2025
//  Function Author     :   Omkar Mahadev Bhargude
//  Parameters          :   NONE
//  Description         :   Checks if array is sorted in Increasing order
//  Returns             :   bool
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::CheckSortedInc()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] < Arr[i - 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CheckSortedDec()
//  Function Date       :   14/10/2025
//  Function Author     :   Omkar Mahadev Bhargude
//  Parameters          :   NONE
//  Description         :   Checks if array is sorted in Decreasing order
//  Returns             :   bool
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::CheckSortedDec()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] < Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    END OF SEARCHING 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      SORTING ALGORITHMS :-
//
//////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class           :   Sorting
//  Description     :   Generic implemention of Searching algorithms.
//  Author          :   Omkar Mahadev Bhargude
//  Date            :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Sorting
{
    public:

        int *Arr;
        int iSize;
        bool Sorted;

        Sorting(
                    int A                           // Parametrised constructor
                );
    
        ~Sorting();                                 // Destructor

        void AcceptElement();

        void DisplayElement();

        
        BOOL BubbleSort();

        BOOL BubbleSortEfficient();

        BOOL InsertionSort();

        BOOL SelectionSort();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Sorting ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is parametrised constructor of class Sorting
//  Input Parameter      :   int
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Sorting<T>::Sorting(
                        int A
                    )
{
    this->iSize = A;
    this->Arr = new int[iSize];
    this->Sorted = true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   ~Sorting ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is destructor of class Sorting
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Sorting<T>::~Sorting()
{
    delete []Arr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Accpet()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//
//  Description          :   This function accpets input from user and store it in array
//
//  Input Parameter      :   [T] generic type
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Sorting<T>::AcceptElement()
{
    int i = 0;

    cout<<"Enter "<<iSize<<" elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))
        {
            if(Arr[i] < Arr[i - 1])
            {
                Sorted = false;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Display()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//
//  Description          :   This function displays the array
//
//  Input Parameter      :   NONE
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Sorting<T>::DisplayElement()
{
    int i = 0;

    cout<<"Elements from array are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BubbleSort()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Sorts an array of elements in ascending order using the Bubble Sort algorithm by
//                          repeatedly swapping adjacent elements if they are in the wrong order.
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;

    // Filter
    if(Sorted == true)
    {
        return TRUE;
    }

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"[INFO] Data after pass : "<<i + 1<<"\n";
        DisplayElement();
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BubbleSortEfficient()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   sorts an array in ascending order using an optimized Bubble Sort algorithm that stops
//                          early if no swaps are made in a pass, improving efficiency for nearly sorted array
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::BubbleSortEfficient()
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = false;

    // Filter
    if(Sorted == true)
    {
        return TRUE;
    }

    for(i = 0; (i < iSize && bFlag == true); i++)
    {
        for(j = 0; j < iSize -1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = false;
            }
        }

        cout<<"[INFO] Data after pass : "<<i + 1<<"\n";
        DisplayElement();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   SelectionSort()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   sorts an array in ascending order by repeatedly selecting the minimum element from 
//                          the unsorted portion and placing it at its correct position
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0; i < iSize - 1; i++)
    {   
        min_index = i;
        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }

        }
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   InsertionSort()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Sorts an array in ascending order by repeatedly picking the next element and 
//                          inserting it into its correct position in the already sorted portion of the array.
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1, selected = Arr[i]; (j >= 0 && Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = selected;
    }

    return TRUE;
}

int main()
{
    DoublyLL<int> * sobj = new DoublyLL<int>();
    int iRet = 0;

    sobj->InsertAtFirst(51);
    sobj->InsertAtLast(21);
    sobj->InsertAtPosition(11,3);

    sobj->DisplayGenList();

    iRet = sobj->CountNodes();
    cout<<iRet<<"\n";

    return 0;
}