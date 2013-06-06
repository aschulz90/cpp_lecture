#include "Vector.h"

namespace Math
{
	inline Vector operator + (const Vector& left, const Vector& right){
		int i;
		Vector tmp(0, 0);
		if(left.getNumElements > right.getNumElements){
			tmp = left;
			for (i = 0; i < right.getNumElements; i++){
				tmp[i] += right[i];
			}
			i++;
			while (i < left.getNumElements) tmp[i++] = left[i];
		} else {
			tmp = right;
			for (i = 0; i < left.getNumElements; i++){
				tmp[i] += left[i];
			}
			i++;
			while (i < right.getNumElements) tmp[i++] = right[i];
		}
		return tmp;
	}

	inline Vector operator - (const Vector& left, const Vector& right){
		int i;
		Vector tmp(0, 0);
		if(left.getNumElements > right.getNumElements){
			tmp = left;
			for (i = 0; i < right.getNumElements; i++){
				tmp[i] -= right[i];
			}
			i++;
			while (i < left.getNumElements) tmp[i++] = left[i];
		} else {
			tmp = right;
			for (i = 0; i < left.getNumElements; i++){
				tmp[i] -= left[i];
			}
			i++;
			while (i < right.getNumElements) tmp[i++] = right[i];
		}
		return tmp;
	}

	inline Vector operator * (Element left, const Vector& right){
		Vector tmp(right);
		for (int i = 0; i < right.getNumElements; i++){
			tmp[i] = tmp[i] * left;
		}
		return tmp;
	}
	
	inline Vector operator * (Vector& left, Element right){
		return right * left;
	}
}