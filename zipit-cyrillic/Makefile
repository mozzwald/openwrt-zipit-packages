# 
# OpenWrt
#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=zipit-cyrillic
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/zipit-cyrillic
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Cyrillic stuff for Zipit Z2
  SUBMENU:=Terminal
endef

define Build/Compile
endef

define Package/zipit-cyrillic/description
  Cyrillic stuff for Zipit Z2
  Use the "Alt+Ctrl" key to switch between input languages.
endef

define Package/zipit-cyrillic/install
	$(INSTALL_DIR) \
		$(1)/etc/console-setup

	$(INSTALL_BIN) \
		$(FILES_DIR)/keymap-2.6-ru.map \
		$(1)/etc/console-setup
endef

$(eval $(call BuildPackage,zipit-cyrillic))
