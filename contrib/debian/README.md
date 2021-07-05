
Debian
====================
This directory contains files used to package amerox/amero-qt
for Debian-based Linux systems. If you compile amerox/amero-qt yourself, there are some useful files here.

## amero: URI support ##


amero-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install amero-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your amero-qt binary to `/usr/bin`
and the `../../share/pixmaps/amero128.png` to `/usr/share/pixmaps`

amero-qt.protocol (KDE)

