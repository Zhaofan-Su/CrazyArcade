#ifndef _GAME_H_
#define _GAME_H_

#include"cocos2d.h"

//游戏场景
class GameScene :public cocos2d::Layer
{
public:
    static cocos2d::Scene*createScene();            //创建场景

    virtual bool init();

    void menuExitcallback(cocos2d::Ref*pSender);   //“退出”按钮函数

    void initMapLayer();                           //初始化游戏层的函数


    CREATE_FUNC(GameScene);
};
#endif // !_GAME_H_
