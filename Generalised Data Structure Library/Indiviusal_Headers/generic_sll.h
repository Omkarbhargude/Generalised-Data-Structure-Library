#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Singly Linear Linked List 
//
//////////////////////////////////////////////////////////////////////////////////////////////
 
#define TRUE 1
#define FALSE 0

typedef int     BOOL;
//
//  This is generic singly linked list of type T
//
template<class T>
struct GEN_SINGLYLIST
{
    T Data;                                 // Generic data stored in node
    struct GEN_SINGLYLIST<T> *next;         // Pointer to next node 
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   Singly_LinkedList
//  Description      :   This class contains generic implementation of Singly Linear LinkedList
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLinkedList
{
    public:
        struct GEN_SINGLYLIST<T> *pHead;        // Pointing to first node in List
        int iCount;

        SinglyLinkedList();

        void Display_LIST();

        int Count_Nodes();

        BOOL Insert_At_GenList_First(
                                        T no
                                );

        BOOL Insert_At_GenList_Last(
                                        T no
                                    );

        BOOL Delete_At_GenList_First();

        BOOL Delete_At_GenList_Last();

        BOOL Insert_At_Position_GenList(
                                            T no,
                                            int pos
                                        );

        BOOL Delete_At_Position_GenList(
                                            int pos
                                    );

        BOOL Search_From_GenList(
                                T data
                            );

        int Search_First_Ouccrence(
                                    T data
                                );

        int Search_Last_Ouccrence(
                                    T data
                                );

        int Search_All_Ouccrence(
                                    T data
                                );

        BOOL Reverse_GenList();
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
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->pHead = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Display_LIST()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function displays all the elements from Linked List
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLinkedList<T>::Display_LIST()
{
    struct GEN_SINGLYLIST<T> *tempNode = NULL;

    if(pHead == NULL)
    {
        cout<<"[WARN] Cannot Display : List is empty\n";
        return;
    }

    tempNode = pHead;

    while(tempNode != NULL)
    {
        cout<<tempNode->Data<<" -> ";

        tempNode = tempNode -> next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Count_Nodes
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function returns the count of nodes present in Linked list
//  Input Parameter      :   NONE
//  Returns              :   Numeric Value (integer) to the caller
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLinkedList<T>::Count_Nodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Insert_At_GenList_First ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in linked list at first position 
//
//  Input Parameter      :   [T] Generic Datatype
// 
//  Returns              :   BOOLEAN
//                           If the function succeeds it 
//                          
//                       
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyLinkedList<T>::Insert_At_GenList_First(
                                                        T no
                                                )
{
    struct GEN_SINGLYLIST<T> *newn = NULL;          // New node to be insert

    newn = new GEN_SINGLYLIST<T>();
    newn->Data = no;
    newn->next = NULL;

    // If this linked list is empty
    if(pHead == NULL)
    {
        pHead = newn;
    }
    else
    {
        newn->next = pHead;
        pHead = newn;
    }

    iCount++;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Insert_At_GenList_Last ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function Insert the node in linked list at Last position 
//
//  Input Parameter      :   [T] Generic Datatype 
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyLinkedList<T>::Insert_At_GenList_Last(
                                                    T no
                                                )
{
    struct GEN_SINGLYLIST<T> * tempNode = NULL;
    struct GEN_SINGLYLIST<T> * newn = NULL;

    newn = new GEN_SINGLYLIST<T>();
    newn->Data = no;
    newn->next = NULL;

    if(pHead == NULL)
    {
        pHead = newn;
    }
    else
    {
        tempNode = pHead;

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
//  Function Name        :   Delete_At_GenList_First ()
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
BOOL SinglyLinkedList<T>::Delete_At_GenList_First()
{
    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if(pHead == NULL)
    {
        return FALSE;
    }
    else if(pHead -> next == NULL)
    {
        delete pHead;
    }
    else
    {
        tempNode = pHead;

        pHead = pHead->next;

        delete tempNode;
    }

    iCount--;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Delete_At_GenList_Last ()
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
BOOL SinglyLinkedList<T>::Delete_At_GenList_Last()
{
    struct GEN_SINGLYLIST<T> *tempNode = NULL;

    if(pHead == NULL)
    {
        return FALSE;
    }
    else if(pHead -> next == NULL)
    {
        delete pHead;
    }
    else
    {
        tempNode = pHead;

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
//  Function Name        :   Insert_At_Position_GenList ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function inserts the given node at given position in 
//                           Linked list 
//
//  Input Parameter      :   [T] Generic Data, [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyLinkedList<T>::Insert_At_Position_GenList(
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
        Insert_At_GENLIST_First(no);
    }
    else if(pos == iCount+1)
    {
        Insert_At_GENLIST_Last(no);
    }
    else
    {
        newn = new GEN_SINGLYLIST<T>();
        newn->Data = no;
        newn->next = NULL;

        tempNode = pHead;

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
//  Function Name        :   Delete_At_Position_GenList ()
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
BOOL SinglyLinkedList<T>::Delete_At_Position_GenList(
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
        Delete_At_GenList_First();
    }
    else if(pos == iCount)
    {
        Delete_At_GenList_Last();
    }
    else
    {
        tempNode = pHead;

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
//  Function Name        :   Search_From_GenList ()
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
BOOL SinglyLinkedList<T>::Search_From_GenList(
                                                T s_data
                                            )
{
    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if(pHead == NULL)
    {
        cout<<"[WARN] Cannot search: list is empty\n";
        return FALSE;
    }

    tempNode = pHead;

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
//  Function Name        :   Search_First_Ouccrence ()
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
int SinglyLinkedList<T>::Search_First_Ouccrence(
                                                    T s_data
                                                )
{
    int iPos = 0;

    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    tempNode = pHead;

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
//  Function Name        :   Search_Last_Ouccrence ()
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
int SinglyLinkedList<T>::Search_Last_Ouccrence(
                                                    T s_data
                                                )
{
    int iPos = 0;
    int iOucc = 0;

    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    tempNode = pHead;

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
//  Function Name        :   Search_All_Ouccrence ()
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
int SinglyLinkedList<T>::Search_All_Ouccrence(
                                                    T s_data
                                                )
{
    int iCnt = 0;

    struct GEN_SINGLYLIST<T> * tempNode = NULL;

    if(pHead == NULL)
    {
        cout<<"[WARN] Cannot Search : List is empty\n";
        return FALSE;
    }

    tempNode = pHead;

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
