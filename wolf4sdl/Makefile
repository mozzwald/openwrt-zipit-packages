#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=wolf4sdl
PKG_VERSION:=1.7
PKG_RELEASE:=1
PKG_REV:=8460157be01accb2065c08fd98d997258a5738fb

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/wolf4sdl.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/wolf4sdl
  SECTION:=games
  CATEGORY:=Games
  TITLE:=SDL version of Wolfenstein 3D
  URL:=http://www.chaos-software.de.vu/
  DEPENDS=+libstdcpp +libsdl +libsdl-mixer
endef

define Package/wolf4sdl/description
	SDL port of the PC 3D shooter Wolfenstein 3D
endef

define Package/wolf4sdl/install
	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/wolf3d $(1)/usr/bin
		$(INSTALL_BIN) ./files/runwolf $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/sections/games
		$(INSTALL_BIN) ./files/wolf3d.gmenu $(1)/usr/share/gmenu2x/sections/games
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/skins/Default/icons
		$(INSTALL_BIN) ./files/wolf3d.png $(1)/usr/share/gmenu2x/skins/Default/icons
endef

$(eval $(call BuildPackage,wolf4sdl))
