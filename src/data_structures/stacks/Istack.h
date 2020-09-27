#ifndef DATA_STRUCTURES_I_STACK_H_
#define DATA_STRUCTURES_I_STACK_H_

namespace data_structures {

template <typename T>
class IStack {
 public:
  virtual ~IStack() {}
  virtual void push(T elem) = 0;
  virtual T& pop() = 0;
  virtual T& top() = 0;
  virtual bool IsEmpty() const = 0;
  virtual bool IsFull() const = 0;
  virtual void SetEmpty() = 0;
};

} // namespace data_structures



#endif // DATA_STRUCTURES_I_STACK_H_
