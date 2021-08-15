/**
* @file DoublyLinkedList.hpp
* @description 'İkili Bağıl Liste' oluşturma sınıfnın değişkenleri ve fonksyionlarının başlığını tutuyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 11.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/



#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include <Iterator.hpp>
using namespace std;

class DoublyLinkedList{
	private:
		Node* head;
		int size;
		Iterator IterateFromPrevIndex(int index) const;		
		Iterator IterateFromFirstNode() const;
	public:
		DoublyLinkedList();
		Node** ReturnHeadReference();
		bool IsEmpty() const;
		int Count() const;
		void Add(const int&);
		const int& ReturnIndex(int);
		void Insert(int , const int& );
		Node* ReturnNodeInIndex(int);
		void ReverseList(Node**);		
		void RemoveAt(int);
		friend ostream& operator<<(ostream& , DoublyLinkedList& );
		void Clear();
		~DoublyLinkedList();
};
#endif