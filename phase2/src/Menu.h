#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
    void showMainMenu();
    void handleUserInput();
    
private:
    void textEncryption();
    void textDecryption();
    void fileEncryption();
    void fileDecryption();
    
    int getIntInput(const std::string& prompt);
    std::string getStringInput(const std::string& prompt);
};

#endif
