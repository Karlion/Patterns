#include"../Task 1 (SortPack)/SortPack.h"
#include<vector>
using namespace std;
int main()
{
	int n, count = 0;
	cout << "Enter the number of elements: " << endl;
	cin >> n;
	ArrayOfInt a(n);
	SortPack pb;
	a.fill();
	pb.attach(a);
	cout << "Your sequence:";
	pb.show();
	cout << "                    Bubble sort:" << endl;
	pb.bubble();
	pb.show();
	cout << "                    Insert sort:" << endl;
	a.fill();
	pb.attach(a);
	pb.insert();
	pb.show();
	cout << "                    Select sort:" << endl;
	a.fill();
	pb.attach(a);
	pb.select();
	pb.show();
	cout << "                    Shell sort:" << endl;
	a.fill();
	pb.attach(a);
	pb.shell();
	pb.show();
	cout << "                    Quick sort:" << endl;
	a.fill();
	pb.attach(a);
	pb.quick();
	cout << "counter=" << count << endl;
	pb.show();
	system("pause");
	return 0;
}