#include <vector>
#include <iostream>
#include <exception>

template <typename T>
class Stack
{
	struct element
	{
		T val;
		element* next = nullptr;
		~element()
		{
			delete next;
		};
	};

	element* _top;
public:
	Stack() : _top{ nullptr }
	{};
	~Stack()
	{
		delete _top;
	};

	bool empty()
	{
		if (_top) return false;
		return true;
	}

	void push(const T& val)
	{
		if (!_top)
		{
			_top = new element;
			_top->next = nullptr;
			_top->val = val;
		}
		else
		{
			element* temp = new element;
			temp->val = val;
			temp->next = _top;
			_top = temp;
		}
	}

	T& top()
	{
		if (!_top) throw std::exception();
		return _top->val;
	}

	void pop()
	{
		if (!_top) throw std::exception();
		element* temp = _top->next;
		_top->next = nullptr;
		delete _top;
		_top = temp;
	}

};