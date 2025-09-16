#include<iostream>
#include<string.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Doubly Linear Linked List 
//
//////////////////////////////////////////////////////////////////////////////////////////////
 
#define TRUE 1
#define FALSE 0

typedef int     BOOL;
//
//  This is generic doubly linear linked list of type T
//
template<class T>
struct GEN_DOUBLYLIST
{
    T Data;                                 // Generic data stored in node
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
        cout<<tempNode->Data<<" <-> ";

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
//  Input Parameter      :   [T] Generic Datatype
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
    newn->Data = no;
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
//  Input Parameter      :   [T] Generic Datatype 
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
    newn->Data = no;
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

//////////////////////////////////////////////////////////////////////////////////////////////
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
//  Input Parameter      :   [T] Generic Data, [INT] Position
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
        newn->Data = no;
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
        if(tempNode->Data == s_data)
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

        if(tempNode -> Data == s_data)
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

        if(tempNode->Data == s_data)
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
        if(tempNode -> Data == s_data)
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }

    return iCnt;
}


