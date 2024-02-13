#include "../include/ClientID.hpp"

#include <memory>
#include <stdexcept>

ClientID::ClientID() { id_ = std::shared_ptr<char[]>(new char[size]); }

ClientID::ClientID(char const *id) {
  id_ = std::shared_ptr<char[]>(new char[size]);

  // Comprobamos que el char const *id contenga 11 caracteres.

  if (isInvalid(id))
    throw std::invalid_argument(ID_ERROR);

  // copiamos el id hacia id_
  std::strcpy(id_.get(), id);
}

ClientID::~ClientID() {}