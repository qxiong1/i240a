CXX = g++
CXXFLAGS = -g -Wall -std=c++17

#produce a list of all cc files
CXX_FILES = $(wildcard *.cc)

HXX_FILES = $(wildcard *.hh)

#produce a list of all *.o files by substituting cc in CXX_FILES with o.
OFILES = $(CXX_FILES:cc=o)

SRC_FILE = $(CXX_FILES) $(HXX_FILES) Makefile

TARGET = fns-compare

#default target
all:		$(TARGET)

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) -o $@

dist:		$(SRC_FILE)
		tar -cf fns-compare.tar $(SRC_FILE)

.phony:		clean
clean:
		rm -rf *~ *.o $(TARGET) $(DEPDIR)


#auto-dependences
#<http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/>

#dir in which to generate dependences
DEPDIR = .deps

#have DEPDIR/*.d file for each *.cc file
DEPFILES = $(CXX_FILES:%.cc=$(DEPDIR)/%.d)

#-MT $@ sets target name in dependency file
#-MMD tells compiler to generate prereqs without including system headers
#-MP adds target for each prereq
#-MF $(DEPDIR)/$*.d sets name of output dependency file
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

#delete built-in implicit rule for building .o from .cc
%.o: %.cc

#create our own implicit rule for building %.o from %.cc
#| $(DEPDIR) makes DEPDIR an order only prereq
%.o:		%.cc $(DEPDIR)/%.d | $(DEPDIR)
		$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $<

#create DEPDIR if it does not exist
$(DEPDIR):
		@mkdir -p $@

#add a target to include all DEPFILES
$(DEPFILES):
include $(wildcard $(DEPFILES))
