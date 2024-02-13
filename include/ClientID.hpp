#ifndef CLIENTID_CPP_
#define CLIENTID_CPP_

#include "ID.hpp"

#include <cstddef>

struct ClientID : ID {
  ClientID();
  ClientID(char const *);
  ~ClientID();

  inline bool isInvalid(const char *id) override {
    return std::strlen(id) != (size - 1);
  }

private:
  static constexpr char const *ID_ERROR{"EL Id debe tener 11 caracteres"};
  const std::size_t size{12};
};

#endif // CLIENTID_CPP_