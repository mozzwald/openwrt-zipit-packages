#
# OpenWrt
#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fheroes2
PKG_REV:=2864
PKG_VERSION:=r$(PKG_REV)
PKG_RELEASE:=1

PKG_SOURCE=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://fheroes2.svn.sourceforge.net/svnroot/fheroes2/trunk/fheroes2
PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/fheroes2
  SECTION:=games
  CATEGORY:=Games
  TITLE:=Free implementation of Heroes of the Might and Magic II engine
  URL:=http://sourceforge.net/projects/fheroes2/
  DEPENDS:=+libsdl +libpng +libtheora +libsdl +libsdl-mixer +libsdl-image +libsdl-ttf +libintl-full $(ICONV_DEPENDS)
endef

define Package/fheroes2/description
  Free implementation of Heroes of the Might and Magic II engine
endef

TARGET_CFLAGS += $(ICONV_CFLAGS) $(INTL_CFLAGS)
TARGET_LDFLAGS += $(ICONV_LDFLAGS) $(INTL_LDFLAGS) -liconv -lintl

MAKE_FLAGS += -j4 \
	PLATFORM=all \
	WITHOUT_NETWORK=y \
	PREFIX=/usr \
	CXX="$(TARGET_CXX)" \
	AR="$(TARGET_CROSS)ar"

define Build/Configure
endef

define Package/fheroes2/install
	$(INSTALL_DIR) $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/fheroes2
	$(CP) -r $(PKG_BUILD_DIR)/files $(1)/usr/share/fheroes2/
	$(CP) -r $(PKG_BUILD_DIR)/data $(1)/usr/share/fheroes2/
	$(CP) -r $(PKG_BUILD_DIR)/image $(1)/usr/share/fheroes2/
	$(CP) -r $(PKG_BUILD_DIR)/maps $(1)/usr/share/fheroes2/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fheroes2 $(1)/usr/bin/fheroes2
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/fheroes2.key $(1)/usr/share/fheroes2/
	$(INSTALL_DATA) $(FILES_DIR)/fheroes2.cfg $(1)/usr/share/fheroes2/
endef

$(eval $(call BuildPackage,fheroes2))
