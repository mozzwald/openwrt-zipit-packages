#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=eduke32
PKG_VERSION:=1.0
PKG_RELEASE:=1
PKG_REV:=73591eca0b998d71d27f12c4bf061c3d76402689

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/eduke32-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/eduke32
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Duke Nukem 3D Game
  URL:=http://www.3drealms.com
  DEPENDS=+libsdl +libsdl-mixer +libvorbis +libogg
endef

define Package/eduke32/description
	SDL port of the PC 3D shooter Duke Nukem 3D
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) /home/mozzwald/zipit/build/eduke32-zipit/* $(PKG_BUILD_DIR)
endef

define Package/eduke32/install
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

$(eval $(call BuildPackage,eduke32))
