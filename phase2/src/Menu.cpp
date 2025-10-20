#include "Menu.h"           // 包含自定义的Menu类声明
#include "Crypto.h"         // 包含加密算法类
#include "FileHandler.h"    // 包含文件处理类
#include <iostream>         // 输入输出流库（cout, cin等）
#include <limits>           // 数值限制库（用于处理输入验证）

// 显示主菜单的方法实现
void Menu::showMainMenu() {
    // 使用cout输出菜单界面
    // \n 表示换行，std::endl 也是换行但会刷新输出缓冲区
    std::cout << "\n=== XOR文本加密解密工具 ===" << std::endl;
    std::cout << "1. 文本加密" << std::endl;      // 选项1：文本加密功能
    std::cout << "2. 文本解密" << std::endl;      // 选项2：文本解密功能  
    std::cout << "3. 文件加密" << std::endl;      // 选项3：文件加密功能
    std::cout << "4. 文件解密" << std::endl;      // 选项4：文件解密功能
    std::cout << "5. 退出" << std::endl;          // 选项5：退出程序
    std::cout << "请选择功能 (1-5): ";            // 提示用户输入选择
}
//该部分是 菜单的显示，通过5个数字对应不同的功能，清晰直观。

// 处理用户输入的主循环方法
void Menu::handleUserInput() {
    int choice = 0;  // 定义变量存储用户选择，初始化为0
    while (true) {  //因为是true所以构成无限循环，能够一直运行，直至按照菜单输入5退出 
        showMainMenu();          // 每次循环先显示菜单
        choice = getIntInput(""); // 调用getIntInput方法获取用户输入的整数
        
        // switch case 进行选择，输入不同的数字对应进行不同的功能 
        switch (choice) {
            case 1: 
                textEncryption();  // 如果输入1，调用文本加密方法
                break;            // 跳出switch，继续循环显示菜单
            case 2: 
                textDecryption();  // 如果输入2，调用文本解密方法
                break;   
            case 3: 
                fileEncryption();  // 如果输入3，调用文件加密方法
                break;
            case 4: 
                fileDecryption();  // 如果输入4，调用文件解密方法
                break;                
            case 5: 
                // 用户选择退出，显示告别信息
                std::cout << "感谢使用" << std::endl;
                return;  // 直接退出整个函数，结束程序                
            default:
                // 如果输入不是1-5，提示错误并重新循环
                std::cout << "选择错误，请重新输入！" << std::endl;
        }
    }
}
// 获取整数输入的工具方法（getIntput上文提到的获取用户输入的整数）以及错误处理 
int Menu::getIntInput(const std::string& prompt) {
    int value;  // 用于存储用户输入的整数
    while (true) {  //因为一定要是1~5范围内的整数程序才能继续进行，故也是一个无限循环 
        // 如果提示信息不为空，就显示提示（依旧没看懂，照搬的） 
        if (!prompt.empty()) {
            std::cout << prompt;
        }
        
		//（这块当时真没咋看懂，直接照搬的AI） 
        // 尝试从标准输入读取整数到value变量
        // std::cin >> value 会返回流的状态，成功读取为true，失败为false
        if (std::cin >> value) {
            std::cin.ignore();  // 清除输入缓冲区中的换行符或其他残留字符
            break;              // 输入成功，跳出循环
        } 
        else {
            // 输入失败（用户输入了非数字字符）
            std::cout << "输入错误，请输入数字: ";            
            // 清除cin的错误状态标志（比如用户输入字母导致的错误状态）
            std::cin.clear();            
            // 忽略缓冲区中的所有无效字符，直到遇到换行符
            // std::numeric_limits<std::streamsize>::max() 是最大可能的字符数
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;  // 返回用户输入的有效整数
}

//这块没咋懂  AI这部分给的解释 
//错误处理机制详解：
//用户可能输入字母、符号等非数字内容
//std::cin >> value失败时会进入错误状态
//std::cin.clear()清除错误状态，让cin恢复正常
//std::cin.ignore()清空缓冲区，避免无效字符影响后续输入
//循环确保必须输入有效数字才能继续

//之后就是相应的获取输入以及对应1~4四个数字对应功能代码 

// 获取字符串输入的工具方法
std::string Menu::getStringInput(const std::string& prompt) {
    std::string input;        // 创建空字符串存储输入
    std::cout << prompt;      // 显示提示信息
    std::getline(std::cin, input);  // 读取整行输入（包括空格）
    return input;             // 返回用户输入的字符串
}

// 文本加密功能实现（1） 
void Menu::textEncryption() {
    // 获取用户要加密的文本
    std::string text = getStringInput("请输入要加密的文本: ");   
    // 获取数字密钥（0-255之间的整数）
    int key = getIntInput("请输入数字密钥 (0-255): ");    
    // 调用加密函数进行XOR加密
    std::string encrypted = Crypto::xorWithNumber(text, key);
    // 显示加密结果
    std::cout << "加密结果: " << encrypted << std::endl;
}

// 文本解密功能实现  （2） 
void Menu::textDecryption() {
    // 获取要解密的文本（应该是加密后的密文）
    std::string text = getStringInput("请输入要解密的文本: ");  
    // 获取相同的数字密钥（必须与加密时相同）
    int key = getIntInput("请输入数字密钥: ");
    // XOR加密和解密使用同一个函数！
    std::string decrypted = Crypto::xorWithNumber(text, key);
    // 显示解密结果
    std::cout << "解密结果: " << decrypted << std::endl;
}

// 文件加密功能实现（3） 
void Menu::fileEncryption() {
    // 获取要加密的文件路径
    std::string inputFile = getStringInput("请输入要加密的文件路径: ");
    // 获取数字密钥
    int key = getIntInput("请输入数字密钥 (0-255): ");
    // 获取加密后文件的保存路径
    std::string outputFile = getStringInput("请输入加密后文件的保存路径: ");
    std::string content;  // 用于存储文件内容
    // 尝试读取文件，FileHandler::readFile返回bool表示成功与否
    if (FileHandler::readFile(inputFile, content)) {
        // 读取成功，进行加密
        std::string encrypted = Crypto::xorWithNumber(content, key);
        
        // 尝试保存加密后的文件
        if (FileHandler::writeFile(outputFile, encrypted)) {
            std::cout << "文件加密成功！结果已保存到: " << outputFile << std::endl;
        } else {
            std::cout << "文件保存失败！" << std::endl;
        }
    } else {
        // 文件读取失败
        std::cout << "文件读取失败！请检查文件路径是否正确。" << std::endl;
    }
}
// 文件解密功能实现（4） 
void Menu::fileDecryption() {
    // 获取要解密的文件路径（应该是加密后的文件）
    std::string inputFile = getStringInput("请输入要解密的文件路径: ");
    // 获取相同的数字密钥
    int key = getIntInput("请输入数字密钥: ");
    // 获取解密后文件的保存路径
    std::string outputFile = getStringInput("请输入解密后文件的保存路径: ");
    std::string content;  // 用于存储文件内容
    // 读取加密文件
    if (FileHandler::readFile(inputFile, content)) {
        // 使用相同的XOR函数进行解密
        std::string decrypted = Crypto::xorWithNumber(content, key);       
        // 保存解密后的文件
        if (FileHandler::writeFile(outputFile, decrypted)) {
            std::cout << "文件解密成功！结果已保存到: " << outputFile << std::endl;
        } else {
            std::cout << "文件保存失败！" << std::endl;
        }
    } else {
        std::cout << "文件读取失败！请检查文件路径是否正确。" << std::endl;
    }
}




 
