#ifndef _SETTING_H_
#define _SETTING_H

#include"cocos2d.h"

class Setting :public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();               //��������

    virtual bool init();

    void menuGoCallback(cocos2d::Ref*pSender);            //������ذ�ťʱ���õĺ���������

    CREATE_FUNC(Setting);
};
#endif // ! _SETTING_H_



