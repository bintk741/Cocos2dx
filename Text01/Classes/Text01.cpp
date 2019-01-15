//MenuGameScene - giao diện game

#include "Text01.h"
#include "cocos2d.h"
//#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "LogoScene.h"
#include "TouchEventScene.h"

USING_NS_CC;
Scene* Text01::createScene()
{
	auto scene = Scene::create();
	auto layer = Text01::create();
	scene->addChild(layer);
	return scene;
}
bool Text01::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	
	auto background = Sprite::create("background.png");
	//background->setScaleY(1.2);
	background->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(background);
	
	//static auto mySprite = Sprite::create("CloseNormal.png");
	//mySprite->setPosition(50, 100);

	//Create Label
	auto myLabel = Label::createWithTTF("Your Text", "fornt/Marker Felt.ttf", 24);

	auto myLabel = Label::createWithSystemFont("My Label Text", "Arial", 16);

	/*myLabel->enableShadow();
	myLabel->enableOutline(Color4B::BLUE, 2);
	myLabel->enableGlow(Color4B::BLUE, 2);
	myLabel->enableItalics();*/




	//Create menu
	
	
	//Menu & MenuItem hinh anh
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [](Ref* sender)
	{
		exit(0);
	});
	closeItem->setAnchorPoint(Vec2(1, 1));
	closeItem->setPosition(screenSize.width /2, screenSize.height /2);

	auto itemPlay = MenuItemFont::create("Play", [](Ref* sender) 
	{
	});
	auto itemSetting = MenuItemFont::create("Setting",[](Ref* sender)
	{
	});
	auto itemMoregame = MenuItemFont::create("More Game", [](Ref* sender) 
	{
	});
	auto itemAbout = MenuItemFont::create("About", [](Ref* sender) 
	{
	});
	itemPlay->setPosition(0, 50);
	itemSetting->setPosition(0, 50);
	itemMoregame->setPosition(0, 50);
	itemAbout->setPosition(0, 50);

	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoregame, itemAbout, nullptr);
	menuLabel->setPosition(screenSize.width /2, screenSize.height /2);
	addChild(menuLabel);



	auto myMenu = Menu::create(closeItem, nullptr);
	myMenu->setPosition(screenSize.width /2, screenSize.height /2);
	addChild(myMenu);


	//Menu & MenuItem = String

	//auto itemPlay = MenuItemFont::create("Play", nullptr);
	//auto itemSetting = MenuItemFont::create("Setting", nullptr);
	//auto itemMoregame = MenuItemFont::create("Moregame", nullptr);
	//auto itemAbout = MenuItemFont::create("About", nullptr);

	//itemPlay->setPosition(400, 400);
	//itemSetting->setPosition(400, 200);
	//itemMoregame->setPosition(400, 200);
	//itemAbout->setPosition(400, 200);

	//auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoregame, itemAbout, nullptr);
	//menuLabel->setPosition(0, 0);
	//addChild(menuLabel);


	//Create Button

	//auto screenSize = Director::getInstance()->getVisibleSize();

	//auto ratingButton = ui::Button::create("rating_normal.png", "rating pressed.png");
	//ratingButton->addClickEventListener([&](Ref*envent) 
	//{
	//	log("Rating clicked");
	//});
	//ratingButton->setAnchorPoint(Vec2(1, 0));
	//ratingButton->setPosition(Vec2(screenSize.width, 0));
	//addChild(ratingButton);

	////CheckBox
	//static auto checkbox = ui::CheckBox::create("checkbox_normal.png", "checkbox_pressed.png", "checkbox_checked.png", "checkbox_normal_disable.png", "checkbox_checked_disable.png");
	//checkbox->setSelected(true);
	//checkbox->addCCSEventListener([&](Ref* event) 
	//{
	//	log("CheckBox state: %d", checkbox->isSelected());
	//});
	//checkbox->setPosition(Vec2(100, 100));
	//checkbox->setEnabled(false);
	//addChild(checkbox);

	//Loading Bar

	auto loadingBarGB = Sprite::create("loadingbar_bg.png");
	loadingBarGB->setPosition(Vec2(screenSize.width / 2, 50));
	addChild(loadingBarGB);
	static auto loadingbar = ui::LoadingBar::create("loadingbar.png");
	loadingbar->setPercent(0);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPosition(loadingBarGB->getPosition());
	addChild(loadingbar);
	//update Loading Bar
	auto updateLoadingBar = CallFunc::create([=]()// dấu "=" trong create([])
	{
		if (loadingbar-> getPercent()<100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
		if (loadingbar->getPercent() == 100)
		{
			loadingbar->setVisible(false);
			loadingBarGB->setVisible(false);
		}
	});
	auto sequenceRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingbar->runAction(repeat);

	//ScrollView

	//auto scrollView = ui::ScrollView::create();
	//scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	//scrollView->setContentSize(Size(300, 200));
	//scrollView->setInnerContainerSize(Size(1280, 2500));
	//scrollView->setBounceEnabled(true);
	//scrollView->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2)); // .
	//for (int i = 0; i < 50; i++);
	//{
	//	ui::Button *button = ui::Button::create("CloseNormal.png", "CloseSelected.png");
	//	button->setPosition(Vec2(scrollView->getContentSize().width / 2, i * 50));
	//	scrollView->addChild(button);
	//}
	//addChild(scrollView);

	//Slier

	//static auto slider = ui::Slider::create();
	//slider->loadBarTexture("slider_bar_bg.png");
	//slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable.png");
	//slider->loadProgressBarTexture("slider_bar_pressed.png");
	//slider->setPercent(10);
	//slider->setPosition(Vec2( screenSize.width / 2, 140));
	//slider->addClickEventListener([](Ref* event) 
	//{
	//	log("Slider: %d", slider->getPercent());
	//});
	//addChild(slider);


	//TextField

	//static auto textField = ui::TextField::create("Input Text Here", "Arial", 30);
	//textField->setMaxLengthEnabled(true);
	//textField->setMaxLength(2);
	//textField->setPasswordEnabled(true);
	//textField->setPosition(Vec2(screenSize.width / 2, screenSize.height - 100));
	//textField->addClickEventListener([](Ref* event)
	//{
	//	log("TextField: %s", textField->getString().c_str());
	//});
	//addChild(textField);
}