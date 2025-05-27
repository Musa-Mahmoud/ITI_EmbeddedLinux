SUMMARY = "Image that enables GUI and launch a Qt6 application"

LICENSE = "CLOSED"

inherit core-image

IMAGE_FEATURE:append = " splash ssh-server-dropbear package-management"

IMAGE_INSTALL:append = " bash connman-client qtwayland weston weston-init tigervnc"

ROOTFS_MAXSIZE = "0"

EXTRA_USERS_PARAMS = "usermod -p '\$6\$7IO8ENiZ8KcLpTJ8\$mQtWxLxWmOXBM9CUiPb0p3bG04H6ZWevQKgWHlYgX3ITTVSoIBBMWF8YJIHOje8Sd0q4BN1Z0hEQIrtIm14qB.' root;"
