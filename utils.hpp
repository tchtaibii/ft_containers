#ifndef UTILS_CPP
#define UTILS_CPP

namespace ft {
    
    template <typename T>
    struct remove_cv {
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

    template <bool B, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T> {
        typedef T type;
    };
    
    template<class T>
    struct is_char
    {
        static const bool value = false;
    };

    template<>
    struct is_char<remove_cv<char>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_char<remove_cv<signed char>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_char<remove_cv<unsigned char>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_char<remove_cv<wchar_t>::type>
    {
        static const bool value = true;
    };

    
    template<class T>
    struct is_integral_
    {
        static const bool value = false;
    };
    
    template<>
    struct is_integral_<remove_cv<bool>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<char>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<signed char>::type>
    {
        static const bool value = true;
    };


    template<>
    struct is_integral_<remove_cv<short int>::type>
    {
        static const bool value = true;
    };

     template<>
    struct is_integral_<remove_cv<int>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<long int>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<unsigned char>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<unsigned short int>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<unsigned int>::type>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral_<remove_cv<unsigned long int>::type>
    {
        static const bool value = true;
    };
    
    template<class T>
    struct is_integral
    {
        static const bool value = is_integral_<typename remove_cv<T>::type>::value;
    };
    // template <class InputIterator1, class InputIterator2>
    // bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
    //                           InputIterator2 first2, InputIterator2 last2){
    // std::ptrdiff_t a = std::distance(last1, first1);
    // std::ptrdiff_t b = std::distance(last2, first2);
    //     if (a > b)
    //         return (1);
    //     return (0);                           
    // }
}

#endif