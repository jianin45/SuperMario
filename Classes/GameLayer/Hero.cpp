//
//  Hero.cpp
//  SuperMarry
//
//  Created by Hello,world! on 15/1/28.
//
//

#include "Hero.h"

Hero::Hero():
main_body(nullptr),small_size(Size(14,16)),big_size(Size(18,32)),
state(MarioDirection::eNormalRight)

{
    current_size = small_size;
    
}

Hero::~Hero()
{
    
}

Hero* Hero::create()
{
    Hero* p_hero = new Hero();
    if (p_hero && p_hero->heroInit())
    {
        p_hero->autorelease();
        return p_hero;
    }
    CC_SAFE_DELETE(p_hero);
    return nullptr;
}

bool Hero::heroInit()
{
    this->setContentSize(small_size);
    state = MarioDirection::eNormalRight;
    
    main_body = Sprite::create("smallWalkRight.png",Rect(0,0,14,16));
    main_body->setAnchorPoint(Vec2(0,0));
    
    this->addChild(main_body);

    return true;
}

Size Hero::getCurrentSize()
{
    return current_size;
}













