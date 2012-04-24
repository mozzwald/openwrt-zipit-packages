include $(TOPDIR)/rules.mk

PKG_NAME:=zipit-files
PKG_VERSION:=0.1

include $(INCLUDE_DIR)/package.mk

define Package/zipit-files/Default
    MAINTAINER:="Angus Gratton" <gus@projectgus.com>
    TITLE:=ZipIt Z2 Files
    SECTION:=utils
    CATEGORY:=Utilities
endef

define Build/Compile
endef

define Package/zipit-files/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,zipit-files))
