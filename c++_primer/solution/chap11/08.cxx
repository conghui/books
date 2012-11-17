/*
 Using the code you developed for Exercise 11.3, modify the exception class 
 you created so that the invalid index used with operator[]() is stored in the 
 exception object when the exception is thrown and later displayed by the 
 catch clause. Modify your program so that operator[]() throws an exception 
 during the execution of the program.
*/

class OutOfBounds 
{
public:
    OutOfBounds(int ix) : _index(ix) { };
    int index() { return _index };

private:
    int _index;
};

int &IntArray::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw OutOfBounds(index);
    }

    return ia[index];
}
