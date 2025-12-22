CC := gcc
CFLAGS := -I. -Wall -Wextra -g
RM := rm -f

SRCS := main.c \
        config.c \
        Book/book.c \
        Candidate/candidate.c \
        Transaction/transaction.c \
        BookKeeping/bookKeeping.c \
        LiveReading/LiveReading.c

OBJS := $(SRCS:.c=.o)

TARGET := lms.exe

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJS) $(TARGET)

# EOF
