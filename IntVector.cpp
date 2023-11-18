#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value) : _size(capacity), _capacity(capacity) {
    if (_capacity > 0) {
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    } else {
        _data = nullptr;
    }
}

IntVector::~IntVector() {
    if (_data != nullptr) {
        delete[] _data;
        _data = nullptr;
    }
}

const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    } else {
        return _data[index];
    }
}

int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    } else {
        return _data[index];
    }
}

void IntVector::insert(unsigned index, int value) {
    if (index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (_size + 1 > _capacity) {
        expand();
    }
    ++_size;
    for (unsigned i = _size - 1; i > index; --i) {
        _data[i] = _data[i - 1];
    }
    _data[index] = value;
}
    
void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i + 1 < _size; ++i) {
        _data[i] = _data[i + 1];
    }
    --_size;
}

void IntVector::assign(unsigned n, int value) {
    clear();
    resize(n, value);
}

void IntVector::push_back(int value) {
    if (_size + 1 > _capacity) {
        expand();
    }
    ++_size;
    _data[_size - 1] = value;
}

void IntVector::resize(unsigned size, int value) {
    if (size > _size) {
        if (size > _capacity) {
            if (size - _capacity > _capacity) {
                expand(size - _capacity);
            } else {
                expand();
            }
        }
        for (unsigned i = 0; i < size; ++i) {
            cout << _data[i];
        }
        for (unsigned i = _size; i < size; ++i) {
            _data[i] = value;
        }
    }
    _size = size;
}
   
void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        expand(n - _capacity);
        _capacity = n;
    }
}

void IntVector::expand() {
    if (_capacity == 0) {
        ++_capacity;
    } else {
        _capacity *= 2;
    }
    int *tempArr = new int[_capacity];
    for (unsigned i = 0; i < _size; ++i) {
      tempArr[i] = _data[i];
    }
    delete[] _data;
    _data = tempArr;
}

void IntVector::expand(unsigned amount) {
    _capacity += amount;
    int *tempArr = new int[_capacity];
    for (unsigned i = 0; i < _size; ++i) {
      tempArr[i] = _data[i];
    }
    delete[] _data;
    _data = tempArr;
}