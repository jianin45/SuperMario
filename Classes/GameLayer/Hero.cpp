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
state(MarioState::eNormalRight)

{
    current_size = small_size;
    this->frameWithTextureInitiation();
    
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
    state = MarioState::eNormalRight;
    
    main_body = Sprite::create("smallWalkRight.png",Rect(0,0,14,16));
    main_body->setAnchorPoint(Vec2(0,0));
    
    this->addChild(main_body);

    return true;
}

Size Hero::getCurrentSize()
{
    return current_size;
}

void Hero::setHeroState(MarioState sta)
{
    if (state == sta)
    {
        return;
    }
    
    
    switch (sta)
    {
        state = sta;
        case MarioState::eLeft:
        {
            main_body->setDisplayFrame(small_left);
        }
            break;
        case MarioState::eRight:
        {
            main_body->setDisplayFrame(small_right);
        }
            break;
        case MarioState::eNormalLeft:
        {
            main_body->setDisplayFrame(small_left);
        }
            break;
        case MarioState::eNormalRight:
        {
            main_body->setDisplayFrame(small_right);
        }
            break;
        default:
            break;
    }
}

void Hero::frameWithTextureInitiation()
{
    Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage("walkLeft.png");
    
    big_jumpLeft = SpriteFrame::createWithTexture(pTexture, Rect(180, 0, 18, 32));
    big_jumpLeft->retain();
    big_left = SpriteFrame::createWithTexture(pTexture, Rect(18*9, 0, 18, 32));
    big_left->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("walkRight.png");
    big_jumpRight = SpriteFrame::createWithTexture(pTexture, Rect(180, 0, 18, 32));
    big_jumpRight->retain();
    big_rihgt = SpriteFrame::createWithTexture(pTexture, Rect(0, 0, 18, 32));
    big_rihgt->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("smallWalkLeft.png");
    small_left = SpriteFrame::createWithTexture(pTexture, Rect(14*9, 0, 14, 16));
    small_left->retain();
    small_jumpLeft = SpriteFrame::createWithTexture(pTexture, Rect(140, 0, 14, 16));
    small_jumpLeft->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("smallWalkRight.png");
    small_right = SpriteFrame::createWithTexture(pTexture, Rect(0, 0, 14, 16));
    small_right->retain();
    small_jumpRight = SpriteFrame::createWithTexture(pTexture, Rect(140, 0, 14, 16));
    small_jumpRight->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("WalkLeft_fire.png");
    fire_jumpLeft = SpriteFrame::createWithTexture(pTexture, Rect(180, 0, 18, 32));
    fire_jumpLeft->retain();
    fire_normalLeft = SpriteFrame::createWithTexture(pTexture, Rect(18*9, 0, 18, 32));
    fire_normalLeft->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("WalkRight_fire.png");
    fire_jumpRight = SpriteFrame::createWithTexture(pTexture, Rect(180, 0, 18, 32));
    fire_jumpRight->retain();
    fire_normalRight = SpriteFrame::createWithTexture(pTexture, Rect(0, 0, 18, 32));
    fire_normalRight->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("allow_walkLeft.png");
    arrow_normalLeft = SpriteFrame::createWithTexture(pTexture, Rect(0, 0, 18, 32));
    arrow_normalLeft->retain();
    arrow_jumpLeft = SpriteFrame::createWithTexture(pTexture, Rect(180, 0, 18, 32));
    arrow_jumpLeft->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("allow_walkRight.png");
    arrow_normalRight = SpriteFrame::createWithTexture(pTexture, Rect(0, 0, 18, 32));
    arrow_normalRight->retain();
    arrow_jumpRight = SpriteFrame::createWithTexture(pTexture, Rect(180, 0, 18, 32));
    arrow_jumpRight->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("small_die.png");
    lifeOver_small = SpriteFrame::createWithTexture(pTexture, Rect(16, 0, 16, 18));
    lifeOver_small->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("normal_die.png");
    lifeOver_normal = SpriteFrame::createWithTexture(pTexture, Rect(24, 0, 24, 34));
    lifeOver_normal->retain();
    
    pTexture = Director::getInstance()->getTextureCache()->addImage("fire_die.png");
    lifeOver_fire = SpriteFrame::createWithTexture(pTexture, Rect(24, 0, 24, 34));
    lifeOver_fire->retain();
}









