#include"MapLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;

bool MapLayer::init()
{
    auto map = TMXTiledMap::create("map/FirstMap.tmx");         //����ͼ����GameScene��
    map->setPosition(Vec2(20,40));                              //���õ�ͼλ��
    map->setAnchorPoint(Vec2::ZERO);                            //����ͼê������Ϊ���½�ԭ�㴦
    this->addChild(map);

    return true;
}