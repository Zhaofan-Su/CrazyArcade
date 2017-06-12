#ifndef __HERO_H__ 
#define __HERO_H__ 

#include "cocos2d.h" 
#include "cocos-ext.h" 

using namespace cocos2d; 
USING_NS_CC_EXT;  

enum hero_direction
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

// 角色属性
struct HeroInfo {
	HeroInfo()
	: fSpeed(1.f)
	{
	}

	float		fSpeed;		// 角色速度
};

class Hero:
	public cocos2d::CCNode 
{ 
public: 
	int direction;
	cocos2d::Vec2 position;
	void addPlayerAnimation();
	void addPlayer();
	int getDirection(EventKeyboard::KeyCode keyCode);
	void Moveto(int direction);
    
	Animate * player1_animate_left;
	Animate * player1_animate_right;
	Animate * player1_animate_down;
	Animate * player1_animate_up;

	float width = 40;
	float height = 40;

	Sprite* player;
	CREATE_FUNC(Hero);

public:
	// 增加速度
	void addSpeed(float fSpeed);

	// 获取角色属性
	inline const HeroInfo &getHeroInfo() {
		return mInfo;
	}

private:
	// 构造函数
	Hero() {

	}

private:
	// 角色属性
	HeroInfo		mInfo;
};


#endif // __HERO_H__
