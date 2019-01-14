#include "LogoScene.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;
Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}
bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto logo = Sprite::create("bullet.png");
	logo->setScale(0, 4);
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);

	//MoveBy
	auto moveBy1 = MoveBy::create(0,Vec2(0,100));
	auto moveBy2 = MoveBy::create(0,Vec2(0,200));
	auto moveBy3 = MoveBy::create(0,Vec2(0,100));
	auto moveBy4 = MoveBy::create(0,Vec2(0,200));

	//Sequence
	auto sequence = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	
	//Repeat
	auto repeat = RepeatForever::create(sequence);
	logo->runAction(repeat);

	//background
	//auto background = Sprite::create("image.png");
	auto background = Sprite::create("background.png");
	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(Vec2(0, 0));
	addChild(background);

	//loading
	auto loading = Sprite::create("loadingbar.png");
	loading->setScale(0, 4);
	loading->setAnchorPoint(Vec2(0, 0));
	loading->setPosition(Vec2(0, 0));
	addChild(loading);

	//test label

	//chuyen canh  auto gotoNext
	auto gotoNext = CallFunc::create([]() 
	{
		Director::getInstance()->replaceScene(HelloWorld::createScene()); 
	});

	return true;
}
	