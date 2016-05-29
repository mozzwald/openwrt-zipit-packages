include $(TOPDIR)/rules.mk

PKG_NAME:=zipit-files
PKG_VERSION:=0.1

include $(INCLUDE_DIR)/package.mk

define Package/zipit-files
    MAINTAINER:="Angus Gratton" <gus@projectgus.com>
    TITLE:=ZipIt Z2 Files
    SECTION:=utils
    CATEGORY:=Utilities
    DEPENDS:=@BROKEN
endef

define Package/Prepare
	mkdir -p $(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
endef

define Build/Compile
endef

define Package/zipit-files/install
	$(INSTALL_DIR) $(1)/usr/local/bin 
		$(INSTALL_BIN) ./files/bin/battlevel $(1)/usr/local/bin/battlevel
		$(INSTALL_BIN) ./files/bin/volup $(1)/usr/local/bin/volup
		$(INSTALL_BIN) ./files/bin/voldn $(1)/usr/local/bin/voldn
	$(INSTALL_DIR) $(1)/usr/local/sbin
		$(INSTALL_BIN) ./files/sbin/keyb $(1)/usr/local/sbin/keyb
		$(INSTALL_BIN) ./files/sbin/lcdb $(1)/usr/local/sbin/lcdb
		$(INSTALL_BIN) ./files/sbin/cpu $(1)/usr/local/sbin/cpu
		$(INSTALL_BIN) ./files/sbin/suspend $(1)/usr/local/sbin/suspend
endef

$(eval $(call BuildPackage,zipit-files))
