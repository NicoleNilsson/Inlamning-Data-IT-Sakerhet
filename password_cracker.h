#ifndef __PASSWORD_CRACKER_H
#define __PASSWORD_CRACKER_H

#include <string>

void defNotHackerMenu();
void matchPassword(const std::string hash, int algorithm);

void spicySetUp();
std::string MD5Hash(const std::string& input);
std::string SHA256Hash(const std::string& input);
void MD5HashFile();
void SHA256HashFile();


#endif //__PASSWORD_CRACKER_H