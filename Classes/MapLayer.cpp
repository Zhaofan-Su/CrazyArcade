#include"MapLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;


bool MapLayer::init()
{
    if (!Layer::init())
        return false;

    map = TMXTiledMap::create("map/FirstMap.tmx");
    map->setPosition(Vec2(20, 40));                            //设置地图位置
    map->setAnchorPoint(Vec2::ZERO);                           //将地图锚点设置为左下角原点处

    TMXObjectGroup*group = map->getObjectGroup("objects");     //通过对象层名获得对象层中对象集合
    ValueMap spawnPoint = group->getObject("hero");            //通过对象名获得对象信息，返回类型ValueMap

    collidable = map->getLayer("collidable");                  //通过层名字“collidable”创建层
    collidable->setVisible(false);                             //设置碰撞层不可见

    this->addChild(map);
}

bool MapLayer::ifncollidable(Vec2 position)                      //若欲移动处为障碍物，则返回false
{                                                                //position为要移动处的坐标
    //从像素坐标点转化为瓦片坐标点
    Vec2 tileCoord = this->tileCoordFromPosition(position);
    
    //获得瓦片的GID
    tileCoord.x -= 20;
    tileCoord.y -= 40;
    int tileGid = collidable->getTileGIDAt(tileCoord);

    if (tileGid > 0)
    {
        Value prop = map->getPropertiesForGID(tileGid);
        ValueMap propValueMap = prop.asValueMap();

        std::string collision = propValueMap["Collidable"].asString();

        if (collision == "true")
            return false;
    }

    return true;
}
Vec2 MapLayer::tileCoordFromPosition(Vec2 position)
{
    int x = position.x / 40;
    int y = (520 - position.y) / 40;
    
    return Vec2(x, y);
}
