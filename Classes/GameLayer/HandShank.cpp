//
//  HandShank.cpp
//  SuperMario
//
//  Created by Hello,world! on 15/2/15.
//
//

#include "HandShank.h"

enum class TouchesStatement
{
    begin,
    end
};//触摸过程的状态

HandShank::HandShank():
//按键初始化
pos_LOR(Vec2(84, 48)),pos_leftkey(Vec2(40, 48)),pos_rightkey(Vec2(128, 48)),
pos_jumpkey(Vec2(432,35)),pos_firekey(Vec2(353, 35)),
pos_setkey(Vec2(260,33))
{
    
}

HandShank::~HandShank()
{
    
}

bool HandShank::init()
{
    do
    {
        CC_BREAK_IF(Layer::init());
        
        controlUI = Sprite::create("controlUI.png");
        controlUI->setAnchorPoint(Vec2(0,0));
        
        frame_LOR_normal = SpriteFrame::create("backKeyImage.png", Rect(0, 0, 72, 72));
        frame_LOR_left = SpriteFrame::create("backKeyLeft.png", Rect(0, 0, 72, 72));
        frame_LOR_right = SpriteFrame::create("backKeyRight.png", Rect(0, 0, 72, 72));
        frame_AB_normal = SpriteFrame::create("AB_normal.png", Rect(0,0,72,50));
        frame_AB_selected = SpriteFrame::create("AB_select.png", Rect(0,0,72,50));
        
        frame_LOR_normal->retain();
        frame_LOR_left->retain();
        frame_LOR_right->retain();
        frame_AB_normal->retain();
        frame_AB_selected->retain();
        
        image_LOR = Sprite::createWithSpriteFrame(frame_LOR_normal);
        image_LOR->setPosition(pos_LOR);
        image_jump = Sprite::createWithSpriteFrame(frame_AB_normal);
        image_jump->setPosition(pos_jumpkey);
        image_fire = Sprite::createWithSpriteFrame(frame_AB_normal);
        image_fire->setPosition(pos_firekey);
        
        menu_leftkey = MenuItemImage::create("leftright.png", "leftright.png");
        menu_leftkey->setPosition(pos_leftkey);
        menu_rightkey = MenuItemImage::create("leftright.png", "leftright.png");
        menu_rightkey->setPosition(pos_rightkey);
        menu_jumpkey = MenuItemImage::create("AB_normal.png", "AB_select.png");
        menu_jumpkey->setPosition(pos_jumpkey);
        menu_firekey = MenuItemImage::create("AB_normal.png", "AB_select.png");
        menu_firekey->setPosition(pos_firekey);
        
        menu_setkey = MenuItemImage::create("M_n.png", "M_s.png",
                                            CC_CALLBACK_1(HandShank::menuCallBackSet, this));
        menu_setkey->setPosition(pos_setkey);
        menu = Menu::create(menu_setkey,NULL);
        menu->setPosition(Vec2(0,0));
        
        //
        //this->addChild(controlUI);
        this->addChild(image_LOR);
        this->addChild(image_jump,3);
        this->addChild(image_fire,3);
        this->addChild(menu);
        
    } while (0);

    return true;
}

#pragma mark -触摸事件


void HandShank::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    this->disposeTouches(touches, TouchesStatement::begin);
}

//移动时，不是长按
void HandShank::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
    log("我说，放…… …… …… ……开!");
    
}

void HandShank::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
    this->disposeTouches(touches, TouchesStatement::end);
}

void HandShank::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
    log("touch cancel 是怎么一回事？");
}


#pragma mark -private

void HandShank::disposeTouches(const std::vector<Touch*>& touches, TouchesStatement state)
{
    for(auto& it:touches)
    {
        Touch* touch = (Touch*)it;
        Point pos_touch = touch->getLocation();
        if (rect_leftkey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_leftkey = true;
                    break;
                case TouchesStatement::end:
                {
                    isDown_leftkey = false;
                    image_LOR->setDisplayFrame(frame_LOR_normal);
                    //hero->setHeroState(MarioState::eNormalLeft);
                }
                default:
                    break;
            }
        }
        else if (rect_rightkey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_rightkey = true;
                    break;
                case TouchesStatement::end:
                {
                    isDown_rightkey = false;
                    image_LOR->setDisplayFrame(frame_LOR_normal);
                    //hero->setHeroState(MarioState::eNormalRight);
                }
                default:
                    break;
            }
        }
        else if (rect_jumpkey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_jumpkey = true;
                    break;
                case TouchesStatement::end:
                {
                    isDown_jumpkey = false;
                    image_jump->setDisplayFrame(frame_AB_normal);
                }
                default:
                    break;
            }
        }
        else if (rect_firekey.containsPoint(pos_touch))
        {
            switch (state)
            {
                case TouchesStatement::begin:
                    isDown_firekey = true;
                    break;
                case TouchesStatement::end:
                    isDown_firekey = false;
                    image_fire->setDisplayFrame(frame_AB_normal);
                default:
                    break;
            }
        }
    }
}


void HandShank::initKeyRect()
{
    rect_leftkey = Rect(pos_leftkey.x-menu_leftkey->getContentSize().width/2,
                        pos_leftkey.y-menu_leftkey->getContentSize().height/2,
                        menu_leftkey->getContentSize().width,
                        menu_leftkey->getContentSize().height);
    rect_rightkey = Rect(pos_rightkey.x-menu_rightkey->getContentSize().width/2,
                         pos_rightkey.y-menu_rightkey->getContentSize().height/2,
                         menu_rightkey->getContentSize().width,
                         menu_rightkey->getContentSize().height);
    rect_firekey = Rect(pos_firekey.x-menu_firekey->getContentSize().width/2,
                        pos_firekey.y-menu_firekey->getContentSize().height/2,
                        menu_firekey->getContentSize().width,
                        menu_firekey->getContentSize().height);
    rect_jumpkey = Rect(pos_jumpkey.x-menu_jumpkey->getContentSize().width/2,
                        pos_jumpkey.y-menu_jumpkey->getContentSize().height/2,
                        menu_jumpkey->getContentSize().width,
                        menu_jumpkey->getContentSize().height);
}


void HandShank::menuCallBackSet(cocos2d::Ref *sender)
{
    
}







