#pragma once
class Pair
{
	private:
	int num1, num2;
public:
	Pair();
	Pair(int num1, int num2);
	int get1();
	int get2();
	friend Pair operator+(const Pair& other1, const Pair& other2);
	friend Pair operator+(Pair& p, int otherNum);
	//added method to take into account an integer on the left and an operator on the right.
	friend Pair operator+(int otherNum, Pair& p);

};

