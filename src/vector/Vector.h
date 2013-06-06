#pragma once
#pragma once

#include <memory>

namespace Math
{
	typedef float Element;

	class Vector
	{
	public:
		/// Vector number-type.
		typedef float Element;
		
		/// Create empty from size, filled with a given value.
		/// \param size		vectors size
		/// \param value	value applied to all elements
		explicit Vector(unsigned int size, Element value = 0): m_size(size), m_elements(new Element[size]){
			for (unsigned int i = 0; i < size; i++){
				m_elements[i]=value;
			}
		}

		/// Copy constructor.
		Vector(const Vector& vector){
			*this = vector;
		}

		/// Destructor, releases allocated memory.
		~Vector(){
			for (unsigned int i = 0; i < m_size; i++){
				delete &m_elements[i];
			}
			delete &m_elements;
		}

		/// Returns number of elements
		unsigned int getNumElements() const { return m_size; }
		
		/// Destroys content of this instance and copies all data from the right one
		/// \param right	assigned Math::Vector
		/// \return Reference to this
		Vector& operator = (const Vector& right){
			for (unsigned int i = 0; i < m_size; i++){
				delete &m_elements[i];
			}
			m_elements.reset(new m_elements[right.getNumElements()]);
			for (unsigned int i = 0; i < right.getNumElements(); i++){
				m_elements[i] = right[i];
			}
			return *this;
		}

		/// Returns element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid 
		Element operator [] (unsigned int index) const{
			if(index < m_size) {
				return m_elements[index];
			} else {
				return m_elements[m_size-1];
			}
		}

		/// Returns reference to element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid
		Element& operator [] (unsigned int index){
			if(index < m_size) {
				return m_elements[index];
			} else {
				return m_elements[m_size-1];
			}
		}

		// TODO: Insert additional Operators (here or global where necessary)
		// -> Use const wherever possible and useful!
		// -> Where possible use methods in favor of global functions!
		//
		// Vector + Vector
		// Vector - Vector
		// Element * Vector
		// Vector * Element
		// Vector * Vector (scalar product, element wise multiplication, then sum)
		// std::ostream << Vector (output as formated text)

		
		

	private:
		/// intern element array
		std::unique_ptr<Element[]> m_elements;

		/// number of elements
		unsigned int m_size;
	};
}
