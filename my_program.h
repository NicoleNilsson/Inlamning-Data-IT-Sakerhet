#ifndef __MY_PROGRAM_H
#define __MY_PROGRAM_H

#include "account.h"
#include <string>

class MyProgram{
public:
    MyProgram(){}
    void mainMenu();

private:
    enum returnCodes{
            USER_NAME_OK,
            USER_NAME_WRONG_FORMAT,
            PASSWORD_OK,
            PASSWORD_TOO_SHORT,
            NO_SPECIAL_CHARACTER,
            NO_DIGIT,
            NO_UPPER_CASE,
            NO_LOWER_CASE,
            LOG_IN_SUCCESS,
            // USER_FOUND,
            USER_NOT_FOUND,
            WRONG_PASSWORD,
    };

    #define MIN_PASSWORD_LENGTH 8
    #define SALT_LENGTH 16

    void createAccount();
    int verifyUserNameFormat(const std::string userName);
    void stringToLower(std::string &str);
    void createPassword(Account &account);
    int verifyPasswordFormat(const std::string password);
    std::string createSALT();
    std::string hashPassword(const std::string& input);
    void addToFile(Account account);
    void enterLogInDetails();
    int logIn(std::string userName, std::string password);
};



#endif //__MY_PROGRAM_H