//
//  SelectMenu.h
//  SuperMarry
//
//  Created by Hello,world! on 15/1/19.
//
//

#ifndef __SuperMarry__SelectMenu__
#define __SuperMarry__SelectMenu__

#include <stdio.h>
USING_NS_CC;

class SelectMenu : public Layer
{
    
public:
    virtual bool init();
    CREATE_FUNC(SelectMenu);
    void menuCloseCallBack();
    
public:
    MenuItem* new_game;
    MenuItem* back_game;
    Label* m_level;
    
    void menuBegin(Ref *pSender);
    void menuBack(Ref *pSender);
    
public:
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);
    
protected:
    
private:
    int current_page;
    const int total_page = 8;
    Layer* p_layer;
    
    Size visible_size;
    Point origin;
    
    void createSelectLayer();
    void createBackground();
    void createSceneItem();
};

#endif /* defined(__SuperMarry__SelectMenu__) */











