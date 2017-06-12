#ifndef _LOADING_H_
#define _LOADING_H_

#include"cocos2d.h"

class Loading :public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();               //´´½¨³¡¾°

    virtual bool init();

    void gotoHelloScene(float t);

    CREATE_FUNC(Loading);
};
#endif // !_LOADING_H_
