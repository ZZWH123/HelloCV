#include "Crypto.h"
std::string Crypto::XORCipher(const std::string&input,char key){
	std::string output =input; //创建与输入相同大小的字符串 
	for(size_t i=0;i<input.length();++i){
		output[i]=input[i]^key;//每个字符都与同一个密钥数字进行XOR 
	}
	return output;
}
