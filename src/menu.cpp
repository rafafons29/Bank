#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <string_view>

bool valid_input(std::string const &str) {
  for (char c : str) {
    if (!std::isdigit(c))
      return false;
  }
  return true;
}

bool end_menu(std::string &str) {
  constexpr static char const *END{"SALIR"};
  std::for_each(str.begin(), str.end(), [](char &c) { c = std::toupper(c); });
  return (std::strcmp(END, str.c_str()) != 0);
}

void menu() {
  constexpr static char const *OPTIONS{
      "1. Mostrar saldos finales en orden ascendente.\n"
      "2. Determinar cuenta con el mayor saldo.\n"
      "3. Visualizar datos de una cuenta especifica.\n"
      "4. Mostrar todo el dinero depositado en el banco.\n"
      "Digite la opcion que desea, para terminar el programa teclee la "
      "palabra 'Salir'\n"};
  constexpr static char const *INVALID_OPTION{"Opcion no valida"};

  std::string option;

  do {
    std::cout << OPTIONS << '\n';
    std::getline(std::cin >> std::ws, option);
    if (!valid_input(option)) {
      std::cout << INVALID_OPTION << '\n';
    }
  } while (end_menu(option));
}