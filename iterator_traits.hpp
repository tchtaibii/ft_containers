#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


template <typename T>
struct iterator_traits
{
 typedef std::random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef T& refrence;
  typedef T* pointer;
  typedef typename std::ptrdiff_t difference_type;
};

template <typename T>
struct iterator_traits<T*>
{
  typedef std::random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef T& refrence;
  typedef T* pointer;
  typedef typename std::ptrdiff_t difference_type;

};

template <typename T>
struct iterator_traits<const T*>
{
  typedef std::random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef T& refrence;
  typedef T* pointer;
  typedef typename std::ptrdiff_t difference_type;
};

#endif