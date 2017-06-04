#ifndef _HOMESCENE_H_
#define _HOMESCENE_H_
#include "cocos2d.h"
class Home:public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();                     //创建home界面
    virtual bool init();

    void menuStartCallback(cocos2d::Ref*pSender);            //开始按钮，调用函数声明
    void menuSetCallback(cocos2d::Ref*pSender);              //设置按钮，调用函数声明
    void menuHelpCallback(cocos2d::Ref*pSender);             //帮助按钮，调用函数声明

    //virtual void onEnter();
    //virtual void onEnterTransitionDidFinish();
    //virtual void onExit();
    //virtual void onExitTransitionDidStart();
    //virtual void cleanup();

    CREATE_FUNC(Home);
};
#endif // !_HOMESCENE_H_

