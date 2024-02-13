#ifndef ID_HPP_
#define ID_HPP_

#include <cstdio>
#include <cstring>
#include <memory>

struct ID {
  bool operator==(char const *id);
  bool operator==(ID const &id);
  char operator[](std::size_t);
  char const *c_str();

  virtual inline bool isInvalid(const char *id) = 0;

protected:
  std::shared_ptr<char[]> id_;
};

#endif // ID_HPP_