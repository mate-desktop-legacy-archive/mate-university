MATE University
===============

MATE University is targeted at all levels of developers (including
beginners) to learn how to develop new panel applets, Caja (file manager)
extensions, pluma (text editor) and eom (image viewer) plugins, etc. to
expand the already powerful MATE Desktop experience.

  * Online source: https://github.com/mate-desktop/mate-university
  * Online documentation: http://wiki.mate-desktop.org/university



applet-c
--------

A sample panel applet written in c.


applet-python
-------------

A sample panel applet written in python.


cairo-test
----------

A sample c application to learn GTK+ and cairo.


### Prerequisites

On a Linux Mint 18.3 I had to install:
```
libgtk2.0-dev
```

Based on the code the following are likely needed as well:
```
libglib2.0-dev
libgtk-3-dev
libmate-panel-applet-dev
mate-common
```
Maybe `libmate-panel-applet-4-1` as well.


### Installing

I have used:
```
./autogen.sh --prefix=/usr
make
sudo make install
```
(The prefix may not be needed.)

For the python applet specifying gtk+ v2 is needed:
```
./autogen.sh --with-gtk=2.0
```
