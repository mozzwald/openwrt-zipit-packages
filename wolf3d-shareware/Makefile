#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=wolf3d-shareware
PKG_VERSION:=1.4
PKG_RELEASE:=1

PKG_SOURCE:=wolf3d-shareware.tar.bz2
PKG_SOURCE_URL:=http://mozzwald.homelinux.net/zipit/openwrt/packages/
PKG_SOURCE_SUBDIR:=wolf3d
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/wolf3d-shareware
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Shareware data for Wolfenstein 3D
  URL:=http://www.3drealms.com/wolf3d
  DEPENDS:=+wolf4sdl
endef

define Package/wolf3d-shareware/description
	Shareware data of Apogee's Wolfenstein
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	tar xvf $(DL_DIR)/$(PKG_SOURCE) -C $(PKG_BUILD_DIR)
endef

define Build/Compile
	#do nothing
endef

define Package/wolf3d-shareware/install
	$(INSTALL_DIR) $(1)/usr/games/wolf3d
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/audiohed.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/gamemaps.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/order.frm $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/vgadict.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/vgahead.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/w3dhelp.exe $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/audiot.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/maphead.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/vendor.doc $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/vgagraph.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/vswap.wl1 $(1)/usr/games/wolf3d/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_SOURCE_SUBDIR)/wolf3d.exe $(1)/usr/games/wolf3d/
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/sections/games
		$(INSTALL_BIN) ./files/wolf3dsw.gmenu $(1)/usr/share/gmenu2x/sections/games/
endef

$(eval $(call BuildPackage,wolf3d-shareware))
