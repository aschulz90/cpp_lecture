#include <string>
#include "bitarray.hpp"
#include <iostream>

void outputHelper( const BiA::BitArray& array, bool binaryRepresentation );

BiA::BitArray BiA::create( int numElements )
{
	// 1 - size variable
	// numElements/32 - number of uint32_t for all bits rounded down
	// round up:  (numElements+31)/32
	int numInts = 1 + ((numElements+31)/32);
	BitArray theNewOne = new uint32_t[numInts];
	theNewOne[0] = numElements;
	memset( theNewOne+1, 0, numInts*4-4 );
	return theNewOne;
}

// TODO: implement all the other functions.
//	- start with getSize and get -> debugging easier

int BiA::getSize( const BitArray& array ){
	return array[0];
}

bool BiA::get( const BitArray& array, int index ){
	return (array[1+index/32] & ( 1 << index%32)) >> index%32;
}

void BiA::set( BitArray& array, int index, bool value ){
	index %= getSize(array);
	if (value) array[1+index/32] |= 1<<(index%32); else	array[1+index/32] &= !(1<<(index%32));
}

void BiA::toggle( BitArray& array, int index ){
	if (get(array, index)) set(array, index, true); else set(array, index, true);
}

BiA::BitArray BiA::concatenate( const BitArray& array1, const BitArray& array2 ){
	BitArray temp = create(getSize(array1) + getSize(array2));
	temp[0] = getSize(array1) + getSize(array2);
	for( int i=0; i<getSize(array1); i++ ){
		set(temp, i, get(array1, i));
		//std::cout << get(array1, i) << '\n';
	}
	int n = 0;
	for( int i=getSize(array1); i<getSize(temp); i++ ){
		set(temp, i, get(array2, n++));
	}
	return temp;
}

void BiA::or( BitArray& array1, const BitArray& array2 ){
	if (getSize(array1) >= getSize(array2)){
		for( int i=0; i<getSize(array1); i++ ){
			if (i < getSize(array2))
				set(array1, i, (get(array1, i) | get(array2, i))); else
				set(array1, i, (get(array1, i) | false));
		}
	} else {
		int oldSize = getSize(array1);
		array1 = (uint32_t*) malloc(((getSize(array2)+31)/32) + 1);
		memset(array1 + oldSize, 0, getSize(array2) - oldSize);
		for( int i=0; i<getSize(array1); i++ ){
			set(array1, i, (get(array1, i) | get(array2, i)));
		}
	}
}