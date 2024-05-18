#include <iostream>
using namespace std;

void pp(int& a) {
    std::cout << &a << " " << a << " " << sizeof(a) << std::endl;
}

template<typename T>

class Array {
    T* m_arr;
    size_t m_size;

public:
    Array(size_t size):  m_arr(new T[size]), m_size(size){
        cout << "Array Constructor\n";
    }
    ~Array() {
        delete[] m_arr;
        cout << "Array Destructor\n";
    }
    T get(size_t index) const {
        return m_arr[index];
    }
    void set(size_t index, T val) {
        m_arr[index] = val;
    }
    void print()const {
        for (size_t i = 0; i < m_size; i++) {
            cout << i << " " << m_arr[i] << '\n';
        }
    }
    const T& operator[](size_t index) const {
        return m_arr[index];
    }
    T& operator[](size_t index) {
        return m_arr[index];
    }


};

int main(int argc, char* argv[])
{
    Array<float> myArray(10);
    myArray[2] = 1000;
    myArray.print();
    return 0;
}