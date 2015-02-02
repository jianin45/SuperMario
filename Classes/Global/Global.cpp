//
//  Global.cpp
//  SuperMary
//
//  Created by Hello,world! on 15/1/31.
//
//

#include "Global.h"

Global* Global::_globalInstance;
Global* Global::getInstance()
{
    if (_globalInstance == nullptr)
    {
        _globalInstance = new Global();
    }
    return _globalInstance;
}

Global::Global()
{
    
}

Global::~Global()
{
    
}