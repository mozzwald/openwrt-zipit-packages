# 
# Copyright (c) 2010 mozzwald
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=prboom
PKG_VERSION:=2.5.0
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/prboom
PKG_MD5SUM:=a8a15f61fa2626ab98051ab2703378c4

include $(INCLUDE_DIR)/package.mk

define Package/prboom
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Port of Doom
  URL:=http://prboom.sourceforge.net/
  DEPENDS:=+libsdl +libpng +libpthread
  MENU:=1
endef

define Package/prboom/description
  Port of the popular first person shooter Doom engine
endef

define Build/Configure
	$(call Build/Configure/Default, \
		--disable-gl \
		--disable-sdltest \
		--libdir=$(STAGING_DIR)/usr/lib/SDL \
		--includedir=$(STAGING_DIR)/usr/include \
	)
	# Ugly, but configure does not detect presence of uid_t and gid_t properly
	$(SED) '/gid_t/d' $(PKG_BUILD_DIR)/config.h 
	$(SED) '/uid_t/d' $(PKG_BUILD_DIR)/config.h 
endef

define Package/prboom/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/share/doom
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/prboom $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/prboom-game-server $(1)/usr/bin/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/data/prboom.wad $(1)/usr/share/doom
	$(INSTALL_DATA) $(FILES_DIR)/prboom.cfg $(1)/usr/share/doom
endef

$(eval $(call BuildPackage,prboom))
