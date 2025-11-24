#ifndef FILEHANDLER_H
#define FILEHANDLER_H//依旧是定义宏，如果没定义则定义它 
#include <string>
class FileHandler {   // 定义这个叫做FileHandler的类 
public:
	//读取文件中的内容 
    static bool readFile(const std::string& filename, std::string& content);
   // bool返回值：成功返回true，失败返回false
   // std::string& content：引用参数，用于返回读取的内容
   //filename：文件的地址、名称，告诉程序操作那个文件，content则是文件中的文本内容，以字符串的形式进行存储。 
   // 将字符串内容写入文件
    static bool writeFile(const std::string& filename, const std::string& content);
};

#endif
