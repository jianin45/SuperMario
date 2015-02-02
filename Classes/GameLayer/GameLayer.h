//
//  GameLayer.h
//  SuperMarry
//
//  Created by Hello,world! on 15/1/28.
//
//

#ifndef __SuperMarry__GameLayer__
#define __SuperMarry__GameLayer__

#include <stdio.h>

using namespace cocos2d;

class GameMap;
class Hero;

class GameLayer : public Layer
{
public:
    Layer* main_layer;
    
    GameMap* main_map;
    Size map_size;
    Point map_begin_pos;//地图起始点，上半部分为地图
    
    Hero* hero;
    Size hero_size;
    Point birth_pos;//英雄出生点
    
private:
    void initHeroAndMap();//加载地图
    
public:
    GameLayer();
    ~GameLayer();
    bool init();
    
    CREATE_FUNC(GameLayer);
    
};

#endif /* defined(__SuperMarry__GameLayer__) */










