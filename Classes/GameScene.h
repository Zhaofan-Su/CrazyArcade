#ifndef _GAME_H_
#define _GAME_H_

#include"cocos2d.h"

//��Ϸ����
class GameScene :public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();            //��������

    virtual bool init();

    void menuExitcallback(cocos2d::Ref*pSender);   //���˳�����ť����

    void initMapLayer();                           //��ʼ����Ϸ��ĺ���


    CREATE_FUNC(GameScene);
};
#endif // !_GAME_H_
