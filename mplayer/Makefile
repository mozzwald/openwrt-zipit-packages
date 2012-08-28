# 
# OpenWrt
#
# This is free software, licensed under the GNU General Public License v2.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mplayer
PKG_REV:=32726
PKG_VERSION:=r$(PKG_REV)
PKG_RELEASE:=1

PKG_SOURCE=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=svn://svn.mplayerhq.hu/mplayer/trunk
PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/mplayer
  SECTION:=multimedia
  CATEGORY:=Multimedia
  TITLE:=MPlayer, the movie player
  URL:=http://www.mplayerhq.hu
  DEPENDS:=+libjpeg +libpng +zlib +libfreetype +fontconfig $(ICONV_DEPENDS) +libmad +libaa +giflib +fribidi +libtheora +libggi
  DEPENDS+=+alsa-lib +libfaad2 +libmpcdec +libmpg123 +libspeex +libpthread
endef

define Package/mplayer/description
  MPlayer is a movie player which runs on many systems.
endef

CONFIGURE_ARGS := \
		--prefix=/usr \
		--confdir=/etc \
		--target=$(TARGET_CROSS) \
		--host-cc=gcc \
		--cc="$(TARGET_CC)" \
		--as="$(TARGET_AS)" \
		--charset=UTF-8 \
		--extra-cflags="$(TARGET_CFLAGS)" \
		--extra-ldflags="$(TARGET_LDFLAGS)" \
		--yasm='' \
		--enable-mad \
		--enable-tremor-internal \
		--disable-mp3lib \
		--enable-fbdev \
		--enable-alsa \
		--enable-largefiles \
		--disable-sdl \
		--enable-mplayer \
		--disable-mencoder \
		--enable-armv5te \
		--enable-cross-compile \
		--disable-ivtv \
		--enable-dynamic-plugins \
		--enable-pxa

# mplayer makefile is soooo broken.  have to specify libs by hand, if
# compileing with --enable-system-ffmpeg
# TARGET_CFLAGS+= -std=c99 -DPATH_MAX=512 -D_GNU_SOURCE
# -lavcore

# todo: remove once building correctly
MAKE_FLAGS = -j4

define Package/mplayer/install
	$(INSTALL_DIR) \
		$(1)/usr/bin \
		$(1)/etc

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/mplayer \
		$(1)/usr/bin/mplayer
	$(INSTALL_DATA) \
		$(FILES_DIR)/mplayer.conf \
		$(1)/etc/

endef

$(eval $(call BuildPackage,mplayer))
