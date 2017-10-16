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
	
	void last()const;
	
	friend ostream& print(ostream& ost, stack<T> const& test);
	stack& operator=(stack const& other);

private:
	T* array_;
	size_t array_size_;
	size_t count_;
	void swap(stack& first_obj, stack& second_obj);
};

template<typename T> 
void stack<T>::swap(stack<T>& first_obj, stack<T>& second_obj)
{
	std::swap(first_obj.array_, second_obj.array_);
	std::swap(first_obj.array_size_, second_obj.array_size_);
	std::swap(first_obj.count_, second_obj.count_);
}

template<typename T>
stack<T>::stack(): array_size_(1), count_(0)
{
	array_ = new T[1]();
}

template <typename T>
stack<T>::stack(stack<T> const& obj)
{
	count_ = obj.count_;
	array_size_ = obj.array_size_;
	array_ = new T[array_size_];

	std::copy(obj.array_, obj.array_ + count_, array_);
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> const& obj)
{
	if (this != &obj)
	{
		stack<T> temp(obj);
		swap(*this, temp);
	}
	return *this;
}

template<typename T>
size_t stack<T>::count() const
{
	return count_;
}

template<typename T>
void stack<T>::push(T const& el)
{
	if (array_size_ == count_) 
	{
		array_size_ *= 2;
		stack<T> temp(*this);
		swap(*this, temp);
	}
	array_[count_++] = el;
}
template<typename T>
T stack<T>::pop()
{
	if (count_ == 0)
	{
		throw "Stack is empty!";
	}
	count_--;
	T result = array_[count_];
	return result;
}

template<typename T>
ostream& print(ostream& ost, stack<T> const& test)
{
		if (test.count_ == 0)
		{
			throw "Stack is empty!";
		}
		for (int i = 0; i < test.count_; i++)
		{
			ost << test.array_[i] << ' ';
		}
		return ost;
}


template<typename T>
void stack<T>::last() const
{
	if (count_ == 0)
	{
		cout << "Stack is empty\n";
	}
	else {
		cout << array_[count_ - 1]<< "\n";
	}
}

