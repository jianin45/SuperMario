//
//  GameEnum.h
//  SuperMary
//
//  Created by Hello,world! on 15/1/31.
//
//

#ifndef SuperMary_GameEnum_h
#define SuperMary_GameEnum_h

enum class MarioState : unsigned int
{
    eLeft,eRight,            //跑动起来的状态，有动画
    eJumpLeft,eJumpRight,
    eNormalLeft,eNormalRight,//静止状态
    eFireTheHole,
    eFlyBug                  //作弊状态，在空中飞行
};



#endif
