#pragma once

#include "tensor.hpp"

namespace hpsf {
namespace tensor {

template<std::size_t dimension, class Container>
class tensor<dimension, Container>::view
{
  public:
    using value_type = typename Container::value_type;
    using size_type  = typename Container::size_type;

  private:
    std::shared_ptr<tensor_iterator<dimension, Container>> iter;
    size_type                                              length;

  public:
    tensor_iterator<dimension, Container> begin() const;
    tensor_iterator<dimension, Container> end() const;
    value_type                            at(size_type) const;
};

template<std::size_t dimension, class Container>
inline tensor_iterator<dimension, Container>
tensor<dimension, Container>::view::begin() const
{
    return this->iter;
}

template<std::size_t dimension, class Container>
inline tensor_iterator<dimension, Container>
tensor<dimension, Container>::view::end() const
{
    return this->iter + length;
}

} // namespace tensor
} // namespace hpsf