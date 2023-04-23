#pragma once

#include "tensor.hpp"

namespace hpsf {
namespace tensor {

template<std::size_t dimension, class Container>
class tensor<dimension, Container>::offset
{};

} // namespace tensor
} // namespace hpsf