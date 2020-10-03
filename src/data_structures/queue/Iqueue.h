#ifndef DATA_STRUCTURES_QUEUE_I_QUEUE_H_
#define DATA_STRUCTURES_QUEUE_I_QUEUE_H_

namespace data_structures {

// Queue interface
template<typename T>
class IQueue {
 public:
  virtual void add(const T& elem) = 0;
  virtual T rem() = 0;
  virtual T& first() = 0;
  virtual int length() const = 0;
  virtual bool IsFull() const = 0;
  virtual bool IsEmpty() const = 0;
  virtual void SetEmpty() = 0;
  virtual ~IQueue() {}
};

} // namespace data_structures

#endif // DATA_STRUCTURES_QUEUE_I_QUEUE_H_