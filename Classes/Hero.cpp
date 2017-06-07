//hero.cpp

#include "Hero.h" 
#include "MapLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Hero::addPlayerAnimation()
{
	//创建player1的帧缓存，并加载player1的动画图片到缓存
	auto *player1_spriteFrameCache = SpriteFrameCache::getInstance();
	player1_spriteFrameCache->addSpriteFramesWithFile("hero/player1_anim.plist", "hero/player1_anim.png");

	//创建player1的上下左右四个方向的Vector 
	Vector<SpriteFrame*> player1_anim_left_vector;
	Vector<SpriteFrame*> player1_anim_right_vector;
	Vector<SpriteFrame*> player1_anim_down_vector;
	Vector<SpriteFrame*> player1_anim_up_vector;

	//定义name数组
	char name[20];
	memset(name, 0, 20);

	//第1-4张图片是表示向左的动画，把这四张图片从缓存中取出，分别保存到相应角色的vector中
	for (int i = 1; i <= 4; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_left_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}
	//第5-8张图片是表示向右的动画
	for (int i = 5; i <= 8; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_right_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}
	//第9-12张图片是表示向下的动画
	for (int i = 9; i <= 12; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_down_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}
	//第13-16张图片是表示向上的动画
	for (int i = 13; i <= 16; i++)
	{
		sprintf(name, "player1_anim_%02d.png", i);
		player1_anim_up_vector.pushBack(player1_spriteFrameCache->getSpriteFrameByName(name));
	}

	//根据角色的上下左右四个vector 创建四个方向的动作
	Animation * player1_animation_left = Animation::createWithSpriteFrames(player1_anim_left_vector, 0.1f,-1);
	Animation * player1_animation_right = Animation::createWithSpriteFrames(player1_anim_right_vector, 0.1f,-1);
	Animation * player1_animation_down = Animation::createWithSpriteFrames(player1_anim_down_vector, 0.1f,-1);
	Animation * player1_animation_up = Animation::createWithSpriteFrames(player1_anim_up_vector, 0.1f,-1);

	///根据角色的上下左右四个动作  创建四个方向的动画
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