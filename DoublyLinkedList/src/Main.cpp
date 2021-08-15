/**
* @file Main.cpp
* @description Dosya Okuma işlemlerinin bulunduğu ve okunan değerlerin oluşturulan ikili bağlı listelere atandığı bölüm.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 14.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/

#include "Compare.hpp"
#include "DoublyLinkedList.hpp"
#include <sstream>
#include <string>
#include <fstream>

int main()
{
    DoublyLinkedList* sayi1=new DoublyLinkedList();
    DoublyLinkedList* sayi2=new DoublyLinkedList();

    

    ifstream myFileStream("./doc/sayilar.txt");
    if (!myFileStream.is_open())
    {
        cout<<"Failed To open file"<<endl;
        return 0;
    }
    
    string temp,temp2,firstList,secondList;
    int firstListint,secondListint;
    string myString,line;

    while (getline(myFileStream, line))
    {
        stringstream ss(line);
        getline(ss,temp,'#');
        getline(ss,temp2,'#');
        if (temp2!="")
        {
            secondList=temp2;
            firstList=temp;
            temp2="";
        }
    }
    
    int sizeofList=firstList.length();
    
    string stringList1[sizeofList];
    string stringList2[sizeofList];

    for (size_t i = 0,j=0; i < sizeofList/3; i++,j+=3)
    {
        stringList1[i]=firstList.substr(j,3);
        if (stringList1[i][0]=='0')
        {
            stringList1[i][0]='1';
        }
        
        stringList2[i]=secondList.substr(j,3);
        if (stringList2[i][0]=='0')
        {
            stringList2[i][0]='1';
        }
    }
    
    int sizeofIntList=sizeofList/3;
    int list1[sizeofIntList];
    int list2[sizeofIntList];

    for (size_t i = 0; i < sizeofIntList; i++)
    {
        list1[i]=stoi(stringList1[i]);
        list2[i]=stoi(stringList2[i]);
        sayi1->Add(list1[i]);
        sayi2->Add(list2[i]);
    }
 

    cout<<endl<<"Sayi 1: "<<*sayi1<<endl;
    cout<<"Sayi 2: "<<*sayi2<<endl;
    
    cout<<endl<<endl<<"---------------------Karsilastirmadan Sonra---------------------"<<endl<<endl<<endl;

    Compare(sayi1,sayi2);

    cout<<"Sayi 1: "<<*sayi1<<endl;
    cout<<"Sayi 2: "<<*sayi2<<endl;

    cout<<endl<<endl;
    
    delete sayi1;
    delete sayi2;
    return 0;
}