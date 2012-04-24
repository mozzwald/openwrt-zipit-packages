include $(TOPDIR)/rules.mk

PKG_NAME:=z2mouse
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/z2mouse
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=z2mouse, Zipit Z2 mouse emulator
  URL:=http://mozzwald.com/anarsoul/z2mouse-svo2.c
  SUBMENU:=Terminal
  DEPENDS:=@TARGET_pxa_zipitz2 +kmod-input-userlevel
endef

define Package/zmouse/description
	Mouse emulator for the ZipIt Z2, by anarsoul
endef

define Build/Prepare
	$(CP) $(FILES_DIR)/z2mouse-svo2.c $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(TARGET_CC) -o $(PKG_BUILD_DIR)/z2mouse $(PKG_BUILD_DIR)/z2mouse-svo2.c
endef

define Package/z2mouse/install
	mkdir -p $(1)/usr/bin/
	$(CP) $(PKG_BUILD_DIR)/z2mouse $(1)/usr/bin/
	$(CP) ./files/etc $(1)/etc
endef

define Package/z2mouse/postinst
#!/bin/sh
[ -n "$${IPKG_INSTROOT}" ] || /etc/init.d/z2mouse enable || true
endef


$(eval $(call BuildPackage,z2mouse))

