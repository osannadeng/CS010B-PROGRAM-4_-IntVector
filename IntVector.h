#include <iostream>

class IntVector {
  public:
    IntVector(unsigned capacity = 0, int value = 0);
    ~IntVector();
    unsigned size() const { return _size; }
    unsigned capacity() const { return _capacity; }
    bool empty() const { return _size == 0; }
    const int & at(unsigned index) const;
    const int & front() const { return _data[0]; }
    const int & back() const { return _data[_size - 1]; }
    int & at(unsigned index);
    void insert(unsigned index, int value);
    void erase(unsigned index);
    int & front() { return _data[0]; }
    int & back() { return _data[_size - 1]; }
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back() { --_size; }
    void clear() { _size = 0; }
    void resize(unsigned size, int value = 0);
    void reserve(unsigned n);
  private:
    unsigned _size;
    unsigned _capacity;
    int *_data;
    void expand();
    void expand(unsigned amount);
};