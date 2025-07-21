// by folkert van heusden <folkert@vanheusden.com>
// MIT license
#include <rtmidi/RtMidi.h>
#include <utility>

#include "midi.h"


bool init_midi()
{
	return true;
}

void deinit_midi()
{
}

RtMidiOut * allocate_midi_output_port()
{
	auto *p = new RtMidiOut();
	p->openVirtualPort("TESTER output");
	return p;
}

void send_midi_note(RtMidiOut *const p, const int channel, const int note, const int velocity)
{
	std::vector<unsigned char> message { (unsigned char)(0x90 + channel), (unsigned char)note, (unsigned char)velocity };
	p->sendMessage(&message);
}

RtMidiIn * allocate_midi_input_port()
{
	auto *p = new RtMidiIn();
	p->openVirtualPort("TESTER input");
	p->ignoreTypes(true, true, true);  // ignore sysex, timing, and active sensing messages
	return p;
}

std::vector<unsigned char> receive_midi_note(RtMidiIn *const p)
{
	std::vector<unsigned char> message;
	p->getMessage(&message);
	return message;
}

void close_midi_in_port(RtMidiIn *const midi_port)
{
	delete midi_port;
}

void close_midi_out_port(RtMidiOut *const midi_port)
{
	delete midi_port;
}
