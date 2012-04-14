#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sdlquake-shareware-data
PKG_VERSION:=1.0.6
PKG_RELEASE:=1

PKG_SOURCE:=quakesw-1.0.6.tar.gz
PKG_SOURCE_URL:=http://www.libsdl.org/projects/quake/data
PKG_SOURCE_SUBDIR:=id1
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/sdlquake-shareware-data
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Shareware data for sdlquake
  URL:=http://www.libsdl.org/projects/quake
  DEPENDS:=+sdlquake
endef

define Package/sdlquake-shareware-data/description
	Shareware data of id software's Quake
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	tar xvf $(TOPDIR)/dl/$(PKG_SOURCE) -C $(PKG_BUILD_DIR)
endef

define Build/Compile
	#do nothing
endef

define Package/sdlquake-shareware-data/install
	$(INSTALL_DIR) $(1)/usr/games/sdlquake/id1
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/id1/pak0.pak $(1)/usr/games/sdlquake/id1
		$(INSTALL_BIN) ./files/config.cfg $(1)/usr/games/sdlquake/id1
endef

$(eval $(call BuildPackage,sdlquake-shareware-data))
