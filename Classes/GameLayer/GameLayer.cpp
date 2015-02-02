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
main_map(nullptr),map_size(Size::ZERO),map_begin_pos(Vec2(0.0f,96.0f)),
//英雄初始化
hero(nullptr),hero_size(Vec2(0,0)),birth_pos(Vec2(180.0f,32.0f))


{
    //
    main_layer = Layer::create();
    main_layer->retain();
    
    
}

GameLayer::~GameLayer()
{
    
}

bool GameLayer::init()
{
    log("进入游戏界面！");
    
    this->initHeroAndMap();
    
    
    
    
    return true;
}

#pragma mark -Pravite

void GameLayer::initHeroAndMap()
{
    main_map = GameMap::create("MarioMap1.tmx");
    main_map->setPosition(Vec2(0,0));
    main_layer->addChild(main_map,0);
    
    map_size = Size(main_map->map_size.width*main_map->tile_size.width,
                    main_map->map_size.height*main_map->tile_size.height);
    
    hero = Hero::create();
    
    
    
    
    main_layer->setPosition(map_begin_pos);
    this->addChild(main_layer);
}







