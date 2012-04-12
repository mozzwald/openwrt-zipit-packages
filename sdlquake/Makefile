# 
# Copyright (c) 2010 mozzwald
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sdlquake
PKG_VERSION:=1.0.9
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.libsdl.org/projects/quake/src/
PKG_MD5SUM:=6465dc6545970352dfa6305c36c2403d

include $(INCLUDE_DIR)/package.mk

define Package/sdlquake
  SECTION:=games
  CATEGORY:=Games
  TITLE:=sdluake
  URL:=http://www.libsdl.org/projects/quake/
  MENU:=1
  DEPENDS:=+libsdl
endef

define Package/sdlquake/description
  Port of ID Software's popular Quake 3-D shooter game
endef

define Build/Configure
	$(call Build/Configure/Default, \
 		--program-prefix="" \
 		--program-suffix="" \
 		--prefix=/usr \
	);
endef

EXTRA_LDFLAGS=	-Wl,-rpath-link=$(STAGING_DIR)/usr/lib \
		-L$(STAGING_DIR)/usr/lib/SDL \
		-L$(STAGING_DIR)/usr/lib \
		-rpath=$(STAGING_DIR)/usr/lib \

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		LDFLAGS="$(LDFLAGS) $(EXTRA_LDFLAGS)" \
		$(TARGET_CONFIGURE_OPTS) \
		CROSS="$(TARGET_CROSS)" \
		ARCH="$(ARCH)" \
		$(1);
endef

define Package/sdlquake/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/sdlquake $(1)/usr/bin/
endef

$(eval $(call BuildPackage,sdlquake))
