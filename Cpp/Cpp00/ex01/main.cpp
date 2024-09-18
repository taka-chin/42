#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
  std::string command;
  PhoneBook phoneBook;
  Contact contact;
  unsigned int count = 0;

  while (true) {
    std::getline(std::cin, command);
    if (std::cin.eof())
      exit(1);
    if (command == "ADD") {
      phoneBook.addContact(count % 8);
      count++;
    }
    if (command == "SEARCH") {
      phoneBook.displayContactTable(count);
      phoneBook.searchContact();
    }
    if (command == "EXIT")
      break;
  }
  return (0);
}
