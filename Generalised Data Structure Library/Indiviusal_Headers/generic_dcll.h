#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Doubly Circuler Linked List 
//
//////////////////////////////////////////////////////////////////////////////////////////////
 
#define TRUE 1
#define FALSE 0

typedef int     BOOL;
//
//  This is generic doubly circuler linked list of type T
//
template<class T>
struct GEN_DOUBLYCLL
{
    T Data;                                 // Generic data stored in node
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
        cout<<tempNode->Data<<" <-> ";

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
//  Input Parameter      :   [T] Generic Datatype
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
    newn->Data = no;
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
//  Input Parameter      :   [T] Generic Datatype 
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
    newn->Data = no;
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
//  Input Parameter      :   [T] Generic Data, [INT] Position
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
        newn->Data = no;
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
    
    if((p_Head->Data == s_data) || (p_Tail->Data == s_data))
    {
        return TRUE;
    }

    tempNode = p_Head;
    itempNode = p_Tail;

    do
    {
        if((tempNode->Data == s_data) || (itempNode->Data == s_data))
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

        if(tempNode -> Data == s_data)
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

        if(tempNode->Data == s_data)
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
        if((tempNode -> Data == s_data))
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }while(tempNode != p_Head);

    return iCnt;
}
