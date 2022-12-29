#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP


namespace ft{
    template <typename T, typename Alloc = std::allocator<T>>
    class vector{
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef allocator_type::reference reference;
        typedef allocator_type::pointer pointer;
        
        public:
            // (constructor)
            vector() : size_(0), capacity_(0), elements_(nullptr) {}
            explicit vector (const allocator_type& alloc = allocator_type())
    {};
            explicit vector (size_type n, const T& val = T(), const allocator_type& alloc = allocator_type());	
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());	
            vector (const vector& x);
            // (destructor)
            ~Vector() {}
        public:
        alloc ccc;

        private:
            size_t size_;
            size_t capacity_;
            pointer* elements_;
    };
};



#endif