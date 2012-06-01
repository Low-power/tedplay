#pragma once

#include <string>

class TED;
class Audio;

extern TED *machineInit(unsigned int sampleRate);
extern int tedplayMain(char *fileName, Audio *player);
extern void tedPlaySetVolume(unsigned int masterVolume);
extern void tedPlaySetSpeed(unsigned int speedPct);
extern void tedplayPause();
extern void tedplayPlay();
extern void tedplayStop();
extern void tedplayClose();
extern void tedPlayGetSongs(unsigned int &current, unsigned int &total);
extern bool tedPlayIsChannelEnabled(unsigned int channel);
extern void tedPlayChannelEnable(unsigned int channel, unsigned int enable);
extern int tedPlayGetState();
//
extern void machineReset();
extern void machineDoSomeFrames(unsigned int count);
extern void dumpMem(std::string name);
