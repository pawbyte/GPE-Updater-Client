CC=g++
CXXFLAGS = -lSDL2main -lSDL2 -lSDL2_ttf

HEADERS = \
        src\updater.h \


OBJECTS = \
        obj\updater.o \


BINARIES = GPE_Updater

# This is the first rule. It is therefore default
build: release

GPE_Updater: $(OBJECTS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Since I don't know what sources go to what headers, if a header changes
# assume everything needs to be rebuilt.
$(OBJECTS): $(HEADERS)

release: CXXFLAGS += -O2 -Wfatal-errors -Wextra
release: $(BINARIES)

debug: CXXFLAGS += -g
debug: $(BINARIES)

clean:
	rm $(OBJECTS)
	rm $(BINARIES)

