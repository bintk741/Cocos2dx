#ifndef __ANIMATION_SCENE_H__
#define __ANIMATION_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class AnimationScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuChoseCallback(cocos2d::Ref*pSender);

	CREATE_FUNC(AnimationScene);
};
#endif // __ANIMATION_SCENE_H__
