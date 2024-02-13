#include "../include/AccountID.hpp"
#include "../include/ClientID.hpp"
#include "../include/Cuenta.hpp"
#include "../include/Cuentas.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

void menu();

int main() {
  try {
    Cuentas accounts{Cuenta(AccountID("1234567890896745"),
                            ClientID("12345678909"), ElectOperation::Deposit,
                            5000)};
    accounts.add_acount(Cuenta(AccountID("9087654321432156"),
                               ClientID("02102979929"),
                               ElectOperation::Withdraw, 1000));

    for (auto &acc : accounts)
      std::cout << acc << '\n';

    std::cout << "Cuenta con el mayor saldo: "
              << accounts.get_max_valance_account()->get_valance() << '\n';
    std::cout << "Dinero total del banco: " << *accounts.get_max_account_bank()
              << '\n';
  } catch (std::invalid_argument const &e) {
    std::cerr << e.what();
  }

  // menu();
}