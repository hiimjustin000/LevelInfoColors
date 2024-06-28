#include "LICColorPopup.hpp"

#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(LICLevelInfoLayer, LevelInfoLayer) {
    bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) return false;

        auto dailyID = level->m_dailyID.value();
        auto isDaily = dailyID > 0 && dailyID < 100000;
        auto isWeekly = dailyID >= 100000;
        auto isGauntlet = level->m_gauntletLevel;
        auto background = static_cast<CCSprite*>(getChildByID("background"));
        if (background) {
            if (isDaily) background->setColor(Mod::get()->getSettingValue<ccColor3B>("daily-color"));
            else if (isWeekly) background->setColor(Mod::get()->getSettingValue<ccColor3B>("weekly-color"));
            else if (isGauntlet) background->setColor(Mod::get()->getSettingValue<ccColor3B>("gauntlet-color"));
            else background->setColor(Mod::get()->getSettingValue<ccColor3B>("normal-color"));
        }

        auto colorButtonSprite = CircleButtonSprite::createWithSpriteFrameName("GJ_paintBtn_001.png", 1.0f, CircleBaseColor::Pink);
        auto colorButton = CCMenuItemExt::createSpriteExtra(colorButtonSprite, [background, isDaily, isWeekly, isGauntlet](auto) {
            auto defaultColor = isWeekly || isGauntlet ? ccColor3B { 51, 51, 51 } : ccColor3B { 0, 102, 255 };
            LICColorPopup::create(background, background ? background->getColor() : defaultColor, defaultColor, isDaily, isWeekly, isGauntlet)->show();
        });
        colorButton->setID("color-button"_spr);
        auto leftSideMenu = getChildByID("left-side-menu");
        leftSideMenu->addChild(colorButton);
        leftSideMenu->updateLayout();

        return true;
    }
};
