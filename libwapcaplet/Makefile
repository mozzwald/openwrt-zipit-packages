include $(TOPDIR)/rules.mk

PKG_NAME:=libwapcaplet
PKG_VERSION:=0.2.2
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-src.tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/libs/releases/
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libwapcaplet
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Libwapcaplet is a string internment library, written in C
	URL:=http://www.netsurf-browser.org/projects/libwapcaplet/
	PKG_BUILD_DEPENDS:=+netsurf-buildsystem
endef

define Package/libwapcaplet/description
	LibWapcaplet is a string internment library, written in C. It provides reference counted string interment and rapid string comparison functionality. It was developed as part of the NetSurf project.
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

define Package/libwapcaplet/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwapcaplet.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libwapcaplet))
