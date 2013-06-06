#include "Vector.h"
#include <iostream>

std::ostream& operator<< (std::ostream &out, Math::Vector &right){
	
	for (unsigned int i = 0; i < right.getNumElements(); i++) out << (float) right[i] << std::endl;
}
inline Math::Vector operator + (const Math::Vector& left, const Math::Vector& right);
inline Math::Vector operator - (const Math::Vector& left, const Math::Vector& right);
inline Math::Vector operator * (const Math::Element left, const Math::Vector& right);
inline Math::Vector operator * (const Math::Vector& left, const Math::Element right);
inline Math::Vector operator * (const Math::Vector& left, const Math::Vector& right);



int main()
{
	Math::Vector a(5, 0.5f);

	// prefix sum
	for(unsigned int i=1; i<a.getNumElements(); ++i)
		a[i] += a[i-1];
	std::cout << "a: " << a << std::endl;

	// do some simple math
	Math::Vector b(6, 10.0f);
	std::cout << "b: " << b << std::endl;

	Math::Vector c = a + b;
	std::cout << "c = a + b: " << c << std::endl;

	Math::Vector d = a - b;
	std::cout << "d = a - b: " << d << std::endl;

	Math::Vector e = a * 10;
	std::cout << "e = a * 10: " << e << std::endl;

	Math::Vector f = 10 * a;
	std::cout << "f = 10 * a: " << f << std::endl;
}
