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
    Size win_size;
    
    GameMap* main_map;
    Size map_size;
    Point map_beginPos;//地图起始点，上半部分为地图
    
    Hero* hero;
    Size hero_size;
    Point birth_pos;//英雄出生点
    
    //手柄相关
    Sprite* controlUI;//背景图
    
    Sprite* image_backKey;
    Sprite* image_jump;
    Sprite* image_fire;
    SpriteFrame* frame_backKey_normal;//单次点击时显示
    SpriteFrame* frame_backKey_left;//长按时显示
    SpriteFrame* frame_backKey_right;//同上
    SpriteFrame* frame_AB_normal;
    SpriteFrame* frame_AB_selected;
    
    Point pos_backKey;//方向背景
    Point pos_leftKey;
    Point pos_rightKey;
    Point pos_jumpKey;
    Point pos_fireKey;
    Point pos_setKey;
    
    Menu* menu;//按键
    MenuItem* menu_leftKey;
    MenuItem* menu_rightKey;
    MenuItem* menu_jumpKey;
    MenuItem* menu_fireKey;
    MenuItem* menu_setKey;
   
    
#pragma mark -私有和不常用public
    
private:
    void initHeroAndMap();//加载地图和英雄
    void initControlUI();//加载手柄
    //按钮
    void menuCallBackLeft(Ref* sender);
    void menuCallBackRight(Ref* sender);
    void menuCallBackJump(Ref* sender);
    void menuCallBackFire(Ref* sender);
    void menuCallBackSet(Ref* sender);
    
public:
    GameLayer();
    ~GameLayer();
    bool init();
    
    CREATE_FUNC(GameLayer);
};

#endif /* defined(__SuperMarry__GameLayer__) */










