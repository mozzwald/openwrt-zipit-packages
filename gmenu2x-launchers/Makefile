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
  DEPENDS:=+gmenu2x +tmux
  VARIANT:=gmenu2x-tmux
endef

define Package/gmenu2x-tmux/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ 
	$(CP) \
		./files/tmux/gmenu2x/* \
		$(1)/usr/share/gmenu2x/

	$(INSTALL_DIR) $(1)/etc/ 
	$(CP) \
		./files/tmux/tmux.conf \
		$(1)/etc/tmux.conf
endef

$(eval $(call BuildPackage,gmenu2x-tmux))

define Package/gmenu2x-ohboy
  CATEGORY:=GMenu2X
  TITLE:=ohboy launcher for gmenu2x
  DEPENDS:=+gmenu2x +ohboy
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

define Package/gmenu2x-links
  CATEGORY:=GMenu2X
  TITLE:=links launcher for gmenu2x
  DEPENDS:=+gmenu2x +links
  VARIANT:=gmenu2x-links
endef

define Package/gmenu2x-links/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ \

	$(CP) \
		./files/links/* \
		$(1)/usr/share/gmenu2x/
endef

$(eval $(call BuildPackage,gmenu2x-links))

define Package/gmenu2x-gmu
  CATEGORY:=GMenu2X
  TITLE:=GMU launcher for gmenu2x
  DEPENDS:=+gmenu2x +gmu
  VARIANT:=gmenu2x-gmu
endef

define Package/gmenu2x-gmu/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ \

	$(CP) \
		./files/gmu/* \
		$(1)/usr/share/gmenu2x/
endef

$(eval $(call BuildPackage,gmenu2x-gmu))

define Package/gmenu2x-burgerspace
  CATEGORY:=GMenu2X
  TITLE:=Burgerspace launcher for gmenu2x
  DEPENDS:=+gmenu2x +burgerspace
  VARIANT:=gmenu2x-burgerspace
endef

define Package/gmenu2x-burgerspace/install
	$(INSTALL_DIR) \
		$(1)/usr/share/gmenu2x/ \

	$(CP) \
		./files/burgerspace/* \
		$(1)/usr/share/gmenu2x/
endef

$(eval $(call BuildPackage,gmenu2x-burgerspace))

