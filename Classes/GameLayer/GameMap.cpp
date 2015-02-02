//
//  GameMap.cpp
//  SuperMarry
//
//  Created by Hello,world! on 15/1/28.
//
//

#include "GameMap.h"

GameMap::GameMap()

{
    
    
}

GameMap::~GameMap()
{
    
}

GameMap* GameMap::create(const char *tmxFile)
{
    GameMap* game_map = new GameMap();
    if (game_map && game_map->initWithTMXFile(tmxFile))
    {
        game_map->extraInit();
        game_map->autorelease();
        return game_map;
    }
    CC_SAFE_DELETE(game_map);
    return NULL;
}

void GameMap::extraInit()
{
    tile_size = _tileSize;
    map_size = _mapSize;
    
    
    
}






