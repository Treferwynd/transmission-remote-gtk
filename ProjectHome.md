## About ##

transmission-remote-gtk is a cross-platform application for remote management of the Transmission BitTorrent client using its RPC interface.

  * Remotely add (file/url), start, stop, remove, remove & delete, verify, reannounce torrents.
  * Works as a .torrent handler (eg. from a web browser).
  * Set torrent properties such as speed, seed, peer limits, file priorities, add/edit/remove trackers.
  * Change remote settings like global limits, download directory, and connectivity preferences.
  * [Create custom action commands to invoke on torrents from the UI](http://code.google.com/p/transmission-remote-gtk/wiki/ExecuteCommand).
  * Basic RSS support.
  * Many translations.

## News ##

### 18/04/2014: Available in Ubuntu Trusty, and RSS ###

Ubuntu Trusty has just been released, and it is the first version of Ubuntu to include transmission-remote-gtk.

In other news, a simple RSS reader has been added to git recently. Give it a try if you use RSS.

### 02/01/2014: New beta Windows binaries (GTK3) ###

It's been well over a year since the Windows binaries have been updated, the main reason being how tricky it is to get a working build environment setup (I lost the old one). There was also a GTK theming issue with progress bars being blank which I've patched.

These new binaries use GTK3 instead of GTK2. I think this improves the overall appearance greatly. Other libraries, GeoIP DB, and translations have been updated too.

### 09/06/2013: 1.1.1 Bugfix release ###

The 1.1.1 release is mainly a bugfix, for files lists displaying with duplicate directories in some cases. Two new translations (Sinhalese and Latvian).

### 05/09/2012: New look 1.1 release ###

The 1.1 release is now available. The big new feature is a Transmission style shown below, with the old one being kept as an alternative (set using the view menu). There are other improvements and bugfixes too.

## Downloads ##

  * [Sources](https://code.google.com/p/transmission-remote-gtk/downloads/list)
  * [My stable Ubuntu PPA (for pre-Hardy)](https://code.launchpad.net/~ajf/+archive/trg)
  * [My unstable Ubuntu PPA](https://code.launchpad.net/~ajf/+archive/transmission-remote-gtk-unstable)
  * [RPMs included in Fedora](http://koji.fedoraproject.org/koji/packageinfo?packageID=12876)
  * [Gentoo ebuild](http://packages.gentoo.org/package/net-p2p/transmission-remote-gtk)
  * [CentOS/RHEL](http://code.google.com/p/transmission-remote-gtk/downloads/list)
  * [Arch (builds from git)](https://aur.archlinux.org/packages/transmission-remote-gtk-git/)
  * [included in SuSE](http://software.opensuse.org/package/transmission-remote-gtk)
  * [will be included in Ubuntu Trusty (not yet released)](http://packages.ubuntu.com/trusty/transmission-remote-gtk)

![![](http://eth0.org.uk/~alan/transmission-remote-gtk-1.1.png)](http://eth0.org.uk/~alan/transmission-remote-gtk-1.1.png)

## Screenshots ##

Linux:

![![](http://eth0.org.uk/~alan/transmission-remote-gtk-1.0.2-fedora.png)](http://eth0.org.uk/~alan/transmission-remote-gtk-1.0.2-fedora.png)

Windows:

![![](http://eth0.org.uk/~alan/trg-win32-gtk3.png)](http://eth0.org.uk/~alan/trg-win32-gtk3.png)