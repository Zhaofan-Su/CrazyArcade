//hero.cpp

#include "Hero.h" 
#include "MapLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Hero::addPlayerAnimation()
{
	//����player1��֡���棬������player1�Ķ���ͼƬ������
	auto *player1_spriteFrameCache = SpriteFrameCache::getInstance();
	player1_spriteFrameCache->addSpriteFramesWithFile("hero/player1_anim.plist", "hero/player1_anim.png");

	//����player1�����������ĸ������Vector 
	Vector<SpriteFrame*> player1_anim_left_vector;
	Vector<SpriteFrame*> player1_anim_right_vector;
	Vector<SpriteFrame*> player1_anim_down_vector;
	Vector<SpriteFrame*> player1_anim_up_vector;

	//����name����
	char name[20];
	memset(name, 0, 20);

	//��1-4��ͼƬ�Ǳ�ʾ����Ķ�������������ͼƬ�ӻ�����ȡ�����ֱ𱣴浽��Ӧ��ɫ��vector��
	for (int i = 1; i <= 4; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_left_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}
	//��5-8��ͼƬ�Ǳ�ʾ���ҵĶ���
	for (int i = 5; i <= 8; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_right_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}
	//��9-12��ͼƬ�Ǳ�ʾ���µĶ���
	for (int i = 9; i <= 12; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_down_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}
	//��13-16��ͼƬ�Ǳ�ʾ���ϵĶ���
	for (int i = 13; i <= 16; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_up_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}

	//���ݽ�ɫ�����������ĸ�vector �����ĸ�����Ķ���
	Animation * player1_animation_left = Animation::createWithSpriteFrames(player1_anim_left_vector, 0.1f,-1);
	Animation * player1_animation_right = Animation::createWithSpriteFrames(player1_anim_right_vector, 0.1f,-1);
	Animation * player1_animation_down = Animation::createWithSpriteFrames(player1_anim_down_vector, 0.1f,-1);
	Animation * player1_animation_up = Animation::createWithSpriteFrames(player1_anim_up_vector, 0.1f,-1);

	///���ݽ�ɫ�����������ĸ�����  �����ĸ�����Ķ���
	player1_animate_left = Animate::create(player1_animation_left);
	player1_animate_right = Animate::create(player1_animation_right);
	player1_animate_down = Animate::create(player1_animation_down);
	player1_animate_up = Animate::create(player1_animation_up);
}

void Hero::addPlayer()
{
	player = Sprite::create("hero/player1.png");
	player ->setPosition(Vec2(20, 200));
	player ->setAnchorPoint(Vec2::ZERO);
	addChild(player);
	player->runAction(player1_animate_down);
}

int Hero::getDirection(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		CCLOG("UP key was pressed");
		direction = UP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		CCLOG("DOWN key was pressed");
		direction = DOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		CCLOG("LEFT key was pressed");
		direction = LEFT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		CCLOG("RIGHT key was pressed");
		direction = RIGHT;
	}
	return this->direction;
}

void Hero::Moveto(int direction)
{
	Vec2 playerPos = player->getPosition();
    player->stopAllActions();
	
	if (direction == UP)
	{
		addPlayerAnimation();
        if (playerPos.y + 40 <= 560)
        {
            CCMoveBy * move = CCMoveBy::create(mInfo.fSpeed, ccp(0, 40));
            Action *GOUP = runAction(player1_animate_up);
            CCSpawn * spawn = CCSpawn::create(move, GOUP, NULL);
            player->setAnchorPoint(Vec2::ZERO);
            player->runAction(spawn);
        }
	}
	else if (direction == DOWN)
	{
		addPlayerAnimation();
        if (playerPos.y - 40 >= 40)
        {
            CCMoveBy * move = CCMoveBy::create(mInfo.fSpeed, ccp(0, -40));
            Action *GODOWN = runAction(player1_animate_down);
            CCSpawn * spawn = CCSpawn::create(move, GODOWN, NULL);
            player->setAnchorPoint(Vec2::ZERO);
            player->runAction(spawn);
        }
	}
	else if (direction == LEFT)
	{
		addPlayerAnimation();
        if (playerPos.x - 40 >= 20)
        {
            CCMoveBy * move = CCMoveBy::create(mInfo.fSpeed, ccp(-40, 0));;
            Action *GOLEFT = runAction(player1_animate_left);
            CCSpawn * spawn = CCSpawn::create(move, GOLEFT, NULL);
            player->setAnchorPoint(Vec2::ZERO);
            player->runAction(spawn);
        }
	}
	else if (direction == RIGHT)
	{
		addPlayerAnimation();
        if (playerPos.x + 40 <= 620)
        {
            CCMoveBy * move = CCMoveBy::create(mInfo.fSpeed, ccp(40, 0));;
            Action *GORIGHT = runAction(player1_animate_right);
            CCSpawn * spawn = CCSpawn::create(move, GORIGHT, NULL);
            player->setAnchorPoint(Vec2::ZERO);
            player->runAction(spawn);
        }
	}
}

void Hero::addSpeed(float fSpeed)
{
	if (fSpeed <= 0.f)
		return;

	fSpeed += fSpeed;
}