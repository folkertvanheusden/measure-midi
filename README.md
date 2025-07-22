This program attemps to measure the latency of a MIDI system.
For that it sends a message and busy-loops for a reply.
Then the duration it took to transmit is shown.

    mkdir build ; cd build ; cmake .. ; make -j4

Then:

    ./build/measure-midi

then using e.g. helvum or qpwgraph route the output of this program into is input.

On debian-systems, this program requires librtmidi-dev, on redhat-alike (rpm) it uses rtmidi-devel.
