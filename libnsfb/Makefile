include $(TOPDIR)/rules.mk

PKG_NAME:=libnsfb
PKG_VERSION:=0.1.3
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-src.tar.gz
PKG_SOURCE_URL:=http://download.netsurf-browser.org/libs/releases/
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libnsfb
	MAINTAINER:="Xiangfu Liu" <xiangfu@sharism.cc>
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=LibNSFB is a framebuffer abstraction library, written in C
	DEPENDS:=+libsdl
	URL:=http://www.netsurf-browser.org/projects/libnsfb/
	PKG_BUILD_DEPENDS:=+netsurf-buildsystem
endef

define Package/libnsfb/description
	The overall idea of the library is to provide a generic abstraction to a linear section of memory which corresponds to a visible array of pixel elements on a display device. Different colour depths are supported and the library provides routines for tasks such as drawing onto the framebuffer and rectangle copy operations.
endef

MAKE_FLAGS += NSSHARED=$(STAGING_DIR)/usr/share/netsurf-buildsystem \
    PREFIX=/usr \
    WARNFLAGS="" \
    NSFB_XCB_AVAILABLE=no \
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
	$(SED) \
		's,^\(prefix\|exec_prefix\)=.*,\1=$(STAGING_DIR)/usr,g' \
		$(1)/usr/lib/pkgconfig/libnsfb.pc
	$(SED) \
		's/xcb\|xcb-icccm\|xcb-image\|xcb-keysyms//g' \
		$(1)/usr/lib/pkgconfig/libnsfb.pc
endef

define Package/libnsfb/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnsfb.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libnsfb))
