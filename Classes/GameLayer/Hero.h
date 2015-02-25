//
//  Hero.h
//  SuperMarry
//
//  Created by Hello,world! on 15/1/28.
//
//

#ifndef __SuperMarry__Hero__
#define __SuperMarry__Hero__

#include <stdio.h>
#include "GameEnum.h"

using namespace cocos2d;

/**
 *  当Hero继承自Sprite,这时一个Layer试图用this->addChild()添加到其上,会因为绘制问题而崩溃,具体原因可能是底层绘制的逻辑问题,需要再查
 */
class Hero : public Node
{
    
public:
    Hero();
    ~Hero();
    
    static Hero* create();
    void setHeroState(MarioState sta);
    
public:
    Sprite* main_body;
    Size current_size,small_size,big_size;
    
    MarioState state;
    Size getCurrentSize();
    
    SpriteFrame* big_rihgt;//变大后的
    SpriteFrame* big_left;
    SpriteFrame* big_jumpRight;
    SpriteFrame* big_jumpLeft;
    
    SpriteFrame* small_right;//普通情况
    SpriteFrame* small_left;
    SpriteFrame* small_jumpRight;
    SpriteFrame* small_jumpLeft;
    
    SpriteFrame* fire_normalRight;//有子弹情况
    SpriteFrame* fire_normalLeft;
    SpriteFrame* fire_jumpRight;
    SpriteFrame* fire_jumpLeft;
    
    SpriteFrame* arrow_normalRight;//无敌状态
    SpriteFrame* arrow_normalLeft;
    SpriteFrame* arrow_jumpRight;
    SpriteFrame* arrow_jumpLeft;
    
    SpriteFrame* lifeOver_small;
    SpriteFrame* lifeOver_normal;
    SpriteFrame* lifeOver_fire;
    
private:
    void frameWithTextureInitiation();
    bool heroInit();
    
};

#endif /* defined(__SuperMarry__Hero__) */
