#include <iostream>
#include <queue>
template<typename T>
class FreewillArray {
public:
    FreewillArray() = default;
    FreewillArray(size_t size)
    :_size{size}{
        _arr = new T[size];
    }
    FreewillArray(size_t size, const T& t)
    :_size{size}{
        _arr = new T[size]{t};
    }
    ~FreewillArray(){
        delete[] _arr;
    }
    T& get(size_t index){
        return _arr[index];
    }
    T& operator[](size_t index){
        return get(index);
    }
    const T& get(size_t index) const {
        return _arr[index];
    }
    const T& operator[](size_t index) const {
        return get(index);
    }
protected:
    size_t _size{0};
    T *_arr{nullptr};
};

template <typename T>
class SortableArray : public FreewillArray<T>
{
public:
    SortableArray() = default;
    SortableArray(size_t size, const T &t) : FreewillArray<T>{size, t} {};
    SortableArray(size_t size) : FreewillArray<T>{size} {};
    void sort(std::greater<T> f = std::greater<T>()){
        for (size_t i = 1; i < this->_size; i++)
        {
            for (size_t j = 0; j < this->_size - i; j++)
            {
                if(f(this->_arr[j], this->_arr[j + 1])){
                    std::swap(this->_arr[j], this->_arr[j + 1]);
                }
            }
        }
    }
};

int main(){
    SortableArray<int> arr{10};
    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = rand();
    }
    arr.sort();
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    
}