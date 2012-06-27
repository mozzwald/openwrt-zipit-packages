#
# Copyright (C) 2009 Qi Hardware Inc.
# Author: Xiangfu Liu <xiangfu@qi-hardware.com>
# 
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=links
PKG_VERSION:=2.3pre1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://links.twibright.com/download/

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/links
    MAINTAINER:="Xiangfu Liu" <xiangfu@sharism.cc>
    TITLE:=Text and graphics WWW browser
    SUBMENU:=Web
    SECTION:=net
    CATEGORY:=Network
    URL:=http://links.twibright.com/
    DEPENDS:=+libpng +libtiff +libopenssl +libsdl +libjpeg
endef

define Package/links/description
    Text and graphics WWW browser
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) $(FILES_DIR)/directfb-config $(PKG_BUILD_DIR)
	$(CP) $(FILES_DIR)/configure $(PKG_BUILD_DIR)
endef

CONFIGURE_ARGS += --enable-graphics \
  --enable-debuglevel=0 \
  --with-ssl \
  --with-sdl \
  --without-gpm \
  --without-pmshell \
  --without-atheos \
  --without-svgalib \
  --without-fb \
  --without-directfb \
  --without-x

#TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include/directfb
TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include/SDL

CONFIGURE_VARS += \
	DIRECTFB_CONFIG="$(PKG_BUILD_DIR)/directfb-config $(STAGING_DIR)"
#CONFIGURE_VARS += \
#	SDL_CONFIG="$(PKG_BUILD_DIR)/sdl-config $(STAGING_DIR)"
#DIRECTFB_CONFIG="$(STAGING_DIR)/root-xburst/usr/bin/directfb-config"

#Try this instead for sdl-config
# Maybe I should add this dir to the path for configure.
CONFIGURE_VARS += \
	SDL_CONFIG="$(STAGING_DIR)/usr/bin/sdl-config"
#CONFIGURE_VARS += \
#	SDL_CONFIG="$(STAGING_DIR)/target-arm_v5te_uClibc-0.9.33_eabi/usr/bin/sdl-config"

define Package/links/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/links $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/root/.links
	$(INSTALL_BIN) ./files/links.his $(1)/root/.links/
	$(INSTALL_BIN) ./files/links.cfg $(1)/root/.links/
	$(INSTALL_BIN) ./files/html.cfg $(1)/root/.links/
	$(INSTALL_BIN) ./files/linkskeys.txt $(1)/root/.links/
endef

$(eval $(call BuildPackage,links))
