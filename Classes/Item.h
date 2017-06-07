#ifndef __ITEM_H__
#define __ITEM_H__

#include "cocos2d.h"

USING_NS_CC;

// 道具类型
enum ItemType
{
	kItemNormal			= 0,	// 默认类型
	kItemBubbleNum		= 1,	// 增加泡泡数目
	kItemBubbleSize		= 2,	// 增加泡泡威力
	kItemRoleSpeed_1	= 3,	// 增加角色移动速度1
	kItemRoleSpeed_2	= 4,	// 增加角色移动速度2
	kItemMax
};

// 道具属性
struct ItemInfo
{
	ItemInfo() : eItemType(ItemType::kItemNormal)
	, nBubbleNum(0)
	, nBubbleSize(0)
	, fRoleSpeed(0.f) {
		random();
	}

	ItemType		eItemType;

	unsigned int	nBubbleNum;		// 增加泡泡数目
	unsigned int	nBubbleSize;	// 增加泡泡威力
	
	float			fRoleSpeed;		// 增加角色移动速度

private:
	// 随机类型
	void random() {
		int nRand = cocos2d::random(ItemType::kItemNormal + 1, ItemType::kItemMax - 1);

		eItemType = static_cast<ItemType>(nRand);

		switch (eItemType)
		{
		case kItemNormal:
			break;
		case kItemBubbleNum:
			// 随机1-3个泡泡
			nBubbleNum = cocos2d::random(1, 3);
			break;
		case kItemBubbleSize:
			// 随机10-30个坐标的大小
			nBubbleSize = cocos2d::random(10, 30);
			break;
		case kItemRoleSpeed_1:
			// 随机0.1-0.5的加速度
			fRoleSpeed = cocos2d::random(0.1f, 0.5f);
			break;
		case kItemMax:
			break;
		default:
			break;
		}
	}
};

// 道具类
class Item : public Sprite
{
protected:
	Item() {

	}
	virtual ~Item() {

	}
	virtual bool init();

	// 播放相应的帧动画 (有崩溃改成了Sprite图片)
	void playAnimateByTtemType(const ItemType &type);

public:
	CREATE_FUNC(Item);

	// ItemInfo 的 get set方法
	CC_SYNTHESIZE_PASS_BY_REF(ItemInfo, mItemInfo, ItemInfo);

};


#endif // __ITEM_H__
