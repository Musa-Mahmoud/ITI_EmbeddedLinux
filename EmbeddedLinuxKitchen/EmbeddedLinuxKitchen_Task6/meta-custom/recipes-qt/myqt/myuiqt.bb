SUMMARY = "Recipe for the Qt6 application"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Musa-Mahmoud/ITI_Qt.git;branch=main"
SRCREV = "auto"

inherit qt6-cmake qt6-paths

DEPENDS = "qtbase qtmultimedia qt-declarative-native qtwayland"
RDEPENDS:${PN} = "qtbase qtwayland qtmultimedia"
