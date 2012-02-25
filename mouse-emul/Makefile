include $(TOPDIR)/rules.mk

PKG_NAME:=mouse-emul
PKG_VERSION:=0.1.3
PKG_REV:=v0.1.3
PKG_RELEASE:=1
PKG_INSTALL:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=git://github.com/anarsoul/mouse-emul.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/mouse-emul
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=mouse-emul, generic mouse emulator
  URL:=http://github.com/anarsoul/mouse-emul
  SUBMENU:=Terminal
endef

define Package/mouse-emul/description
	Generic mouse emulator
endef

MAKE_FLAGS += \
	PREFIX=/usr \
	CFLAGS="$(TARGET_CFLAGS)"\
	LDFLAGS="$(TARGET_LDFLAGS)"

define Build/Configure
endef

define Package/mouse-emul/install
	$(INSTALL_DIR) $(1)/usr/bin/ \

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mouse-emul $(1)/usr/bin/mouse-emul
endef

$(eval $(call BuildPackage,mouse-emul))
