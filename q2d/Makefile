#
# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=q2d
PKG_VERSION:=0.0.3
PKG_RELEASE:=1
#PKG_VERSION:=0.0.5
#PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=http://sourceforge.net/projects/q2d/files/
PKG_SOURCE_URL:=https://mozzwald.com/zipit/openwrt/packages/
PKG_MD5SUM:=0e2ff5cbddc37f9bf2c7b3647952883a
#PKG_MD5SUM:=c2a383ee3f1842f6c0973b79239751a3

include $(INCLUDE_DIR)/package.mk

define Package/q2d
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libsdl
  TITLE:=Program for live 2d graphical representation of data streams
  URL:=http://q2d.sourceforge.net/
endef

define Package/q2d/description
Quick2dPlot, or q2d for short, is an open source minimalistic plotting 
program designed for live 2d graphical representation of data streams. 
The program may be useful for plotting output of different user's 
application programs, especially in case when the user wants to see a 
plot or a number of plots during calculations or a data acquisition 
process. The program is command-driven and uses no widgets. Q2d is 
written in C, it takes advantage of SDL library for plotting and seems 
to be reasonably fast
endef

MAKE_PATH := src
#MAKE_VARS += \
#	exeext=""

#TAR_CMD:=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components 1 $(TAR_OPTIONS)

#TARGET_CPPFLAGS += \
#	-DUCL_NO_ASM \

define Package/q2d/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/q2d $(1)/usr/bin/
endef

$(eval $(call BuildPackage,q2d))
