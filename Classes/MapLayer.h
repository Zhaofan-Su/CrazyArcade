#ifndef _MAPLAYER_H_
#define _MAPLAYER_H_

#include"cocos2d.h"

//�õ�ͼ����������Ϸ�����������ͼ
class MapLayer :public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(MapLayer);
};
#endif // !_MAPLAYER_H_
