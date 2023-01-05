#include "CheckedArray.h"
template<class T>
CheckedArray<T>::CheckedArray() : size(10)
{
	p = new T[size];
	for (int i = 0; i < size; i++)
		p[i] = i * 5;
}

template<class T>
CheckedArray<T>::CheckedArray(int size)
{
	this->size = size;
	p = new T[size];
	for (int i = 0; i < size; i++)
		p[i] = (i + 1);

}

template<class T>
CheckedArray<T>::~CheckedArray()
{
	delete p;
}

template<class T>
T& CheckedArray<T>::operator[](int index) throw(ArrayOutOfRange)
{
	try
	{
		if (index >= size || index < 0)
			throw ArrayOutOfRange();
		else
			return p[index];
	}
	catch (ArrayOutOfRange &e)
	{
		cout << "Invalid index:" << index << ". ";
		cout << e.what() << endl;
	}
}

template<class T>
int CheckedArray<T>::length()
{
	return size;
}

template<class T>
void CheckedArray<T>::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}
