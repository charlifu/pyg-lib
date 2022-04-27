#pragma once

#include <ATen/ATen.h>

template <typename scalar_t>
inline scalar_t randint(scalar_t low, scalar_t high) {
  // TODO Avoid explicit tensor creation.
  const auto dtype = c10::CppTypeToScalarType<scalar_t>::value;
  const auto options = at::TensorOptions().dtype(dtype);
  const auto rand = at::randint(low, high, {1}, options);
  return rand.template data_ptr<scalar_t>()[0];
}

template <typename scalar_t>
inline scalar_t randint(scalar_t high) {
  return randint<scalar_t>(0, high);
}