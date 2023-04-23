#pragma once

#include "tensor.hpp"

namespace hpsf {
namespace tensor {

template<std::size_t dimension, class Container>
class tensor<dimension, Container>::iterator
{
  private:
    using container_iterator       = typename Container::iterator;
    using const_container_iterator = typename Container::iterator;
    container_iterator* ptr;

  public:
    iterator(container_iterator* ptr)
      : ptr(ptr){};

    iterator operator++()
    {
        this->ptr += dimension;
        return *this;
    }

    iterator operator++(int)
    {
        ++this;
        return *this;
    }

    iterator operator+(int steps)
    {
        this->ptr += steps * dimension;
        return *this;
    }

    bool operator!=(const iterator& other) const
    {
        return this->ptr != other.ptr;
    }

    std::shared_ptr<tensor_view<dimension, Container>> operator*() const
    {
        return std::make_shared<tensor_view<dimension, Container>>(
          tensor_view<dimension, Container>(this)
        );
    };
};
} // namespace tensor
} // namespace hpsf