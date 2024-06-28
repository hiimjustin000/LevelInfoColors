#include <Geode/Geode.hpp>

using namespace geode::prelude;

class LICColorPopup : public Popup<CCSprite*, ccColor3B const&, ccColor3B const&, bool, bool, bool>, public ColorPickerDelegate {
protected:
    ccColor3B m_color;
    ccColor3B m_originalColor;
    ccColor3B m_defaultColor;
    CCControlColourPicker* m_picker;
    TextInput* m_rInput;
    TextInput* m_gInput;
    TextInput* m_bInput;
    TextInput* m_hexInput;
    CCSprite* m_newColorSpr;
    CCMenuItemSpriteExtra* m_resetBtn;
    CCMenuItemSpriteExtra* m_hardResetBtn;

    static unsigned char stringToByte(std::string const&);

    bool setup(CCSprite*, ccColor3B const&, ccColor3B const&, bool, bool, bool) override;
    void updateState(CCNode* except = nullptr);
    void colorValueChanged(ccColor3B) override;
    void onClose(CCObject*) override;
public:
    static LICColorPopup* create(CCSprite*, ccColor3B const&, ccColor3B const&, bool, bool, bool);
};
