template <typename T>
class MyContainer {
 public:
  // ... container members and methods go here ...

  class Iterator {
   public:
    Iterator(T* ptr) : ptr_(ptr) {}

    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

    Iterator& operator++() {
      ++ptr_;
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp(*this);
      ++ptr_;
      return tmp;
    }

    Iterator& operator--() {
      --ptr_;
      return *this;
    }

    Iterator operator--(int) {
      Iterator tmp(*this);
      --ptr_;
      return tmp;
    }

    Iterator operator+(int i) const { return Iterator(ptr_ + i); }
    Iterator operator-(int i) const { return Iterator(ptr_ - i); }

    bool
