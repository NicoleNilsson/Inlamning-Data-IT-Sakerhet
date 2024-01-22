// #include <iostream>
#include <string> 
// #include <fstream>
// #include <algorithm>
// #include <ranges>
// #include <iomanip>
// #include <openssl/evp.h>
// #include <openssl/md5.h>
// #include <regex>
// #include <cstdlib>
// #include <ctime>
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

// void Account::mainMenu(){
// 	while(1){
//         std::string atmChoice;
//         std::cout << "1. Create account." << std::endl
//                     << "2. Log in to account." << std::endl
//                     << "9. Exit." << std::endl;
//         std::getline(std::cin, atmChoice);

//         if(atmChoice == "1"){
//             createAccount();
//         }else if(atmChoice == "2"){
//             enterLogInDetails();
//         }else if(atmChoice == "9"){
//             break;
// 		}else{
//             std::cout << "Please enter 1, 2 or 9." << std::endl;
//         }
//     }
// }

// void Account::createAccount(){
//     std::string userName;
//     while(1){    
//         std::cout << "Enter e-mail or press 0 to go back to main menu: " << std::endl;
//         std::getline(std::cin, userName);

//         if(userName == "0"){
//             return;
//         }else if(verifyUserNameFormat(userName) == USER_NAME_WRONG_FORMAT){
//             std::cout << "Invalid e-mail format." << std::endl;
//             continue;
//         }else{
//             break;
//         }
//     }

//     //is this a stupid way to check if username is taken?
//     if(logIn(userName, "notARealPassword") != USER_NOT_FOUND){
//         std::cout << "There is already a user with user name " << userName << std::endl;
//         return;
//     }

//     Account account(userName);
//     createPassword(account);
//     std::cout << "Account created" << std::endl;
//     addToFile(account);
// }

// int Account::verifyUserNameFormat(const std::string userName){
//     //format = atLeasOneChar@atLeastOneChar.atLeastOneChar
//     std::regex pattern(".+@.+\\..+");
//     if(std::regex_match(userName, pattern)){
//         return USER_NAME_OK;
//     }else{
//         return USER_NAME_WRONG_FORMAT;
//     }
// }

// void Account::createPassword(Account &account){
//     std::string password;
//     std::cout << "Password needs to contain:" << std::endl 
//                 << "at least 8 characters" << std::endl
//                 << "at least one upper case letter" << std::endl 
//                 << "at least one lower case letter " <<std::endl
//                 << "at least one digit" << std::endl
//                 << "at least one special character" << std::endl 
//                 << std::endl;
    
//     loop: while(1){       
//         std::cout << "Enter password: " << std::endl;
//         std::getline(std::cin, password);

//         switch (verifyPasswordFormat(password)){
//             case PASSWORD_OK:
//                 break;
//             case PASSWORD_TOO_SHORT:
//                 std::cout << "Password need to be at least 8 characters" << std::endl;
//                 continue;
//             case NO_UPPER_CASE:
//                 std::cout << "Password need to contain at least one upper case letter." << std::endl;
//                 continue;
//             case NO_LOWER_CASE:
//                 std::cout << "Password need to contain at least one lower case letter." << std::endl;
//                 continue;
//             case NO_DIGIT:
//                 std::cout << "Password need to contain at least one digit." << std::endl;
//                 continue;
//             case NO_SPECIAL_CHARACTER:
//                 std::cout << "Password need to contain at least one special character" << std::endl;
//                 continue;
//         }
//         break;
//     }

//     account.SALT = createSALT();
//     account.password = hashPassword(password+account.SALT);
// }

// int Account::verifyPasswordFormat(const std::string password){
//     if(password.length() < MIN_PASSWORD_LENGTH){
//         return PASSWORD_TOO_SHORT;   
//     }

//     auto upperCase = std::any_of(password.begin(), password.end(), [](char c){
//         return isupper(c);
//     });
//     if(!upperCase){
//         return NO_UPPER_CASE;
//     }
//     auto lowerCase = std::any_of(password.begin(), password.end(), [](char c){
//         return islower(c);
//     });
//     if(!lowerCase){
//         return NO_LOWER_CASE;      
//     }
//     auto digit = std::any_of(password.begin(), password.end(), [](char c){
//         return isdigit(c);
//     });
//     if(!digit){
//         return NO_DIGIT;      
//     }
//     auto specialCharacter = std::any_of(password.begin(), password.end(), [](char c){
//         return !isdigit(c) && !isalpha(c);
//     });
//     if(!specialCharacter){
//         return NO_SPECIAL_CHARACTER;      
//     }

//     return PASSWORD_OK;
// }

// std::string Account::createSALT() {
//     const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?/{}[]";
//     std::srand(time(0));
//     int stringLength = characters.length();

//     std::string SALT;
//     for (int i = 0; i < SALT_LENGTH; ++i) {
//         SALT += characters[std::rand() % stringLength];
//     }

//     return SALT;
// }

// // 100% tog fram denna med chatGPT
// std::string Account::hashPassword(const std::string& input) {
//     MD5_CTX md5Context;
//     EVP_MD_CTX *mdctx = EVP_MD_CTX_new();

//     EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);
//     EVP_DigestUpdate(mdctx, input.c_str(), input.length());

//     unsigned char digest[MD5_DIGEST_LENGTH];
//     unsigned int md_len;

//     EVP_DigestFinal_ex(mdctx, digest, &md_len);
//     EVP_MD_CTX_free(mdctx);

//     std::stringstream ss;
//     for (unsigned int i = 0; i < md_len; i++) {
//         ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
//     }

//     return ss.str();
// }

// void Account::addToFile(Account account){
//     std::ofstream outFile("accounts.txt", std::ios::app);
//     outFile << account.userName + ":" + account.SALT + ":" + account.password << std::endl;
//     outFile.close();
// }

// void Account::enterLogInDetails(){
//     std::string userName;
//     std::string password;
//     std::cout << "Enter e-mail: " << std::endl;
//     std::getline(std::cin, userName);
//     std::cout << "Enter password: " << std::endl;
//     std::getline(std::cin, password);

//     int logInSatus = logIn(userName, password);

//     if(logInSatus == USER_NOT_FOUND){
//         std::string userInput;
//         std::cout << "There is no user " << userName << std::endl
//                     << "Would you like to create an account? (y/n)" << std::endl;
//         std::getline(std::cin, userInput);
//         if(userInput == "y"){
//             createAccount();
//         }else{
//             return;
//         }
//     }else if(logInSatus == WRONG_PASSWORD){
//         std::cout << "Wrong password." << std::endl;
//     }else if(logInSatus == LOG_IN_SUCCESS){
//         std::cout << "Logged in." << std::endl;
//     }
// }

// int Account::logIn(std::string userName, std::string password){
//     std::ifstream inFile("accounts.txt", std::ios::in);

//     std::string foundUserName;
//     std::string foundSALT;
//     std::string foundPassword;
//     std::string line;

//     while(inFile){
//         std::getline(inFile, foundUserName, ':');
//         if(foundUserName == userName){
//             std::getline(inFile, foundSALT, ':');
//             std::getline(inFile, foundPassword);

//             if(foundPassword == hashPassword(password+foundSALT)){
//                 return LOG_IN_SUCCESS;
//             }else{
//                 return WRONG_PASSWORD;
//             }
//         }
//         //reads rest of line if userName not a match
//         std::getline(inFile, line);
//     }
//     return USER_NOT_FOUND;
// }
