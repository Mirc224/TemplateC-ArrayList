#pragma once
#include <iostream>
#include <cstddef>
#include <cstring>
#include <cstdint>
#include <stdexcept>
#include <iterator>

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

	T& operator[](size_t index) { return data[index]; } //nechraneny najrychlejsi
	T& at(size_t index) 
	{
		if (index > 0 && index < size)
			return data[index];
		throw std::invalid_argument("Invalid index");
	}
	class Iterator : std::iterator<std::random_access_iterator_tag, T>  //stary, bude odstraneny asi
	{
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using point = T*;
		using reference = T & ;


		Iterator(T* data,size_t size): index(0), data(data), maxsize(size){} //zakazdym novy iterator
		Iterator(T* data, size_t size, size_t index) : index(index), data(data), maxsize(size) {}


		Iterator& operator++() { ++index; return *this; }
		Iterator& operator--() { --index; return *this; }
		Iterator& operator+(size_t offset) { index += offset; index = index > maxsize ? maxsize : index; return *this; }
		Iterator& operator-(size_t offset) { index -= offset; index = index > maxsize ? maxsize : index; return *this; }
		bool operator==(const Iterator& rhs) { return this->index == rhs.index && this->data == rhs.data; }
		bool operator!=(const Iterator& rhs){ return this->index != rhs.index || this->data != rhs.data; }
		T& operator*() { return data[index]; }
	private:
		size_t index;
		size_t maxsize;
		T* data;
	};

	Iterator begin()
	{
		return Iterator(this->data, this->size);
	}
	Iterator end()
	{
		return Iterator(this->data, this->size, this->size); //nastavi na koniec max size
	}
private:
	T* data; // musi byt dynamicke pole
	size_t capacity;
	size_t size;
};

