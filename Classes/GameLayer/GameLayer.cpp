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


GameLayer::GameLayer():

//地图初始化
main_map(nullptr),map_size(Size::ZERO),map_beginPos(Vec2(0.0f,96.0f)),

//英雄初始化
hero(nullptr),hero_size(Vec2(0,0)),birth_pos(Vec2(20.0f,32.0f)),

//按键初始化
pos_backKey(Vec2(84, 48)),pos_leftKey(Vec2(40, 48)),pos_rightKey(Vec2(128, 48)),
pos_jumpKey(Vec2(432,35)),pos_fireKey(Vec2(353, 35)),pos_setKey(Vec2(260,33))

//

{
    main_layer = Layer::create();
    main_layer->retain();
    
    win_size = Director::getInstance()->getWinSize();
    
    
}

GameLayer::~GameLayer()
{
    
}

bool GameLayer::init()
{
    log("进入游戏界面！");
    
    this->initHeroAndMap();
    this->initControlUI();
    
    
    
    return true;
}
#pragma mark -Menu

void GameLayer::menuCallBackLeft(Ref* sender)
{
    log("%s",__FUNCTION__);
    image_backKey->setSpriteFrame(frame_backKey_normal);
}
void GameLayer::menuCallBackRight(cocos2d::Ref *sender)
{
    log("%s",__FUNCTION__);
    image_backKey->setSpriteFrame(frame_backKey_normal);
}
void GameLayer::menuCallBackJump(cocos2d::Ref *sender)
{
    log("%s",__FUNCTION__);
}
void GameLayer::menuCallBackFire(cocos2d::Ref *sender)
{
    log("%s",__FUNCTION__);
}
void GameLayer::menuCallBackSet(cocos2d::Ref *sender)
{
    log("%s",__FUNCTION__);
}

#pragma mark -Pravite

void GameLayer::initControlUI()
{
    controlUI = Sprite::create("controlUI.png");
    controlUI->setAnchorPoint(Vec2(0,0));
    
    frame_backKey_normal = SpriteFrame::create("backKeyImage.png", Rect(0, 0, 72, 72));
    frame_backKey_left = SpriteFrame::create("backKeyLeft.png", Rect(0, 0, 72, 72));
    frame_backKey_right = SpriteFrame::create("backKeyRight.png", Rect(0, 0, 72, 72));
    frame_AB_normal = SpriteFrame::create("AB_normal.png", Rect(0,0,72,50));
    frame_AB_selected = SpriteFrame::create("AB_select.png", Rect(0,0,72,50));
    
    frame_backKey_normal->retain();
    frame_backKey_left->retain();
    frame_backKey_right->retain();
    frame_AB_normal->retain();
    frame_AB_selected->retain();
    
    image_backKey = Sprite::create("backKeyImage.png");
    image_backKey->setPosition(pos_backKey);
    image_jump = Sprite::createWithSpriteFrame(frame_AB_normal);
    image_jump->setPosition(pos_jumpKey);
    image_fire = Sprite::createWithSpriteFrame(frame_AB_normal);
    image_fire->setPosition(pos_fireKey);
    
    menu_leftKey = MenuItemImage::create("leftright.png", "AB_select.png",
                                         CC_CALLBACK_1(GameLayer::menuCallBackLeft, this));
    menu_leftKey->setPosition(pos_leftKey);
    menu_rightKey = MenuItemImage::create("leftright.png", "AB_select.png",
                                          CC_CALLBACK_1(GameLayer::menuCallBackRight, this));
    menu_rightKey->setPosition(pos_rightKey);
    menu_jumpKey = MenuItemImage::create("AB_normal.png", "AB_select.png",
                                         CC_CALLBACK_1(GameLayer::menuCallBackJump, this));
    menu_jumpKey->setPosition(pos_jumpKey);
    menu_fireKey = MenuItemImage::create("AB_normal.png", "AB_select.png",
                                         CC_CALLBACK_1(GameLayer::menuCallBackFire, this));
    menu_fireKey->setPosition(pos_fireKey);
    menu_setKey = MenuItemImage::create("M_n.png", "M_s.png",
                                        CC_CALLBACK_1(GameLayer::menuCallBackSet, this));
    menu_setKey->setPosition(pos_setKey);
    
    menu = Menu::create(menu_leftKey,menu_rightKey,menu_jumpKey,menu_fireKey,menu_setKey,NULL);
    menu->setPosition(Vec2(0,0));
    
    //
    this->addChild(controlUI);
    this->addChild(image_backKey);
    this->addChild(image_jump);
    this->addChild(image_fire);
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







