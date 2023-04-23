#pragma once

#include <vector>
#include <memory>

namespace hpsf {

namespace tensor {

template<std::size_t dimension, class Container = std::vector<double>>
class tensor final
{
  public:
    using value_type      = typename Container::value_type;
    using reference       = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type       = typename Container::size_type;
    using container_type  = Container;

    class offset;
    class view;
    class iterator;

  private:
    Container               c;
    std::unique_ptr<offset> l1 = nullptr;
    std::unique_ptr<offset> l2 = nullptr;
    std::unique_ptr<offset> l3 = nullptr;

  public:
    tensor()                    = default; // default constructor
    tensor(tensor&)             = default; // copy constructor
    tensor(tensor&&)            = default; // move constructor
    tensor& operator=(tensor&)  = default; // copy assignment operator
    tensor& operator=(tensor&&) = default; // move assignment operator
    ~tensor()                   = default; // destructor

    iterator        begin() noexcept;
    iterator        end() noexcept;

    size_type       size() const noexcept;
    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;
};

template<std::size_t dimension, typename Container>
using tensor_offset = typename tensor<dimension, Container>::offset;

template<std::size_t dimension, class Container>
using tensor_view = typename tensor<dimension, Container>::view;

template<std::size_t dimension, typename Container>
using tensor_iterator = typename tensor<dimension, Container>::iterator;

} // namespace tensor
} // namespace hpsf