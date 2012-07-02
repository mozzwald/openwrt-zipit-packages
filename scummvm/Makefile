# Copyright (C) 2010 tuxbrain.com
#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=scummvm
PKG_VERSION:=1.4.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_CAT:=bzcat

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/scummvm
    TITLE:=free implementation of LucasArts SCUMM interpreter
    SECTION:=games
    CATEGORY:=Games
    URL:=http://www.scummvm.org/
	 DEPENDS:=$(ICONV_DEPENDS) +libsdl +libsdl-sound +libsdl-mixer +libmad +libstdcpp +libasound +libpng +libpthread +libvorbis +libz
endef
PKG_BUILD_DIR:=$(BUILD_DIR)/scummvm-$(PKG_VERSION)

define Package/scummvm/description
	ScummVM is a program which allows you to run certain classic graphical point-and-click adventure games, provided you already have their data files. The clever part about this: ScummVM just replaces the executables shipped with the games, allowing you to play them on systems for which they were never designed! 
endef

MAKE_FLAGS += AR="$(TARGET_CROSS)ar cru" LD="$(TARGET_CXX)"

TARGET_CFLAGS += -Wno-psabi

define Build/Configure
	$(call Build/Configure/Default, --backend=sdl --enable-tremor --enable-alsa --enable-zlib --disable-nasm --enable-mad --disable-scalers  --disable-mt32emu --disable-hq-scalers --with-sdl-prefix=$(STAGING_DIR)/usr/bin)

endef

define Package/scummvm/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/scummvm $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/scummvm
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/gui/themes/*.zip $(1)/usr/share/scummvm
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dists/engine-data/*.dat $(1)/usr/share/scummvm
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dists/engine-data/*.tbl $(1)/usr/share/scummvm
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dists/engine-data/*.cpt $(1)/usr/share/scummvm
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dists/pred.dic $(1)/usr/share/scummvm
endef

$(eval $(call BuildPackage,scummvm))
