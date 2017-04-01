#include"../Task 17 (Proxy)/Proxy.h"


void main()
{
	ISortings *sort = new Sortings;
	ISortings *proxy = new ProxySortings(sort);
	vector<double> mas1, mas2, mas3;
	mas1.assign(10, 0);
	mas2.assign(10, 0);
	mas3.assign(10, 0);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		mas1[i] = rand() % 100;
		mas2[i] = rand() % 100;
		mas3[i] = rand() % 100;
	}
	show(mas1);
	show(mas2);
	show(mas3);
	mas1 = proxy->bubble(mas1);
	mas2 = proxy->selection(mas2);
	mas3 = proxy->shaker(mas3);
	cout << "Bubble: ";
	show(mas1);
	cout << "Selection: ";
	show(mas2);
	cout << "Shaker: ";
	show(mas3);
	system("pause");
}