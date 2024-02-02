#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include <string>

class Account{
public:
    Account(){}
    Account(std::string userName):userName(userName){}
    
    void setPassword(std::string password);
    void setSALT(std::string SALT);
    std::string getUserName();
    std::string getSALT();
    std::string getPassword();

private:
    std::string userName;
    std::string password;
    std::string SALT;
};

#endif //__ACCOUNT_H