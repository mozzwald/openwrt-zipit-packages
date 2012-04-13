#
# Copyright (C) 2005-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mupdf
PKG_VERSION:=0.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-source.tar.gz
PKG_SOURCE_URL:=http://mupdf.googlecode.com/files/
PKG_MD5SUM:=76640ee16a797a27fe49cc0eaa87ce3a

include $(INCLUDE_DIR)/package.mk

define Package/mupdf/Default
  URL:=http://www.mupdf.com
  DEPENDS:=+jbig2dec +openjpeg +zlib +libfreetype +libjpeg
endef

define Package/mupdf
  $(call Package/mupdf/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=lightweight PDF viewer and toolkit written in portable C
endef

define Package/mupdf-tools
  $(call Package/mupdf/Default)
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Command-line PDF tools
endef

define Package/mupdf/description
  MuPDF is a lightweight PDF viewer and toolkit written in portable C.
endef

define Package/mupdf-tools/description
  This package installs command-line tools: pdfclean, pdfinfo, pdfdraw, pdfextract, pdfshow
endef

MAKE_FLAGS+=build=release prefix=/usr verbose=true CROSSCOMPILE="yes" NOX11="yes" os=Linux
TARGET_CFLAGS+= -I$(STAGING_DIR)/usr/include/freetype2
TARGET_LDFLAGS+= \
       -Wl,-rpath-link=$(STAGING_DIR)/usr/lib

define Build/Configure
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/build
	$(CP) $(FILES_DIR)/generated $(PKG_BUILD_DIR)/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/pdf/mupdf.h \
		$(PKG_BUILD_DIR)/fitz/fitz.h \
		$(PKG_BUILD_DIR)/apps/pdfapp.h \
		$(1)/usr/include/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) -a \
		$(PKG_BUILD_DIR)/build/release/lib*.so* \
		$(1)/usr/lib/
endef

define Package/mupdf/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) -a \
		$(PKG_BUILD_DIR)/build/release/lib*.so* \
		$(1)/usr/lib/
endef

define Package/mupdf-tools/install
	$(INSTALL_DIR) \
		$(1)/usr/bin

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/build/release/{pdfclean,pdfinfo,pdfdraw,pdfextract,pdfshow} \
		$(1)/usr/bin

endef

$(eval $(call BuildPackage,mupdf))
$(eval $(call BuildPackage,mupdf-tools))
