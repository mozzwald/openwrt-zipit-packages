include $(TOPDIR)/rules.mk

PKG_NAME:=libhubbub
PKG_VERSION:=0.3.1
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-src.tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/libs/releases/

include $(INCLUDE_DIR)/package.mk

define Package/libhubbub
	MAINTAINER:="Xiangfu Liu" <xiangfu@sharism.cc>
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Hubbub is an HTML5 compliant parsing library
	URL:=http://www.netsurf-browser.org/projects/hubbub/
	DEPENDS:=+libparserutils
	PKG_BUILD_DEPENDS:=+netsurf-buildsystem
endef

define Package/libhubbub/description
	Hubbub is an HTML5 compliant parsing library, written in C. It was developed as part of the NetSurf project and is available for use by other software under the MIT licence.
endef

MAKE_FLAGS += NSSHARED=$(STAGING_DIR)/usr/share/netsurf-buildsystem \
    PREFIX=/usr \
    COMPONENT_TYPE=lib-shared \
    DESTDIR="$(PKG_INSTALL_DIR)"

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

define Package/libhubbub/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libhubbub.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libhubbub))
