#
# Copyright (C) 2008-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bldaemon-zipit
PKG_VERSION:=20160226
PKG_RELEASE:=2
PKG_REV:=config

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/bldaemon-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/bldaemon-zipit
  SECTION:=utilities
  CATEGORY:=Utilities
  TITLE:=bldaemon-zipit
  URL:=http://github.com/mozzwald/bldaemon-zipit
  DEPENDS:=+librt +confuse
endef

define Package/bldaemon-zipit/description
  Manages zipit screen and keyboard backlights
endef

define Package/bldaemon-zipit/install
	$(INSTALL_DIR) $(1)/usr/sbin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/bldaemon $(1)/usr/sbin/bldaemon
	$(INSTALL_DIR) $(1)/etc/init.d
		$(INSTALL_BIN) ./files/z2-bldaemon $(1)/etc/init.d/S10z2-bldaemon
	$(INSTALL_DIR) $(1)/etc/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/bldaemon.conf $(1)/etc/
endef

$(eval $(call BuildPackage,bldaemon-zipit))
