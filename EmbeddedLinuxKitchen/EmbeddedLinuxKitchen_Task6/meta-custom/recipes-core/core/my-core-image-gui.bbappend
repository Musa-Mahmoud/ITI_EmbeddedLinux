SUMMARY = "Core recipe appends: ip"

SRC_URI:append = " file://myqt.service"
SYSTEM_AUTO_ENABLE = "enable"
SYSTEM_SERVICE:{PN} = "qt.service"

do_install_APPEND() {
    install -d ${D}${sysconfdir}/systemd/network
    cat << 'EOF' > ${D}${sysconfdir}/systemd/network/eth0.network
[Match]
Name=eth0

[Network]
Address=192.168.1.100/24
Gateway=192.168.1.1
DNS=8.8.8.8
EOF
}


do_install_APPEND() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0440 ${WORKDIR}/qt.service ${D}${systemd_unitdir}/system
}
