#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pianobar
PKG_VERSION:=2012.01.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://6xq.net/static/projects/pianobar
PKG_MD5SUM:=448c57d65c71158674e8b30a8cfa217e

include $(INCLUDE_DIR)/package.mk

define Package/pianobar
  SECTION:=sound
  CATEGORY:=Sound
  DEPENDS:=+libfaad2 +libmad +libgnutls +libao
  TITLE:=Pianobar CLI Pandora Client
  URL:=http://6xq.net/projects/pianobar
endef

define Package/pianobar/description
	pianobar is a free/open-source, console-based 
        replacement for Pandora’s flash player.
endef

TARGET_CFLAGS += -std=c99

PREFIX="/usr"

define Package/pianobar/install
	$(INSTALL_DIR) $(1)/usr/bin \
		$(1)/usr/share/gmenu2x/skins/Default/icons \
		$(1)/usr/share/gmenu2x/sections/applications

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pianobar $(1)/usr/bin/
	$(INSTALL_BIN) ./files/pianobar.png $(1)/usr/share/gmenu2x/skins/Default/icons
	$(INSTALL_BIN) ./files/pianobar.gmenu $(1)/usr/share/gmenu2x/sections/applications
endef

$(eval $(call BuildPackage,pianobar))
