//
//  MainMenu.h
//  SuperMarry
//
//  Created by Hello,world! on 15/1/16.
//
//

#ifndef __SuperMarry__MainMenu__
#define __SuperMarry__MainMenu__

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

class MainMenu : public Layer
{
    
public:
    MainMenu();
    ~MainMenu();
    
    Menu* _menu;
    MenuItem* _start_game;
    
    
    
    bool init();
    
    CREATE_FUNC(MainMenu);
    
protected:

    MenuItem* _quit_game;
    MenuItem* _about_game;
    MenuItem* _setting_game;
    
protected:
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);
    
protected:
    void menuCallBackForStartGame();
    void menuQuit();
    void menuAboutGame();
    void menuSettingGame();
    
    
private:
    
};

#endif /* defined(__SuperMarry__MainMenu__) */
