#include "Contact.hpp"

const std::string &Contact::getFirstName() { return first_name_; }

const std::string &Contact::getLastName() { return last_name_; }

const std::string &Contact::getNickName() { return nick_name_; }

const std::string &Contact::getPhoneNumber() { return phone_number_; }

const std::string &Contact::getDarkestSecret() { return darkest_secret_; }

void Contact::setFirstName(std::string first_name) { first_name_ = first_name; }

void Contact::setLastName(std::string last_name) { last_name_ = last_name; }

void Contact::setNickName(std::string nick_name) { nick_name_ = nick_name; }

void Contact::setPhoneNumber(std::string phone_number) {
  phone_number_ = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
  darkest_secret_ = darkest_secret;
}
