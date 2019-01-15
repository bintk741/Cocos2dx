#ifndef __TOUCH_EVENT_SCENE_H__
#define __TOUCH_EVENT_SCENE_H__

#include "cocos2d.h"

class TouchEventScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	//On Touch Began
	bool TouchEventScene::onTouchBegan(Touch* touch, Event * event);
	//On Touch Moved
	void TouchEventScene::onTouchMoved(Touch* touch, Event * event);
	//On Touch Ended
	void TouchEventScene::onTouchEnded(Touch* touch, Event * event);


	virtual bool init();
	void menuChoseCallback(cocos2d::Ref*pSender);

	CREATE_FUNC(TouchEventScene);
};
#endif // __TOUCH_EVENT_SCENE_H__
