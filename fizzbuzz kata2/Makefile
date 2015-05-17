#compiler and linker config
CC=g++
LD=g++
CFLAGS=-Wall -O2 -std=c++11 -g
LDFLAGS=
LINKFLAGS= -lcppunit

#dirs
OBJDIR=obj
SRCDIRS=src
BINDIR=bin

#resulting bin
TARGET=$(BINDIR)/output

C_SRC = $(shell find $(SRCDIRS) -name '*.cpp')
OBJS = $(addprefix $(OBJDIR)/, $(C_SRC:.cpp=.o))
DEPS = $(addprefix $(OBJDIR)/, $(C_SRC:.cpp=.d))
DIRS=$(addprefix $(OBJDIR)/, $(shell find $(SRCDIRS) -type d))

.PHONY : clean all hierarchy

all: hierarchy $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET) $(LINKFLAGS)

#create file hierarchy
hierarchy: $(OBJDIR) $(BINDIR) $(DIRS)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
$(BINDIR):
	mkdir -p $(BINDIR)

$(DIRS):
	mkdir -pv $(DIRS)

#compile c/asm sources
$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -MM -MT '$@ $(basename $@).d' $< > $(basename $@).d

$(OBJDIR)/%.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

-include $(DEPS)

clean:
	-rm -r $(TARGET) $(OBJDIR)
