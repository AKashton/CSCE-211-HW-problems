#pragma once
using namespace std;
class ArrayOutOfRange
{
public:
	const char* what() const throw()
	{
		return "index out of bounds";
	}

};

