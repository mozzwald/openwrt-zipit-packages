#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nupdf
PKG_VERSION:=621ae34de6
PKG_REV:=621ae34de6fcd4f9306838d594ae7b39d41d3aac
PKG_RELEASE:=1


PKG_SOURCE_URL:=git://github.com/deeice/nupdf.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

include $(INCLUDE_DIR)/package.mk

define Package/nupdf
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=relatively fast pdf reader in SDL
  URL:=http://code.google.com/p/nupdf/
  DEPENDS:=+mupdf +libsdl
endef

define Package/nupdf/description
  nupdf is a relatively fast pdf reader; it uses the mupdf library to render pages/handle files, and SDL for the UI
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/usr/include -DZIPIT_Z2

TARGET_LDFLAGS += \
	-Wl,-rpath-link=$(STAGING_DIR)/usr/lib \
	-ldl -lSDL -lmupdf -lfitz \
	-lfreetype -lpthread \
	-lm -ljpeg -lz

#	cp -f files/pdfapp.* $(PKG_BUILD_DIR)
#	cp -f files/main.c $(PKG_BUILD_DIR)

define Build/Compile
	$(TARGET_CC) $(PKG_BUILD_DIR)/*.c -o $(PKG_BUILD_DIR)/nupdf $(TARGET_CFLAGS) -L$(PKG_BUILD_DIR) $(TARGET_LDFLAGS)
	$(TARGET_CROSS)strip $(PKG_BUILD_DIR)/nupdf
endef

define Package/nupdf/install
	$(INSTALL_DIR) \
		$(1)/usr/bin $(1)/usr/share/nupdf

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/nupdf $(1)/usr/share/nupdf/nupdf.bin

	$(INSTALL_BIN) \
		$(FILES_DIR)/nupdf.sh $(1)/usr/bin/nupdf

	$(CP) \
		$(PKG_BUILD_DIR)/{data,config} $(1)/usr/share/nupdf
endef

$(eval $(call BuildPackage,nupdf))
