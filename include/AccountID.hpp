#ifndef ACCOUNTID_HPP_
#define ACCOUNTID_HPP_

#include "ID.hpp"

#include <cstddef>
#include <cstring>

struct AccountID : ID {
  AccountID();
  AccountID(char const *id);
  ~AccountID();

  inline bool isInvalid(const char *id) override {
    return std::strlen(id) != (size - 1);
  }

private:
  static constexpr char const *ID_ERROR{"EL Id debe tener 16 caracteres"};
  const std::size_t size{17};
};

#endif // ACCOUNTID_HPP_