#include "DynamicArray.hpp"
#include <iostream>

DynamicArray::DynamicArray(size_t size) {
	storage = new int[size];
	storage_length = size;
	nitems = 0;
}

size_t DynamicArray::length() {
	return (size_t)nitems;
}

int DynamicArray::select(size_t k) {
	return storage[k];
}

void DynamicArray::store(int o, size_t k) {
	storage[k] = o;
}

void DynamicArray::push(int o) {
	if (nitems >= storage_length) {
		extend();
	}
	storage[nitems] = o;
	nitems++;
}

int DynamicArray::pop() {
	nitems--;
	return storage[nitems];
}

void DynamicArray::extend() {
	std::cout << "extend" << std::endl;
	int newLength = storage_length + 1;
	int *newStorage = new int[newLength];
	for (int i = 0; i < storage_length; i++) {
		newStorage[i] = storage[i];
	}
	storage_length++;
	storage = newStorage;
}