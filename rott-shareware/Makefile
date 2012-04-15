#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rott-shareware
PKG_VERSION:=1.0.1
PKG_RELEASE:=1
PKG_REV:=70ee5396d973d3a254bf673a0d3ae3df40d28095

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/rott-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/rott-shareware
  SECTION:=games
  CATEGORY:=Games
  TITLE:=SDL Shareware version of Rise of the Triad
  URL:=http://rott
  DEPENDS=+libsdl +libsdl-mixer
endef

define Package/rott-shareware/description
	SDL port of the PC 3D shooter Rise of the Triad - Shareware Version
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) /home/mozzwald/zipit/build/rott-zipit/* $(PKG_BUILD_DIR)
endef

define Package/rott-shareware/install
	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) ./files/rottsw $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/games/rottsw
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/rott $(1)/usr/games/rottsw
		$(INSTALL_BIN) ./files/huntbgin.wad $(1)/usr/games/rottsw
		$(INSTALL_BIN) ./files/huntbgin.rtc $(1)/usr/games/rottsw
		$(INSTALL_BIN) ./files/huntbgin.rtl $(1)/usr/games/rottsw
		$(INSTALL_BIN) ./files/remote1.rts $(1)/usr/games/rottsw
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/sections/games
		$(INSTALL_BIN) ./files/rottsw.gmenu $(1)/usr/share/gmenu2x/sections/games
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/skins/Default/icons
		$(INSTALL_BIN) ./files/rott.png $(1)/usr/share/gmenu2x/skins/Default/icons
endef

$(eval $(call BuildPackage,rott-shareware))
