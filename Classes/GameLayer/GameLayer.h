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
class HandShank;
class Hero;

class GameLayer : public Layer
{
public:
    GameLayer();
    ~GameLayer();
    bool init();
    static GameLayer* getInstance();
    //CREATE_FUNC(GameLayer);
public:
    
    Layer* main_layer;
    Size win_size;
    Point win_middle;
    
    GameMap* main_map;
    Size map_size;
    Point map_beginPos;//地图起始点，上半部分为地图
    
    Hero* hero;
    Size hero_size;
    Point birth_pos;//英雄出生点
    float move_offset;
    
    HandShank* hand_shank;//手柄
    Point shank_pos;
    
    void update(float dt);
private:
    void initialization();//初始化元素
    void initHeroAndMap();//加载地图和英雄

    void addTouchListener();//加载触摸监听
    void updateControl();//更新控制器
    
    
    //按钮
//    void menuCallBackLeft(Ref* sender);
//    void menuCallBackRight(Ref* sender);
//    void menuCallBackJump(Ref* sender);
//    void menuCallBackFire(Ref* sender);
    void menuCallBackSet(Ref* sender);

};

#endif /* defined(__SuperMarry__GameLayer__) */










