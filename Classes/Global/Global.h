//
//  Global.h
//  SuperMary
//
//  Created by Hello,world! on 15/1/31.
//
//

#ifndef __SuperMary__Global__
#define __SuperMary__Global__

#include <stdio.h>
USING_NS_CC_MATH;

class Global : public Ref
{
public:
    static Global* _globalInstance;
    static Global* getInstance();
    
    
public:
    Global();
    ~Global();
    
    
    
};

#endif /* defined(__SuperMary__Global__) */







