#ifndef _MAPLAYER_H_
#define _MAPLAYER_H_

#include"cocos2d.h"

//该地图层用于往游戏场景中载入地图
class MapLayer :public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(MapLayer);
};
#endif // !_MAPLAYER_H_
