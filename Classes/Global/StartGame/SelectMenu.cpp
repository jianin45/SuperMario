//
//  SelectMenu.cpp
//  SuperMarry
//
//  Created by Hello,world! on 15/1/19.
//
//

#include "SelectMenu.h"

#include "MainMenu.h"
#include "GameLayer.h"

bool SelectMenu::init()
{
    log("SelectMenu %s",__func__);
    bool b_ret = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        
        current_page = 1;
        visible_size = Director::getInstance()->getWinSize();
        origin = Director::getInstance()->getVisibleOrigin();
        
        this->createBackground();
        this->createSelectLayer();
        this->createSceneItem();
        
        auto listen = EventListenerTouchOneByOne::create();
        listen->onTouchBegan     = CC_CALLBACK_2(SelectMenu::onTouchBegan, this);
        listen->onTouchMoved     = CC_CALLBACK_2(SelectMenu::onTouchMoved, this);
        listen->onTouchEnded     = CC_CALLBACK_2(SelectMenu::onTouchEnded, this);
        listen->onTouchCancelled = CC_CALLBACK_2(SelectMenu::onTouchCancelled, this);
        listen->setSwallowTouches(true);
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen, this);

        b_ret = true;
    } while (0);
    
    return b_ret;
}

void SelectMenu::menuCloseCallBack()
{
    log("Close callback!");
}

#pragma mark -选择关卡相关
void SelectMenu::onEnter()
{
    Layer::onEnter();
}

void SelectMenu::onExit()
{
    Layer::onExit();
}

bool SelectMenu::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    log("SelectMenu on touch begin!");
    return true;
}

void SelectMenu::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    
}

void SelectMenu::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    
}

void SelectMenu::onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    
}

#pragma mark -MenuItem

void SelectMenu::menuBegin(cocos2d::Ref *pSender)
{
    //后续会在这里处理与关卡有关的内容
    
    GameLayer* game_layer = GameLayer::getInstance();
    
    Scene* p_scene = Scene::create();
    p_scene->addChild(game_layer);
    
    Director::getInstance()->replaceScene(p_scene);
}

void SelectMenu::menuBack(cocos2d::Ref *pSender)
{
    MainMenu *main_menu = MainMenu::create();
    Scene *p_scene = Scene::create();
    p_scene->addChild(main_menu);
    Director::getInstance()->replaceScene(p_scene);
}


#pragma mark -pravite

void SelectMenu::createSceneItem()
{
    new_game = MenuItemImage::create("newgameA.png",
                                     "newgameB.png",
                                     CC_CALLBACK_1(SelectMenu::menuBegin, this));
    new_game->setPosition(Vec2(origin.x + visible_size.width/2, 30));
    
    back_game = MenuItemImage::create("backA.png", "backB.png",
                                      CC_CALLBACK_1(SelectMenu::menuBack, this));
    back_game->setPosition(Vec2(origin.x + 20, origin.y + visible_size.height - 20));
    
    Menu* menu = Menu::create(new_game,back_game,NULL);
    menu->setAnchorPoint(Size::ZERO);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,2);//
    
    m_level = Label::createWithSystemFont("Level: 1", "Arial", 20);
    //createWithTTF 不支持使用字体名称创建
    m_level->setPosition(Vec2(origin.x + visible_size.width/2,
                              origin.y + visible_size.height - 20));
    this->addChild(m_level,3);//
}


void SelectMenu::createSelectLayer()
{
    p_layer = Layer::create();
    __String* select_name = NULL;
    for (int i=current_page; i<=total_page; ++i)
    {
        select_name = __String::createWithFormat("select%d.jpg",i);
        Sprite* p_sprite = Sprite::create(select_name->getCString());
        p_sprite->setPosition(Vec2(visible_size.width*(i-0.5f),
                                   visible_size.height/2+10));
        p_layer->addChild(p_sprite,0,i);
    }
    p_layer->setContentSize(Size::Size(480*8, 320));
    this->addChild(p_layer,1);//
}

void SelectMenu::createBackground()
{
    Sprite *p_background = Sprite::create("bg.png");
    p_background->setPosition(Vec2(origin.x + visible_size.width/2,
                          origin.y + visible_size.height/2));
    this->addChild(p_background, 0);//
}






