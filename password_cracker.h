#ifndef __PASSWORD_CRACKER_H
#define __PASSWORD_CRACKER_H

#include <string>

enum hashMethod{
    USE_SHA256,
    USE_MD5
};

void defNotHackerMenu();
void matchPassword(const std::string hash, int algorithm);

std::string MD5Hash(const std::string& input);
std::string SHA256Hash(const std::string& input);
void MD5HashFile();
void SHA256HashFile();

void spicySetUp();


#endif //__PASSWORD_CRACKER_H