#include "Visitor.h"

void main()
{
	Visitor *vis = new ConcreteVisitor;
	Square *sq = new Square(10);
	Triangle *tr = new Triangle(3, 4, 5);
	cout << "Triagles perimetr: " << tr->accept(vis) << endl;
	cout << "Squares perimetr: " << sq->accept(vis) << endl;
	system("pause");
}