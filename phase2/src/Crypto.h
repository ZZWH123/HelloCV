//Crypto.h
#ifndef CRYPTO_H
#define CRYPTO_H         //定义宏
#include <string>
class Crypto{            //定义Crypto这个类 
public：                 //用XOR加密解密 
    static std::string XORCipher(const std::string& input,char key);
    };
#endif     
