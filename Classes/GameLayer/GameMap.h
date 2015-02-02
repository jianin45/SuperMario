//
//  GameMap.h
//  SuperMarry
//
//  Created by Hello,world! on 15/1/28.
//
//

#ifndef __SuperMarry__GameMap__
#define __SuperMarry__GameMap__

#include <stdio.h>

using namespace cocos2d;

class GameMap : public TMXTiledMap
{
public:
    GameMap();
    ~GameMap();
    static GameMap* create(const char* tmxFile);
    
public:
    Size tile_size;
    Size map_size;
    
    
private:
    //初始化
    void extraInit();
    
};

#endif /* defined(__SuperMarry__GameMap__) */













