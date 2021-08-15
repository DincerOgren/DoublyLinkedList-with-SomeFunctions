/** 
* @file Iterator.hpp
* @description 'Iterator' oluşturma sınıfnın değişkenleri ve fonksyionlarının başlığını tutuyor.
* @course 1-B 1.Öğretim
* @assignment 1.Ödev
* @date 12.08.2021
* @author Emre Dinçer Öğren , emre.ogren@ogr.sakarya.edu.tr, B191210036
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <Node.hpp>


class Iterator{
	public:
		Node* current;
		Iterator();
		Iterator(Node*);
		bool IsEndNode();
		void StepNext();
		void StepBack();
		const int& GetCurrentData()const;
};
#endif