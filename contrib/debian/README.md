
Debian
====================
This directory contains files used to package aitrad/aitra-qt
for Debian-based Linux systems. If you compile aitrad/aitra-qt yourself, there are some useful files here.

## aitra: URI support ##


aitra-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install aitra-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your aitra-qt binary to `/usr/bin`
and the `../../share/pixmaps/aitra128.png` to `/usr/share/pixmaps`

aitra-qt.protocol (KDE)

