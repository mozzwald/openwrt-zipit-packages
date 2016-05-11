include $(TOPDIR)/rules.mk

PKG_NAME:=calcurse
PKG_VERSION:=4.1.0
PKG_RELEASE:=1

PKG_SOURCE:=calcurse-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://calcurse.org/files/
PKG_MD5SUM:=baf0b0f736b6ee6609701ef50ea588ad
PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/calcurse-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/calcurse
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=Calcurse
	DEPENDS:=+libncurses +libreadline +libncursesw +libpthread
	URL:=http://calcurse.org
endef

define Package/calcurse/description
	Fullscreen curses based calendar.
endef

define Build/Configure
	$(call Build/Configure/Default, \
		--prefix=/usr \
	)
endef

define Package/calcurse/install
	$(INSTALL_DIR) $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/calcurse $(1)/usr/bin/
endef

$(eval $(call BuildPackage,calcurse))
