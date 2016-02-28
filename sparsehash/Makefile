# 
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sparsehash
PKG_VERSION:=2.0.3
PKG_RELEASE:=2
PKG_REV:=sparsehash-2.0.3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=git://github.com/sparsehash/sparsehash.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

define Package/sparsehash
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Sparsehash
  BUILDONLY:=1
  URL:=https://github.com/sparsehash/sparsehash
endef

define Package/sparsehash/description
	An extremely memory-efficient hash_map implementation. 2 bits/entry overhead! The SparseHash library contains several hash-map implementations, including implementations that optimize for space or speed.
	These hashtable implementations are similar in API to SGI's hash_map class and the tr1 unordered_map class, but with different performance characteristics. It's easy to replace hash_map or unordered_map by sparse_hash_map or dense_hash_map in C++ code.
endef

define Build/InstallDev
	$(INSTALL_DIR) \
		$(1)/usr/include/google

	$(CP) \
		$(PKG_INSTALL_DIR)/usr/include/google/* \
		$(1)/usr/include/google/
endef

$(eval $(call BuildPackage,sparsehash))
