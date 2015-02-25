//
//  HandShank.h
//  SuperMario
//
//  Created by Hello,world! on 15/2/15.
//
//
/**
 *  手柄类，处理所有游戏控制
 */
#ifndef __SuperMario__HandShank__
#define __SuperMario__HandShank__

#include <stdio.h>
USING_NS_CC;

enum TestStatement:char;    //向前声明一个枚举（传统）
enum class TouchesStatement;//使用枚举类向前声明

class HandShank : public Layer
{
public:
    HandShank();
    ~HandShank();
    bool init();
    CREATE_FUNC(HandShank);
   
    //当按下某个键时
    bool isDown_leftkey;
    bool isDown_rightkey;
    bool isDown_jumpkey;
    bool isDown_firekey;
    
    //改变按键状态
    void setLeftKeySelected();
    void setRightKeySelected();
    void setJumpKeySelected();
    void setFireKeySelected();
    
    //按键区域
    Rect rect_leftkey;
    Rect rect_rightkey;
    Rect rect_jumpkey;
    Rect rect_firekey;
    
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
    void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);
    
private:
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
    
    void initShankUI();//按键布局
    void initKeyRect();//初始化按钮区域
    void menuCallBackSet(Ref* sender);
    /**
     *  用于处理点击事件
     *
     *  @param touches     屏幕点击事件
     *  @param state       点击所属的过程
     */
    void disposeTouches(const std::vector<Touch*>& touches,TouchesStatement state);
    
};



#endif /* defined(__SuperMario__HandShank__) */
