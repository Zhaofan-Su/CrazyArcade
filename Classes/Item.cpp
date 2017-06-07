#include "Item.h"


bool Item::init()
{
	if (!Sprite::init())
		return false;

	//playAnimateByTtemType(mItemInfo.eItemType);

	std::string sFileName = StringUtils::format("item/Gift%d.png", (int)mItemInfo.eItemType);

	setTexture(sFileName);
	setTextureRect(Rect(0, 0, 42, 45));

	return true;
}

void Item::playAnimateByTtemType(const ItemType &type)
{
	// 设置相应帧动画 126 * 45	
	CCTexture2D* pTexture = CCTextureCache::getInstance()->addImage(StringUtils::format("item/Gift%d.png", (int)type));

	Vector<SpriteFrame *> vSpriteFrame;

	int nWidth = 126 / 3, nHeight = 45;
	int nCount = 0;
	do {
		auto pSpriteFrame = CCSpriteFrame::createWithTexture(pTexture, cocos2d::Rect(nWidth * nCount, 0, nWidth, nHeight));

		vSpriteFrame.pushBack(pSpriteFrame);
	} while (++nCount < 3);

	auto pAnimation = Animation::createWithSpriteFrames(vSpriteFrame, .1f, -1);

	//runAction(Animate::create(pAnimation));
}