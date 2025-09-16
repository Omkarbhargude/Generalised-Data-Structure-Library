#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic Singly Circuler Linked List 
//
//////////////////////////////////////////////////////////////////////////////////////////////
 
#define TRUE 1
#define FALSE 0

typedef int     BOOL;
//
//  This is generic singly circuler linked list of type T
//
template<class T>
struct GEN_SINGLYCLL
{
    T Data;                                 // Generic data stored in node
    struct GEN_SINGLYCLL<T> *next;         // Pointer to next node 
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
class SinglyCLL
{
    public:
        struct GEN_SINGLYCLL<T> *pHead;       // Pointing to first node in List
        struct GEN_SINGLYCLL<T> *pTail;
        int iCount;

        SinglyCLL();

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
    this->pHead = NULL;
    this->pTail = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Display_LIST()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function displays all the elements from singly circular list
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::Display_LIST()
{
    struct GEN_SINGLYCLL<T> *tempNode = NULL;

    if(pHead == NULL)
    {
        cout<<"[WARN] Cannot Display : List is empty\n";
        return;
    }

    tempNode = pHead;

    do
    {
        cout<<tempNode->Data<<" -> ";

        tempNode = tempNode -> next;

    }while(tempNode != pHead);

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Count_Nodes
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//  Description          :   This function returns the count of nodes present in circular list
//  Input Parameter      :   NONE
//  Returns              :   Numeric Value (integer) to the caller
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::Count_Nodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Insert_At_GenList_First ()
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
BOOL SinglyCLL<T>::Insert_At_GenList_First(
                                                        T no
                                                )
{
    struct GEN_SINGLYCLL<T> *newn = NULL;          // New node to be insert

    newn = new GEN_SINGLYCLL<T>();
    newn->Data = no;
    newn->next = NULL;

    // If this linked list is empty
    if(pHead == NULL && pTail == NULL)
    {
        pHead = newn;
        pTail = newn;
    }
    else
    {
        newn->next = pHead;
        pHead = newn;
    }

    pTail -> next = pHead;
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Insert_At_GenList_Last ()
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
BOOL SinglyCLL<T>::Insert_At_GenList_Last(
                                                    T no
                                                )
{
    struct GEN_SINGLYCLL<T> * tempNode = NULL;
    struct GEN_SINGLYCLL<T> * newn = NULL;

    newn = new GEN_SINGLYCLL<T>();
    newn->Data = no;
    newn->next = NULL;

    if(pHead == NULL && pTail == NULL)
    {
        pHead = newn;
        pTail = newn;
    }
    else
    {
        pTail -> next = newn;

        pTail = newn;
    }

    pTail -> next = pHead;
    iCount++;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Delete_At_GenList_First ()
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
BOOL SinglyCLL<T>::Delete_At_GenList_First()
{

    if(pHead == NULL)
    {
        return FALSE;
    }
    else if(pHead == pTail)
    {
        delete pHead;
        pHead = NULL;
        pTail = NULL;
    }
    else
    {

        pHead = pHead->next;

        delete pTail -> next;
    }

    iCount--;
    pTail ->next = pHead;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Delete_At_GenList_Last ()
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
BOOL SinglyCLL<T>::Delete_At_GenList_Last()
{
    struct GEN_SINGLYCLL<T> *tempNode = NULL;

    if(pHead == NULL)
    {
        return FALSE;
    }
    else if(pHead == pTail)
    {
        delete pHead;

        pHead = NULL;
        pTail = NULL;
    }
    else
    {
        tempNode = pHead;

        while(tempNode -> next -> next != pHead)
        {
            tempNode = tempNode->next;
        }

        pTail = tempNode;
        delete tempNode->next;
    }

    iCount--;
    pTail -> next = pHead;
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Insert_At_Position_GenList ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This Function inserts the given node at given position in 
//                           singly circular Linked list 
//
//  Input Parameter      :   [T] Generic Data, [INT] Position
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::Insert_At_Position_GenList(
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
        Insert_At_GENLIST_First(no);
    }
    else if(pos == iCount+1)
    {
        Insert_At_GENLIST_Last(no);
    }
    else
    {
        newn = new GEN_SINGLYCLL<T>();
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
BOOL SinglyCLL<T>::Delete_At_Position_GenList(
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
BOOL SinglyCLL<T>::Search_From_GenList(
                                                T s_data
                                            )
{
    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    if(pHead == NULL && pTail == NULL)
    {
        cout<<"[WARN] Cannot search: list is empty\n";
        return FALSE;
    }
    
    if((pHead->Data == s_data) || (pTail->Data == s_data))
    {
        return TRUE;
    }

    tempNode = pHead;

    do
    {
        if(tempNode->Data == s_data)
        {
            return TRUE;
        }

        tempNode = tempNode->next;
    }while(tempNode != pHead);

        return FALSE;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Search_First_Ouccrence ()
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
int SinglyCLL<T>::Search_First_Ouccrence(
                                                    T s_data
                                                )
{
    int iPos = 0;

    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    tempNode = pHead;

    do
    {
        iPos++;

        if(tempNode -> Data == s_data)
        {
            return iPos;
        }

        tempNode = tempNode->next;
    }while(tempNode != pHead);

    return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Search_Last_Ouccrence ()
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
int SinglyCLL<T>::Search_Last_Ouccrence(
                                                    T s_data
                                                )
{
    int iPos = 0;
    int iOucc = 0;

    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    tempNode = pHead;

    do
    {
        iPos++;

        if(tempNode->Data == s_data)
        {
            iOucc = iPos;
        }

        tempNode = tempNode->next;
    }while(tempNode != pHead);

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
int SinglyCLL<T>::Search_All_Ouccrence(
                                                    T s_data
                                                )
{
    int iCnt = 0;

    struct GEN_SINGLYCLL<T> * tempNode = NULL;

    if(pHead == NULL)
    {
        cout<<"[WARN] Cannot Search : List is empty\n";
        return FALSE;
    }

    tempNode = pHead;

    do
    {
        if(tempNode -> Data == s_data)
        {
            iCnt++;
        }

        tempNode = tempNode -> next;
    }while(tempNode != pHead);

    return iCnt;
}
