#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

void PhoneBook::printMsg(int id) {
  std::cout << "Don’t have empty fields\n" << std::flush;
  switch (id) {
  case 1:
    std::cout << "First name: " << std::flush;
    break;
  case 2:
    std::cout << "Last name: " << std::flush;
    break;
  case 3:
    std::cout << "Nickname: " << std::flush;
    break;
  case 4:
    std::cout << "Phone number: " << std::flush;
    break;
  case 5:
    std::cout << "Darkest secret: " << std::flush;
    break;
  }
}

bool PhoneBook::isprintString(std::string str) {
  bool flag = true;

  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    if (!std::isprint(*it)) {
      flag = false;
      break;
    }
  }
  return (flag);
}

std::string PhoneBook::inputCheck(int id) {
  std::string buf;
  while (true) {
    std::getline(std::cin, buf);
    if (std::cin.eof())
      exit(1);
    if (!std::cin.good() || buf.empty() || !isprintString(buf))
      printMsg(id);
    else
      break;
  }
  return buf;
}

void PhoneBook::addContact(unsigned int index) {
  std::string buf;

  printMsg(1);
  buf = inputCheck(1);
  contacts[index].setFirstName(buf);

  printMsg(2);
  buf = inputCheck(2);
  contacts[index].setLastName(buf);

  printMsg(3);
  buf = inputCheck(3);
  contacts[index].setNickName(buf);

  printMsg(4);
  buf = inputCheck(4);
  contacts[index].setPhoneNumber(buf);

  printMsg(5);
  buf = inputCheck(5);
  contacts[index].setDarkestSecret(buf);
};

void PhoneBook::testSetContact(void) {
  int i = 0;
  while (i < 8) {
    contacts[i].setFirstName("testFisrtName");
    contacts[i].setLastName("testLastName");
    contacts[i].setNickName("testNiclName");
    contacts[i].setPhoneNumber("testPhoneNumber");
    contacts[i].setDarkestSecret("testDarkestSecret");
    i++;
  }
};

void PhoneBook::displayContactList(int index) {
  std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
  std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
  std::cout << "Nick name: " << contacts[index].getNickName() << std::endl;
  std::cout << "Phone number: " << contacts[index].getPhoneNumber()
            << std::endl;
  std::cout << "Darkest sercret: " << contacts[index].getDarkestSecret()
            << std::endl;
};

int PhoneBook::findIndex(void) {
  int index;

  index = 0;
  while (!contacts[index].getFirstName().empty()) {
    index++;
  }
  return index;
};

std::string PhoneBook::processContact(std::string buf) {
  if (buf.length() > 10)
    buf = buf.substr(0, 9) + ".";
  return buf;
}
void PhoneBook::printHeader() {
  std::cout << "|" << std::setw(10) << "Index" << std::flush;
  std::cout << "|" << std::setw(10) << "First name" << std::flush;
  std::cout << "|" << std::setw(10) << "Last name" << std::flush;
  std::cout << "|" << std::setw(10) << "Nick name" << std::flush;
  std::cout << "|" << std::endl << std::flush;
}

void PhoneBook::displayContactTable(unsigned int index) {
  std::string buf;

  unsigned int i = 0;
  if (index > 7)
    index = 8;
  printHeader();
  while (i < index) {
    std::cout << "|" << std::setw(10) << i << std::flush;
    buf = contacts[i].getFirstName();
    buf = processContact(buf);
    std::cout << "|" << std::setw(10) << buf << std::flush;
    buf = contacts[i].getLastName();
    buf = processContact(buf);
    std::cout << "|" << std::setw(10) << buf << std::flush;
    buf = contacts[i].getNickName();
    buf = processContact(buf);
    std::cout << "|" << std::setw(10) << buf << std::flush;
    std::cout << "|" << std::endl << std::flush;
    i++;
  }
}

void PhoneBook::searchContact() {
  int index = -1;
  while (true) {
    std::cout << "Please input index 0 to 7\n" << std::flush;
    std::cin >> index;
    if (std::cin.eof())
      exit(1);
    if (std::cin.good() && (index > -1 && index < 8))
      break;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  displayContactList(index);
}
