#ifndef __ITEM_H__
#define __ITEM_H__

#include "cocos2d.h"

USING_NS_CC;

// ��������
enum ItemType
{
	kItemNormal			= 0,	// Ĭ������
	kItemBubbleNum		= 1,	// ����������Ŀ
	kItemBubbleSize		= 2,	// ������������
	kItemRoleSpeed_1	= 3,	// ���ӽ�ɫ�ƶ��ٶ�1
	kItemRoleSpeed_2	= 4,	// ���ӽ�ɫ�ƶ��ٶ�2
	kItemMax
};

// ��������
struct ItemInfo
{
	ItemInfo() : eItemType(ItemType::kItemNormal)
	, nBubbleNum(0)
	, nBubbleSize(0)
	, fRoleSpeed(0.f) {
		random();
	}

	ItemType		eItemType;

	unsigned int	nBubbleNum;		// ����������Ŀ
	unsigned int	nBubbleSize;	// ������������
	
	float			fRoleSpeed;		// ���ӽ�ɫ�ƶ��ٶ�

private:
	// �������
	void random() {
		int nRand = cocos2d::random(ItemType::kItemNormal + 1, ItemType::kItemMax - 1);

		eItemType = static_cast<ItemType>(nRand);

		switch (eItemType)
		{
		case kItemNormal:
			break;
		case kItemBubbleNum:
			// ���1-3������
			nBubbleNum = cocos2d::random(1, 3);
			break;
		case kItemBubbleSize:
			// ���10-30������Ĵ�С
			nBubbleSize = cocos2d::random(10, 30);
			break;
		case kItemRoleSpeed_1:
			// ���0.1-0.5�ļ��ٶ�
			fRoleSpeed = cocos2d::random(0.1f, 0.5f);
			break;
		case kItemMax:
			break;
		default:
			break;
		}
	}
};

// ������
class Item : public Sprite
{
protected:
	Item() {

	}
	virtual ~Item() {

	}
	virtual bool init();

	// ������Ӧ��֡���� (�б����ĳ���SpriteͼƬ)
	void playAnimateByTtemType(const ItemType &type);

public:
	CREATE_FUNC(Item);

	// ItemInfo �� get set����
	CC_SYNTHESIZE_PASS_BY_REF(ItemInfo, mItemInfo, ItemInfo);

};


#endif // __ITEM_H__
