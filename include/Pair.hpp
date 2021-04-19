
#ifndef OPTIONAL_HPP_
#define OPTIONAL_HPP_
#include <iostream>
template <typename T>
class Pair{
public:
    T x; //сделать ссылку(указатель)
    T y;

    Pair(T x, T y);
    Pair(const Pair& other);
    Pair& operator=(const Pair& other);

//!=, +    
    template <typename V>
    friend std::ostream& operator<<(std::ostream& os, const Pair<V>& source);
     
};

template <typename T>
Pair<T>::Pair(T x, T y): x(x),y(y) {} 

template <typename T>
Pair<T>::Pair(const Pair& other): x(other.x), y(other.y){}



template <typename T>
Pair<T>& Pair<T>::operator=(const Pair& other){
    x=other.x;
    y=other.y;
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os,const Pair<T>& source){
    os<<"[ "<<source.x<<' '<<source.y<<" ]\n";
    return os;
}


template <typename T>
Pair<T> operator+(const Pair<T>& first, const Pair<T>& second){
    return Pair<T>(first.x+second.x,first.y+second.y);
}

template <typename T>
bool operator!=(const Pair<T>& first,const Pair<T>& second){
    if(first.x!=second.x || first.y!=second.y)
        return true;

    return false;

}

typedef Pair<int> Pair_i;
typedef Pair<double> Pair_d;

#endif
