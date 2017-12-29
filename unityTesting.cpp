#include "unityTesting.hpp"
#include <cassert>
#include <iostream>
#include "vector3D.hpp"

void testOperatorAFF()
{
	Vector3D v1(2, 2, 5), v2(4, 4, 10), v3(4, 4, 10);
	assert((v1 = v2) == v3);
	std::cout << "Operator '=' OK" << std::endl;
}

void testOperatorEQ()
{
	Vector3D v1(2, 2, 5), v2(2, 2, 5);
	assert(v1 == v2);
	std::cout << "Operator '==' OK" << std::endl;
}

void testOperatorDIF()
{
	Vector3D v1(2, 2, 5), v2(4, 4, 10);
	assert(v1 != v2);
	std::cout << "Operator '!=' OK" << std::endl;
}

void testOperatorMULT()
{
	Vector3D v1(2, 2, 5), v2(4, 4, 10);
	assert((v1 * 2) == v2);
	assert((2 * v1) == v2);
	assert((v1 * v2) == Vector3D(8, 8, 50));
	std::cout << "Operator '*' OK" << std::endl;
}


void testOperatorDIV()
{
	Vector3D v1(2, 2, 5), v2(4, 4, 10);
	assert((2 / v1) == Vector3D(1, 1, 0.4));
	assert((v1 / 2) == Vector3D(1, 1, 2.5));
	assert((v1 / v2) == Vector3D(0.5, 0.5, 0.5));
	std::cout << "Operator '/' OK" << std::endl;	
}

void testOperatorPLUS()
{
	Vector3D v1(2, 2, 5), v2(4, 4, 10);
	assert((v1 + v2) == Vector3D(6, 6, 15));
	std::cout << "Operator '+' OK" << std::endl;
}

void testOperatorMINUS()
{
	Vector3D v1(2, 2, 5), v2(4, 4, 10);
	assert((v1 - v2) == Vector3D(-2, -2, -5));
	std::cout << "Operator '-' OK" << std::endl;
}

void testVectorNorm()
{
	Vector3D v(5, 5, 5);
	assert(v.getNorm() == sqrt(5*5*3));

	// assert(v.getNorm() == Vector3D())
}

