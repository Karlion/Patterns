#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>


class Item {
public:
	virtual bool operator<(const Item&) const = 0;
	virtual void showItem() = 0;
};

class ArrayOfItems {
public:
	virtual Item& operator[](int) = 0;
	virtual void swap(Item&, Item&) = 0;
	virtual void fill() = 0;
	virtual void show() const = 0;
	virtual size_t size() = 0;
};



class IntToSort : public Item {
private:
	int value;
public:
	IntToSort() : value(0) {};

	IntToSort(int i) : value(i) {};

	bool operator<(const Item& operand) const {
		return value < static_cast<const IntToSort&>(operand).value;
	}
	void showItem() {
		std::cout << value << " ";
	}
};

class ArrayOfInt : public ArrayOfItems {
	std::vector<IntToSort> arrayToSort;
public:
	ArrayOfInt(int size) :arrayToSort(size) {}

	Item& operator[](int i) {
		return static_cast<Item&>(arrayToSort[i]);
	}

	void fill()
	{
		srand((unsigned int)time(NULL));
		auto rng = [&](){return std::rand() % arrayToSort.size(); };
		std::generate_n(arrayToSort.begin(), arrayToSort.size(), rng);
	}

	void addArray(std::vector<int> v) {
		for (auto i = v.begin(); i < v.end(); i++)
		{
			arrayToSort.push_back(*i);
		}
	}

	void show() const {
		for (auto x : arrayToSort) x.showItem();
	}

	void swap(Item& a, Item& b) {
		auto temp = static_cast<IntToSort&>(a);
		static_cast<IntToSort&>(a) = static_cast<IntToSort&>(b);
		static_cast<IntToSort&>(b) = temp;
	}

	size_t size() {
		return arrayToSort.size();
	}
};

class SortPack {
private:

	ArrayOfItems *items;

	int quantity;

private:

	void quickPart(int left, int right) {
		int i = left, j = right;
		int mid = (left + right) / 2;

		while (i <= j) {
			while ((*items)[i] < (*items)[mid] && i <= j)
				i++;
			while ((*items)[mid] < (*items)[j] && i <= j)
				j--;
			if (i <= j) {
				if (i == mid) {
					mid = j;
				}
				else if (j == mid) {
					mid = i;
				}

				items->swap((*items)[i], (*items)[j]);
				i++;
				j--;
			}
		}



		if (left < j)
			quickPart(left, j);
		if (i < right)
			quickPart(i, right);
	}

public:

	SortPack() : quantity(0) {}

	void bubble() {
		for (int i(quantity - 1); i > 0; i--) {
			for (int j(0); j < i; j++) {
				if ((*items)[j + 1] < (*items)[j]) items->swap((*items)[j], (*items)[j + 1]);
			}
		}
	}

	void select() {
		int start = 0;

		while (start != quantity) {
			int minIndex = start;
			for (int i(start); i < quantity; i++) {
				if ((*items)[i] < (*items)[minIndex]) minIndex = i;
			}
			items->swap((*items)[minIndex], (*items)[start]);
			start++;
		}
	}

	void insert() {
		for (int i(1); i < quantity; i++)
			for (int j = i; j > 0 && (*items)[j] < (*items)[j - 1]; j--) 
				items->swap((*items)[j], (*items)[j - 1]);
	}

	void shell() {
		for (int d = quantity / 2; d >= 1; d /= 2)
			for (int i = d; i < quantity; i++)
				for (int j = i; j >= d && (*items)[j] < (*items)[j - d]; j -= d)
					items->swap((*items)[j], (*items)[j - d]);
	}


	void attach(ArrayOfItems& array) {
		quantity = (int)array.size();
		items = &array;
	}

	void show() {
		items->show();
		std::cout << "\n";
	}

	void quick() {
		quickPart(0, quantity - 1);
	}

	bool isSorted() {
		for (int i(0); i < quantity - 1; i++) {
			if ((*items)[i + 1] < (*items)[i]) return false;
		}
		return true;
	}
};