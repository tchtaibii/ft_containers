iterator insert(iterator position, const value_type &val)
{
    this->insert(position, 1, val);
    return (++position);
}
void insert(iterator position, size_type size, const value_type &val)
{
    iterator it = this->begin();
    if (this->size_ + size >= this->capacity_)
        this->reserve(this->size_ + size);
    size_type i = 0;
    while (it != position)
    {
        ++it;
        ++i;
    }
    // std::memmove
    for (size_type j = this->size_; j >= 1 && j >= i; j--)
        this->alloc.construct(i + j + size - 1, this->m_container[j - 1]);
    for (size_type j = 0; j < size; j++)
        this->alloc.construct(i + j, val);
    this->size_ += size;
}
void insert(iterator position, iterator first, iterator last)
{
    size_type size = last - first;
    iterator it = this->begin();
    if (this->size_ + size >= this->capacity_)
        this->reserve(this->size_ + size);
    size_type i = 0;
    while (it != position)
    {
        ++it;
        ++i;
    }
    // std::memmove
    for (size_type j = this->size_ - 1; j > i + 1; j++)
        this->alloc.construct(i + j + size, this->m_container[+j - 1]);
    for (size_type j = 0; j < size; j++)
        this->alloc.construct(i + j, *first++);
    this->size_ += size;
}