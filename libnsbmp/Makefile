include $(TOPDIR)/rules.mk

PKG_NAME:=libnsbmp
PKG_VERSION:=0.0.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-src.tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/libs/releases/
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libnsbmp
	MAINTAINER:=Vasily Khoruzhick <anarsoul@gmail.com>
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Libnsbmp is a decoding library for BMP and ICO image file formats, written in C
	URL:=http://www.netsurf-browser.org/projects/libnsbmp/
	DEPENDS:=
endef

define Package/libnsbmp/description
	Libnsbmp is a decoding library for BMP and ICO image file formats, written in C
endef

define Build/Compile
	rm -rf $(PKG_INSTALL_DIR)
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR) \
		$(MAKE_FLAGS) \
		COMPONENT_TYPE=lib-shared \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Build/InstallDev
	mkdir -p $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/local/include/* $(1)/usr/include/
	mkdir -p $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/local/lib/* $(1)/usr/lib/
endef

define Package/libnsbmp/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/local/lib/libnsbmp.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libnsbmp))
