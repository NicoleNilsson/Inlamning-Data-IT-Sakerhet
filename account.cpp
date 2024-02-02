#include <string> 
#include "account.h"

void Account::setPassword(std::string password){
    this->password = password;
}
void Account::setSALT(std::string SALT){
    this->SALT = SALT;
}
std::string Account::getUserName(){
    return userName;
}
std::string Account::getSALT(){
    return SALT;
}
std::string Account::getPassword(){
    return password;
}
