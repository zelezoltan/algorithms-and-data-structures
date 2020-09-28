#ifndef DATA_STRUCTURES_QUEUE_DYNAMIC_QUEUE
#define DATA_STRUCTURES_QUEUE_DYNAMIC_QUEUE

#include "fixed_queue.hpp"

namespace data_structures {

template <typename T>
class DynamicQueue : public FixedQueue<T> {
 public:
  DynamicQueue(int size) : FixedQueue<T>::FixedQueue(size) {}
  DynamicQueue() {};
  void add(T elem) override;
  bool IsFull() const override { return false; }
};

template <typename T>
void DynamicQueue<T>::add(T elem) {
  if (this->length_ == this->size_) {
    T* new_arr = this->size_ == 0 ? new T[1] : new T[2*this->size_];
    for (int i = 0; i < this->length_; ++i) {
      new_arr[i] = this->arr_[this->start_ind_];
      this->start_ind_ = (this->start_ind_ + 1) % this->size_;
    }
    this->size_ = this->size_ == 0 ? 1 : this->size_ * 2;
    delete[] this->arr_;
    this->arr_ = new_arr;
    this->start_ind_ = 0;
  }
  this->arr_[(this->start_ind_ + this->length_) % this->size_] = elem;
  ++this->length_;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_QUEUE_DYNAMIC_QUEUE
