# 
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libsdl-rtf
PKG_VERSION:=0.1.0
PKG_RELEASE:=1

PKG_SOURCE:=SDL_rtf-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.libsdl.org/projects/SDL_rtf/release/
#PKG_MD5SUM:=8a787e538a8e4d80d4927535be5af083
PKG_BUILD_DIR:=$(BUILD_DIR)/SDL_rtf-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libsdl-rtf
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Simple DirectMedia Layer Rtf
  URL:=https://sourceforge.net/projects/sdlrtf/
  DEPENDS:=+libsdl +libsdl-ttf
endef

define Package/libsdl-rtf/description
  SDL_rtf is a sample library which allows you to display Rich Text Format (RTF) documents in your SDL applications. It comes with an example program showrtf which displays an RTF file using an SDL_ttf font engine. 
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include/SDL

CONFIGURE_VARS += \
	LIBS="-lSDL +libsdl-ttf"

define Build/Configure
    $(call Build/Configure/Default, \
      --with-sdl-exec-prefix=$(STAGING_DIR)\
    )
endef 

define Build/Compile
	rm -rf $(PKG_INSTALL_DIR)
	$(MAKE) -C $(PKG_BUILD_DIR) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Build/InstallDev
	$(INSTALL_DIR) \
		$(1)/usr/include/SDL \
		$(1)/usr/lib \
		$(1)/usr/lib/pkgconfig

	$(CP) \
		$(PKG_INSTALL_DIR)/usr/include/SDL/* \
		$(1)/usr/include/SDL/

	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/*.{a,so*} \
		$(1)/usr/lib/

	$(INSTALL_DATA) \
		$(PKG_INSTALL_DIR)/usr/lib/pkgconfig/* \
		$(1)/usr/lib/pkgconfig
endef

define Package/libsdl-rtf/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libSDL_rtf*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libsdl-rtf))
