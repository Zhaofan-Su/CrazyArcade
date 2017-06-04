#include"MapLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;

bool MapLayer::init()
{
    auto map = TMXTiledMap::create("map/FirstMap.tmx");         //将地图引入GameScene中
    map->setPosition(Vec2(20,40));                              //设置地图位置
    map->setAnchorPoint(Vec2::ZERO);                            //将地图锚点设置为左下角原点处
    this->addChild(map);

    return true;
}