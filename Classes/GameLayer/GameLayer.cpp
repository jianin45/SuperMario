//
//  GameLayer.cpp
//  SuperMarry
//
//  Created by Hello,world! on 15/1/28.
//
//

#include "GameLayer.h"

#include "Global.h"
#include "GameMap.h"
#include "Hero.h"

enum class TouchesStatement
{
    begin,
    end
};//触摸过程的状态

GameLayer::GameLayer():

//地图初始化
main_map(nullptr),map_size(Size::ZERO),map_beginPos(Vec2(0.0f,96.0f)),

//英雄初始化
hero(nullptr),hero_size(Vec2(0,0)),birth_pos(Vec2(20.0f,32.0f)),
move_offset(2.0f),

//按键初始化
pos_LOR(Vec2(84, 48)),pos_leftkey(Vec2(40, 48)),pos_rightkey(Vec2(128, 48)),
pos_jumpkey(Vec2(432,35)),pos_firekey(Vec2(353, 35)),
pos_setkey(Vec2(260,33))
//

{
    main_layer = Layer::create();
    main_layer->retain();
    
    win_size = Director::getInstance()->getWinSize();
    win_middle = Vec2(win_size.width/2, win_size.height/2);
    
}

GameLayer::~GameLayer()
{
    this->unscheduleUpdate();
}

bool GameLayer::init()
{
    log("进入游戏界面！");
    
    this->initHeroAndMap();
    
    this->initControlUI();
    
    this->initKeyRect();
    
    
    
    this->addTouchListener();
    
    this->scheduleUpdate();
    
    return true;
}

void GameLayer::update(float dt)
{
    Point pos_mapCurrent = main_map->getPosition();
    
    //更新控制器
    this->updateControl();
}

void GameLayer::updateControl()
{
    if (isDown_leftkey)
    {
        image_LOR->setDisplayFrame(frame_LOR_left);
        hero->setHeroState(MarioState::eLeft);
        
        hero->setPosition(Vec2(hero->getPosition().x-move_offset, hero->getPosition().y));
        main_map->setPosition(Vec2(main_map->getPosition().x+20, main_map->getPosition().y));
    }
    else if (isDown_rightkey)
    {
        image_LOR->setDisplayFrame(frame_LOR_right);
        hero->setHeroState(MarioState::eRight);
        
        hero->setPosition(Vec2(hero->getPosition().x+move_offset, hero->getPosition().y));
        main_map->setPosition(Vec2(main_map->getPosition().x-20, main_map->getPosition().y));
    }
    else if (isDown_jumpkey)
    {
        image_jump->setDisplayFrame(frame_AB_selected);
        
        hero->setPosition(win_middle);
    }
    else if (isDown_firekey)
    {
        image_fire->setDisplayFrame(frame_AB_selected);
        
        hero->setPosition(birth_pos);
    }
}


#pragma mark -Touch

void GameLayer::disposeTouches(const std::vector<Touch*>& touches, TouchesStatement state)
{
    for(auto& it:touches)
    {
        Touch* touch = (Touch*)it;
        Point pos_touch = touch->getLocation();
        if (rect_leftkey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_leftkey = true;
                    break;
                case TouchesStatement::end:
                {
                    isDown_leftkey = false;
                    image_LOR->setDisplayFrame(frame_LOR_normal);
                    hero->setHeroState(MarioState::eNormalLeft);
                }
                default:
                    break;
            }
        }
        else if (rect_rightkey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_rightkey = true;
                    break;
                case TouchesStatement::end:
                {
                    isDown_rightkey = false;
                    image_LOR->setDisplayFrame(frame_LOR_normal);
                    hero->setHeroState(MarioState::eNormalRight);
                }
                default:
                    break;
            }
        }
        else if (rect_jumpkey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_jumpkey = true;
                    break;
                case TouchesStatement::end:
                {
                    isDown_jumpkey = false;
                    image_jump->setDisplayFrame(frame_AB_normal);
                }
                default:
                    break;
            }
        }
        else if (rect_firekey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_firekey = true;
                    break;
                case TouchesStatement::end:
                    isDown_firekey = false;
                    image_fire->setDisplayFrame(frame_AB_normal);
                default:
                    break;
            }
        }
    }
}

void GameLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    this->disposeTouches(touches, TouchesStatement::begin);
}

//移动时，不是长按
void GameLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
    log("我说，放…… …… …… ……开!");
    
}

void GameLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
    this->disposeTouches(touches, TouchesStatement::end);
}

void GameLayer::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
    log("touch cancel 是怎么一回事？");
}



#pragma mark -Pravite(部分)

void GameLayer::addTouchListener()
{
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(GameLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(GameLayer::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(GameLayer::onTouchesEnded, this);
    listener->onTouchesCancelled = CC_CALLBACK_2(GameLayer::onTouchesCancelled, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameLayer::initKeyRect()
{
    rect_leftkey = Rect(pos_leftkey.x-menu_leftkey->getContentSize().width/2,
                        pos_leftkey.y-menu_leftkey->getContentSize().height/2,
                        menu_leftkey->getContentSize().width,
                        menu_leftkey->getContentSize().height);
    rect_rightkey = Rect(pos_rightkey.x-menu_rightkey->getContentSize().width/2,
                         pos_rightkey.y-menu_rightkey->getContentSize().height/2,
                         menu_rightkey->getContentSize().width,
                         menu_rightkey->getContentSize().height);
    rect_firekey = Rect(pos_firekey.x-menu_firekey->getContentSize().width/2,
                        pos_firekey.y-menu_firekey->getContentSize().height/2,
                        menu_firekey->getContentSize().width,
                        menu_firekey->getContentSize().height);
    rect_jumpkey = Rect(pos_jumpkey.x-menu_jumpkey->getContentSize().width/2,
                        pos_jumpkey.y-menu_jumpkey->getContentSize().height/2,
                        menu_jumpkey->getContentSize().width,
                        menu_jumpkey->getContentSize().height);
}

void GameLayer::initControlUI()
{
    controlUI = Sprite::create("controlUI.png");
    controlUI->setAnchorPoint(Vec2(0,0));
    
    frame_LOR_normal = SpriteFrame::create("backKeyImage.png", Rect(0, 0, 72, 72));
    frame_LOR_left = SpriteFrame::create("backKeyLeft.png", Rect(0, 0, 72, 72));
    frame_LOR_right = SpriteFrame::create("backKeyRight.png", Rect(0, 0, 72, 72));
    frame_AB_normal = SpriteFrame::create("AB_normal.png", Rect(0,0,72,50));
    frame_AB_selected = SpriteFrame::create("AB_select.png", Rect(0,0,72,50));
    
    frame_LOR_normal->retain();
    frame_LOR_left->retain();
    frame_LOR_right->retain();
    frame_AB_normal->retain();
    frame_AB_selected->retain();
    
    image_LOR = Sprite::createWithSpriteFrame(frame_LOR_normal);
    image_LOR->setPosition(pos_LOR);
    image_jump = Sprite::createWithSpriteFrame(frame_AB_normal);
    image_jump->setPosition(pos_jumpkey);
    image_fire = Sprite::createWithSpriteFrame(frame_AB_normal);
    image_fire->setPosition(pos_firekey);
    
    menu_leftkey = MenuItemImage::create("leftright.png", "leftright.png");
    menu_leftkey->setPosition(pos_leftkey);
    menu_rightkey = MenuItemImage::create("leftright.png", "leftright.png");
    menu_rightkey->setPosition(pos_rightkey);
    menu_jumpkey = MenuItemImage::create("AB_normal.png", "AB_select.png");
    menu_jumpkey->setPosition(pos_jumpkey);
    menu_firekey = MenuItemImage::create("AB_normal.png", "AB_select.png");
    menu_firekey->setPosition(pos_firekey);
    
    menu_setkey = MenuItemImage::create("M_n.png", "M_s.png",
                                        CC_CALLBACK_1(GameLayer::menuCallBackSet, this));
    menu_setkey->setPosition(pos_setkey);
    menu = Menu::create(menu_setkey,NULL);
    menu->setPosition(Vec2(0,0));
    
    //
    this->addChild(controlUI);
    this->addChild(image_LOR);
    this->addChild(image_jump,3);
    this->addChild(image_fire,3);
    this->addChild(menu);
}

void GameLayer::initHeroAndMap()
{
    main_map = GameMap::create("MarioMap1.tmx");
    main_map->setPosition(Vec2(0,0));
    map_size = Size(main_map->map_size.width*main_map->tile_size.width,
                    main_map->map_size.height*main_map->tile_size.height);
    
    hero = Hero::create();
    hero->setPosition(birth_pos);
    hero->setAnchorPoint(Vec2(0.5f,0.0f));
    hero_size = hero->getCurrentSize();
    
    
    main_layer->addChild(main_map,0);
    main_layer->addChild(hero);
    main_layer->setPosition(map_beginPos);
    this->addChild(main_layer);
}

#pragma mark -Menu

void GameLayer::menuCallBackSet(cocos2d::Ref *sender)
{
    log("将这件事变得更加有趣起来!");
    
}


//以下按钮失效
void GameLayer::menuCallBackLeft(Ref* sender)
{
    log("按左键你想干嘛？");
    image_LOR->setSpriteFrame(frame_LOR_normal);
    
}
void GameLayer::menuCallBackRight(cocos2d::Ref *sender)
{
    log("那按右键呢？");
    image_LOR->setSpriteFrame(frame_LOR_normal);
    
}
void GameLayer::menuCallBackJump(cocos2d::Ref *sender)
{
    log("跳起来就抓不到我了吧！");
}
void GameLayer::menuCallBackFire(cocos2d::Ref *sender)
{
    log("放开那个女孩！");
}







