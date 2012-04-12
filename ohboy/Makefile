#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ohboy
PKG_VERSION:=1.0.0-beta1
PKG_RELEASE:=1
PKG_REV:=41f792f215e0e1117283c0d236e5de3982eb4441

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/ohboy-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/ohboy
  SECTION:=emulators
  CATEGORY:=Emulators
  TITLE:=SDL Gameboy Emulator
  URL:=http://code.google.com/p/ohboy/
  DEPENDS:=+libsdl +libpng
endef

define Package/ohboy/description
	SDL Gameboy emulator with menu based on gnuboy
endef

define Build/Configure
	$(CP) $(PKG_BUILD_DIR)/Makefile.zipitz2 $(PKG_BUILD_DIR)/Makefile
endef

define Package/ohboy/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ohboy $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ohboy.rc $(1)/etc
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/skins/Default/icons/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ohboy.png $(1)/usr/share/gmenu2x/skins/Default/icons/
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/sections/games
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ohboy.gmenu $(1)/usr/share/gmenu2x/sections/games/ohboy
endef

$(eval $(call BuildPackage,ohboy))
