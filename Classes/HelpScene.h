#ifndef _HELP_H_
#define _HELP_H_

#include"cocos2d.h"

class Help :public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();                   //��������

    virtual bool init();

    void menuGobackCallback(cocos2d::Ref*pSender);        //������ذ�ť����õĺ���

    CREATE_FUNC(Help);
};
#endif // !_HELP_H_

