#pragma once
#include <iostream>
#include "ArrayOutOfRange.cpp"
using namespace std;
template<class T>
class CheckedArray
{
public:
	CheckedArray();
	CheckedArray(int size);
	~CheckedArray();
	T& operator[](int index) throw (ArrayOutOfRange);
	int length();
	void show() const;
private:
	T* p;
	int size;
};

