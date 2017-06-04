#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();               //创建场景

    virtual bool init();
    
     //a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);     //关闭按钮的函数声明
    void menuNextCallback(cocos2d::Ref*pSender);       //go按钮的函数声明

    //virtual void onEnterTransitionDidFinish();
    //virtual void onExitTransitionDidStart();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
