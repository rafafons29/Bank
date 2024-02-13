#include "../include/Cuentas.hpp"

Cuentas::Cuentas(Cuenta &&acount) {
  acounts.push_back(acount);
  max_valance_acount = &*acounts.begin();
  max_account_bank += acount.get_valance();
}

void Cuentas::add_acount(Cuenta &&acount) {
  acounts.push_back(acount);
  acounts.sort([](Cuenta const &ac1, Cuenta const &ac2) {
    return ac1.get_valance() < ac2.get_valance();
  });

  for (auto &acount : acounts)
    if (acount.get_valance() > max_valance_acount->get_valance())
      max_valance_acount = &acount;

  max_account_bank += acount.get_valance();
}