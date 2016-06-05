# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.

include $(TOPDIR)/rules.mk

PKG_NAME:=netsurf
PKG_VERSION:=3.3
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-src.tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/netsurf/releases/source/
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/netsurf
	MAINTAINER:="Xiangfu Liu" <xiangfu@sharism.cc>
	SUBMENU:=Web
	SECTION:=network
	CATEGORY:=Network
	TITLE:=netsurf
	URL:=http://www.netsurf-browser.org/
	DEPENDS:=+libjpeg +libpng +libsdl +libcss +libdom +libhubbub \
		+libparserutils +libnsfb +libnsgif +libnsbmp +libutf8proc \
		+libnsutils +libxml2 +libcurl +libfreetype +liberation-fonts-ttf \
		+libopenssl $(ICONV_DEPENDS)
	PKG_BUILD_DEPENDS:=+netsurf-buildsystem
endef

define Package/netsurf/description
	NetSurf is a free, open source web browser. It is written in C and released under the GNU Public Licence version 2. NetSurf has its own layout and rendering engine entirely written from scratch. It is small and capable of handling many of the web standards in use today.
endef

MAKE_FLAGS += "TARGET=framebuffer" \
    NSSHARED=$(STAGING_DIR)/usr/share/netsurf-buildsystem \
    PREFIX=/usr
    
TARGET_CFLAGS += $(ICONV_CFLAGS) -I$(STAGING_DIR)/usr/include/SDL
TARGET_LDFLAGS += $(ICONV_LDFLAGS) -liconv -Wl,-rpath-link=$(STAGING_DIR)/usr/lib

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) $(FILES_DIR)/Makefile.config $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(MAKE_VARS) \
	$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR)/$(MAKE_PATH) \
		$(MAKE_FLAGS)
endef


define Package/netsurf/install
	$(INSTALL_DIR) \
		$(1)/usr/bin $(1)/usr/share/netsurf

	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/usr/bin/netsurf \
		$(1)/usr/bin/

	$(INSTALL_DATA) \
		$(PKG_INSTALL_DIR)/usr/share/netsurf/* \
		$(1)/usr/share/netsurf/


	$(CP) $(FILES_DIR)/Choices $(1)/usr/share/netsurf/
	$(CP) $(FILES_DIR)/Cookies $(1)/usr/share/netsurf/
endef

$(eval $(call BuildPackage,netsurf))
