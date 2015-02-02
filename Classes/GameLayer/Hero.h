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

class Hero : public Node
{
    
public:
    Hero();
    ~Hero();
    
    static Hero* create();
    
public:
    Sprite* main_body;
    Size current_size,small_size,big_size;
    
    
    MarioDirection state;
    
    Size getCurrentSize();
    
    
private:
    bool heroInit();
    
};

#endif /* defined(__SuperMarry__Hero__) */














