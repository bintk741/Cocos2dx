#include "TouchEventScene.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Sprite * beeMC;

Scene* TouchEventScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchEventScene::create();
	scene->addChild(layer);
	return scene;
}
bool TouchEventScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//Tạo con ong :v

	beeMC = Sprite::create("bee2.png");//chọn bee2 vì nó thẳng nhất
	beeMC-> setScale(0, 2);
	beeMC->setPosition(Vec2(0, 0));
	addChild(beeMC);

	//Event Dispatcher

	//Touch Event
	//Touch Began
	//Tạo sự kiện xử lử 1 điểm chạm trên màn hình.
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TouchEventScene::onTouchBegan, this);
	//Tạo sự kiện xử lý di chuyển
	listener->onTouchMoved = CC_CALLBACK_2(TouchEventScene::onTouchMoved, this);
	//Tạo sự kiện xử lý kết thúc
	listener->onTouchEnded = CC_CALLBACK_2(TouchEventScene::onTouchEnded, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;

	//virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	//virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	//virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

	//bool TouchScene::onTouchBegan(Touch* touch, Event * event)
	//{
	//	return true;
	//}
	//void TouchScene::onTouchMoved(Touch* touch, Event* event) {}
	//void TouchScene::onTouchEnded(Touch* touch, Event* event) {}

	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC CALLBACK 2 (touchScene::onTouchBegan, this);
	//listener->onTouchMoved = CC CALLBACK 2 (touchScene::onTouchBegan, this);
	//listener->onTouchEnded = CC CALLBACK 2 (touchScene::onTouchBegan, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
bool TouchEventScene::onTouchBegan(Touch* touch, Event* event)
{
	//Tọa độ chạm trên màn hình
	Vec2 touchLocation = touch->getLocation();
	//beeMC->setPosition(touchLocation);
	auto actionMoveTo = MoveTo::create(2, touchLocation);
	beeMC->runAction(actionMoveTo);
	return true;

}
void TouchEventScene::onTouchMoved(Touch* touch, Event* event)
{
	//Tọa độ di chuyển trên màn hình
	Vec2 touchLocation = touch->getLocation();
	beeMC->setPosition(touchLocation);

}
void TouchEventScene::onTouchEnded(Touch* touch, Event* event)
{
	//Tọa độ di chuyển trên màn hình
	//Vec2 touchLocation = touch->getLocation();
	beeMC->setPosition(Vec2(0, 0));
}