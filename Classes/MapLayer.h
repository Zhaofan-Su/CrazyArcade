#ifndef _MAPLAYER_H_
#define _MAPLAYER_H_

#include"cocos2d.h"
#include"Hero.h"

//该地图层用于往游戏场景中载入地图
class MapLayer :public cocos2d::Layer
{
public:
    //cocos2d::TMXLayer*collidable;
    //cocos2d::TMXTiledMap*map;
    virtual bool init();

    //void onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event);

    //Hero*player1;

    //bool setPlayerPosition(cocos2d::Vec2 position);
    //cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
    CREATE_FUNC(MapLayer);
};
#endif // !_MAPLAYER_H_
