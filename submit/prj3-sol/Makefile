TARGET = multi-queue
OBJS = job.o command.o command-stream.o command-test.o priority-queue.o

CXX = g++
CXXFLAGS = -g -Wall -std=c++17

$(TARGET):		$(OBJS)
			$(CXX) $^ -o $@

clean:			
			rm -f *~ $(OBJS) $(TARGET) main

#dependencies
job.o:			job.cc job.hh
command.o:		command.cc command.hh job.hh
command-stream.o:	command-stream.cc command-stream.hh command.hh
command-test.o:		command-test.cc command.hh command-stream.hh priority-queue.hh
priority-queue.o:	priority-queue.cc priority-queue.hh

main:			priority-queue.o
			$(CXX) $^ -o $@
