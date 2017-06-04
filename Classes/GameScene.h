#ifndef _GAME_H_
#define _GAME_H_

#include"cocos2d.h"
#include"cocos-ext.h"
#include"Hero.h"

//��Ϸ����
class GameScene :public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();            //��������

    virtual bool init();

    void menuExitcallback(cocos2d::Ref*pSender);   //���˳�����ť����

    void initMapLayer();                           //��ʼ����Ϸ��ĺ���

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event);

	Hero* player1;

    CREATE_FUNC(GameScene);
};
#endif // !_GAME_H_
