#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LeetStack {

public:
    LeetStack() : m_data() {}
    T &top();
    const T &top() const ;
    void pop();
    void push(T);
    size_t size();
    bool empty();

private:
    vector<T> m_data;
};


template <typename T>
inline void LeetStack<T>::push(T t) {
    m_data.push_back(t);
}

template <typename T>
inline T& LeetStack<T>::top() {
    return m_data.back();
}

template <typename T>
inline const T& LeetStack<T>::top() const {
    return m_data.back();
}

template <typename T>
inline void LeetStack<T>::pop() {
    m_data.pop_back();
}

template <typename T>
inline size_t LeetStack<T>::size() {
    return m_data.size();
}

template <typename T>
inline bool LeetStack<T>::empty() {
    return m_data.empty();
}





