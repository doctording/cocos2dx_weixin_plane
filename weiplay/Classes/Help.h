#ifndef __HELP_H__
#define __HELP_H__

#include "cocos2d.h"

#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CCSGUIReader.h"

using namespace cocos2d::ui;
using namespace cocostudio;

class Help : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void back(cocos2d::Ref* pSender,cocos2d::ui::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Help);
};

#endif // __HELLOWORLD_SCENE_H__
