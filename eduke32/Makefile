#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=eduke32
PKG_VERSION:=1.4.0
PKG_RELEASE:=2
PKG_REV:=b49a0c62bb619f6e2e72704d1bcc4a1dc0b83d72

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/eduke32-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/eduke32
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Duke Nukem 3D Game
  URL:=http://www.3drealms.com
  DEPENDS=+libsdl +libsdl-mixer +libvorbis +libogg
endef

define Package/eduke32/description
	SDL port of the PC 3D shooter Duke Nukem 3D
endef

define Package/eduke32/install
	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/eduke32 $(1)/usr/bin/eduke32
endef

$(eval $(call BuildPackage,eduke32))
