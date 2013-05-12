#
# Copyright (C) 2013 zippy
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=milkytracker
PKG_VERSION:=0.90.85
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://www.milkytracker.org/files/

include $(INCLUDE_DIR)/package.mk

define Package/milkytracker
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=SDL-based Music Tracker
	DEPENDS:=+libsdl +libstdcpp
	URL:=http://www.milkytracker.org
endef

CONFIGURE_ARGS += --without-alsa \
  --without-jack \
  CPPFLAGS="-D__LOWRES__ -fomit-frame-pointer -fpermissive -fno-exceptions -fno-rtti" \
  COMPILED_BY=zippy

##
##  CFLAGS="-D__LOWRES__ -O2 -fomit-frame-pointer" \
##  CXXFLAGS="-D__LOWRES__ -O2 -fomit-frame-pointer" \

MAKE_VARS += CC='$(TARGET_CC)' CXX='$(TARGET_CXX)' STRIP='$(TARGET_STRIP)' \
	CFLAGS='$(TARGET_CFLAGS) -I$(STAGING_DIR)/usr/include/SDL -D__LOWRES__' \
	CPPFLAGS='$(TARGET_CFLAGS) -I$(STAGING_DIR)/usr/include/SDL -D__LOWRES__ -fomit-frame-pointer -fpermissive -fno-exceptions -fno-rtti' \
	LFLAGS='$(TARGET_LDFLAGS) -Wl,-rpath-link=$(STAGING_DIR)/usr/lib -L$(STAGING_DIR)/usr/lib/SDL -lSDL -lpthread' \

define Package/milkytracker/install
	$(INSTALL_DIR) \
		$(1)/usr/bin \
		$(1)/usr/share/milkytracker \
		$(1)/usr/share/milkytracker/docs \
		$(1)/usr/share/milkytracker/songs

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/src/tracker/milkytracker \
		$(1)/usr/share/milkytracker/
#		$(1)/usr/bin/

	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/docs/* \
		$(1)/usr/share/milkytracker/docs/

	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/resources/music/* \
		$(1)/usr/share/milkytracker/songs/
endef

$(eval $(call BuildPackage,milkytracker))
