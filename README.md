# Zoom Out Vision (Geode mod)

A small Geode mod that applies a user-configurable zoom-out multiplier during gameplay. The default is **1.25× wider** (camera zoom divided by 1.25). The setting can be changed from the mod's Geode settings page.

## Compatibility target

This project targets **Geode v1.5.5** and **Geometry Dash iOS 2.2081**. It is source code, not a compiled `.geode` installer. It has not been compiled or tested on an iPad in this workspace. Geode mods must be built for the target platform; an iOS build needs the matching Geode SDK/bindings and an iOS-capable build environment. A desktop `.geode` file is not an iOS substitute.

The mod adjusts the gameplay camera's current zoom each frame while preserving the game's unscaled zoom value between updates. It intentionally overrides level zoom triggers while active. Set the multiplier back to `1.0` to restore normal zoom. The supported setting range is `1.0` to `2.0`.

## Project contents

- `mod.json` — Geode v1.5.5 metadata, iOS/GD version target and adjustable multiplier.
- `CMakeLists.txt` — standard Geode CMake project setup.
- `src/main.cpp` — gameplay camera hook.
- `about.md`, `changelog.md`, and `LICENSE` — mod information and license.

## Build

Build this project with Geode's CLI and the **Geode v1.5.5 SDK/binaries for iOS**, not a newer SDK, then verify that the resulting `.geode` package targets iOS and GD 2.2081. Geode's official mod creation guide documents the `geode build` workflow and manual installation of the generated package on supported platforms: <https://docs.geode-sdk.org/getting-started/create-mod/>.

This archive does not include a `.geode` binary because this environment is Linux and cannot produce/sign an iOS-targeted Geode mod for your specific Helper installation. The iPad itself is not a Geode mod compiler.

## Install on iPad with Geode Helper

1. Keep a backup of your Geometry Dash save data before changing the modded installation.
2. Build a compatible **iOS** `.geode` package using the matching Geode v1.5.5/iOS 2.2081 toolchain.
3. Open Geometry Dash through Geode Helper. Tap the in-game **Geode** button and check whether your version offers an import/install-from-file flow for local `.geode` files. If it does, select the iOS `.geode` file in Files and install it there.
4. If your Helper build only offers the online mod browser and no local-file import, these official instructions do not specify a supported way to import a custom local package. Do not install desktop/Android binaries or copy them into random app folders. You will need an iOS mod package hosted on a Geode-compatible repository, or a supported iOS developer workflow that can place the built package in the Helper's Geode mods directory.
5. Restart Geometry Dash if requested. Open the mod's settings page and set **Zoom-out multiplier** (1.0 means normal; larger values show more of the level).

The official iOS launcher guide explains the Geode button and online mod browser, but does not document a universal local `.geode` import process: <https://github.com/geode-sdk/ios-launcher/blob/main/MODERN-IOS-INSTALL.md>.

## Notes

- A smaller multiplier change (for example 1.10–1.25) is recommended first. Values near 2.0 make gameplay much smaller and may affect readability.
- This mod is a camera/view modification only. It does not alter hitboxes, movement, or level data.
- This source package is provided as-is. It is not yet an approved or indexed Geode mod.
