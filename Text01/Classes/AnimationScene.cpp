#include "AnimationScene.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
Scene* AnimationScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AnimationScene::create();
	scene->addChild(layer);
	return scene;
}
bool AnimationScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	auto screenSize = Director::getInstance()->getVisibleSize();

	auto logo = Sprite::create("bullet.png");
	logo->setScale(0, 4);
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);

	static auto mySprite = Sprite::create("CloseNormal.png");
	mySprite->setPosition(50, 100);

	//Create Label
	auto myLabel = Label::createWithTTF("Your Text", "fornt/Marker Felt.ttf", 24);

	//Animation

	auto beeMC = Sprite::create();
	beeMC->setPosition(screenSize.width, 100);
	addChild(beeMC);

	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("bee1.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee2.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee3.png", Rect(0, 0, 150, 150)));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	beeMC->runAction(RepeatForever::create(animate));

	//Paticle System
	auto praticleSystem = ParticleSystemQuad::create("particle_texture.plist");
}
//Chuyển sang TouchEventScene.h and .cpp
//	//Event Dispatcher
//
//	//Touch Event
//	//Touch Began
//	//Tạo sự kiện xử lử 1 điểm chạm trên màn hình.
//	auto listener = EventListenerTouchOneByOne::create();
//	listener->onTouchBegan = CC_CALLBACK_2(AnimationScene::onTouchBegan, this);
//	//Tạo sự kiện xử lý moved
//	listener->onTouchBegan = CC_CALLBACK_2(AnimationScene::onTouchBegan, this);
//	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
//
//	return true;
//
//	//virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
//	//virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
//	//virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);
//
//	//bool TouchScene::onTouchBegan(Touch* touch, Event * event)
//	//{
//	//	return true;
//	//}
//	//void TouchScene::onTouchMoved(Touch* touch, Event* event) {}
//	//void TouchScene::onTouchEnded(Touch* touch, Event* event) {}
//
//	//auto listener = EventListenerTouchOneByOne::create();
//	//listener->onTouchBegan = CC CALLBACK 2 (touchScene::onTouchBegan, this);
//	//listener->onTouchMoved = CC CALLBACK 2 (touchScene::onTouchBegan, this);
//	//listener->onTouchEnded = CC CALLBACK 2 (touchScene::onTouchBegan, this);
//	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//}
//bool AnimationScene::onTouchBegan(Touch* touch, Event* event)
//{
//	//Tọa độ chạm trên màn hình
//	Vec2 touchLocation = touch->getLocation();
//
//	return true;
//	
//}
//void AnimationScene::onTouchMoved(Touch* touch, Event* event)
//{
//	//Tọa độ chạm trên màn hình
//	Vec2 touchLocation = touch->getLocation();
//
//}