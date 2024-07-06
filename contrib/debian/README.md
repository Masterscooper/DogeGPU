
Debian
====================
This directory contains files used to package dogpud/dogpu-qt
for Debian-based Linux systems. If you compile dogpud/dogpu-qt yourself, there are some useful files here.

## dogpu: URI support ##


dogpu-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install dogpu-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your dogpu-qt binary to `/usr/bin`
and the `../../share/pixmaps/dogpu128.png` to `/usr/share/pixmaps`

dogpu-qt.protocol (KDE)

