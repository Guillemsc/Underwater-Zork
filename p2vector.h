
#ifndef __p2Vector__
#define __p2Vector__

#include <iostream>
#include <string>

using namespace std;

template <class T>
class p2vector
{
private:
	unsigned int my_size;
	unsigned int my_capacity;
	unsigned int things;
	T *buffer;

public:
	// empty vector
	p2vector()
	{
		my_capacity = 0;
		my_size = 0;
		buffer = nullptr;
		things = 0;
	}

	// set size
	p2vector(unsigned int size)
	{
		my_capacity = size;
		my_size = size;
		buffer = new T[size];
		things = 0;
	}

	// alloc
	p2vector(const p2vector<T> &v)
	{
		my_size = v.my_size;
		my_capacity = v.my_capacity;
		buffer = new T[my_size];
		for (int i = 0; i < my_size; i++)
			buffer[i] = v.buffer[i];
		things = 0;
	}

	// destructor
	~p2vector()
	{
		delete[] buffer;
	}

	// Methods
	// push back
	void push_back(const T &v)
	{
		if (my_size >= my_capacity)
			reserv(my_capacity + 5);
		buffer[my_size++] = v;
		things++;
	}

	// pop back
	void pop_back()
	{
		my_size--;
	}

	// reserve
	void reserv(unsigned int capacity)
	{
		if (buffer == 0)
		{
			my_size = 0;
			my_capacity = 0;
		}
		T *Newbuffer = new T[capacity];

		unsigned int l_Size = capacity < my_size ? capacity : my_size;

		for (unsigned int i = 0; i < l_Size; i++)
			Newbuffer[i] = buffer[i];

		my_capacity = capacity;
		delete[] buffer;
		buffer = Newbuffer;
	}

	// operator []
	T & operator[](unsigned int index)
	{
		return buffer[index];
	}

	// operator =
	p2vector<T> & operator=(const p2vector<T> &v)
	{
		delete[] buffer;
		my_size = v.my_size;
		my_capacity = v.my_capacity;
		buffer = new T[my_size];
		for (int i = 0; i < my_size; i++)
			buffer[i] = v.buffer[i];
		return *this;
	}

	int get_things()
	{
		return things;
	}
};

#endif