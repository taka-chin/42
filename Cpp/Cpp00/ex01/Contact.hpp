#ifndef CPP00_EX01_Contact_H_
#define CPP00_EX01_Contact_H_

#include <string>

class Contact {
private:
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;

public:
  const std::string &getFirstName();
  const std::string &getLastName();
  const std::string &getNickName();
  const std::string &getPhoneNumber();
  const std::string &getDarkestSecret();
  void setFirstName(std::string first_name);
  void setLastName(std::string last_name);
  void setNickName(std::string nick_name);
  void setPhoneNumber(std::string phone_number);
  void setDarkestSecret(std::string darkest_secret);
};

#endif
