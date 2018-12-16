#pragma once
#include <iostream>
#include <cstddef>
#include <cstring>
#include <cstdint>

template <typename T>
class ArrayList
{
public:
	// je dobre v array zadefinovat kapacitu
	ArrayList() : data(new T[1000]), capacity(1000), size(0) {} // nastavime pole na nullptr treba to dt
	ArrayList(size_t size) : data(new T[size]), capacity(size), size(size) {}
	virtual ~ArrayList() { delete[] data; }


	void add(T element)
	{
		if (size + 1 > capacity)
		{
			capacity += 1000;
			T* newData = new T[capacity];
			memcpy(newData, data, capacity - 1000); // skopiruje kapacitu prve je destination, druhe je ciel
			delete[] data;
			data = newData; // toto neskopiruje data, len nastavi pointer ale vytvorili sme novy pointer tym new ore, takze chill a ten stary sme vymazali  
			data[size++] = element;
		}
		else
		{
			data[size++] = element;
		}
	}
	void remove(size_t index) // index na size_t  pouzivaj  podla OS    vdaka tomu mozem vsetku pamat adresovat
	{
		for (size_t i = index; i < size - 1; ++i)
		{
			data[i] = std::move(data[i + 1]); // nemusime vymazat prvok, lebo sa prepise
		}
		--size;
		if (size + 2000 < capacity)
		{
			capacity -= 1000;
			T* newData = new T[capacity];
			memcpy(newData, data, size); // staci len tolko prvkov tam dat kolko je size
			delete[] data;
			data = newData; // toto neskopiruje data, len nastavi pointer ale vytvorili sme novy pointer tym new ore, takze chill a ten stary sme vymazali  
		}
	}
	T* find(T& element) // pointer aby sme ho mohli meni a aby sme mohli vratit nullptr
	{
		for (size_t i = 0; i < size; ++i)
			if (data[i] == element)
				return &data[i];
		return nullptr;

	}
	size_t findIndex(T& element)
	{
		for (size_t i = 0; i < size; ++i)
			if (data[i] == element)
				return i;
		return SIZE_MAX;
	}
	size_t getSize()
	{
		return this->size;
	}
	bool isEmpty()
	{
		return size == 0;
	}

	T* getData()
	{
		return this->data;
	}
private:
	T* data; // musi byt dynamicke pole
	size_t capacity;
	size_t size;
};

