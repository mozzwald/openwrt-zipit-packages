#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fancy-beeper-daemon
PKG_VERSION:=1.0
PKG_RELEASE:=1
PKG_REV:=97f5bb22a9e748a38c0292a061245511d2ca9969

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/mozzwald/Fancy-Beeper-Daemon.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/fancy-beeper-daemon
  SECTION:=utilities
  CATEGORY:=Utilities
  TITLE:=Run a script or play a sound file on terminal bell
  DEPENDS:=+kmod-fancy-beeper
  URL:=https://github.com/mozzwald/Fancy-Beeper-Daemon
endef

define Package/fancy-beeper-daemon/description
	Run a script or play a sound file when there is a terminal bell
endef

define Build/Compile
	( cd $(PKG_BUILD_DIR) ; \
		$(TARGET_CC) $(TARGET_CFLAGS) daemons/beepcmd/beepcmd.c -o ./beepcmd $(TARGET_LDFLAGS) ; \
	)
endef

define Package/fancy-beeper-daemon/install
	$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/beepcmd $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/sounds
		$(INSTALL_DATA) ./files/z2beep.wav $(1)/usr/share/sounds/z2beep.wav
	$(INSTALL_DIR) $(1)/etc/init.d
		$(INSTALL_BIN) ./files/S99beepcmd $(1)/etc/init.d/S99beepcmd
endef

$(eval $(call BuildPackage,fancy-beeper-daemon))
