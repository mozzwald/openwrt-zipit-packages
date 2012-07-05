# 
# Copyright (c) 2010 mozzwald
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=f3
PKG_VERSION:=v2
PKG_RELEASE:=1

PKG_SOURCE:=f3-v2.tar.gz
PKG_SOURCE_URL:=http://www.mozzwald.com/zipit/
PKG_MD5SUM:=f9f893a12fdd5ca273ad826fb8cbd39d

include $(INCLUDE_DIR)/package.mk

define Package/f3
  SECTION:=utilities
  CATEGORY:=Utilities
  TITLE:=f3
  URL:=http://oss.digirati.com.br/f3
  MENU:=1
endef

define Package/f3/description
  Test SD Cards for fakes
endef

define Build/Compile
	$(MAKE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR)/$(MAKE_PATH) $(MAKE_FLAGS)
endef

define Package/f3/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/f3write $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/f3read $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,f3))
