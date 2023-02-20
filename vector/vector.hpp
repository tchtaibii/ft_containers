#pragma once

#include <iostream>
#include "./iterator.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/utils.hpp"
namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef const T const_value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef typename ft::iterator<value_type> iterator;
		typedef typename ft::iterator<value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename std::ptrdiff_t difference_type;
		// Default constructor
		explicit vector(const allocator_type &alloc = allocator_type()) : data_(NULL), size_(0), capacity_(0), alloc(alloc) {}
		// Constructor that takes an initial size and a value
		explicit vector(size_type size, value_type value = T(), const allocator_type &alloc = allocator_type()) : alloc(alloc)
		{
			size_ = size;
			capacity_ = size;
			data_ = this->alloc.allocate(size);
			for (size_type i = 0; i < size; i++)
				this->alloc.construct(data_ + i, value);
		}
		// Copy constructor
		vector(const vector &other) : data_(NULL), size_(other.size_), capacity_(other.capacity_), alloc(other.alloc)
		{
			data_ = this->alloc.allocate(capacity_);
			for (size_type i = 0; i < size_; i++)
				this->alloc.construct(data_ + i, other.data_[i]);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			this->alloc = alloc;
			this->size_ = 0;
			this->capacity_ = 0;
			this->data_ = NULL;
			if (!ft::is_input_it<typename iterator_traits<InputIterator>::iterator_category>::value)
			{
				difference_type n = std::distance(first, last);
				this->data_ = this->alloc.allocate(n);
				capacity_ = n;
				while (size_ < (size_type)n)
					this->alloc.construct(&data_[size_++], *(first++));
			}
			else
			{
				while (first != last)
				{
					this->push_back(*(first++));
				}
			}
		}

		// Assigment copy
		vector &operator=(const vector &other)
		{
			if (this != &other)
			{
				// Deallocate the current data array
				this->clear();
				if (data_)
					this->alloc.deallocate(data_, this->capacity_);
				// Allocate a new data array and copy the elements from the other vector
				this->size_ = other.size_;
				this->capacity_ = other.capacity_;
				this->data_ = this->alloc.allocate(capacity_);
				for (size_type i = 0; i < this->size_; i++)
					this->alloc.construct(&data_[i], other.data_[i]);
			}
			return *this;
		}
		// Destructor
		~vector()
		{
			this->clear();
			if (data_)
				alloc.deallocate(data_, capacity_);
		}
		// Return true if the vector is empty
		bool empty() const { return size_ == 0; }
		// Return the number of elements in the vector
		size_type size() const { return size_; }
		// Return size of allocated storage capacity
		size_type capacity() const { return capacity_; }
		// Return max size of the vector
		size_type max_size() const
		{
			return alloc.max_size() > PTRDIFF_MAX ? PTRDIFF_MAX : alloc.max_size();
		}
		// Add an element to the end of the vector
		void push_back(value_type value)
		{
			this->resize(size_ + 1, value);
		}
		// Removes the last element in the vector, effectively reducing the container size by one.
		void pop_back()
		{
			this->alloc.destroy(data_ + size_ - 1);
			--size_;
		}
		// Resizes the container so that it contains n elements.
		void resize(size_type n, value_type val = value_type())
		{
			if (n > capacity_)
			{
				size_type tmp_size = size_;
				size_type tmp_capacity = capacity_;
				if ((capacity_ * 2) >= n)
					tmp_capacity *= 2;
				else
					tmp_capacity = n;
				pointer data_new = this->alloc.allocate(tmp_capacity);
				size_type i = 0;
				while (i < tmp_size)
				{
					this->alloc.construct(&data_new[i], data_[i]);
					i++;
				}
				while (i < n)
				{
					this->alloc.construct(&data_new[i], val);
					i++;
				}
				size_ = n;
				for (size_type i = 0; i < tmp_size; i++)
					alloc.destroy(&data_[i]);
				if (data_ != NULL)
					this->alloc.deallocate(data_, capacity_);
				capacity_ = tmp_capacity;
				data_ = this->alloc.allocate(capacity_);
				for (size_type i = 0; i < n; i++)
					alloc.construct(&data_[i], data_new[i]);
				for (size_type i = 0; i < n; i++)
					alloc.destroy(&data_new[i]);
				if (data_ != NULL)
					this->alloc.deallocate(data_new, tmp_capacity);
				// data_ = data_new;
			}
			else
			{
				if (n < size_)
				{
					while (n < size_)
					{
						this->alloc.destroy(data_ + size_ - 1);
						size_--;
					}
				}
				else if (n > size_)
					while (size_ < n)
						alloc.construct(&data_[size_++], val);
			}
		}
		// Returns a reference to the element at position n in the vector.
		reference at(size_type index)
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return data_[index];
		}
		const_reference at(size_type index) const
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return data_[index];
		}
		// Return a reference to the element at the given index, without bounds checking
		reference operator[](size_type index) { return data_[index]; }
		const_reference operator[](const size_type index) const { return data_[index]; }
		// Returns a reference to the first element in the vector.
		reference front() { return data_[0]; }
		const_reference front() const { return data_[0]; }
		// Returns a reference to the last element in the vector.
		reference back() { return data_[size_ - 1]; }
		const_reference back() const { return data_[size_ - 1]; }
		// Requests that the vector capacity be at least enough to contain n elements.
		void reserve(size_type n)
		{
			if (capacity_ < n)
			{
				pointer new_data_ = this->alloc.allocate(n);
				for (size_type i = 0; i < size_; i++)
					this->alloc.construct(new_data_ + i, this->data_[i]);
				for (size_type i = 0; i < size_; i++)
					alloc.destroy(data_ + i);
				if (data_)
					this->alloc.deallocate(data_, capacity_);
				data_ = new_data_;
				capacity_ = n;
			}
		}
		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		void clear()
		{
			if (size_ != 0)
			{
				for (size_type i = 0; i < size_; i++)
					alloc.destroy(data_ + i);
				size_ = 0;
			}
		}
		// Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		void swap(vector &x)
		{
			std::swap(data_, x.data_);
			std::swap(size_, x.size_);
			std::swap(capacity_, x.capacity_);
		}
		// begin iterator
		const_iterator begin() { return iterator(data_); }
		iterator begin() const { return const_iterator(data_); }
		// end iterator
		iterator end() { return iterator(data_ + size_); }
		const_iterator end() const { return const_iterator(data_ + size_); }
		// begin iterator
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
		// reverse end
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
		// The vector is extended by inserting new elements before the element at the specified position

		iterator insert(iterator position, const value_type &val)
		{
			size_type index = (position - this->begin());
			push_back(val);
			size_type tmp_size = size_;
			value_type tmp;
			// shift element to the left
			while (index < tmp_size - 1)
			{
				if (tmp_size - 2 >= 0 && tmp_size - 1 >= 0)
				{
					tmp = data_[tmp_size - 1];
					data_[tmp_size - 1] = data_[tmp_size - 2];
					data_[tmp_size - 2] = tmp;
					tmp_size--;
				}
				else
					break;
			}
			iterator it = std::find(this->begin() + index, this->end(), val);
			return (it);
		}
		void insert(iterator position, size_type n, const value_type &val)
		{
			if ((size_type)std::numeric_limits<difference_type>::max() == n)
				throw std::length_error("Length exception");
			if (n)
			{
				if (size_ + n <= capacity_)
				{
					for (size_type i = 0; i < n; i++)
						alloc.construct(&data_[i + size_], val);
					if (size_)
						std::rotate(position, this->end(), this->end() + n);
					size_ += n;
				}
				else
				{
					pointer tmp;
					size_type tmp_capacity = 0;
					if (size_ + n <= capacity_ * 2)
						tmp_capacity = capacity_ * 2;
					else
						tmp_capacity = size_ + n;
					tmp = alloc.allocate(tmp_capacity);
					size_type i = 0;
					if (size_)
					{
						// std::cout << "*****************" << std::endl;
						for (iterator it = this->begin(); it != position; it++)
						{
							this->alloc.construct(&tmp[i], *it);
							// std::cout << tmp[i] << std::endl;
							i++;
						}
						// std::cout << "*****************" << std::endl;
					}

					size_type j = 0;
					while (j < n)
					{
						alloc.construct(&tmp[i + j], val);
						// std::cout << tmp[i + j] << std::endl;
						j++;
					}
					// std::cout << "*****************" << std::endl;
					while (i < size_)
					{
						alloc.construct(&tmp[i + j], data_[i]);
						// std::cout << tmp[i + j] << std::endl;
						i++;
					}
					// std::cout << "*****************" << std::endl;
					size_type tmp_size = size();
					this->clear();
					if (data_)
						this->alloc.deallocate(data_, capacity_);
					size_ = n + tmp_size;
					capacity_ = tmp_capacity;
					data_ = tmp;
				}
			}
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			if (last != first)
			{
				vector range;
				while (first != last)
				{
					range.push_back(*first);
					first++;
				}
				size_type n = range.size();
				if (size_ + n <= capacity_)
				{
					for (size_type i = 0; i < n; i++)
						alloc.construct(&data_[i + size_], range.data_[i]);
					if (size_)
						std::rotate(position, this->end(), this->end() + n);
					size_ += n;
				}
				else
				{
					pointer tmp;
					size_type tmp_capacity = 0;
					if (size_ + n <= capacity_ * 2)
						tmp_capacity = capacity_ * 2;
					else
						tmp_capacity = size_ + n;
					tmp = alloc.allocate(tmp_capacity);
					size_type i = 0;
					if (size_)
					{
						// std::cout << "*****************" << std::endl;
						for (iterator it = this->begin(); it != position; it++)
						{
							this->alloc.construct(&tmp[i], *it);
							// std::cout << tmp[i] << std::endl;
							i++;
						}
						// std::cout << "*****************" << std::endl;
					}

					size_type j = 0;
					while (j < n)
					{
						alloc.construct(&tmp[i + j], range.data_[j]);
						// std::cout << tmp[i + j] << std::endl;
						j++;
					}
					// std::cout << "*****************" << std::endl;
					while (i < size_)
					{
						alloc.construct(&tmp[i + j], data_[i]);
						// std::cout << tmp[i + j] << std::endl;
						i++;
					}
					// std::cout << "*****************" << std::endl;
					size_type tmp_size = size();
					this->clear();
					if (data_)
						this->alloc.deallocate(data_, capacity_);
					size_ = n + tmp_size;
					capacity_ = tmp_capacity;
					data_ = tmp;
				}
			}
		}
		void assign(size_type n, const value_type &val)
		{
			this->clear();
			this->resize(n, val);
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{

			this->clear();
			if (first != last)
			{
				vector tmp(first, last);
				*this = tmp;
			}
		}
		iterator erase(iterator position)
		{
			if (size_)
			{
				iterator it = this->begin();
				while (position != it)
					it++;
				size_type i = it - this->begin();
				value_type tmp = data_[i];
				// shift all elements to the right
				for (size_type j = i; j < size_ - 1; j++)
					data_[j] = data_[j + 1];
				data_[size_ - 1] = tmp;
				this->pop_back();
			}
			return (position);
		}
		iterator erase(iterator first, iterator last)
		{
			pointer tmp;
			// size_type d = last - first;
			tmp = alloc.allocate(capacity_);
			iterator it = begin();
			size_type i = 0;
			while (it != end())
			{
				if (it == first)
				{
					while (it != last)
					{
						it++;
					}
					last = &tmp[i];
				}
				if (it != end())
				{
					alloc.construct(&tmp[i], *it);
					i++;
					it++;
				}
			}
			this->clear();
			if (data_)
				alloc.deallocate(data_, capacity_);
			size_ = i;
			data_ = tmp;
			return last;
		}
		allocator_type get_allocator() const { return this->alloc; }

	private:
		pointer data_;
		size_type size_;
		size_type capacity_;
		allocator_type alloc;
	};
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return 1;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return 1;
		}
		return 0;
	}

	template <class _T, class alloc_>
	void swap(vector<_T, alloc_> &v1, vector<_T, alloc_> &v2)
	{
		v1.swap(v2);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return 0;
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
			{
				if (lhs[i] > rhs[i])
					return 0;
			}
		}
		return 1;
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return 1;
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
			{
				if (lhs[i] > rhs[i])
					return 1;
			}
		}
		return 0;
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return 0;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return 0;
		}
		return 1;
	}
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return 0;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return 0;
		}
		return 1;
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return 1;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return 1;
		}
		return 0;
	}
}