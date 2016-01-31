# 
# Copyright (c) 2010 wejp
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gmu
PKG_VERSION:=0.9.1
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://wejp.k.vu/files/
PKG_MD5SUM:=b9beb8ae21828c637821fcc98b989603

include $(INCLUDE_DIR)/package.mk

define Package/gmu
  SECTION:=multimedia
  CATEGORY:=Multimedia
  TITLE:=Gmu Music Player
  URL:=http://wejp.k.vu/projects/gmu/
  MENU:=1
  DEPENDS:=+libsdl +libsdl-image +libsdl-gfx +libmpcdec +libmikmod \
	+libvorbisidec +libspeex +libflac +libogg +libncurses \
	+libncursesw +BUILD_PATENTED:libmpg123
endef

define Package/gmu/description
  A popular music player for various handheld devices.
  It supports various file formats and comes with a
  file browser and a playlist editor/viewer.
endef

#LFLAGS='$(TARGET_LDFLAGS) -Wl,-rpath-link=$(STAGING_DIR)/usr/lib -L$(STAGING_DIR)/usr/lib/SDL $(STAGING_DIR)/usr/lib/libncursesw.a -lSDL -lasound -lpthread -lm -ldl -lz -lgcc -Wl,-export-dynamic' \

MAKE_VARS += CC='$(TARGET_CC)' CXX='$(TARGET_CXX)' STRIP='$(TARGET_STRIP)' \
	CFLAGS='-O3 -ffast-math -fno-strict-aliasing -fomit-frame-pointer $(TARGET_CFLAGS) -I$(STAGING_DIR)/usr/include/SDL -DFILE_HW_H="\"hw_zipit-z2.h\"" -D_GNU_SOURCE=1 -D_REENTRANT' \
	LFLAGS='$(TARGET_LDFLAGS) -Wl,-rpath-link=$(STAGING_DIR)/usr/lib -L$(STAGING_DIR)/usr/lib/SDL -lSDL -lasound -lpthread -lncurses -lm -ldl -lz -lgcc -Wl,-export-dynamic' \
	PREFIX=/usr \
	TARGET=zipit-z2

define Package/gmu/install
	$(INSTALL_DIR) \
		$(1)/usr/bin \
		$(1)/usr/share/gmu \
		$(1)/usr/share/gmu/themes/default-modern \
		$(1)/usr/share/gmu/htdocs
#		$(1)/etc/gmu \
#		$(1)/usr/share/gmu/decoders \
#		$(1)/usr/share/gmu/frontends \

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/gmuc \
		$(1)/usr/bin/gmuc
	
	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/gmu.bin \
		$(1)/usr/bin/gmu.bin
		
	$(INSTALL_BIN) \
		./files/gmu \
		$(1)/usr/bin/

#	$(INSTALL_BIN) \
#		$(PKG_BUILD_DIR)/decoders/* \
#		$(1)/usr/share/gmu/decoders/

#	$(INSTALL_BIN) \
#		$(PKG_BUILD_DIR)/frontends/* \
#		$(1)/usr/share/gmu/frontends/


#	$(INSTALL_DATA) \
#		$(PKG_BUILD_DIR)/*z2*.conf \
#		$(1)/etc/gmu/
		
#	$(INSTALL_DATA) \
#		$(PKG_BUILD_DIR)/*z2*.keymap \
#		$(1)/etc/gmu/
		
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/themes/default-modern/* \
		$(1)/usr/share/gmu/themes/default-modern/

	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/htdocs/* \
		$(1)/usr/share/gmu/htdocs/

#	$(INSTALL_DATA) \
#		$(PKG_BUILD_DIR)/README.txt \
#		$(1)/usr/share/gmu/
endef

$(eval $(call BuildPackage,gmu))
