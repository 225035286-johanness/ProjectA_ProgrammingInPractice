CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = mfms

SRCS = main.c employees.c budget.c suppliers.c assets.c reports.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
