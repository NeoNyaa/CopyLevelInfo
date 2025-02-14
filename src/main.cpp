#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(NeoLayer, LevelInfoLayer) {
  void onCopyInfo(CCObject * target) {
    auto YTvTitle = fmt::format("{} - {} (Geometry Dash)", this->m_level->m_creatorName, this->m_level->m_levelName);
    auto YTvDesc = std::to_string(this->m_level->m_levelID.value());
    auto test = clipboard::write(fmt::format("{}\nLevel ID: {}\n", YTvTitle, YTvDesc));
    Notification::create(("Level info copied to clipboard!"), CCSprite::create("Copy.png"_spr), 3)->show();
  }

  bool init(GJGameLevel * var1, bool var2) {
    if (!LevelInfoLayer::init(var1, var2)) return false;

    auto button = CCMenuItemSpriteExtra::create(
      CircleButtonSprite::createWithSpriteFrameName("Copy.png"_spr,
        .8f,
        CircleBaseColor::Green,
        CircleBaseSize::Medium
      ), this, menu_selector(NeoLayer::onCopyInfo));
    button->setID("neo-copy-info-button");

      if (auto menu = getChildByID("left-side-menu")) {
        menu->addChild(button);
        menu->updateLayout();
      }

      return true;
  }
};
