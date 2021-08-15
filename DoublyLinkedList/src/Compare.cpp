/**
* @file Compare.cpp
* @description 'Compare' fonksiyonunun gövdesini tutuyor.Parametre olarak verilen iki listenin elemanlarını sırasıyla karşılaştırıp,
     büyük ,küçük veya eşit olma durumuna göre farklı işlemler yapıyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 10.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/


#include "Compare.hpp"
    
    
    void Compare(DoublyLinkedList*& liste1, DoublyLinkedList*& liste2)
    {
        for (int i = 0; i < liste1->Count(); i++)
        {
                
            if (liste1->ReturnIndex(i)    >   liste2->ReturnIndex(i))
            {
               
                liste1->ReverseList(liste1->ReturnHeadReference());
               
            }
            

            else if (liste1->ReturnIndex(i) == liste2->ReturnIndex(i))
            {
                liste2->ReverseList(liste2->ReturnHeadReference());
            }
            

            else if (liste1->ReturnIndex(i)    <   liste2->ReturnIndex(i))
            {
                SwapNodes(liste1,liste2,i);
            }
        }

    }