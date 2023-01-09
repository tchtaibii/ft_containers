#ifndef FT_vector_HPP
#define FT_vector_HPP

#include <iostream>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T &reference;
		typedef T *pointer;
		typedef size_t size_type;

	public:
		// Default constructor
		vector(const allocator_type &alloc = allocator_type()) : data_(nullptr), size_(0), capacity_(0), alloc(alloc) {}
		// Constructor that takes an initial size and a value
		vector(size_t size, value_type value = T(), const allocator_type &alloc = allocator_type()) : alloc(alloc)
		{
			size_ = size;
			capacity_ = size;
			data_ = this->alloc.allocate(size);
			for (size_type i = 0; i < size; i++)
				this->alloc.construct(data_ + i, value);
		}
		// Copy constructor
		vector(const vector &other) : data_(nullptr), size_(other.size_), capacity_(other.capacity_), alloc(other.alloc)
		{
			data_ = this->alloc.allocate(size_);
			for (size_type i = 0; i < size_; i++)
				this->alloc.construct(data_ + i, other.data_[i]);
		}
		// Assigment copy
		vector &operator=(const vector &other)
		{
			if (this != &other)
			{
				// Deallocate the current data array
				for (size_type i = 0; i < size_; i++)
					this->alloc.destroy(data_ + i);
				this->alloc.deallocate(data_, size_);
				// Allocate a new data array and copy the elements from the other vector
				size_ = other.size_;
				capacity_ = other.capacity_;
				data_ = this->alloc.allocate(size_);
				for (size_type i = 0; i < size_; i++)
					this->alloc.construct(data_ + i, other.data_[i]);
			}
			return *this;
		}
		// Destructor
		~vector()
		{
		  for (size_t i = 0; i < size_; i++)
		    alloc.destroy(data_ + i);
		  alloc.deallocate(data_, size_);
		}

		// Return true if the vector is empty
		bool empty() const { return size_ == 0; }

		// Return the number of elements in the vector
		size_type size() const { return size_; }

		// Return size of allocated storage capacity r
		size_type capacity() const { return capacity_; }

		// Return max size of the vector
		size_type max_size() const { return alloc.max_size();}

		// Add an element to the end of the vector
		void push_back(value_type value)
		{
		  if (size_ == capacity_)
		    this->resize(size_ + 1);
		  this->alloc.construct(data_ + size_+ 1, value);
		}

		// resize vector
		void resize (size_type n, value_type val = value_type())
		{
			if (n >= 0)
			{
				int tmp_capacity = this->capacity();
				int tmp_size = this->size();
				if (n > capacity_)
				{
					if (capacity_ * 2 >= n)
						capacity_ *= 2;
					else
						capacity_ = n;
				}
				ft::vector<value_type> new_(capacity_, val);
				new_.size_ = n;
				size_type i = -1;
				while ( ++i < new_.size_)
					new_.alloc.construct(new_.data_ + i, this->data_[i]);
				// for (size_type i = 0; i < tmp_size; i++)
				// 	this->alloc.destroy(this->data_ + i);
				// this->alloc.deallocate(this->data_, tmp_size);
				*this = new_;
				// for (size_type i = 0; i < tmp_size; i++)
				// 	new_.alloc.destroy(new_.data_ + i);
				// new_.alloc.deallocate(new_.data_, new_.size_);
			}
		}

		// Return a reference to the element at the given index, with bounds checking
		value_type& at(size_t index) {
		  if (index >= size_)
		    throw std::out_of_range("Index out of range");
		  return data_[index];
		}

		// Return a reference to the element at the given index, without bounds checking
		value_type &operator[](size_t index) { return data_[index]; }

	private:
		pointer data_;
		size_type size_;
		size_type capacity_;
		allocator_type alloc;
	};
}
#endif