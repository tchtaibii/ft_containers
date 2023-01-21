#ifndef UTILS_CPP
#define UTILS_CPP

namespace ft
{

    template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <typename T>
    struct remove_cv{
        typedef T type;
    };

    template <typename T>
    struct remove_cv<const T> {
        typedef T type;
    };

    template <typename T>
    struct remove_cv<volatile T> {
        typedef T type;
    };

    template <typename T>
    struct remove_cv<const volatile T> {
        typedef T type;
    };

    template<typename T>
    struct is_integral
    {
        static const bool value = false;
    };

    template<>
    struct is_integral <remove_cv<bool>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<char>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<signed char>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<short int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<long int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned char>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned short int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned long int>::type>
    {
        static const bool value = true; 
    };
}

#endif