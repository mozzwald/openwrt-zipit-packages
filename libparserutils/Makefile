include $(TOPDIR)/rules.mk

PKG_NAME:=libparserutils
PKG_VERSION:=0.2.1
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-src.tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/libs/releases/
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libparserutils
	MAINTAINER:="Xiangfu Liu" <xiangfu@sharism.cc>
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=LibParserUtils has some built-in charset converters
	URL:=http://www.netsurf-browser.org/projects/libparserutils/
	DEPENDS:= $(ICONV_DEPENDS)
	PKG_BUILD_DEPENDS:=+netsurf-buildsystem
endef

define Package/libparserutils/description
	LibParserUtils has the following built-in charset converters. UTF-8, UTF-16 (platform-native endian), ISO-8859-n, Windows-125n, US-ASCII.
endef

MAKE_FLAGS += NSSHARED=$(STAGING_DIR)/usr/share/netsurf-buildsystem \
    PREFIX=/usr \
    COMPONENT_TYPE=lib-shared \
    DESTDIR="$(PKG_INSTALL_DIR)"

TARGET_CFLAGS += $(ICONV_CFLAGS)
TARGET_LDFLAGS += $(ICONV_LDFLAGS)

define Build/Compile
	rm -rf $(PKG_INSTALL_DIR)
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR) \
		$(MAKE_FLAGS) \
		all install
endef

define Build/InstallDev
	mkdir -p $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
	mkdir -p $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

define Package/libparserutils/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libparserutils.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libparserutils))
