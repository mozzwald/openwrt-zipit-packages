include $(TOPDIR)/rules.mk

PKG_NAME:=picoc
PKG_VERSION:=2.1
PKG_RELEASE:=2

PKG_SOURCE:=picoc-$(PKG_VERSION).tar.bz2
	PKG_SOURCE_URL:=http://picoc.googlecode.com/files
	PKG_MD5SUM:=6505fb108d195bad0854c7024993cc24
	PKG_CAT:=bzip2 -cd

#PKG_BUILD_DIR:=$(BUILD_DIR)/picoc-$(PKG_VERSION)
PKG_BUILD_DIR:=$(BUILD_DIR)/picoc

include $(INCLUDE_DIR)/package.mk

define Package/picoc
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=PicoC
	URL:=http://code.google.com/p/picoc/
	#DEPENDS:= +libreadline
endef

define Package/picoc/description
	Simple C interpreter.
endef

define Build/Configure
        $(call Build/Compile/Default)
endef


define Package/picoc/install
	$(INSTALL_DIR) $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/picoc $(1)/usr/bin/
	 $(INSTALL_DIR) $(1)/usr/share/picoc/
	 $(INSTALL_DIR) $(1)/usr/share/picoc/tests/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/tests/* $(1)/usr/share/picoc/tests/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/README $(1)/usr/share/picoc/
endef

$(eval $(call BuildPackage,picoc))
