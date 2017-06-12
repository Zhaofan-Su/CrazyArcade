#include"MapLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;


bool MapLayer::init()
{
    if (!Layer::init())
        return false;

    map = TMXTiledMap::create("map/FirstMap.tmx");
    map->setPosition(Vec2(20, 40));                            //���õ�ͼλ��
    map->setAnchorPoint(Vec2::ZERO);                           //����ͼê������Ϊ���½�ԭ�㴦

    TMXObjectGroup*group = map->getObjectGroup("objects");     //ͨ�����������ö�����ж��󼯺�
    ValueMap spawnPoint = group->getObject("hero");            //ͨ����������ö�����Ϣ����������ValueMap

    collidable = map->getLayer("collidable");                  //ͨ�������֡�collidable��������
    collidable->setVisible(false);                             //������ײ�㲻�ɼ�

    this->addChild(map);
}

bool MapLayer::ifncollidable(Vec2 position)                      //�����ƶ���Ϊ�ϰ���򷵻�false
{                                                                //positionΪҪ�ƶ���������
    //�����������ת��Ϊ��Ƭ�����
    Vec2 tileCoord = this->tileCoordFromPosition(position);
    
    //�����Ƭ��GID
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
