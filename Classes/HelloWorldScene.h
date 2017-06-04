#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();               //��������

    virtual bool init();
    
     //a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);     //�رհ�ť�ĺ�������
    void menuNextCallback(cocos2d::Ref*pSender);       //go��ť�ĺ�������

    //virtual void onEnterTransitionDidFinish();
    //virtual void onExitTransitionDidStart();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
