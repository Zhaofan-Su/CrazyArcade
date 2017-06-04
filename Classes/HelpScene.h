#ifndef _HELP_H_
#define _HELP_H_

#include"cocos2d.h"

class Help :public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();                   //创建场景

    virtual bool init();

    void menuGobackCallback(cocos2d::Ref*pSender);        //点击返回按钮后调用的函数

    CREATE_FUNC(Help);
};
#endif // !_HELP_H_

