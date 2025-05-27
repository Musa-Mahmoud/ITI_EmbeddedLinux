SUMMARY = "Add a service for the Qt6 application at startup"

SRC_URI:append = " file://myqt.service"
SYSTEM_AUTO_ENABLE = "enable"
SYSTEM_SERVICE:{PN} = "qt.service"

do_install::APPEND() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0440 ${WORKDIR}/qt.service ${D}${systemd_unitdir}/system
}
