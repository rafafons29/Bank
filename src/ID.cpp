#include "../include/ID.hpp"

#include <stdexcept>

bool ID::operator==(char const *id) {
  // Sobrecarga del operador de igualdad para hacer comprobaciones
  if (std::strlen(id_.get()) == std::strlen(id))
    for (std::size_t i{0}; i < std::strlen(id_.get()); i++)
      if (id_[i] != id[i])
        return false;

  return true;
}

bool ID::operator==(ID const &id) {
  if (std::strlen(id_.get()) == std::strlen(id.id_.get()))
    for (std::size_t i{0}; i < std::strlen(id_.get()); i++)
      if (id_[i] != id.id_[i])
        return false;

  return true;
}

char ID::operator[](std::size_t index) {
  // Sobrecarga del operador [], para acceder a un elemento por su indice.
  return id_[index];
}

char const *ID::c_str() { return id_.get(); }
