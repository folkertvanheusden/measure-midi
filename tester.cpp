// by folkert van heusden <folkert@vanheusden.com>
// MIT license
#include <cinttypes>
#include <cstdio>
#include <unistd.h>

#include "midi.h"
#include "time.h"


int main(int argc, char *argv[])
{
	init_midi();

	RtMidiOut *out = allocate_midi_output_port();
	RtMidiIn  *in  = allocate_midi_input_port ();

	uint8_t nr = 0;
	for(;;) {
		uint64_t start = get_ns();
		send_midi_note(out, 9, nr, 127);
		uint64_t sent  = get_ns();

		uint64_t recv  = 0;
		for(;;) {
			uint64_t now = get_ns();
			auto     msg = receive_midi_note(in);
			if (msg.empty() == false && msg.at(1) == nr) {
				recv = now;
				break;
			}
			if (now > sent + 1000000000)  // timeout of 1 second
				break;
		}

		if (recv)
			printf("took %.6f ms\n", (recv - sent) / 1000000.);

		nr = (nr + 1) & 127;

		usleep(100000);
	}


	close_midi_in_port (in );
	close_midi_out_port(out);

	return 0;
}
