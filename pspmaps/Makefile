#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pspmaps
PKG_VERSION:=2.2
PKG_RELEASE:=1

PKG_SOURCE:=PSP-Maps-2.2.tar.gz
PKG_BUILD_DIR=$(BUILD_DIR)/PSP-Maps-$(PKG_VERSION)
PKG_SOURCE_URL:=http://royale.zerezo.com/psp

include $(INCLUDE_DIR)/package.mk

define Package/pspmaps
  TITLE:=pspmaps
  SECTION:=utils
  CATEGORY:=Utilities
  URL:=http://royale.zerezo.com/psp/
  DEPENDS:=+libsdl +libsdl-image +libsdl-gfx +libsdl-mixer +libsdl-ttf +libxml2 +libcurl
endef

define Package/pspmaps/description
	Map viewer using google maps service.
endef

MAKE_VARS += \
	CURLCONFIG=$(STAGING_DIR)/host/bin/curl-config \
	SDLCONFIG=$(STAGING_DIR)/host/bin/sdl-config \
	XMLCONFIG=$(STAGING_DIR)/host/bin/xml2-config

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
