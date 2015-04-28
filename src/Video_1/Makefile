INCLUDE = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)

SOURCE = edge.cpp

OBJS = $(SOURCE:.cpp=.o)

TARGET = test
$(TARGET):$(OBJS)
	g++ -o $(TARGET) $(OBJS) -I $(INCLUDE) $(LIBS)
$(OBJS):$(SOURCE)
	g++ -c $(SOURCE)
clean:
	rm $(OBJS) $(TARGET)
%.o:%.cpp
	g++ -I $(INCLUDE) -o $@ -C $<
