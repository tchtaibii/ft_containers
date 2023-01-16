#ifndef ENABLE_IF_CPP
#define ENABLE_IF_CPP


template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {
    typedef T type;
};

#endif