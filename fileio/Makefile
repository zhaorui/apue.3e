ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS =	fileflags hole mycat seek

all:	$(PROGS) setfl.o bigfile

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)
bigfile:
	@echo "creating the 512 Mb bigfile for testing..."
	sudo dd bs=$$((1024*1024*512)) count=1 if=/dev/disk0 > $@

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o file.hole bigfile

include $(ROOT)/Make.libapue.inc
