# 
# Copyright (c) 2010 mozzwald
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=prboom
PKG_VERSION:=2.5.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/prboom
PKG_MD5SUM:=a8a15f61fa2626ab98051ab2703378c4

include $(INCLUDE_DIR)/package.mk

define Package/prboom
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Port of Doom
  URL:=http://prboom.sourceforge.net/
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
endef

#define Build/Compile
#	$(MAKE_VARS) \
#	$(MAKE) -C $(PKG_BUILD_DIR)/$(MAKE_PATH) $(MAKE_FLAGS)
#endef

define Package/prboom/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/f3write $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/f3read $(1)/usr/bin/
endef

$(eval $(call BuildPackage,prboom))
