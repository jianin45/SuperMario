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

enum TestStatement:char;    //向前声明一个枚举（传统）
enum class TouchesStatement;//使用枚举类向前声明

class GameMap;
class Hero;

class GameLayer : public Layer
{
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
    
    //手柄相关
    Sprite* controlUI;//背景图
    
    Sprite* image_LOR;
    Sprite* image_jump;
    Sprite* image_fire;
    SpriteFrame* frame_LOR_normal;//单次点击时显示
    SpriteFrame* frame_LOR_left;//长按时显示
    SpriteFrame* frame_LOR_right;//同上
    SpriteFrame* frame_AB_normal;
    SpriteFrame* frame_AB_selected;
    
    Menu* menu;//按键
    MenuItemImage* menu_leftkey;
    MenuItemImage* menu_rightkey;
    MenuItemImage* menu_jumpkey;
    MenuItemImage* menu_firekey;
    MenuItemImage* menu_setkey;
    
    Point pos_LOR;//方向背景
    Point pos_leftkey;
    Point pos_rightkey;
    Point pos_jumpkey;//A键
    Point pos_firekey;//B键
    Point pos_setkey;//
    
    Rect rect_leftkey;//按键区域
    Rect rect_rightkey;
    Rect rect_jumpkey;
    Rect rect_firekey;
    
    bool isDown_leftkey;
    bool isDown_rightkey;
    bool isDown_jumpkey;
    bool isDown_firekey;
    
    
#pragma mark -override
    void update(float dt);
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
    void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);
    
    
#pragma mark -私有和不常用public
    
private:
    void initHeroAndMap();//加载地图和英雄
    void initControlUI();//加载手柄
    void initKeyRect();//初始化按钮区域
    void addTouchListener();//加载触摸监听
    void updateControl();//更新控制器
    //按钮
    void menuCallBackLeft(Ref* sender);
    void menuCallBackRight(Ref* sender);
    void menuCallBackJump(Ref* sender);
    void menuCallBackFire(Ref* sender);
    void menuCallBackSet(Ref* sender);
    /**
     *  用于处理点击事件
     *
     *  @param touches     屏幕点击事件
     *  @param state       点击所属的过程
     */
    void disposeTouches(const std::vector<Touch*>& touches,TouchesStatement state);
    
public:
    GameLayer();
    ~GameLayer();
    bool init();
    
    CREATE_FUNC(GameLayer);
};

#endif /* defined(__SuperMarry__GameLayer__) */










