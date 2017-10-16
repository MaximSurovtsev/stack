#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
template<typename T>
class stack {
public:
	stack();
	stack(const stack&);
	size_t count() const;
	void push(T const &);
	T pop();
	void print();
	void last();
	void swap();
	T* swap(const stack&);
	stack& operator=(const stack& other);
private:
	T* array_;
	size_t array_size_;
	size_t count_;
};

template<typename T> 
void stack<T>::swap() {
	T* temp = new T[array_size_]();
	std::copy(array_, array_ + count_, temp);
	array_ = temp;
}
template<typename T>
T* stack<T>::swap(const stack& obj) {
	T* temp = new T[obj.array_size_]();
	std::copy(obj, obj + obj.count_, temp);
	obj.array_ = temp;
	return temp;
}

template<typename T>
stack<T>::stack()
{
	array_ = nullptr;
	array_size_ = 0;
	count_ = 0;
}

template<typename T>
stack<T>::stack(const stack& obj)
{
	std::copy(obj.array_, obj.array_ + obj.count_, array_);
	array_size_ = obj.array_size_;
	count_ = obj.count_;
}



template<typename T>
size_t stack<T>::count() const
{
	return count_;
}

template<typename T>
void stack<T>::push(T const& el)
{
	if (array_size_ == 0) {
		array_size_ = 1;
		count_ = 1;
		array_ = new T[array_size_]();
		array_[0] = el;

	}
	else {
		if (array_size_ == count_) {
			array_size_ *= 2;
			swap();
		}
		array_[count_++] = el;
	}
}
template<typename T>
T stack<T>::pop()
{
	if (array_size_ > 0)
	{
		T temp = array_[--count_];
		if (count_ == 0)
		{
			array_size_ = 0;
			delete[] array_;
		}

		else	if (array_size_ / 2 == count_)
				{
					array_size_ /= 2;
					swap();
				}
				else 
				{
					array_[count_] = 0;
				}
		return temp;
	}
	else {
		throw std::logic_error("Stack is empty!");
	}
}

template<typename T>
void stack<T>::print()
{
		if (array_size_ == 0)
		{
			cout << "Stack is empty!";
			return;
		}
		for (int i = 0; i < array_size_; i++)
		{
			cout << array_[i] << ' ';
		}
		cout << "\n";
}

template<typename T>
void stack<T>::last()
{
	if (count_ == 0)
	{
		cout << "Stack is empty\n";
	}
	else {
		cout << array_[count_ - 1]<< "\n";
	}
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> const & other)
{
	if (this != &other)
	{
		delete[] array_;
		array_ = swap(other);
		array_size_ = obj.array_size_;
		count_ = obj.count_;
	}
	return *this;
}
#endif 
