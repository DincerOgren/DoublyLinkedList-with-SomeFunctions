/**
* @file Iterator.cpp
* @description 'Iterator' sınıfının fonksiyonlarının gövdelerini tutuyor. Nodelar arasında gezinmeyi, 
	node'un datasını döndürmeyi, node'un boş olup olmadığı gibi işlemlerin kontrolünü sağlıyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 12.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/

#include "Iterator.hpp"

    Iterator::Iterator(){
		current=NULL;
	}
	Iterator::Iterator(Node* node){
		current=node;
	}
	bool Iterator::IsEndNode(){
		return current == NULL;
	}
	void Iterator::StepNext(){
		if(!IsEndNode())
			current=current->next;
	}
	void Iterator::StepBack(){
		if(!IsEndNode())
			current=current->prev;
	}
	const int& Iterator::GetCurrentData()const{
		return current->data;
	}