#ifndef CUENTA_HPP_
#define CUENTA_HPP_

#include "AccountID.hpp"
#include "ClientID.hpp"

#include <ostream>
#include <string>

enum class ElectOperation { Withdraw, Deposit };

struct Cuenta {
  Cuenta(AccountID &&, ClientID &&, ElectOperation, float);
  ~Cuenta();

  inline void extract(float monto) { valance_acount_ -= monto; }
  inline void deposit(float monto) { valance_acount_ += monto; }
  inline float const get_valance() const { return valance_acount_; }

  friend std::ostream &operator<<(std::ostream &out, Cuenta &acount) {
    out << "Account ID: " << acount.account_id_.c_str() << '\n'
        << "Client ID: " << acount.client_id_.c_str() << '\n'
        << "Valance acount: " << acount.valance_acount_ << '\n';
    return out;
  }

private:
  AccountID account_id_;
  ClientID client_id_;
  ElectOperation withdraw_or_deposit_;
  float valance_acount_;
};

#endif // CUENTA_HPP_