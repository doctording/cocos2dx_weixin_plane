项目描述
===
cocos2dx仿微信打飞机游戏,游戏运行首页

![](http://i.imgur.com/IHRAPcC.png)

功能介绍
===

目前主要是windows下的exe文件运行，基本上是一个完整的cocos2dx打飞机游戏

* 飞机的移动

* 子弹的发射

* 敌机的随机生成

* 打怪，分数的统计,数据存储

* 帮助页面，最高分统计页面

开发环境
===
* win7 + vs2013 + cocos2dx3.0 + cocostudio

* android-ndk-r9d

* apache-ant-1.9.7

* adt-bundle-windows-x86_64-20130917

cocos2dx，C++相关知识的运用
===

# 动画相关

## 实现游戏背景的滚动

具体参见如下博文

http://blog.csdn.net/qq_26437925/article/details/52052904

## 帧动画

首先图片资源要备好，并且命名上，需要特定的设置

动画在很多地方都需要用到，本程序主要使用了cocos2dx自带的一些动画和帧动画

例子参见 Player.cpp


# 数据相关

## 场景使用tag来传值

1. 先对某个场景设置tag, 例如

```
Scene * GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();

	layer->setTag(404);

	scene->addChild(layer);

	return scene;
}
```
2. 在进行场景跳转时，获取对象，并赋值给对象的某个成员变量

GameOver类 有个int的成员变量score_int

```
auto scene = GameOver::createScene();
GameOver *overLayer = (GameOver*)scene->getChildByTag(404); // tag
overLayer->score_int = score;
// 切换到 GameOver 场景
Director::getInstance()->replaceScene(scene);
```	

3. 在原来设置的场景的类中重写OnEnter方法,注意先super父类的OnEnter()方法

```
void GameOver::onEnter()
{
	Layer::onEnter(); // 这个不能够漏掉
	//CCLOG("get score: %d", score_int);
	auto score_str = __String::createWithFormat("%d", score_int);
	score_label->setString(score_str->getCString());

	SaveData* sd = SaveData::sharedUserData();
	if (score_int > sd->getHighScore())
	{
		sd->setHighScore(score_int);
	}
}
```


## 读取xml数据


## UserDefault的使用
UserDefault可以实现数据的存储，一般情况下不会使用它保存大量的数据，它没有SQL语句那样的灵活。UserDefault除了保存游戏设置外，还有可以长期保持游戏精灵等对象的状态。

本例程序在保存最高分时，使用了UserDefault
win32下，成功创建为 ** proj.win32\Debug.win32\UserDefault.xml**，注意不是在Resource目录下

参见 SaveData类的封装，在器构造函数中，代码如下
```
SaveData::SaveData()
{
	bool isExist = false;
	isExist = UserDefault::getInstance()->getBoolForKey("isExist");
	if (!isExist)
	{
		UserDefault::getInstance()->setBoolForKey("isExist", true);
		m_high_score = 0;
		UserDefault::getInstance()->setIntegerForKey("highScore", m_high_score);
	}
}
```


# 界面相关

## cocostudio的简单运用

cocostudio 制作出界面，里面可以由各种控件，然后可以导出.ExportJson .plist等格式的文件

直接放到项目的Resource目录下

* 可能要添加ui相关的头文件
```
#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CCSGUIReader.h"

using namespace cocos2d::ui;
using namespace cocostudio;
```

* 获取图层，控件
```
auto ui = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Help/Help_1.ExportJson"); 
ui->setPosition(Point(0, 0));
this->addChild(ui);
//获取控件
Button* btnBack = (Button*)Helper::seekWidgetByName(ui, "btn_back");
// 为控件添加事件
btnBack->addTouchEventListener(this, toucheventselector(Help::back));
```


## 场景跳转，暂停功能的实现

实现暂停的方式有多种，这里采用截屏，pushScene,popScene的方式实现

例如，点击暂停按钮后，执行如下代码
```
RenderTexture *renTexture = RenderTexture::create(400, 550);
renTexture->begin();
this->getParent()->visit();
renTexture->end();
Director::getInstance()->pushScene(Pause::scene(renTexture, true));
```

400,500 分别是AppDelegate里面设置的屏幕的宽和高

pushScene到另外一个场景 Pause

Pause里面的某个控件点击回到原来暂停的场景,只需要下面的一句代码
```
Director::getInstance()->popScene();
```

如下图

![](http://i.imgur.com/qXC7O4N.png)


# win32 exe, android apk

一写注意问题和学习参考

http://blog.csdn.net/qq_26437925/article/details/53105197=

http://blog.csdn.net/qq_26437925/article/details/53072121

apk运行截图

![](http://i.imgur.com/7EWjCay.png)

# C++相关

## 单例模式

* 单例的使用动机（参见百度百科）

对于系统中的某些类来说，只有一个实例很重要，例如，一个系统中可以存在多个打印任务，但是只能有一个正在工作的任务；一个系统只能有一个窗口管理器或文件系统；一个系统只能有一个计时工具或ID(序号)生成器。如在Windows中就只能打开一个任务管理器。如果不使用机制对窗口对象进行唯一化，将弹出多个窗口，如果这些窗口显示的内容完全一致，则是重复对象，浪费内存资源；如果这些窗口显示的内容不一致，则意味着在某一瞬间系统有多个状态，与实际不符，也会给用户带来误解，不知道哪一个才是真实的状态。因此有时确保系统中某个对象的唯一性即一个类只能有一个实例非常重要。
如何保证一个类只有一个实例并且这个实例易于被访问呢？定义一个全局变量可以确保对象随时都可以被访问，但不能防止我们实例化多个对象。一个更好的解决办法是让类自身负责保存它的唯一实例。这个类可以保证没有其他实例被创建，并且它可以提供一个访问该实例的方法。这就是单例模式的模式动机。 

* 单例是几个要点
一是某个类只能有一个实例；
二是它必须自行创建这个实例；
三是它必须自行向整个系统提供这个实例。

cocos2dx本身就用到了很多单例,如一些资源管理器


在管理子弹，敌机类是就写了一个单例的Manager类

```
class  Manager
{
public:
    
	static Manager * getInstance();
	static void freeInstance(void);

public:
	static Manager * m_manager;
	Manager();
	
```

```
Manager * Manager::m_manager = NULL;

Manager * Manager::getInstance()
{
	if (m_manager == NULL)
	{
		m_manager = new Manager();
	}
	return m_manager;
}

void Manager::freeInstance(void)
{
	if (m_manager != NULL)
	{
		delete m_manager;
		m_manager = NULL;
	}
}
```

## 数据结构的使用

主要是string，一些集合类的使用
特别是 数组和链表，主要是根据具体对象的属性来判断用什么

## c++11，auto,lamda表达式

# cocos2dx3.0 android apk发布问题

http://blog.csdn.net/qq_26437925/article/details/53072121


编码流程和Git管理
===

本次项目的开发遵循 从小到大，由易到繁，主干到细节

git同步管理，确保每一次都可以有一个新功能的添加或改进，项目是持续可迭代的

多用git命令，git branch,git merge控制好

```
-> 查找素材，大致的思考，初始项目的搭建

-> 游戏背景 ->  plane -> plane的移动控制

-> 打子弹 -> 子弹管理  -> 敌机出现  -> 敌机管理

-> 分数,分数面板的实现

-> 游戏暂停功能的实现

-> 数据的保存

-> 界面的整理

-> 添加游戏开始主页面，帮助页面，最高分界面等

-> win32到Android的转换，优化代码，解bug,完成apk的发布

-> 文档书写，知识点总结

-> 功能完善和添加，迭代开发

```

后期改进
===

* 音频

* 跨平台事件改进