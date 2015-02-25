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
#include "HandShank.h"
#include "Hero.h"

static GameLayer* _shareGameLayer;
GameLayer* GameLayer::getInstance()
{
    if (!_shareGameLayer)
    {
        _shareGameLayer = new GameLayer();
        CCASSERT(_shareGameLayer, "Fault:not enough memony!");
        _shareGameLayer->init();
    }
    return _shareGameLayer;
}

GameLayer::GameLayer():

//地图初始化
main_map(nullptr),map_size(Size::ZERO),map_beginPos(Vec2(0.0f,96.0f)),

//英雄初始化
hero(nullptr),hero_size(Vec2(0,0)),birth_pos(Vec2(20.0f,32.0f+96.0f)),
move_offset(2.0f),

//手柄初始化
hand_shank(nullptr),shank_pos(Vec2(0,0))
{
    main_layer = Layer::create();
    main_layer->retain();
    
    win_size = Director::getInstance()->getWinSize();
    win_middle = Vec2(win_size.width/2, win_size.height/2);
    
    
}

GameLayer::~GameLayer()
{
    //this->unscheduleUpdate();
}

bool GameLayer::init()
{
    log("进入游戏界面！");
    
    this->initialization();

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
    
    if (hand_shank->isDown_leftkey)
    {
        hand_shank->setLeftKeySelected();
        hero->setHeroState(MarioState::eLeft);
        
//        hero->setPosition(Vec2(hero->getPosition().x-move_offset, hero->getPosition().y));
//        main_map->setPosition(Vec2(main_map->getPosition().x+20, main_map->getPosition().y));
    }
    else if (hand_shank->isDown_rightkey)
    {
        hand_shank->setRightKeySelected();
        hero->setHeroState(MarioState::eRight);
        
//        hero->setPosition(Vec2(hero->getPosition().x+move_offset, hero->getPosition().y));
//        main_map->setPosition(Vec2(main_map->getPosition().x-20, main_map->getPosition().y));
    }
    else if (hand_shank->isDown_jumpkey)
    {
        hand_shank->setJumpKeySelected();
        hero->setPosition(win_middle);
    }
    else if (hand_shank->isDown_firekey)
    {
        hand_shank->setFireKeySelected();
        hero->setPosition(birth_pos);
    }
    
}



#pragma mark -Pravite(部分)

void GameLayer::addTouchListener()
{
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(HandShank::onTouchesBegan, hand_shank);
    listener->onTouchesMoved = CC_CALLBACK_2(HandShank::onTouchesMoved, hand_shank);
    listener->onTouchesEnded = CC_CALLBACK_2(HandShank::onTouchesEnded, hand_shank);
    listener->onTouchesCancelled = CC_CALLBACK_2(HandShank::onTouchesCancelled, hand_shank);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


void GameLayer::initialization()
{
    main_map = GameMap::create("MarioMap1.tmx");
    main_map->setPosition(map_beginPos);
    map_size = Size(main_map->map_size.width*main_map->tile_size.width,
                    main_map->map_size.height*main_map->tile_size.height);
    
    hero = Hero::create();
    hero->setPosition(birth_pos);
    hero->setAnchorPoint(Vec2(0.5f,0.0f));
    hero_size = hero->getCurrentSize();
    
    hand_shank = HandShank::create();
    hand_shank->setPosition(shank_pos);
    
    main_layer->addChild(main_map,0);
    main_layer->addChild(hero,1);
    main_layer->addChild(hand_shank,2);
    
    this->addChild(main_layer);
}



#pragma mark -Menu

void GameLayer::menuCallBackSet(cocos2d::Ref *sender)
{
    log("这件事将变得更加有趣!");
}


////以下按钮失效
//void GameLayer::menuCallBackLeft(Ref* sender)
//{
//    log("按左键你想干嘛？");
//    image_LOR->setSpriteFrame(frame_LOR_normal);
//    
//}
//void GameLayer::menuCallBackRight(cocos2d::Ref *sender)
//{
//    log("那按右键呢？");
//    image_LOR->setSpriteFrame(frame_LOR_normal);
//    
//}
//void GameLayer::menuCallBackJump(cocos2d::Ref *sender)
//{
//    log("跳起来就抓不到我了吧！");
//}
//void GameLayer::menuCallBackFire(cocos2d::Ref *sender)
//{
//    log("放开那个女孩！");
//}







