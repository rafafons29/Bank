#include "../include/Cuenta.hpp"

Cuenta::Cuenta(AccountID &&account_id, ClientID &&client_id,
               ElectOperation withdraw_or_deposit, float valance_acount)
    : account_id_(account_id), client_id_(client_id),
      withdraw_or_deposit_(withdraw_or_deposit),
      valance_acount_(valance_acount) {}

Cuenta::~Cuenta() {}
