#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ebindkeys-zipit
PKG_VERSION:=2012.04.12
PKG_RELEASE:=1
PKG_REV:=f2a35ed6d96820c02ba806cbaab963e704c7c334

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/ebindkeys-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/ebindkeys-zipit
  SECTION:=utilities
  CATEGORY:=Utilities
  TITLE:=bind a key or key combo to a command
  URL:=http://home.vay8.net/doku.php?id=ebindkeys-zipit
endef

define Package/ebindkeys-zipit/description
	ebindkeys-zipit lets you bind a key or key-combo to a command
endef

define Package/ebindkeys-zipit/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ebindkeys $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/ebindkeys
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ebindkeysrc.sample $(1)/usr/share/ebindkeys/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/zipit-keys $(1)/usr/share/ebindkeys/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/README $(1)/usr/share/ebindkeys/
	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ebindkeysrc.sample $(1)/etc/ebindkeysrc
endef

$(eval $(call BuildPackage,ebindkeys-zipit))
