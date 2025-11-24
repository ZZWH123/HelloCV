#include "FileHandler.h"
#include <fstream>  // 文件流库
#include <iostream> // 引入输入输出流，用于错误提示

bool FileHandler::readFile(const std::string& filename, std::string& content) {
    std::ifstream file(filename);  // 创建输入文件流对象ifstream，打开文件
    
    if (!file.is_open()) {  // 检查文件是否成功打开，若没打开则输出错误 如下 
        std::cerr << "错误：无法打开文件 " << filename << std::endl;
        return false;
    }
    std::string line; // 读取文件内容到字符串
    content = "";     // 清空内容字符串
    while (std::getline(file, line)) {  // 逐行读取
        content += line + "\n";  // 将每行内容添加到结果中
    }      //注：使用"\n"能让最后的输出保持原来的结构即一行是一行，因为getline会去掉换行符 
	       // 添加后能够做到在写入时的写入文件与原文件的格式一样 
    
    file.close();  // 关闭文件
    return true;   // 读取成功
}

bool FileHandler::writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);  // 创建输出文件流对象ofstream 
    
    if (!file.is_open()) {
        std::cerr << "错误：无法创建文件 " << filename << std::endl;
        return false;
    }//与上面的打开文件成功与否确认类似 
    
    file << content;  // 将内容写入文件
    file.close();
    return true;
}
