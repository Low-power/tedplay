CXXFLAGS += -Wall -Werror=sequence-point -Os
LIBS += -l m
ifdef USE_SDL2
CXXFLAGS += -D USE_SDL2=2
LIBS += -l SDL2
else
LIBS += -l SDL
endif

OBJECTS := Audio.o AudioSDL.o CbmTune.o Cpu.o Filter.o Sid.o Tedmem.o Tedsound.o main.o tedplay.o

tedplay:	$(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f tedplay $(OBJECTS)
