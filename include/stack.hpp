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
	bool isEmpty();
	void swap(stack<T>&);
	void last()const;
	
	std::ostream& print(std::ostream&stream);
	stack& operator=(stack const& other);

private:
	T* array_;
	size_t array_size_;
	size_t count_;
	
};

template <typename T>
void stack<T>::swap(stack<T>& other)
{
	std::swap(array_, other.array_);
	std::swap(array_size_, other.array_size_);
	std::swap(count_, other.count_);
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
		stack(obj).swap(*this);
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
		swap(temp);
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

template <typename T>
std::ostream& stack<T>::print(std::ostream&stream)
{	
	for (unsigned int i = 0; i < count_; ++i)
		stream << array_[i] << " ";
	stream << std::endl;
	return stream;
}
template <typename T>
bool stack<T>::isEmpty()
{
	return (count_ == 0);
}

template <typename T>
inline operator << (std::ostream& stream, stack<T> const& stack_)
{
	return print(stream, stack_);
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

