INCLUDE = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
SOURCE = Video.cpp Decision.cpp

OBJS = $(SRCS:.cpp=.o)

INC = -I./Command -I./Decision

TARGET = video
$(TARGET):$(OBJS)
	g++ -o $(TARGET) $(OBJS) -I $(INCLUDE) $(LIBS)
$(OBJS):$(SOURCE)
	g++ -c $(SOURCE)
clean:
	rm $(OBJS) $(TARGET)
%.o:%.cpp
	g++ -I $(INCLUDE) $(INC) $(LIBS) -o $@ -C $<
