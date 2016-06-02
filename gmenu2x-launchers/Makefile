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

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)/$(BUILD_VARIANT)

include $(INCLUDE_DIR)/package.mk

define Build/Compile

endef

define Package/gmenu2x-tmux
  CATEGORY:=GMenu2X
  TITLE:=tmux launcher for gmenu2x
  DEPENDS:=+tmux
  VARIANT:=gmenu2x-tmux
endef

define Package/gmenu2x-tmux/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ \

	$(CP) \
		./files/tmux/* \
		$(1)/usr/share/gmenu2x/
endef

$(eval $(call BuildPackage,gmenu2x-tmux))

define Package/gmenu2x-ohboy
  CATEGORY:=GMenu2X
  TITLE:=ohboy launcher for gmenu2x
  DEPENDS:=+ohboy
  VARIANT:=gmenu2x-ohboy
endef

define Package/gmenu2x-ohboy/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ \

	$(CP) \
		./files/ohboy/* \
		$(1)/usr/share/gmenu2x/
endef

$(eval $(call BuildPackage,gmenu2x-ohboy))

