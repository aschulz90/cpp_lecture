#include "arraylist.hpp"

// TODO

namespace Collections
{
	ArrayList::ArrayList(int size)
	{
		listSize = size;
		m_numElements = size;
		list = (IElement*) malloc(size+1);
	}

	ArrayList::ArrayList(ArrayList a)
	{
		
	}

	ArrayList::~ArrayList()
	{
		delete list;
	}

	IElement* ArrayList::get(unsigned int index) const{
		return (IElement*) list[index];
	}

	void ArrayList::reserve(unsigned int reservation){
		if (reservation > listSize) {
			list = (IElement*) malloc(reservation);
			listSize = reservation;
		}
	}

	void ArrayList::insert(const IElement& newElement){
		if (m_numElements == listSize){
			list = (IElement*) malloc(m_numElements+1);
			listSize++;
			list[++m_numElements-1] = newElement;
		} else {
			list[++m_numElements-1] = newElement;
		}
	}

	void ArrayList::set( const IElement& newElement, unsigned int index )
	{
		if (index < m_numElements) list[index] = newElement;
	}

	IElement* SingleLinkedList::ListIterator::next()
	{
		if( m_current )
		{
			m_current = m_current->next;
			return m_current ? m_current->data : nullptr;
		}
		return nullptr;
	}

	IElement* SingleLinkedList::ListIterator::current() const
	{
		return m_current ? m_current->data : nullptr;
	}

	// Creates a one-time iterator.
	ICollection::IIterator* SingleLinkedList::getIterator() const
	{
		return new ListIterator( m_first );
	}

};