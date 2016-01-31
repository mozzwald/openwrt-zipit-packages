#
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=freetds
PKG_VERSION:=0.91.112
PKG_SOURCE:=freetds-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=ftp://ftp.freetds.org/pub/freetds/stable/
#PKG_BUILD_DIR:=$(BUILD_DIR)/freetds-$(PKG_VERSION)

PKG_RELEASE:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/freetds
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=freetds
  URL:=http://freetds.org
  DEPENDS:=+unixodbc +libpthread +libncurses +libreadline
endef

define Package/freetds/description
	FreeTDS is a set of libraries for Unix and Linux that allows your programs to natively talk to Microsoft SQL Server and Sybase databases. 
endef

define Package/freetds/install
	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/freetds.conf $(1)/etc/
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/pool.conf $(1)/etc/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.so* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/* $(1)/usr/bin/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/
	$(CP) $(PKG_BUILD_DIR)/include/*.h $(STAGING_DIR)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,freetds))
