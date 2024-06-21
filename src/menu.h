
//==============================================================================
//
//   log.h - exported_h
//
//==============================================================================
//  guillaume plante <guillaume.plante@luminator.com>
//==============================================================================

#ifndef __MENU_H__
#define __MENU_H__

class ConsoleMenu {
public:
    ConsoleMenu() : lastWasInvalid(false), currentMenuPos(0){ }
    void displayMainMenu();
    void displaySubMenu();
    void mainMenuOption1();
    void mainMenuOption2();
    void mainMenuOption3();
    void subMenuOption1();
    void subMenuOption2();
    void subMenuOption3();
    void run();

private:
    void clearScreen();
    void setCursorPosition(int x, int y);
    void handleMainMenuInput(int choice);
    void handleSubMenuInput(int choice);

private:
    bool lastWasInvalid;
    int currentMenuPos;
};

#endif // __MENU_H__
