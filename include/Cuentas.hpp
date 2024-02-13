#ifndef CUENTAS_HPP_
#define CUENTAS_HPP_

#include "Cuenta.hpp"

#include <list>

class Cuentas {
  using l_acounts = std::list<Cuenta>;
  l_acounts acounts;
  Cuenta *max_valance_acount{nullptr};
  double max_account_bank{0.0};

public:
  Cuentas(Cuenta &&);

  void add_acount(Cuenta &&);
  inline Cuenta const *get_max_valance_account() const {
    return max_valance_acount;
  }
  inline double const *get_max_account_bank() const {
    return &max_account_bank;
  }
  inline l_acounts::iterator begin() { return acounts.begin(); }
  inline l_acounts::iterator end() { return acounts.end(); }
};

#endif // CUENTAS_HPP_