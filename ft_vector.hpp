#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

namespace ft{
    template <typename T, typename Alloc = std::allocator<T> >
    class vector{
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T& reference;
        typedef T* pointer;
        typedef size_t size_type;
        
        public:
            // (constructor)
            explicit vector(const allocator_type& alloc = allocator_type()) : alloc(alloc), elements_(nullptr), size_(0), capacity_(0){
            }
            explicit vector(size_type n, const T& val = T(), const allocator_type& alloc = allocator_type())
            {
                this->alloc = alloc;
                this->elements_ = alloc.allocate(n);
                this->size_ = 0;
                this->capacity_ = n;
                while (n > 0)
                {
                    alloc.construct(&elements_[size_], val);
                    size_++;
                    n--;
                }
            }
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());	
            vector (const vector& x);
            vector& operator=(const vector& x)
            {
                int n = x.size_;
                this->size_ = 0;
                this->capacity_ = x.capacity_;
                this->elements_ = alloc.allocate(this->capacity_);
                while (n > 0)
                {
                    alloc.construct(&elements_[size_], x.elements_[size_]);
                    size_++;
                    n--;
                }
                std::cout << "vector : " << elements_[size_] << std::endl;
                return *this;
            }
            // (destructor)
            ~vector() {}

        private:
            allocator_type alloc;
            size_type size_;
            size_type capacity_;
            pointer elements_;
    };
};



#endif