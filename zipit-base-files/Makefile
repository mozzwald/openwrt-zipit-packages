include $(TOPDIR)/rules.mk

PKG_NAME:=zipit-files
PKG_VERSION:=1

include $(INCLUDE_DIR)/package.mk

define Package/zipit-base-files
    MAINTAINER:="Joe Honold" <mozzwald@gmail.com>
    TITLE:=Zipit Z2 Base Files
    SECTION:=utils
    CATEGORY:=Utilities
endef

define Package/Prepare
	mkdir -p $(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
endef

define Build/Compile
endef

define Package/zipit-base-files/install
	$(CP) ./files/* $(1)/

	mkdir -p $(1)/dev
	mkdir -p $(1)/lib
	mkdir -p $(1)/lib/firmware
	mkdir -p $(1)/mnt
	mkdir -p $(1)/overlay
	mkdir -p $(1)/proc
	mkdir -p $(1)/rom
	mkdir -p $(1)/root
	mkdir -p $(1)/sys
	mkdir -p $(1)/tmp
	mkdir -p $(1)/usr
	mkdir -p $(1)/usr/lib
	mkdir -p $(1)/usr/bin
	mkdir -p $(1)/usr/sbin
	mkdir -p $(1)/usr/share
	rm -f $(1)/var
	$(LN) /tmp $(1)/var
	$(LN) /tmp/resolv.conf $(1)/etc/

	chmod 0600 $(1)/etc/shadow
	chmod 1777 $(1)/tmp
endef

$(eval $(call BuildPackage,zipit-base-files))
