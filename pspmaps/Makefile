#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=PSP-Maps
PKG_VERSION:=3e86689ae1
PKG_REV:=3e86689ae177e22b8ce4b49d7dca8208006c4a69
PKG_RELEASE:=2
PKG_INSTALL:=1
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=git://github.com/deeice/PSP-Maps.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/pspmaps
  TITLE:=pspmaps
  SECTION:=utils
  CATEGORY:=Utilities
  URL:=https://github.com/deeice/PSP-Maps/
  DEPENDS:=+libsdl +libsdl-image +libsdl-gfx +libsdl-ttf +libcurl
endef

define Package/pspmaps/description
	Map viewer using google maps service.
endef

MAKE_VARS += \
	CURLCONFIG=$(STAGING_DIR)/host/bin/curl-config \
	SDLCONFIG=$(STAGING_DIR)/host/bin/sdl-config

MAKE_FLAGS += -f Makefile.zipit

TARGET_LDFLAGS+= \
       -Wl,-rpath-link=$(STAGING_DIR)/usr/lib

define Package/pspmaps/install
	$(INSTALL_DIR) \
		$(1)/usr/bin/

	$(INSTALL_DIR) \
		$(1)/usr/share/pspmaps/

	$(INSTALL_BIN) \
		$(FILES_DIR)/pspmaps \
		$(1)/usr/bin/pspmaps

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/pspmaps \
		$(1)/usr/share/pspmaps/pspmaps

	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/urls.txt \
		$(1)/usr/share/pspmaps/

	$(CP) $(PKG_BUILD_DIR)/data $(1)/usr/share/pspmaps/
endef

$(eval $(call BuildPackage,pspmaps))
