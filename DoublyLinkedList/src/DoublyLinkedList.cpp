/**
* @file DoublyLinkedList.cpp
* @description 'İkili Bağıl Liste' oluşturma sınıfnın fonksyionlarının gövdesini tutuyor. 'İkili Bağlı Liste' oluşturmak için
		gerekli fonksiyonları içeriyor. Verilen indexe göre indexteki node'u veya node'un datasını döndüren, listeye eleman ekleyen,
		listeden eleman silen, listeyi ters çeviren fonksiyonları içeriyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 11.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/


#include "DoublyLinkedList.hpp"


    Iterator DoublyLinkedList::IterateFromPrevIndex(int index) const{
			if(!(index < 0 || index > Count())){
				int i=0;
				Iterator  itr(head);
				while(!itr.IsEndNode() && index != i++)
					itr.StepNext();
				return itr;
			}
			return NULL;
		}

    Iterator DoublyLinkedList::IterateFromFirstNode() const{
			if(!IsEmpty())
				return Iterator(head->next);
			return NULL;
		}

    DoublyLinkedList::DoublyLinkedList()
		{
			head=new Node();
			size=0;
		}

    Node**  DoublyLinkedList::ReturnHeadReference()//Listenin Head elemanını döndürür.
		{
			return &head;
		}
        
    bool DoublyLinkedList::IsEmpty() const{//Listenin boş olup olmadığını döndürür.
			return head->next == NULL;
		}

	int DoublyLinkedList::Count() const{//Listenin boyutunu döndürür.
			return size;
		}




	void DoublyLinkedList::Add(const int& obj){//Listenin sonuna eleman ekler
			Insert(Count(), obj);
		}
	const int& DoublyLinkedList::ReturnIndex(int index)//Verilen indexe göre indexteki Node'un datasını döndürür.
	{
		if (!IsEmpty())
		{
			Iterator itr = IterateFromPrevIndex(index+1);
			return itr.GetCurrentData();
		}
		return 0;
	}
	void DoublyLinkedList::Insert(int index, const int& obj){//Verilen indexe göre elemanı indexteki sıraya ekler.
		Iterator itr;
		itr = IterateFromPrevIndex(index);
		Node* newNext = itr.current->next;
		itr.current->next = new Node(obj, newNext, itr.current);
		if(newNext != NULL) 
			newNext->prev = itr.current->next;
		size++;
	}
		

	Node* DoublyLinkedList::ReturnNodeInIndex(int index){//Verilen indexe göre indexteki Node'un kendisini döndürür.
		if (!IsEmpty())
		{
			Iterator itr= IterateFromPrevIndex(index+1);
				return itr.current;
		}
		return NULL;
	}

	void DoublyLinkedList::ReverseList(Node **headRef)//Listeyi ters çevirir.
	{
		Node* ptr1=*headRef;
		Node* ptr2=ptr1->next;
		ptr2->prev=NULL;
		
		ptr1->next=NULL;
		ptr1->prev=NULL;
		
		Node* temp=NULL;
		while (ptr2 != NULL)
		{
			temp=ptr2->prev;
			ptr2->prev=ptr2->next;
			ptr2->next=temp;
			ptr2=ptr2->prev;
		}
	
		if (temp!=NULL)
		{
			Node* ptr3=*headRef;
			ptr3->next=temp->prev;
		}
			
	}
		
	
	void DoublyLinkedList::RemoveAt(int index){//Verilen indexteki elemanı siler.
		Iterator itr;
		itr = IterateFromPrevIndex(index);
		if(itr.current->next != NULL)
		{
			Node* oldNode = itr.current->next;
			itr.current->next=itr.current->next->next;
			if(oldNode->next != NULL) 
			oldNode->next->prev = oldNode->prev;
			delete oldNode;
			size--;
		}
	}
	ostream& operator<<(ostream& screen, DoublyLinkedList& list){//Listeyi ekrana yazdırır.
		if(list.IsEmpty())
			screen<<"Liste bos";
		else{
			for(Iterator itr = list.IterateFromFirstNode();!itr.IsEndNode();itr.StepNext())
				screen<<itr.GetCurrentData()<<"||";
		}
		return screen;
	}
	void DoublyLinkedList::Clear(){//Listenin içindeki elemanların hepsini siler.
		while(!IsEmpty()){
			RemoveAt(0);
		}
	}
	DoublyLinkedList::~DoublyLinkedList(){//Listeyi tamamen siler.
		Clear();
		delete head;
	}
    