#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Vector
{
private:
    T* m_elements;
    int m_size;

public:
    Vector(T input_arr[], int size) : m_size(size) {
        m_elements = new T[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_elements[i] = input_arr[i];
        }
    }

    Vector(int size=0) : m_size(size) {
        m_elements = new T[m_size];

    }

    ~Vector() {
        delete[] m_elements;
        m_elements = nullptr;
    }

    T operator[](int n) {
        return m_elements[n];
    }

    T* begin() {
        return m_elements;
    }

    void push_back(T new_element) {
        T* temp = new T[m_size + 1];
        for (int i = 0; i < m_size; ++i) {
            temp[i] = m_elements[i];
        }
        delete[] m_elements;
        temp[m_size] = new_element;
        m_elements = temp;
        ++m_size;
    }

    int size() const {
        return m_size;
    }

    void show_elements() {
        if (m_size == 0)
            cout << "[]";
        else {
            cout << "[" << m_elements[0];
            for (int i = 1; i < m_size; ++i)
                cout << ", " << m_elements[i];
        }
        cout << "]" << endl;
    }

    void resize(int n) {
        T temp_var{};
        T* temp = new T[n];
        for (int i = 0; i < n; ++i)
            temp[i] = (i < m_size) ? m_elements[i] : temp_var;
        delete[] m_elements;
        m_elements = temp;
        m_size = n;
    }

    void resize(int n, T value) {
        T* temp = new T[n];
        for (int i = 0; i < n; ++i)
            temp[i] = (i < m_size) ? m_elements[i] : value;
        delete[] m_elements;
        m_elements = temp;
        m_size = n;
    }

    void insert(int n, T value) {
        T* temp = new T[++m_size];
        for (int i = 0; i < m_size; ++i) {
            temp[i] = (i < n) ? m_elements[i] : m_elements[i - 1];
        }
        delete[] m_elements;
        temp[n] = value;
        m_elements = temp;
    }

    void insert(int n, int amount, T value) {
        T* temp = new T[m_size + amount];
        for (int i = 0; i < m_size + amount; ++i) {
            temp[i] = (i < n) ? m_elements[i] : (i < n + amount) ? value : m_elements[i - amount];
        }
        delete[] m_elements;
        m_elements = temp;
        m_size += amount;
    }

    void insert(T* vec_index, T* starting_iterator, T* ending_iterator) {
        int size = ending_iterator - starting_iterator;
        int index = vec_index - m_elements;
        T* temp = new T[m_size + size];
        for (int i = 0; i < m_size + size; ++i) {
            temp[i] = (i < index) ? m_elements[i] : (i < index + size) ? *(starting_iterator + i - index) : m_elements[i - size];
        }
        delete[] m_elements;
        m_elements = temp;
        m_size += size;
    }

    void remove(int index) {
        T* temp = new T[--m_size];
        for (int i = 0; i < m_size; ++i) {
            temp[i] = (i < index) ? m_elements[i] : m_elements[i + 1];
        }
        delete[] m_elements;
        m_elements = temp;
    }
};
