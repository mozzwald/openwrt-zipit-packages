# NOT FINISH YET
#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=flatzebra
PKG_VERSION:=0.1.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://mozzwald.com/zipit/src/

include $(INCLUDE_DIR)/package.mk

define Package/flatzebra
  SECTION:=games
  CATEGORY:=Games
  TITLE:=A generic game engine for 2D double-buffering animation
  URL:=http://perso.b2b2c.ca/sarrazip/dev/flatzebra.html
  DEPENDS:=+libstdcpp +libsdl-image +libsdl-mixer
endef

CONFIGURE_ARGS += --disable-sdltest \
	--with-sdl-prefix=$(STAGING_DIR)/usr \
	--with-sdl-exec-prefix=$(STAGING_DIR)/usr
TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include/SDL
TARGET_LDFLAGS+= -Wl,-rpath-link=$(STAGING_DIR)/usr/lib

define Build/InstallDev
	mkdir -p $(STAGING_DIR)/usr/include/flatzebra-0.1
	mkdir -p $(STAGING_DIR)/usr/include/flatzebra-0.1/flatzebra
	$(CP) $(PKG_BUILD_DIR)/src/flatzebra/*.h $(STAGING_DIR)/usr/include/flatzebra-0.1/flatzebra/
	$(CP) $(PKG_BUILD_DIR)/src/flatzebra/.libs/libflatzebra-0.1.so.* $(STAGING_DIR)/usr/lib/
	$(CP) ./files/flatzebra-0.1.pc $(STAGING_DIR)/usr/lib/pkgconfig/
	$(CP) $(STAGING_DIR)/usr/lib/libflatzebra-0.1.so.2.0.0 $(STAGING_DIR)/usr/lib/libflatzebra-0.1.so
endef

define Package/flatzebra/install
	$(INSTALL_DIR) \
		$(1)/usr/lib
	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/src/flatzebra/.libs/libflatzebra-0.1.so.* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,flatzebra))
