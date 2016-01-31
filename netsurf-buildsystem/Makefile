# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.

include $(TOPDIR)/rules.mk

PKG_NAME:=netsurf-buildsystem
PKG_VERSION:=1.3
PKG_RELEASE:=1

PKG_SOURCE:=buildsystem-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/libs/releases/
PKG_BUILD_DIR:=$(BUILD_DIR)/buildsystem-$(PKG_VERSION)

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/netsurf-buildsystem
	MAINTAINER:="Xiangfu Liu" <xiangfu@sharism.cc>
	SUBMENU:=Web
	SECTION:=network
	CATEGORY:=Network
	TITLE:=netsurf
	URL:=http://www.netsurf-browser.org/
endef

define Package/netsurf-buildsystem/description
	NetSurf is a free, open source web browser. It is written in C and released under the GNU Public Licence version 2. NetSurf has its own layout and rendering engine entirely written from scratch. It is small and capable of handling many of the web standards in use today. This is the buildsystem for it.
endef

MAKE_FLAGS += "PREFIX=/usr"

define Build/Prepare
	$(call Build/Prepare/Default)
endef

define Build/Compile
	$(MAKE_VARS) \
	$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR)/$(MAKE_PATH) \
		$(MAKE_FLAGS)
endef


define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/share/netsurf-buildsystem
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/share/netsurf-buildsystem/* \
		$(1)/usr/share/netsurf-buildsystem/
endef

$(eval $(call BuildPackage,netsurf-buildsystem))
