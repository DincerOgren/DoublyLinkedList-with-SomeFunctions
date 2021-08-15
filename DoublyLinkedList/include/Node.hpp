/**
* @file Node.hpp
* @description 'Node' oluşturma sınıfının değişkenleri ve fonksyionlarının başlığını tutuyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 12.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node();
		Node(const int&, Node*, Node*);
};
#endif