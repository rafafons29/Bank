#include "../include/AccountID.hpp"

#include <memory>
#include <stdexcept>

AccountID::AccountID() { id_ = std::shared_ptr<char[]>(new char[size]); }

AccountID::AccountID(char const *id) {
  id_ = std::shared_ptr<char[]>(new char[size]);

  // Comprobamos que el char const *id contenga 11 caracteres.

  if (isInvalid(id))
    throw std::invalid_argument(ID_ERROR);

  // copiamos el id hacia id_
  std::strcpy(id_.get(), id);
}

AccountID::~AccountID() {}