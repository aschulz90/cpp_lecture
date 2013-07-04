#pragma once

#include "collection.hpp"

namespace Collections
{
	// TODO: Dynamical template array class: ArrayList
	//  - implement interface
	//  - reserve
	//  - constructor
	//	- constructor from other collection
	//	- operator[]
	template<typename T> class ArrayList: public ICollection<T>
	{
	public:
		// TODO: constructors

		virtual ~ArrayList()
		{
			// TODO
		}

		void resize( unsigned int numInstances )
		{
			// TODO
		}

		virtual void insert( const T& newElement ) override
		{
			// TODO
		}

		// TODO: Operator []

		class Iterator: public ICollection<T>::IIterator
		{
		public:
			Iterator( T* first, int numElements ) : 
				m_array( numElements ? first : nullptr ), m_remaining( numElements )		{}

			virtual T* next() override
			{
				if( m_remaining > 1 )
				{
					--m_remaining;
					return ++m_array;
				}
				m_remaining = 0;
				m_array = nullptr;
				return nullptr;
			}

			/// \brief Access the current element without changing the iterator
			///
			virtual T* current() const override
			{
				return m_array;
			}

			virtual ~Iterator() override	{}
		private:
			T* m_array;
			int m_remaining;
		};

		virtual std::shared_ptr<typename ICollection<T>::IIterator> getIterator() const override
		{
			// TODO: use std::make_shared and return an Iterator
		}

	private:

	};
};