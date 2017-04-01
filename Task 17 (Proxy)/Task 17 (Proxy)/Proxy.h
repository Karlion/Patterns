#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class ISortings
{
public:
	virtual vector<double> selection(vector<double> mas) = 0;
	virtual vector<double> bubble(vector<double> mas) = 0;
	virtual vector<double> shaker(vector<double> mas) = 0;
};

class Sortings : public ISortings
{
public:
	vector<double> selection(vector<double> mas)
	{
		for (size_t i = 0; i < mas.size(); i++)
		{
			int min = i;
			for (size_t j = min; j < mas.size(); j++)
			{
				if (mas[min] > mas[j])
					min = j;
			}
			swap(mas[i], mas[min]);
		}
		return mas;
	}
	vector<double> bubble(vector<double> mas)
	{
		for (size_t i = 0; i < mas.size() - 1; i++)
		{
			for (size_t j = mas.size() - 1; j > i; j--)
			{
				if (mas[j] < mas[j - 1])
					swap(mas[j], mas[j - 1]);
			}
		}
		return mas;
	}
	vector<double> shaker(vector<double> mas)
	{
		int left = 0, right = mas.size() - 1;
		do {
			for (int i = right; i > left; i--)
			{
				if (mas[i] < mas[i - 1])
				{
					swap(mas[i], mas[i - 1]);
				}
			}
			left += 1;
			for (int i = left; i < right; i++)
			{
				if (mas[i] > mas[i + 1])
				{
					swap(mas[i], mas[i + 1]);
				}
			}
			right -= 1;
		} while (left <= right);
		return mas;
	}
};

class ProxySortings : public ISortings
{
	ISortings *sort;
public:
	ProxySortings(ISortings *_sort)
	{
		sort = _sort;
	}
	vector<double> selection(vector<double> mas)
	{
		return sort->selection(mas);
	}
	vector<double> bubble(vector<double> mas)
	{
		return sort->bubble(mas);

	}
	vector<double> shaker(vector<double> mas)
	{
		return sort->shaker(mas);
	}
};

void show(vector<double> mas)
{
	for (int i = 0; i < mas.size(); i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

