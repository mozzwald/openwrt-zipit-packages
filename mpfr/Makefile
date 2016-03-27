#
# Copyright (C) 2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=mpfr
PKG_VERSION:=3.1.3

PKG_SOURCE_URL:=http://www.mpfr.org/mpfr-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_MD5SUM:=5fdfa3cfa5c86514ee4a241a1affa138
PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/mpfr
    TITLE:=mpfr
    SECTION:=libs
    CATEGORY:=Libraries
    URL:=http://www.mpfr.org
    DEPENDS:=+libgmp
endef

CONFIGURE_ARGS += \
	--enable-static \
	--enable-shared

define Build/InstallDev
	$(INSTALL_DIR) \
		$(1)/usr/include \
		$(1)/usr/lib
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/* \
		$(1)/usr/lib/
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/include/* \
		$(1)/usr/include/
endef

define Package/mpfr/install
	$(INSTALL_DIR) \
		$(1)/usr/lib
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/libmpfr.so* \
		$(1)/usr/lib/
endef

$(eval $(call BuildPackage,mpfr))
