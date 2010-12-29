cfgPeopsMesaGL
==============

GTK config tool for Pete's MesaGL Driver

Make
----

    gcc -o cfgPeopsMesaGL cfgPeopsMesaGL.c $(pkg-config --cflags --libs gtk+-2.0 gmodule-2.0)

Usage
-----

    ./cfgPeopsMesaGL
    ./cfgPeopsMesaGL ABOUT
