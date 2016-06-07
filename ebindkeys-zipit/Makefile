#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ebindkeys-zipit
PKG_VERSION:=2016.06.02
PKG_RELEASE:=2
PKG_REV:=bldaemon

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/ebindkeys-zipit.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/ebindkeys-zipit
  SECTION:=utilities
  CATEGORY:=Utilities
  TITLE:=bind a key or key combo to a command
  DEPENDS:=+kmod-input-uinput +kmod-input-evdev +libpthread
  URL:=http://home.vay8.net/doku.php?id=ebindkeys-zipit
endef

define Package/ebindkeys-zipit/description
	ebindkeys-zipit lets you bind a key or key-combo to a command, now with keymouse and bldaemon
endef

define Package/ebindkeys-zipit/install
	$(INSTALL_DIR) $(1)/usr/sbin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/ebindkeys $(1)/usr/sbin/
	$(INSTALL_DIR) $(1)/usr/local/sbin
		$(INSTALL_BIN) ./files/onHome $(1)/usr/local/sbin/onHome
		$(INSTALL_BIN) ./files/onAltTab $(1)/usr/local/sbin/onAltTab
		$(INSTALL_BIN) ./files/onPowerDown $(1)/usr/local/sbin/onPowerDown
	$(INSTALL_DIR) $(1)/usr/share/ebindkeys
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/ebindkeysrc.sample $(1)/usr/share/ebindkeys/
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/zipit-keys $(1)/usr/share/ebindkeys/
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/README $(1)/usr/share/ebindkeys/
	$(INSTALL_DIR) $(1)/etc
		$(INSTALL_DATA) ./files/ebindkeysrc $(1)/etc/ebindkeysrc
	$(INSTALL_DIR) $(1)/etc/init.d
		$(INSTALL_BIN) ./files/S10ebkdaemon $(1)/etc/init.d/S10ebkdaemon
endef

$(eval $(call BuildPackage,ebindkeys-zipit))
