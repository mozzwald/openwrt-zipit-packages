#
# Copyright (C) 2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gmenu2x-launchers
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(PKG_NAME)

#PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=git://github.com/mozzwald/gmenu2x-zipit.git
#PKG_SOURCE_PROTO:=git
#PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
#PKG_SOURCE_VERSION:=$(PKG_REV)

#PKG_BUILD_DEPENDS:=sparsehash

include $(INCLUDE_DIR)/package.mk

define Build/Compile

endef

define Package/gmenu2x-tmux
  CATEGORY:=GMenu2X
  TITLE:=tmux launcher for gmenu2x
  DEPENDS:=+tmux
endef

define Package/gmenu2x-tmux/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ \

	$(CP) \
		./files/tmux/* \
		$(1)/usr/share/gmenu2x/
endef

$(eval $(call BuildPackage,gmenu2x-tmux))
