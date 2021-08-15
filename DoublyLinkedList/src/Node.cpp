/**
* @file Node.cpp
* @description 'Node' oluşturma sınıfının fonksyionlarının gövdelerini tutuyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 12.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/

#include "Node.hpp"

    Node::Node()
    {
        data=int();
        next=NULL;
        prev=NULL;
    }

    Node::Node(const int& data, Node* next, Node* prev = NULL){
			this->data=data;
			this->next=next;
			this->prev=prev;
	}