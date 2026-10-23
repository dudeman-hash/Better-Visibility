#include <algorithm>
#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

// PlayLayer's update computes the game's normal camera zoom. To avoid
// compounding the zoom-out on every frame, restore the normal value before
// the original update, then apply the multiplier to the freshly computed
// value afterward. Rendering sees the adjusted value until the next update.
class $modify(ZoomOutVisionBaseLayer, GJBaseGameLayer) {
    struct Fields {
        float unscaledZoom = 1.0f;
        bool zoomWasApplied = false;
    };

    void update(float dt) {
        // GJBaseGameLayer is also used by editor/playtest contexts. Only
        // alter the active PlayLayer instance.
        if (PlayLayer::get() != this) {
            GJBaseGameLayer::update(dt);
            return;
        }

        if (m_fields->zoomWasApplied) {
            m_gameState.m_cameraZoom = m_fields->unscaledZoom;
            m_fields->zoomWasApplied = false;
        }

        GJBaseGameLayer::update(dt);

        const double configured = Mod::get()->getSettingValue<double>("zoom-multiplier");
        const float multiplier = static_cast<float>(std::clamp(configured, 1.0, 2.0));
        const float normalZoom = m_gameState.m_cameraZoom;

        m_fields->unscaledZoom = normalZoom;
        m_gameState.m_cameraZoom = normalZoom / multiplier;
        m_fields->zoomWasApplied = true;
    }
};
