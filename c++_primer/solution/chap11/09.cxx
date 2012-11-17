/*
Using the code you developed for Exercise 11.8, change the declaration of 
class IntArray operator[]() to add an appropriate exception specification to 
describe the exception this operator can throw. Modify your program so that 
operator[]() throws an exception not listed in its exception specification. 
What happens then?
*/
class IntArray {
public:
    // ...
    int &operator[](int) throw(OutOfBounds);
    // ...
};

class OutOfBounds 
{
public:
    OutOfBounds(int ix) : _index(ix) { };
    int index() { return _index };

private:
    int _index;
};

int &IntArray::operator[](int index) throw(OutOfBounds) {
    if (index < 0 || index >= _size) {
        throw OutOfBounds(index);
    }

    return ia[index];
}

