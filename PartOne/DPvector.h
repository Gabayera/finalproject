#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class DPvector
{
private:
    T** m_elements;
    int m_size;

public:
    DPvector(T input_arr[], int size);
    DPvector();
    ~DPvector();
    T& operator[](int n);
    T** begin();
    void push_back(T new_element);
    void show_elements();
    void resize(int n);
    void resize(int n, T value);
    void insert(int n, T value);
    void insert(int n, int amount, T value);
    void insert(T* vec_index, T* starting_iterator, T* ending_iterator);
    void remove(int index);
    int size() const;
};

template <typename T>
DPvector<T>::DPvector(T input_arr[], int size)
{
    m_elements = new T*[size];
    for (int i = 0; i < size; i++)
    {
        m_elements[i] = new T(input_arr[i]);
    }
    m_size = size;
}

template <typename T>
DPvector<T>::DPvector()
{
    m_elements = new T*[0];
    m_size = 0;
}

template <typename T>
DPvector<T>::~DPvector()
{
    for (int i = 0; i < m_size; i++)
    {
        delete m_elements[i];
    }
    delete[] m_elements;
    m_elements = nullptr;
}

template <typename T>
T& DPvector<T>::operator[](int n)
{
    return *m_elements[n];
}

template <typename T>
T** DPvector<T>::begin()
{
    return m_elements;
}

template <typename T>
void DPvector<T>::push_back(T new_element)
{
    T** temp = new T*[m_size + 1];
    for (int i = 0; i < m_size; i++)
    {
        temp[i] = m_elements[i];
    }
    temp[m_size] = new T(new_element);
    delete[] m_elements;
    m_elements = temp;
    m_size++;
}

template <typename T>
void DPvector<T>::show_elements()
{
    if (m_size == 0)
        cout << "[]";
    else
    {
        cout << "[" << *m_elements[0];
        for (int i = 1; i < m_size; i++)
            cout << ", " << *m_elements[i];
    }
    cout << "]" << endl;
}

template <typename T>
void DPvector<T>::resize(int n)
{
    T** temp = new T*[n];
    for (int i = 0; i < n; i++)
    {
        if (i < m_size)
            temp[i] = m_elements[i];
        else
            temp[i] = new T();
    }
    for (int i = n; i < m_size; i++)
    {
        delete m_elements[i];
    }
    delete[] m_elements;
    m_elements = temp;
    m_size = n;
}

template <typename T>
void DPvector<T>::resize(int n, T value)
{
    T** temp = new T*[n];
    for (int i = 0; i < n; i++)
    {
        if (i < m_size)
            temp[i] = m_elements[i];
        else
            temp[i] = new T(value);
    }
    for (int i = n; i < m_size; i++)
    {
        delete m_elements[i];
    }
    delete[] m_elements;
    m_elements = temp;
    m_size = n;
}

template <typename T>
void DPvector<T>::insert(int n, T value)
{
    T** temp = new T*[m_size + 1];
    for (int i = 0; i < m_size + 1; i++)
    {
        if (i < n)
            temp[i] = m_elements[i];
        else if (i == n)
            temp[i] = new T(value);
        else
            temp[i] = m_elements[i - 1];
    }
    delete[] m_elements;
    m_elements = temp;
    m_size++;
}

template <typename T>
void DPvector<T>::insert(int n, int amount, T value)
{
    T** temp = new T*[m_size + amount];
    for (int i = 0; i < m_size + amount; i++)
    {
        if (i < n)
            temp[i] = m_elements[i];
        else if (i >= n && i < n + amount)
            temp[i] = new T(value);
        else
            temp[i] = m_elements[i - amount];
    }
    delete[] m_elements;
    m_elements = temp;
    m_size += amount;
}

template <typename T>
void DPvector<T>::insert(T* vec_index, T* starting_iterator, T* ending_iterator)
{
    int size = ending_iterator - starting_iterator;
    int index = vec_index - *m_elements;
    T** temp = new T*[m_size + size];
    for (int i = 0; i < m_size + size; i++)
    {
        if (i < index)
            temp[i] = m_elements[i];
        else if (i >= index && i < index + size)
            temp[i] = new T(*(starting_iterator + i - index));
        else
            temp[i] = m_elements[i - size];
    }
    delete[] m_elements;
    m_elements = temp;
    m_size += size;
}

template <typename T>
void DPvector<T>::remove(int index)
{
    T** temp = new T*[m_size - 1];
    for (int i = 0; i < m_size - 1; i++)
    {
        if (i < index)
            temp[i] = m_elements[i];
        else
            temp[i] = m_elements[i + 1];
    }
    delete m_elements[index];
    delete[] m_elements;
    m_elements = temp;
    m_size--;
}

template <typename T>
int DPvector<T>::size() const
{
    return m_size;
}
