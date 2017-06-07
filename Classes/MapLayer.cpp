#include"MapLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;


/*bool MapLayer::init()
{
    
    map = TMXTiledMap::create("map/FirstMap.tmx");         //����ͼ����GameScene��
    map->setPosition(Vec2(20,40));                              //���õ�ͼλ��
    map->setAnchorPoint(Vec2::ZERO);                            //����ͼê������Ϊ���½�ԭ�㴦
    this->addChild(map);

    TMXObjectGroup*group = map->getObjectGroup("objects");        //ͨ�����������ö�����ж��󼯺�
    ValueMap spawnPoint = group->getObject("hero");               //ͨ����������ö�����Ϣ����������ValueMap

    player1 = Hero::create();                               //��������
    player1->addPlayerAnimation();
    player1->addPlayer();
    this->addChild(player1, 1);

    collidable = map->getLayer("collidable");                //ͨ�������֡�collidable��������

    //ע����̼�����
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MapLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MapLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}
void MapLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
    Vec2 player_pos = player1->getPosition();
    Vec2 Pos;
    if (player1->getDirection(keyCode) == UP)
    {
        Pos.x = player_pos.x;
        Pos.y = player_pos.y + 40;
        if (setPlayerPosition(Pos) && Pos.y <= 560)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == DOWN)
    {
        Pos.x = player_pos.x;
        Pos.y = player_pos.y - 40;
        if (setPlayerPosition(Pos) && Pos.y >= 40)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == LEFT)
    {
        Pos.x = player_pos.x - 40;
        Pos.y = player_pos.y;
        if (setPlayerPosition(Pos) && Pos.x >= 20)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == RIGHT)
    {
        Pos.x = player_pos.x + 40;
        Pos.y = player_pos.y;
        if (setPlayerPosition(Pos) && Pos.x <= 620)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
}

bool MapLayer::setPlayerPosition(Vec2 position)          //�����ƶ���Ϊ�ϰ���򷵻�false
{
    //�����������ת��Ϊ��Ƭ�����
    Vec2 Pos;
    Pos.x = position.x - 20;
    Pos.y = position.y - 40;
    Vec2 tileCoord = this->tileCoordFromPosition(Pos);

    //�����Ƭ��GID
    int tileGid = collidable->getTileGIDAt(tileCoord);

    if (tileGid > 0)
    {
        Value prop = map->getPropertiesForGID(tileGid);
        ValueMap propValueMap = prop.asValueMap();

        std::string collision = propValueMap["collidable"].asString();

        if (collision == "true")
            return false;
    }
    
    //player1->setPosition(position);
    return true;
}

Vec2 MapLayer::tileCoordFromPosition(Vec2 pos)
{
    int x = pos.x / map->getTileSize().width;               //���x����Ƭ������
    int y = ((520 * map->getTileSize().height) - pos.y) /
        map->getTileSize().height;                          //���y����Ƭ������

    return Vec2(x, y);
}*/