#
# Copyright (C) 2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fbpdf
PKG_VERSION:=20111105
PKG_REV:=829d4bcb8753b99948d5bfa346fb659ec38dad6c
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://repo.or.cz/fbpdf.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/fbpdf
  SECTION:=util
  CATEGORY:=Utilities
  SUBMENU:=app
  TITLE:=fbpdf
  URL:=http://litcave.rudi.ir/
  DEPENDS:=+mupdf
endef

define Package/bridge/description
  A small framebuffer pdf viewer. It uses mupdf library by default, but can use poppler.
endef

TARGET_LDFLAGS+= \
       -Wl,-rpath-link=$(STAGING_DIR)/usr/lib

define Build/Compile
	$(call Build/Compile/Default,fbpdf)
endef

define Package/fbpdf/install
	$(INSTALL_DIR) \
		$(1)/usr/bin/

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/fbpdf \
		$(1)/usr/bin/fbpdf
endef

$(eval $(call BuildPackage,fbpdf))
