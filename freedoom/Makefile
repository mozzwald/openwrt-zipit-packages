#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=freedoom
PKG_VERSION:=0.10.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_SOURCE_URL:=https://github.com/freedoom/freedoom/releases/download/v$(PKG_VERSION)/
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
#PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/freedoom1
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Data files for FreeDoom 1
  URL:=https://freedoom.github.io
  DEPENDS:=+prboom
  VARIANT:=freedoom1
endef

define Package/freedoom2
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Data files for FreeDoom 2
  URL:=https://freedoom.github.io
  DEPENDS:=+prboom
  VARIANT:=freedoom2
endef

define Package/freedoom1/description
	Data files for FreeDoom 1 game
endef

define Package/freedoom2/description
	Data files for FreeDoom 2 game
endef

define Build/Prepare
	( cd $(BUILD_DIR) ; \
		unzip $(DL_DIR)/$(PKG_SOURCE) ; \
	);
endef

define Build/Compile
	#do nothing
endef

define Package/freedoom1/install
	$(INSTALL_DIR) $(1)/usr/games/freedoom
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/freedoom1.wad $(1)/usr/games/freedoom
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/README.html $(1)/usr/games/freedoom

	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) ./files/freedoom1 $(1)/usr/bin/freedoom1
endef

$(eval $(call BuildPackage,freedoom1))

define Package/freedoom2/install
	$(INSTALL_DIR) $(1)/usr/games/freedoom
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/freedoom2.wad $(1)/usr/games/freedoom

	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) ./files/freedoom2 $(1)/usr/bin/freedoom2
endef

$(eval $(call BuildPackage,freedoom2))
