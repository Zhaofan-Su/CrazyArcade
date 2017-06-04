#ifndef _HOMESCENE_H_
#define _HOMESCENE_H_
#include "cocos2d.h"
class Home:public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();                     //����home����
    virtual bool init();

    void menuStartCallback(cocos2d::Ref*pSender);            //��ʼ��ť�����ú�������
    void menuSetCallback(cocos2d::Ref*pSender);              //���ð�ť�����ú�������
    void menuHelpCallback(cocos2d::Ref*pSender);             //������ť�����ú�������

    //virtual void onEnter();
    //virtual void onEnterTransitionDidFinish();
    //virtual void onExit();
    //virtual void onExitTransitionDidStart();
    //virtual void cleanup();

    CREATE_FUNC(Home);
};
#endif // !_HOMESCENE_H_

