CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGETS = Score_sys Temp_sys

all: $(TARGETS)

Score_sys: Score_sys.c
	$(CC) $(CFLAGS) Score_sys.c -o Score_sys

Temp_sys: Temp_sys.c
	$(CC) $(CFLAGS) Temp_sys.c -o Temp_sys