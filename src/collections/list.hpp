#pragma once

// QUESTION: can the following line be replaced with class
// ICollection predeclaration?
#include "collection.hpp"

namespace Collections
{

	class SingleLinkedList : public Collections::ICollection{

	public:

		SingleLinkedList();
		~SingleLinkedList();
		void insert( const IElement& newElement );
		IIterator* getIterator();

	private:



	};
}