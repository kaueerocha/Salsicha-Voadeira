CC = gcc
CFLAGS = -Wall
LDFLAGS = -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lSDL_mixer
EXECUTABLE_NAME = salsicha_voadeira

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): SalsichaVoadeiraULTIMATE.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE_NAME) SalsichaVoadeiraULTIMATE.c $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE_NAME)