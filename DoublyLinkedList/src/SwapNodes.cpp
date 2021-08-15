/** 
* @file SwapNodes.cpp
* @description İki tane 'İkili Bağlı Liste' alıp, listeler içindeki alakalı 2 node'un karşılıklı değişmesini sağlıyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 10.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/

#include "SwapNodes.hpp"

void SwapNodes(DoublyLinkedList*& liste1, DoublyLinkedList*& liste2,int index)
    {
        Node* l1node=liste1->ReturnNodeInIndex(index);
        Node* l2node=liste2->ReturnNodeInIndex(index);
        
        Node* tempNext;
        Node* tempPrev;

        tempNext=l1node->next;
        tempPrev=l1node->prev;


        if (index==0)
        {
            Node* head1=*liste1->ReturnHeadReference();
            Node* head2=*liste2->ReturnHeadReference();

            l1node->next=l2node->next;
            l1node->prev=l2node->prev;
            l2node->next->prev=l1node;
            head2->next=head1->next;
            l2node->next=tempNext;
            l2node->prev=tempPrev;
            tempNext->prev=l2node;
            head1->next=l2node;
        }
        else if (index==(liste1->Count()-1))
        {
            l1node->next=l2node->next;  
            l1node->prev=l2node->prev;
            l2node->prev->next=l1node;
            l2node->next=tempNext;
            l2node->prev=tempPrev;
            tempPrev->next=l2node;
        }
        else
        {
            l1node->next=l2node->next;  
            l1node->prev=l2node->prev;
            l2node->next->prev=l1node;
            l2node->prev->next=l1node;
            l2node->prev=tempPrev;
            l2node->next=tempNext;
            tempNext->prev=l2node;
            tempPrev->next=l2node;
        }
    }
