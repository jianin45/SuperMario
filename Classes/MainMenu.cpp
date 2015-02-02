//
//  MainMenu.cpp
//  SuperMarry
//
//  Created by Hello,world! on 15/1/16.
//
//

#include "MainMenu.h"

#include "SelectMenu.h"

#include <iostream>
using namespace std;
using namespace placeholders;

MainMenu::MainMenu()
{
    log("MainMenu class construction!");
    
    Size win_size = Director::getInstance()->getWinSize();
    
    Sprite* background = Sprite::create("background.png");
    background->setPosition(Vec2(win_size.width/2,win_size.height/2));
    this->addChild(background);
    

    _start_game = MenuItemImage::create("startgame_normal.png", "startgame_select.png", CC_CALLBACK_0(MainMenu::menuCallBackForStartGame, this));
    _start_game->setPosition(Vec2(win_size.width/2,win_size.height/2));
    
    _menu = Menu::create(_start_game,NULL);
    _start_game = MenuItemImage::create("startgame_normal.png",
                                        "startgame_select.png",
                                        CC_CALLBACK_0(MainMenu::menuCallBackForStartGame,
                                                      this));
    _start_game->setPosition(Vec2(win_size.width/2,win_size.height/2));
    
    _quit_game = MenuItemImage::create("quitgame_normal.png",
                                       "quitgame_select.png",
                                       CC_CALLBACK_0(MainMenu::menuQuit,
                                                     this));
    _quit_game->setPosition(Vec2(win_size.width/2,win_size.height/2-40));
    
    _about_game = MenuItemImage::create("about_normal.png",
                                        "about_select.png",
                                        CC_CALLBACK_0(MainMenu::menuAboutGame,
                                                      this));
    _about_game->setPosition(win_size.width-50,20);
    
    _setting_game = MenuItemImage::create("Setting_n.png",
                                          "setting_s.png",
                                          CC_CALLBACK_0(MainMenu::menuSettingGame,
                                                        this));
    _setting_game->setPosition(Vec2(win_size.width/2,win_size.height/2-80));
    
    _menu = Menu::create(_start_game,_quit_game,_about_game,_setting_game,NULL);
    _menu->setPosition(Vec2(0, 0));
    this->addChild(_menu,0);
    
}

MainMenu::~MainMenu()
{
    log("MainMenu class destruction!");

}

bool MainMenu::init()
{
    log("MainMenu init!");
    
    bool b_ret = false;
    do {
        
        CC_BREAK_IF(!Layer::init());
    
        //this->setTouchEnabled(true);
        
        auto listen = EventListenerTouchOneByOne::create();
        listen->onTouchBegan     = CC_CALLBACK_2(MainMenu::onTouchBegan, this);
        listen->onTouchMoved     = CC_CALLBACK_2(MainMenu::onTouchMoved, this);
        listen->onTouchEnded     = CC_CALLBACK_2(MainMenu::onTouchEnded, this);
        listen->onTouchCancelled = CC_CALLBACK_2(MainMenu::onTouchCancelled, this);

//        listen->onTouchBegan     = [](Touch* p_touth,Event* p_event)
//        {
//            log("lambda began!");
//            return true;
//        };
        
        listen->setSwallowTouches(true);
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen, this);
        
        b_ret = true;
    } while (0);
    
    return b_ret;
}

void MainMenu::menuCallBackForStartGame()
{
    log("startgame menu call!");
    
    Scene* p_scene = Scene::create();
    p_scene->addChild(SelectMenu::create());
    Director::getInstance()->replaceScene(p_scene);
}

void MainMenu::menuQuit()
{
    log("Menu quit!");
}

void MainMenu::menuAboutGame()
{
    log("Menu about game!");
}

void MainMenu::menuSettingGame()
{
    log("Menu setting game!");
}

#pragma mark -TouchCallBack

bool MainMenu::onTouchBegan(Touch *touch, Event * pEvent)
{
    log("%s",__FUNCTION__);
    return true;
}

void MainMenu::onTouchEnded(Touch *touch, Event * pEvent)
{
    
}

void MainMenu::onTouchCancelled(Touch *touch, Event *pEvent)
{
    
}

void MainMenu::onTouchMoved(Touch *touch, Event *pEvent)
{
    
}


