#include <iostream>
using namespace std;

class Triangle;
class Square;

class Visitor
{
public:
	virtual double getPerimetr(Triangle *tr) = 0;
	virtual double getPerimetr(Square *sq) = 0;
};

class Triangle
{
	double a, b, c;
public:
	Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
	double getA()
	{
		return a;
	}
	double getB()
	{
		return b;
	}
	double getC()
	{
		return c;
	}
	double accept(Visitor *vis)
	{
		return vis->getPerimetr(this);
	}
};

class Square
{
	double  side;
public:
	Square(double _side) : side(_side) {}
	double getSide()
	{
		return side;
	}
	double accept(Visitor *vis)
	{
		return vis->getPerimetr(this);
	}
};

class ConcreteVisitor : public Visitor
{
public:
	virtual double getPerimetr(Triangle *tr)
	{
		double a, b, c;
		a = tr->getA();
		b = tr->getB();
		c = tr->getC();
		return a + b + c;
	}
	virtual double getPerimetr(Square *sq)
	{
		double side = sq->getSide();
		return 4 * side;
	}
};