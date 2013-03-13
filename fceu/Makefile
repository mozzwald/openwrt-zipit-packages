#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fceu
PKG_RELEASE:=1
PKG_REV:=67
PKG_VERSION:=r$(PKG_REV)

PKG_SOURCE_URL:=http://fceu.googlecode.com/svn/trunk/
PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

#PKG_CAT:=tar --strip=1 -xzvf 
#PKG_BUILD_DIR=$(BUILD_DIR)/$(PKG_NAME)

PKG_BUILD_DIR=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/fceu
  SECTION:=games
  CATEGORY:=Games
  TITLE:=SDL version of fceu
  URL:=https://code.google.com/p/fceu
  DEPENDS:=+libsdl +liblua
endef

define Package/fceu/description
	Fceu NES emulator
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	( cd $(PKG_BUILD_DIR)/fceu; mv * .. )
endef

CONFIGURE_ARGS+=--with-lua=$(STAGING_DIR)/usr

TARGET_CFLAGS+=-I$(STAGING_DIR)/usr/include
TARGET_LDLAGS+=-Wl,-rpath-link=$(STAGING_DIR)/usr/lib

#CONFIGURE_CMD = ./autogen.sh

define Build/Configure
#	( cd $(PKG_BUILD_DIR); chmod +x ./autogen.sh; ./autogen.sh );
	( cd $(PKG_BUILD_DIR); aclocal; autoconf; automake -a -c --foreign )
	$(call Build/Configure/Default)
endef

#define Build/Compile
#	cd $(PKG_BUILD_DIR)/fceu; \
#	$(call Build/Compile/Default)
#endef

define Package/fceu/install
	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/fceu $(1)/usr/bin/
		$(INSTALL_BIN) ./files/runfceu $(1)/usr/bin
	$(INSTALL_DIR) $(1)/root/.fceultra
		$(INSTALL_BIN) ./files/fceu98.cfg $(1)/root/.fceultra/
	$(INSTALL_DIR) $(1)/root/.fceultra/fcs
	$(INSTALL_DIR) $(1)/root/.fceultra/fcm
	$(INSTALL_DIR) $(1)/root/.fceultra/snaps
	$(INSTALL_DIR) $(1)/root/.fceultra/gameinfo
	$(INSTALL_DIR) $(1)/root/.fceultra/sav
	$(INSTALL_DIR) $(1)/root/.fceultra/cheats
	$(INSTALL_DIR) $(1)/root/.fceultra/movie
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/sections/games
		$(INSTALL_BIN) ./files/fceu.gmenu $(1)/usr/share/gmenu2x/sections/games
	$(INSTALL_DIR) $(1)/usr/share/gmenu2x/skins/Default/icons
		$(INSTALL_BIN) ./files/fceu.png $(1)/usr/share/gmenu2x/skins/Default/icons
endef

$(eval $(call BuildPackage,fceu))
