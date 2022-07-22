# Sausage vs Burguer

Sausage vs Burguer is a game developed by Gabriel Messas, Kauee Rocha, Pedro Augusto PHS & Lucas Rossato.

This game was 100% built in C language, using the SDL 1.2 library.

To run this game, you will need to have a few dependencies:

- gcc
- SDL-1.2
- SDL-Image
- SDL-Mixer
- SDL-TTF

On Linux, for instance, you can install them by running:

> apt-get install build-essential libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev

Then, download this repository and proceed to the commands:

> cd _**GAME_FOLDER**_

> gcc -o _**EXECUTABLE_NAME**_ SalsichaVoadeiraULTIMATE.c -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lSDL_mixer

> ./_**EXECUTABLE_NAME**_
