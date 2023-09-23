
//gcc -o "nomequalquer" "nomedoarquivo".c -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lSDL_mixer
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

SDL_Rect criatiro(SDL_Rect dest)
{
  SDL_Rect destTIRO;
  destTIRO.x = dest.x + 100;
  destTIRO.y = dest.y + 60;
  //destTIRO.w = dest.w;
  //destTIRO.h = dest.h;

  return destTIRO;
}

typedef struct{
  char name[10];
  char ponto[5];
}Gamer;

int pisca(int i,int freq,SDL_Surface *on,SDL_Surface *off,SDL_Surface *screen,SDL_Rect dest)
{
  i++;

  if(i < freq){
    SDL_BlitSurface(on,NULL,screen,&dest);
  }else{
    SDL_BlitSurface(off,NULL,screen,&dest);
  }

  if(i > (freq * 2)){
    i = 0;
  }

  return i;
}

bool colisaum(SDL_Rect A, SDL_Rect B,int larg, int alt){

  if(A.y + A.h - alt < B.y) return false;
  else if(A.y > B.y + B.h - alt)return false;
  else if(A.x + A.w - larg < B.x)return false;
  else if(A.x > B.x + B.w - larg)return false;
  
  return true;

}

int main()
{
  //INICIA A FERRAMENTA DE VIDEO
  SDL_Init(SDL_INIT_VIDEO);

  //INICIA A FERRAMENTA DE TEXTO
  TTF_Init();

  //DECLARA AS SURFACES
  SDL_Surface * screen;
  SDL_Surface * carregaFLY[3];
  SDL_Surface * carregaPEW[3];
  SDL_Surface * carregaSTAND[3];
  SDL_Surface * carregaBCK;
  SDL_Surface * carregaPEWFLY[3];
  SDL_Surface * carregaMENU;
  SDL_Surface * carregaVOLTAR;
  SDL_Surface * carregaSALSICHA[3];
  SDL_Surface * carregaTON;
  SDL_Surface * carregaTOFF;
  SDL_Surface * carregaMOON;
  SDL_Surface * carregaPARTICULA;
  SDL_Surface * carregaCOMSOM;
  SDL_Surface * carregaSEMSOM;
  SDL_Surface * carregaGANSU;
  SDL_Surface * carregaMILHO;
  SDL_Surface * carregaRANKON;
  SDL_Surface * carregaRANKOFF;
  SDL_Surface * carregaLATERAL;
  SDL_Surface * carregaPREJOGO;
  SDL_Surface * carregaBURGUER;
  SDL_Surface * carregaTUTORIAL;
  SDL_Surface * carregaTRANSICAO;
  SDL_Surface * carregaNICKON;
  SDL_Surface * carregaNICKOFF;
  SDL_Surface * carregaPAUSE;
  SDL_Surface * carregaDIFICUON;
  SDL_Surface * carregaDIFICUOFF;
  SDL_Surface * carregaCONFIRMA;
  SDL_Surface * carregaAMMO;
  SDL_Surface * carregaCONTROLES;
  SDL_Surface * imageFLY[3];
  SDL_Surface * imagePEW[3];
  SDL_Surface * imageSTAND[3];
  SDL_Surface * imageBCK;
  SDL_Surface * imagePEWFLY[3];
  SDL_Surface * imageMENU;
  SDL_Surface * imageVOLTAR;
  SDL_Surface * imageSALSICHA[3];
  SDL_Surface * imageTON;
  SDL_Surface * imageTOFF;
  SDL_Surface * imageMOON;
  SDL_Surface * imagePARTICULA;
  SDL_Surface * imageCOMSOM;
  SDL_Surface * imageSEMSOM;
  SDL_Surface * imageGANSU;
  SDL_Surface * imageMILHO;
  SDL_Surface * imageRANKON;
  SDL_Surface * imageRANKOFF;
  SDL_Surface * imageLATERAL;
  SDL_Surface * imagePREJOGO;
  SDL_Surface * imageBURGUER;
  SDL_Surface * imageTUTORIAL;
  SDL_Surface * imageTRANSICAO;
  SDL_Surface * imageNICK;
  SDL_Surface * imageNICKON;
  SDL_Surface * imageNICKOFF;
  SDL_Surface * imagePAUSE;
  SDL_Surface * imageDIFICUON;
  SDL_Surface * imageDIFICUOFF;
  SDL_Surface * imageCONFIRMA;
  SDL_Surface * imageAMMO;
  SDL_Surface * imageCONTROLES;

  //CRIA CORRES
  SDL_Color colorWHITE = { 255, 255, 255};
  SDL_Color colorRED = {255, 0, 0};
  SDL_Color colorORANGE = {255,127,0};
  SDL_Color colorGREEN = {0, 255, 0};
  SDL_Color colorGOLD = {249,166,2};
  SDL_Color colorBABYBLUE = {50,200,200};
  SDL_Color colorSILVER = {220,220,220};

  // Para os eventos
  SDL_Event event;

  //DESTINOS DA IMAGENS
  SDL_Rect dest = {0,0,0,0};
  SDL_Rect destBCK = {0,0,0,0};
  SDL_Rect destSOM = {1170, 10, 0 ,0};
  SDL_Rect GANSU = {4000,0,0,0}; // ganso
  SDL_Rect destAMMO; //Munição
  SDL_Rect destBURG[5];
  SDL_Rect destMILHO[35]; // POSIÇÃO DOS TIROS
  SDL_Rect destTUTORIAL = {740,320,0,0};//POSIÇÃO DO BURGUINHO NO TUTORIAL anim

  //DESTINO DO TEXTO 
  SDL_Rect destTxt = {0,0,0,0};
  SDL_Rect destS = {0, 200, 0, 0};
  SDL_Rect destGAMEOVER = {500, 128, 0, 0};
  SDL_Rect destMIDDLE = {350, 128, 0, 0};
  SDL_Rect destMIDDLEM = {500, 450, 0, 0};
  SDL_Rect destNICK = {840,480,0,0};
  SDL_Rect destLOW = {500, 600, 0, 0};
  SDL_Rect destHIGH = {500, 300, 0, 0};
  SDL_Rect destVOLTAR = {0,0,0,0};
  SDL_Rect destMOON = {1450,10,0,0};
  SDL_Rect destCONTAGEM = {580, 155, 0,0};
  SDL_Rect destUSERNAME = {1150,10,0,0};
  SDL_Rect destSCORE = {40, 20, 0, 0};
  SDL_Rect destJOGO = {275,180,0,0};
  SDL_Rect destJOGOBIXU = {360,400,0,0};
  SDL_Rect destTUTOR = {700,180,0,0};
  SDL_Rect destPONTO = {25,110,0,0};
  SDL_Rect destMUNICAO = {59, 210,0,0 };
  SDL_Rect destMUNICAOESC = {23,170,0,0};

  //DESTINO DO TEXTO RANKING
  SDL_Rect destNTOP2 = {560,230,0,0}; 
  SDL_Rect destNTOP1 = {560,389,0,0};
  SDL_Rect destNTOP0 = {560,545,0,0};

  SDL_Rect destPTOP2 = {760,230,0,0};
  SDL_Rect destPTOP1 = {760,389,0,0};
  SDL_Rect destPTOP0 = {760,545,0,0};

  // VELOCIDADES DA SALSICHA
  int velX = 0, velY = 10;

  //INSERÇÃO DE EFFEITOS SONOROS
  Mix_Chunk * effect[3];
  Mix_Chunk * nop;
  Mix_Music * musicmenu;
  Mix_Music * musicgameover;

  Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
  effect[0] = Mix_LoadWAV("Som/PewPew.wav");
  effect[1] = Mix_LoadWAV("Som/tirinho.wav");
  effect[2] = Mix_LoadWAV("Som/tiroG3.wav");
  nop = Mix_LoadWAV("Som/nop.wav");
  musicmenu = Mix_LoadMUS("Som/menu.wav");
  musicgameover = Mix_LoadMUS("Som/GAMEOVER.wav");

  //CONTROLE DE ÁUDIO
  int play = 1;

  //NOMEIA A JANELA... SIM ANTES DE CRIÁ-LA
  SDL_WM_SetCaption("SALSICHA VOADEIRA ",NULL);

  //CRIA A JANELA
  screen = SDL_SetVideoMode(1300, 711, 32, SDL_SWSURFACE);

  //FPS
  Uint32 start;
  const int FPS = 30;

  int fps3 = 0;
  int fps2 = 0;
  int fps1 = 0;

  //GERADOR DE IMAGENS
  int select;
  //SELETOR DE DIFICULDADE
  int dificuldade = 1;

  //CARREGA AS IMAGENS DO JOGO
  carregaFLY[0] = IMG_Load("imagens/FlyBABY.png");
  carregaFLY[1] = IMG_Load("imagens/FlyPADRAO.png");
  carregaFLY[2] = IMG_Load("imagens/FlySR.png");
  carregaSALSICHA[0] = IMG_Load("imagens/salsichaBABY.png");
  carregaSALSICHA[1] = IMG_Load("imagens/salsicha.png");
  carregaSALSICHA[2] = IMG_Load("imagens/salsichaSR.png");
  carregaPEW[0] = IMG_Load("imagens/pewBABY.png");
  carregaPEW[1] = IMG_Load("imagens/pewPADRAO.png");
  carregaPEW[2] = IMG_Load("imagens/pewSR.png"); 
  carregaSTAND[0] = IMG_Load("imagens/StandBABY.png");
  carregaSTAND[1] = IMG_Load("imagens/Stand.png");
  carregaSTAND[2] = IMG_Load("imagens/StandSR.png");
  carregaBCK = IMG_Load("imagens/Sky.png");
  carregaPEWFLY[0] = IMG_Load("imagens/pewflyBABY.png");
  carregaPEWFLY[1] = IMG_Load("imagens/pewflyPADRAO.png");
  carregaPEWFLY[2] = IMG_Load("imagens/pewflySR.png");
  carregaMENU = IMG_Load("imagens/menu.png");
  carregaVOLTAR = IMG_Load("imagens/back.png");
  carregaTON = IMG_Load("imagens/titulon.png");
  carregaTOFF = IMG_Load("imagens/tituloff.png");
  carregaMOON = IMG_Load("imagens/moon.png");
  carregaPARTICULA = IMG_Load("imagens/particulas.png");
  carregaCOMSOM = IMG_Load("imagens/comsom.png");
  carregaSEMSOM = IMG_Load("imagens/semsom.png");
  carregaGANSU = IMG_Load("imagens/goose.png");
  carregaMILHO = IMG_Load("imagens/milho.png");
  carregaRANKON = IMG_Load("imagens/rankon.png");
  carregaRANKOFF = IMG_Load("imagens/rankoff.png");
  carregaLATERAL = IMG_Load("imagens/lateral.png");
  carregaPREJOGO = IMG_Load("imagens/prejogo.png");
  carregaBURGUER = IMG_Load("imagens/burguer.png");
  carregaTUTORIAL = IMG_Load("imagens/jump.png");
  carregaTRANSICAO = IMG_Load("imagens/transicaoGameover.png");
  carregaNICKON = IMG_Load("imagens/nickon.png");
  carregaNICKOFF = IMG_Load("imagens/nickoff.png");
  carregaPAUSE = IMG_Load("imagens/pause.png");
  carregaDIFICUON = IMG_Load("imagens/dificuon.png");
  carregaDIFICUOFF = IMG_Load("imagens/dificuoff.png");
  carregaCONFIRMA = IMG_Load("imagens/confirma.png");
  carregaAMMO = IMG_Load("imagens/ammo.png");
  carregaCONTROLES = IMG_Load("imagens/tutorial.png");

  //FORMATA AS IMAGENS DO JOGO
  for(select = 0;select < 3; select++ ){
    imageFLY[select] = SDL_DisplayFormatAlpha(carregaFLY[select]);
    imagePEW[select] = SDL_DisplayFormatAlpha(carregaPEW[select]);
    imageSTAND[select] = SDL_DisplayFormatAlpha(carregaSTAND[select]);
    imagePEWFLY[select] = SDL_DisplayFormatAlpha(carregaPEWFLY[select]);
    imageSALSICHA[select] = SDL_DisplayFormatAlpha(carregaSALSICHA[select]);
  }
  imageBCK = SDL_DisplayFormatAlpha(carregaBCK);
  imageMENU = SDL_DisplayFormatAlpha(carregaMENU);
  imageVOLTAR = SDL_DisplayFormatAlpha(carregaVOLTAR);
  imageTON = SDL_DisplayFormatAlpha(carregaTON);
  imageTOFF = SDL_DisplayFormatAlpha(carregaTOFF);
  imageMOON = SDL_DisplayFormatAlpha(carregaMOON);
  imagePARTICULA = SDL_DisplayFormatAlpha(carregaPARTICULA);
  imageCOMSOM = SDL_DisplayFormatAlpha(carregaCOMSOM);
  imageSEMSOM = SDL_DisplayFormatAlpha(carregaSEMSOM);
  imageGANSU = SDL_DisplayFormatAlpha(carregaGANSU);
  imageMILHO = SDL_DisplayFormatAlpha(carregaMILHO);
  imageRANKON = SDL_DisplayFormatAlpha(carregaRANKON);
  imageRANKOFF = SDL_DisplayFormatAlpha(carregaRANKOFF);
  imageLATERAL = SDL_DisplayFormatAlpha(carregaLATERAL);
  imagePREJOGO = SDL_DisplayFormatAlpha(carregaPREJOGO);
  imageBURGUER = SDL_DisplayFormatAlpha(carregaBURGUER);
  imageTUTORIAL = SDL_DisplayFormatAlpha(carregaTUTORIAL);
  imageTRANSICAO = SDL_DisplayFormatAlpha(carregaTRANSICAO);
  imageNICKON = SDL_DisplayFormatAlpha(carregaNICKON);
  imageNICKOFF = SDL_DisplayFormatAlpha(carregaNICKOFF);
  imagePAUSE = SDL_DisplayFormatAlpha(carregaPAUSE);
  imageDIFICUON = SDL_DisplayFormatAlpha(carregaDIFICUON);
  imageDIFICUOFF = SDL_DisplayFormatAlpha(carregaDIFICUOFF);
  imageCONFIRMA = SDL_DisplayFormatAlpha(carregaCONFIRMA);
  imageAMMO = SDL_DisplayFormatAlpha(carregaAMMO);
  imageCONTROLES = SDL_DisplayFormatAlpha(carregaCONTROLES);

  //DECLARA OS TIPOS DE MODELOS/TAMANHOS DE FONTES
  TTF_Font * zx25;
  TTF_Font * zx50;
  TTF_Font * zx75;
  TTF_Font * zx45;
  TTF_Font * zx150;
  TTF_Font * zx100;
  TTF_Font * zx300;
  TTF_Font * grande;

  //CARREGA UM MODELO/TAMANHO DE FONTE
  zx25 = TTF_OpenFont("zx_spectrum-7.ttf",25);
  zx150 = TTF_OpenFont("zx_spectrum-7.ttf",150);
  zx75 = TTF_OpenFont("zx_spectrum-7.ttf", 75);
  zx50 = TTF_OpenFont("zx_spectrum-7.ttf", 50);
  zx45 = TTF_OpenFont("zx_spectrum-7.ttf", 45);
  zx100 = TTF_OpenFont("zx_spectrum-7.ttf",100);
  zx300 = TTF_OpenFont("zx_spectrum-7.ttf",300);

  //CRIA OS TEXTO
  SDL_Surface * alert = TTF_RenderUTF8_Solid(zx25,"Essa tecla não faz nada!",colorWHITE);
  SDL_Surface * gameover = TTF_RenderUTF8_Solid(zx150,"GAME OVER",colorRED);
  SDL_Surface * iniciar = TTF_RenderUTF8_Solid(zx100,"INICIAR",colorORANGE);
  SDL_Surface * ranking = TTF_RenderUTF8_Solid(zx100,"RANKING",colorORANGE);
  SDL_Surface * opcoes = TTF_RenderUTF8_Solid(zx100,"OPÇÕES",colorORANGE);
  SDL_Surface * facil = TTF_RenderUTF8_Solid(zx100,"Salsichinha",colorORANGE);
  SDL_Surface * medio = TTF_RenderUTF8_Solid(zx100,"Salsicho",colorORANGE);
  SDL_Surface * dificil = TTF_RenderUTF8_Solid(zx100,"Sr. silchão",colorORANGE);
  SDL_Surface * contagem1 = TTF_RenderText_Solid(zx300,"1",colorRED);
  SDL_Surface * contagem2 = TTF_RenderText_Solid(zx300,"2",colorRED);
  SDL_Surface * contagem3 = TTF_RenderText_Solid(zx300,"3",colorRED);
  SDL_Surface * user = TTF_RenderText_Solid(zx100,"Insira seu NickName:",colorRED);
  SDL_Surface * tutorial = TTF_RenderText_Solid(zx100, "TUTORIAL",colorORANGE);
  SDL_Surface * jogar = TTF_RenderText_Solid(zx100, " JOGAR ",colorORANGE);
  SDL_Surface * ponto = TTF_RenderText_Solid(zx50,"pontos",colorWHITE);
  SDL_Surface * municaoEscrita = TTF_RenderUTF8_Solid(zx45,"Munição:", colorWHITE);

  //PARTE DA MUNIÇÃO
  int ammo;
  bool recarga = false;

  int mix = 0;
  int aaatual = 0;
  int aatual = 0;
  int atual = 0;
  int fundo = 0;
  int qtdFrame2 = 2;
  int qtdFrame5 = 5;
  int salvar;
  int controle = 0;
  bool indo = false;
  bool voo = false;
  bool tiro = false;
  bool titulo = false;
  bool shift = false;
  bool alerta = false;
  bool hitmarkGANSU[35];
  bool hitmarkBURG[35];
  bool loadContagem = false;
  bool loadJogo = false;
  bool fim1 = false;
  bool fim2 = false;
  bool som = true; //Se tiver false não sai som
  bool caps = false; //Se tiver false não digita letra maiuscula
  bool verificador = true; //Quando igual a true, compara os pontos do ranking
  bool esc = false; //Pra ver se ta pausado
  bool foraTela[35]; //Ver se milho saiu da tela

  char tecla[2];
  char username[7];
  char charMunicao[10];
  char scoreChar[10];// Variavel que armazena o score(float) só que tipo char
  int i = 0;
  int j = 0;
  int shot = 0;
  int hitcontGANSU = 0;
  int hitcontBURG = 0;
  int m = 0;
  int c = 0;

  //VARIAVEIS USADAS PARA O RANKING/ARQUIVO
  int pontoJogador; // variavel pra fazer atoi na variavel ponto
  float score = 0.0;
  Gamer jogador[3];

  //ARQUIVOS EXTERNOS TXT
  FILE *usuario;
  FILE *pontuacao;
  FILE *ler[3]; //tipo "a+" para ler e se nao tiver criar
  FILE *escrever[3]; //tipo "w" para sobrescrever
  FILE *save;

  //RANKING
  char nome0[7];
  char nome1[7];
  char nome2[7];

  char ponto0[5];
  char ponto1[5];
  char ponto2[5];
  
  //SAVE
  

  //POSIÇAO DO MOUSE
  int mouseX = 0.0;
  int mouseY = 0.0;

  //DEFINE OS ENQUADRAMENTOS
  SDL_Rect anim2 = {0,0,128,128};
  SDL_Rect anim256 = {0,0,256,256};
  SDL_Rect anim5 = {0,0,128,128};
  SDL_Rect anim512 = {0,0,512,512};
  SDL_Rect anim12 = {0,0,256,256};
  SDL_Rect BCK = {0,0,1300,800}; 

  int done = 7; // Variável de controle do loop

  while (done >= 0)
  {
    start = SDL_GetTicks();
    while (done == 1) // Loop principal do menu
    { 
      
      SDL_UpdateRect(screen, 0,0,0,0);

      //MENU PRINCIPAL   
      
      if(play == 1){
        Mix_HaltMusic();
        if(som){
          Mix_PlayMusic(musicmenu,-1);
        }
      }
      
      play++;
      
      SDL_BlitSurface(imageMENU,NULL,screen, NULL);

      controle = pisca(controle,50,imageTON,imageTOFF,screen,destBCK);
      
      SDL_BlitSurface(imageSALSICHA[dificuldade],&anim512,screen,&destS);
      SDL_BlitSurface(iniciar,NULL,screen, &destHIGH);
      SDL_BlitSurface(ranking,NULL,screen, &destMIDDLEM);
      SDL_BlitSurface(opcoes,NULL,screen, &destLOW);
      SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
      // Parte de verificar pontuação e criar a escrita dos melhores (RANKING)
      //FACIL-> 0  MEDIO->1  DIFICIL->2
      if(verificador == true)
      {
        ler[0] = fopen("Arquivo/facil.txt","a+");
        ler[1] = fopen("Arquivo/medio.txt","a+");
        ler[2] = fopen("Arquivo/dificil.txt","a+");

        rewind(ler[0]);
        rewind(ler[1]);
        rewind(ler[2]);

        for(i=0;i<3;i++)
        {
          fscanf(ler[i],"%s",jogador[i].name);
          fscanf(ler[i],"%s", jogador[i].ponto);
        }

        for(i=0;i<3;i++)
        { //Talvez eu posso fechar no FOR de cima depois do ultimo fscanf
          fclose(ler[i]);
        }

        strcpy(nome0,jogador[0].name);
        strcpy(ponto0,jogador[0].ponto);
        strcpy(nome1,jogador[1].name);
        strcpy(ponto1,jogador[1].ponto);
        strcpy(nome2,jogador[2].name);
        strcpy(ponto2,jogador[2].ponto);

        switch(dificuldade)
        {
          case 0: //FACIL
            escrever[0] = fopen("Arquivo/facil.txt", "w");
          break;
          case 1: //MEDIO
            escrever[1] = fopen("Arquivo/medio.txt", "w");
          break;
          case 2: //DIFICIL
            escrever[2] = fopen("Arquivo/dificil.txt", "w");
          break;
          default:
          break;
        }

        pontoJogador = atoi(jogador[dificuldade].ponto);

        if(pontoJogador < score)
        {
          fprintf(escrever[dificuldade],"%s\n", username); 
          fprintf(escrever[dificuldade],"%.0f", score);

          if(dificuldade == 0){
            strcpy(nome0,username);
            strcpy(ponto0,scoreChar);
          }
          else if(dificuldade == 1){
            strcpy(nome1,username);
            strcpy(ponto1,scoreChar);
          }
          else{
            strcpy(nome2,username);
            strcpy(ponto2,scoreChar);
          }
        }
        else // Precisa do ELSE pois como ponteiro é "w", ele cria outro arquivo com mesmo nome mas em branco
        {
          fprintf(escrever[dificuldade],"%s\n", jogador[dificuldade].name);
          fprintf(escrever[dificuldade],"%s", jogador[dificuldade].ponto);
        }

        fclose(escrever[dificuldade]);

        verificador = false;
      }
      
      // Lê a fila de eventos e põe o evento mais antigo em "event"
      while (SDL_PollEvent(&event)) // Loop de eventos
      {
        // Verifica se o evento mais antigo é do tipo SDL_QUIT
        if (event.type == SDL_QUIT){ // Se o usuário clicou para fechar a janela
          done = -1; // Encerre o loop
          save = fopen("Arquivo/salvar.txt","w");
          fprintf(save,"0");
          fclose(save);
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){ 
          SDL_GetMouseState(&mouseX,&mouseY);
          if(mouseX<=790 && mouseX>=500)
          {
            //ENTRA NAS OPÇÕES
            if(mouseY<=550 && mouseY>=450)
            {
              done = 2;
            }
            //MANDA PRO PRE JOGO
            if(mouseY<=450 && mouseY>=300)
            {
              done = 5;
            }

            //ENTRA NAS OPÇÕES
            if(mouseY<=750 && mouseY>=600)
            {
              done = 3;
            }
          }
        }

        //BOTÃO DE VOLTAR
        if(event.type == SDL_MOUSEBUTTONDOWN){
          if(event.button.button == SDL_BUTTON_LEFT)
          {
            SDL_GetMouseState(&mouseX,&mouseY);
            if(mouseX<=128 && mouseX>=0)
            {
              if(mouseY<=128 && mouseY>=0)
              {
                anim2.y = 128;
                SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
              }
            }
          }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
          SDL_GetMouseState(&mouseX,&mouseY);
          if(mouseX<=128 && mouseX>=0)
          {
            if(mouseY<=128 && mouseY>=0)
            {
              anim2.y = 0;
              done = 4;
            }  
          }
        }
        
        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if(event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
            case SDLK_LEFT:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
          }
        }
        if (event.type == SDL_KEYUP){
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 0;
              done = 4;
            break;
            case SDLK_LEFT:
              anim2.y = 0;
              done = 4;
            break;
          }
        }
      }

      fps1 ++;
      if(fps1 == 30){
        atual += 1;

        if(atual > qtdFrame2 - 1)
        {
            atual = 0;
        }
          
        anim512.y = atual * anim512.h;
        fps1 = 0;
      }

      SDL_Surface * nomehub = TTF_RenderText_Solid(zx50,username,colorORANGE);
      SDL_BlitSurface(nomehub,NULL,screen, &destUSERNAME);

      SDL_UpdateRect(screen, 0,0,0,0);
  
    }
    
    //É AQUI QUE O JOGO COMEÇA MESMO
    while (done == 0)
    { 
      if(loadContagem == true){

        srand(time(NULL));

        //RESETA OS INIMIGOS
        GANSU.y = 1+(rand()%583);
        GANSU.x = 2000 +(rand()%500);

        srand(time(NULL));
        destAMMO.y = 1+(rand()%583);
        destAMMO.x = 1300 +(rand()%200);

        for(i=0; i < (3+dificuldade);i++){
          destBURG[i].y = 1+(rand()%583);
          destBURG[i].x = 1300 + (i*20) +(rand()%200);
        }

        //Resetando tudo dos tiros
        ammo = 0;
        for(i=0;i<35;i++){
          hitmarkBURG[i] = true;
          hitmarkGANSU[i] = true;
          foraTela[i] = true;
          destMILHO[i].x = 6000;
        }
        
        sprintf(charMunicao, "%d", ammo);

        SDL_UpdateRect(screen, 0,0,0,0);
        SDL_BlitSurface(imageBCK, &BCK, screen,&destBCK);
        SDL_BlitSurface(imageLATERAL, NULL, screen, NULL); 
        SDL_BlitSurface(municaoEscrita,NULL,screen,&destMUNICAOESC);
        SDL_BlitSurface(ponto,NULL,screen,&destPONTO);
        SDL_BlitSurface(imageSTAND[dificuldade],&anim2,screen,&dest);
        SDL_BlitSurface(contagem3, NULL, screen, &destCONTAGEM);

        SDL_UpdateRect(screen, 0,0,0,0);
        SDL_BlitSurface(imageBCK, &BCK, screen,&destBCK);
        SDL_BlitSurface(imageLATERAL, NULL, screen, NULL);
        SDL_BlitSurface(municaoEscrita,NULL,screen,&destMUNICAOESC);
        SDL_BlitSurface(ponto,NULL,screen,&destPONTO); 
        SDL_BlitSurface(imageSTAND[dificuldade],&anim2,screen,&dest);
        SDL_BlitSurface(contagem2, NULL, screen, &destCONTAGEM);

        SDL_Delay(1000);

        SDL_UpdateRect(screen, 0,0,0,0);
        SDL_BlitSurface(imageBCK, &BCK, screen,&destBCK);
        SDL_BlitSurface(imageLATERAL, NULL, screen, NULL);
        SDL_BlitSurface(municaoEscrita,NULL,screen,&destMUNICAOESC);
        SDL_BlitSurface(ponto,NULL,screen,&destPONTO);
        SDL_BlitSurface(imageSTAND[dificuldade],&anim2,screen,&dest);
        SDL_BlitSurface(contagem1, NULL, screen, &destCONTAGEM);

        SDL_Delay(1000);

        SDL_UpdateRect(screen, 0, 0, 0, 0);
        SDL_BlitSurface(imageBCK, &BCK, screen,&destBCK);
        SDL_BlitSurface(imageLATERAL, NULL, screen, NULL);
        SDL_BlitSurface(municaoEscrita,NULL,screen,&destMUNICAOESC);
        SDL_BlitSurface(ponto,NULL,screen,&destPONTO); 
        SDL_BlitSurface(imageSTAND[dificuldade],&anim2,screen,&dest);
        
        SDL_Delay(500);
        loadContagem = false;
      }

      score += 0.01666667; // Pois atualiza 30x por segundo, e queremos aumentar 1 ponto por seg: 1/30 = 0.03333333
      sprintf(scoreChar, "%.0f", score); // "corverter" float pra char pra na hora de criar o texto

      fundo += 1;

      //o "i" controla a velocidade do background(BCK)

      if( fundo > (12) )
      { 
        fundo = 0;
      }
      BCK.x = fundo * 80;

      SDL_BlitSurface(imageBCK,NULL,screen,NULL);

      //MOVIMENTA A LUA
      if(destMOON.x > 2){
        SDL_BlitSurface(imageMOON,NULL,screen,&destMOON);
        destMOON.x -= 2;
      }

      srand(time(NULL));

      SDL_BlitSurface(imagePARTICULA, &BCK, screen,&destBCK);// Blita a imagem em destBCK

      // Lê a fila de eventos e põe o evento mais antigo em "event"
      while (SDL_PollEvent(&event)) // Loop de eventos
      {
        // Verifica se o evento mais antigo é do tipo SDL_QUIT
        if (event.type == SDL_QUIT){ // Se o usuário clicou para fechar a janela
          done = -1; // Encerre o loop
          save = fopen("Arquivo/salvar.txt","w");
          fprintf(save,"0");
          fclose(save);
        }
        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if (event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              esc = true;
              break;
            case SDLK_d:
              velX = 10;
              break;
            case SDLK_a:
              velX = -10;
              break;
            case SDLK_SPACE:
              tiro = true;
              indo = true;
              break;
            case SDLK_w:
              voo = true;
              velY = -30;
              break;
            default:
              alerta = true;
              break;
          }
        }
          if (event.type == SDL_KEYUP) // Se o usuário soltou um botão do teclado
          {
            // Verifica qual tecla foi solta
            switch (event.key.keysym.sym)
            {
              case SDLK_d:
                velX = 0;
                break;
              case SDLK_a:
                velX = 0;
                break;
              case SDLK_w:
                voo = false;
                velY = 10;
                break;
              case SDLK_SPACE:
                tiro = false;
                break;
              default:
                alerta = false;
                break;
            }
          }
      }

      if(esc) //PAUSE
      {
        while(esc)
        {
          
          SDL_BlitSurface(imageBCK,NULL,screen,NULL);
          SDL_BlitSurface(imagePAUSE, NULL, screen, NULL);
          SDL_UpdateRect(screen, 459,130,630,470);

          while (SDL_PollEvent(&event)) // Loop de eventos
          {
            if (event.type == SDL_QUIT) // Se o usuário clicou para fechar a janela
            {
              done = -1; // Encerre o loop
              esc = false;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){ 
              if(event.button.button == SDL_BUTTON_LEFT)
              {
                SDL_GetMouseState(&mouseX,&mouseY);
                if(mouseX<=887 && mouseX>=583)
                {
                  //CONTINUAR
                  if(mouseY<=293 && mouseY>=221)
                  {
                    esc = false;
                    if(loadJogo){
                      loadJogo = false;
                    }
                  }
                  //SALVAR
                  if(mouseY<=380 && mouseY>=310)
                  {
                    //FAZER A GRAVAÇÃO DOS DADOS AQUI
                    printf("SALVO!\n");
                    save = fopen("Arquivo/salvar.txt","w");
                    loadJogo = true;
                    fprintf(save, "1 %s %.0f %d", username, score, dificuldade);
                    fclose(save);
                  }

                  //SAIR
                  if(mouseY<=470 && mouseY>=400)
                  {
                    esc = false;
                    if(loadJogo){
                      loadJogo = false;
                    }
                    done = 1;
                    play = 0;
                    score = 0;
                  }
                }   
              }
            }
          }
        }
      }

      //PAREDE
      if(dest.x < 160){
        dest.x = 160;
      }
      
      if(dest.x > 1200){
        dest.x = 1200;
      }
      //COLISÃO

      for(i = 0;i < (3 + dificuldade);i++){
        fim1 = colisaum(dest,destBURG[i],50,50);
        if(fim1){
          break;
        }
      }
      fim2 = colisaum(dest,GANSU,100,50);

      //RELOOOOOOAAAADDD
      recarga = colisaum(dest,destAMMO,50,50);

      if(recarga){
        ammo = 30/(dificuldade+1);
        destAMMO.y = 1+(rand()%583);
        destAMMO.x = 1300 +(rand()%200);
        recarga = false;
      }

      sprintf(charMunicao, "%d", ammo);

      //ATUALIZANDO HITMARK DE TODOS TIROS
      if(indo){
        for(i=0;i<35;i++){
          hitmarkGANSU[i] = colisaum(destMILHO[i], GANSU, -10, -10);
          if(hitmarkGANSU[i]){
            hitcontGANSU++;
            destMILHO[i].x = 6000;
          }
          if(hitcontGANSU >= 10){
               srand(time(NULL));
              GANSU.y = 1+(rand()%583);
              GANSU.x = 2200;
              score += 10;
              hitcontGANSU = 0;
          }
        }
        for(i=0;i<35;i++){
          for(j=0;j < 3+dificuldade; j++){
            hitmarkBURG[i] = colisaum(destMILHO[i], destBURG[j], 0, 0); 
            if(hitmarkBURG[i]){
              hitcontBURG++;
              if(hitcontBURG == 4){
                destBURG[j].x = 1500;
                score += 2;
                hitcontBURG = 0;
              }
              destMILHO[i].x = 6000; // Pra sair da tela e matar mesmo sem estar blitado
              break;
            }
          }
        }
      }
      //VERIFICANDO SE SAIU DA TELA
      if(indo){
        for(i=0;i<35;i++){
          if(destMILHO[i].x >= 1250){
            foraTela[i] = true;
            destMILHO[i].x = 6000;
          }
        }
      }

      //BLITANDO O TIRO E ACRESCENTANDO NO EIXO X
      if(indo){
        for(i=0;i<35;i++){
          if(hitmarkGANSU[i] == false && hitmarkBURG[i] == false && foraTela[i] == false){
            destMILHO[i].x += 30;
            SDL_BlitSurface(imageMILHO,NULL,screen,&destMILHO[i]);
          }
        }
      }

      //PARTE DAS ANIMAÇÕES

      if(voo == true && tiro == true){
        if(ammo != 0){
          //TIRINHO INDO
          for(i=0;i<35;i++){
            if(hitmarkGANSU[i] == true || hitmarkBURG[i] == true || foraTela[i] == true ){
              destMILHO[i] = criatiro(dest);
              hitmarkGANSU[i] = false;
              hitmarkBURG[i] = false;
              foraTela[i] = false;
              SDL_BlitSurface(imageMILHO,NULL,screen,&destMILHO[i]);
              SDL_BlitSurface(imagePEWFLY[dificuldade], &anim5, screen, &dest);
              if(som){Mix_PlayChannel(-1,effect[dificuldade],0);}
              ammo--;
              break;
            }
          }
        }else{
          SDL_BlitSurface(imageFLY[dificuldade], &anim2, screen, &dest);
        }
      }
      else {
        //ANIMA O TIIIIRO
        if(tiro == true){
          if(ammo != 0){
            for(i=0;i<35;i++){
              if(hitmarkGANSU[i] == true || foraTela[i] == true || hitmarkBURG[i] == true){
                destMILHO[i] = criatiro(dest);
                hitmarkGANSU[i] = false;
                hitmarkBURG[i] = false;
                foraTela[i] = false;
                ammo--;
                SDL_BlitSurface(imageMILHO,NULL,screen,&destMILHO[i]);
                SDL_BlitSurface(imagePEW[dificuldade], &anim5, screen, &dest);
                if(som){Mix_PlayChannel(-1,effect[dificuldade],0);}
                break;
              }
            }
          }else{
            SDL_BlitSurface(imageSTAND[dificuldade],&anim2,screen,&dest);
          }
        }
        //ANIMA O VOO
        if(voo == true){
        SDL_BlitSurface(imageFLY[dificuldade], &anim2, screen, &dest);
        }
      }


      //ANIMA O GANSU
      if(GANSU.x < 20){
        srand(time(NULL));
        GANSU.y = 1+(rand()%583);
        GANSU.x = 1500 + (rand()%500);
      }
      SDL_BlitSurface(imageGANSU,&anim256,screen,&GANSU);
      GANSU.x -= 10;

      srand(time(NULL));

      //ANIMA A BOLSA DE MUNIÇÃO
      if(destAMMO.x < 20){
        destAMMO.y = 1+(rand()%583);
        destAMMO.x = 1300 + (rand()%200);
      }
      SDL_BlitSurface(imageAMMO,NULL,screen,&destAMMO);
      destAMMO.x -= 20;

      //ANIMA O BURGUINHO
      for(i = 0;i < (3+dificuldade);i++){
        if(destBURG[i].x < 20){
          srand(time(NULL) + (i*30));
          destBURG[i].y = (10*i) +(rand()%583);
          destBURG[i].x = 1300 + (i*30) + (rand()%200);
        }
        SDL_BlitSurface(imageBURGUER,&anim2,screen,&destBURG[i]);
        destBURG[i].x -= 10 ;
      }

      //ANIMA O STAND
      if(voo == false && tiro == false){
        SDL_BlitSurface(imageSTAND[dificuldade],&anim2,screen,&dest);
      }

      if(alerta){
        SDL_BlitSurface(alert,NULL,screen,&destTxt);
      }

      //EXIBE O GAMEOVER
      if(dest.y + 200 >= 800 || fim1 || fim2){

        if(som){
          Mix_PlayMusic(musicgameover, 0);
        }

        SDL_Delay(200); // Delayzin pra tentar sincronizar imagem com som

        SDL_BlitSurface(imageTRANSICAO, NULL, screen, NULL);
        SDL_BlitSurface(gameover,NULL,screen, &destGAMEOVER);
        SDL_BlitSurface(imageLATERAL, NULL, screen, NULL);
        SDL_BlitSurface(municaoEscrita,NULL,screen,&destMUNICAOESC);
        SDL_Surface * SCORE = TTF_RenderText_Solid(zx75, scoreChar, colorRED);
        SDL_BlitSurface(SCORE,NULL,screen, &destSCORE);
        SDL_BlitSurface(ponto,NULL,screen,&destPONTO);


        SDL_UpdateRect(screen, 0,0,0,0);

        SDL_Delay(3000);

        //SDL_UpdateRect(screen,0,0,0,0); 

        destMOON.x = 0;
        GANSU.x = 5000;
        GANSU.y = 1+(rand()%583);
        for(i=0;i<(3 + dificuldade);i++){
          srand((unsigned)time(NULL));
          destBURG[i].x = 1300 + (rand()% 200 + (i * 50));
        }
        indo = false;
        done = 1;
        play = 1;
        verificador = true;
        save = fopen("Arquivo/salvar.txt","w");
        fprintf(save,"0");
        fclose(save);
      }

      //MOVIMENTO GRAVIDADE
      dest.x += velX; // Soma a velocidade X
      dest.y += velY; // Soma a velocidade Y
      destTxt.x = dest.x + 30;
      destTxt.y = dest.y - 25;

      //REALIZA A ANIMAÇÃO DOS SPRITES
      atual += 1;

      if(atual > qtdFrame5 - 1)
      {
        atual = 0;
      }
          
      anim5.y = atual * anim5.h;

      fps3 ++;
      if(fps3 == 10){
        aatual += 1;
        if(aatual > qtdFrame2 - 1)
        {
          aatual = 0;
        }                               
        anim2.y = aatual * anim2.h;
        anim256.y = aatual * anim256.h;
        fps3 = 0;
      }

      SDL_BlitSurface(imageLATERAL, NULL, screen, NULL); 
      SDL_BlitSurface(municaoEscrita,NULL,screen,&destMUNICAOESC);
      SDL_BlitSurface(ponto,NULL,screen,&destPONTO);
      SDL_Surface * SCORE = TTF_RenderText_Solid(zx75, scoreChar, colorRED);
      SDL_BlitSurface(SCORE,NULL,screen, &destSCORE);
      SDL_Surface * municao = TTF_RenderText_Solid(zx75,charMunicao,colorRED);
      SDL_BlitSurface(municao, NULL, screen, &destMUNICAO);



      //DA UPDATE NA TELA
      SDL_Flip(screen);
      SDL_Delay(34);
    }

    //LOOP DO RANK
    while (done == 2) 
    { 
      
      SDL_UpdateRect(screen, 0,0,0,0);
      //Criando as escritas do rank
      SDL_Surface * NTOP2 = TTF_RenderText_Solid(zx50,nome2,colorGOLD);
      SDL_Surface * NTOP1 = TTF_RenderText_Solid(zx50,nome1,colorSILVER);
      SDL_Surface * NTOP0 = TTF_RenderText_Solid(zx50,nome0,colorBABYBLUE);

      SDL_Surface * PTOP2 = TTF_RenderText_Solid(zx50,ponto2,colorGOLD);
      SDL_Surface * PTOP1 = TTF_RenderText_Solid(zx50,ponto1,colorSILVER);
      SDL_Surface * PTOP0 = TTF_RenderText_Solid(zx50,ponto0,colorBABYBLUE);
      
      // Lê a fila de eventos e põe o evento mais antigo em "event"
      while (SDL_PollEvent(&event)) // Loop de eventos
      {
        // Verifica se o evento mais antigo é do tipo SDL_QUIT
        if (event.type == SDL_QUIT){
          done = -1;
          save = fopen("Arquivo/salvar.txt","w");
          fprintf(save,"0");
          fclose(save);
        }
        //BOTÃO DE VOLTAR
        if(event.type == SDL_MOUSEBUTTONDOWN){      
          if(event.button.button == SDL_BUTTON_LEFT)
          {
            SDL_GetMouseState(&mouseX,&mouseY);
            if(mouseX<=128 && mouseX>=0)
            {
              if(mouseY<=128 && mouseY>=0)
              {
                anim2.y = 128;
                SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
              }
              
            }
            
          }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
          SDL_GetMouseState(&mouseX,&mouseY);
          if(mouseX<=128 && mouseX>=0)
          {
            if(mouseY<=128 && mouseY>=0)
            {
              anim2.y = 0;
              done = 1;
            }  
          }
        }
        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if(event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
            case SDLK_LEFT:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
          }
        }
        if (event.type == SDL_KEYUP){
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 0;
              done = 1;
            break;
            case SDLK_LEFT:
              anim2.y = 0;
              done = 1;
            break;
          }
        }
      }

      play++;
      
      controle = pisca(controle,50,imageRANKON,imageRANKOFF,screen,destBCK);

      SDL_BlitSurface(imageVOLTAR,&anim2,screen, NULL);

      //BLITANDO AS INFORMAÇÕES DO RANKING

      SDL_BlitSurface(NTOP0, NULL, screen, &destNTOP0);
      SDL_BlitSurface(NTOP1, NULL, screen, &destNTOP1);
      SDL_BlitSurface(NTOP2, NULL, screen, &destNTOP2);

      SDL_BlitSurface(PTOP0, NULL, screen, &destPTOP0);
      SDL_BlitSurface(PTOP1, NULL, screen, &destPTOP1);
      SDL_BlitSurface(PTOP2, NULL, screen, &destPTOP2);

      SDL_Flip(screen);
      if((1000/FPS) > (SDL_GetTicks() - start)){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - start));
      }

    }

    //LOOP DAS OPÇÕES
    while(done == 3){
      
      SDL_BlitSurface(imageMENU,NULL,screen, NULL);
      SDL_BlitSurface(imageSALSICHA[dificuldade],&anim512,screen,&destS);
      SDL_BlitSurface(facil, NULL, screen, &destHIGH); 
      SDL_BlitSurface(medio, NULL, screen, &destMIDDLEM);
      SDL_BlitSurface(dificil, NULL, screen, &destLOW);
      SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);

      controle = pisca(controle,50,imageDIFICUON,imageDIFICUOFF,screen,destBCK);

      fps1++;
      
      if(fps1 == 30){
        atual += 1;
        if(atual > qtdFrame2 - 1)
        {
            atual = 0;
        }
        anim512.y = atual * anim512.h;
        fps1 = 0;
      }

      while(SDL_PollEvent(&event)) //While de eventos
      { 
        if(event.type == SDL_QUIT)
        {
          done = -1;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){      
          if(event.button.button == SDL_BUTTON_LEFT)
          {
            SDL_GetMouseState(&mouseX,&mouseY);
            
            //DA BACK NO KIBE
            if(mouseX<=128 && mouseX>=0)
            {
              if(mouseY<=128 && mouseY>=0)
              {
                anim2.y = 128;
                SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
              }
              
            }

            //Desativando o som
            if(mouseX>=1170 && mouseX<=1300)
            {
              if(mouseY>=10 && mouseY<=120){
                if(som == true){  
                  som = false;
                  Mix_HaltMusic();
                }
                else{
                  som = true;
                  Mix_PlayMusic(musicmenu,-1);
                }
              }
            }
            //Niveis de DIficuldade
            if(mouseX<=1000 && mouseX>=400)
            {
              if(mouseY<=450 && mouseY>=300)
              {
                //DIFICULDADE BAIXA
                dificuldade = 0;
                score = 0;
              }
              if(mouseY<=600 && mouseY>=450)
              {
                //DIFICULDADE MEDIA
                dificuldade = 1;
                score = 0;
              }
              if(mouseY<=750 && mouseY>=600)
              {
                //DIFICULDADE ALTA
                dificuldade = 2;
                score = 0;
              }
            }
          }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
          SDL_GetMouseState(&mouseX,&mouseY);
          if(mouseX<=128 && mouseX>=0)
          {
            if(mouseY<=128 && mouseY>=0)
            {
              anim2.y = 0;
              done = 1;
            }
          }
        }
        
        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if(event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
            case SDLK_LEFT:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
          }
        }
        if (event.type == SDL_KEYUP){
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 0;
              done = 1;
            break;
            case SDLK_LEFT:
              anim2.y = 0;
              done = 1;
            break;
          }
        }
      }
      
      //Atualizando imagem do SOM
      if(som == true){
        SDL_BlitSurface(imageCOMSOM, NULL, screen, &destSOM);
      }
      else{
        SDL_BlitSurface(imageSEMSOM, NULL, screen, &destSOM);
      }
      
      SDL_Flip(screen);
      if((1000/FPS) > (SDL_GetTicks() - start)){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - start));
      }

    }

    //LOOP DO USER NAME
    while (done == 4) // Loop principal do menu
    { 
     
      SDL_UpdateRect(screen, 0,0,0,0);
              
      // Lê a fila de eventos e põe o evento mais antigo em "event"
      while (SDL_PollEvent(&event)) // Loop de eventos
      {
        // Verifica se o evento mais antigo é do tipo SDL_QUIT
        if (event.type == SDL_QUIT) // Se o usuário clicou para fechar a janela
          done = -1; // Encerre o loop

        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if (event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              done = -1;
            break;
            case SDLK_RETURN:
              if(username[0] == '\0'){
                c = 6;
                strcpy(username,"NoName");
              }
              done = 1;
              score = 0;
            break;
            case SDLK_LSHIFT:
              shift = true;
            break;
            case SDLK_BACKSPACE:
              if(c != 0){
                username[c]=' ';
                c--;
              }
            break;
            case SDLK_SPACE:
              //Só para nao colocar o espaço automaticamente
            break;
            case SDLK_CAPSLOCK:
              if(caps == true){
                caps = false;
              }
              else{
                caps = true;
              }
            break;
            default:
              if(c!=6){
                username[c] = (event.key.keysym.sym);
                if(caps == true && shift == true){
                  username[c] = tolower(username[c]);
                }
                else if(caps == true || shift == true){
                  username[c] = toupper(username[c]);
                }
                else{
                  username[c] = tolower(username[c]);
                }
                c++;
              }
              //COLOCAR O SOM DE ERRO
              else{
                Mix_PlayChannel(-1,nop,0);
              }

            break;
          }
          username[c]='\0';
        }
        if (event.type == SDL_KEYUP){
          switch (event.key.keysym.sym)
          {
            case SDLK_LSHIFT:
              shift = false;
            break;
            default:
            break;
          }
        }

      }
      SDL_UpdateRect(screen, 0,0,0,0);
      controle = pisca(controle,50,imageNICKON,imageNICKOFF,screen,destBCK);
      SDL_Surface * nome = TTF_RenderText_Solid(zx100,username,colorWHITE);
      SDL_BlitSurface(nome,NULL,screen, &destNICK);
      SDL_UpdateRect(screen, 0,0,0,0);

    }

    //LOOP DO PRÉ-JOGO
    while (done == 5)
    {         
      // Lê a fila de eventos e põe o evento mais antigo em "event"
      while (SDL_PollEvent(&event)) // Loop de eventos
      {
        // Verifica se o evento mais antigo é do tipo SDL_QUIT
        if (event.type == SDL_QUIT){ // Se o usuário clicou para fechar a janela
          done = -1; // Encerre o loop
        }
        //BOTÃO DE VOLTAR
        if(event.type == SDL_MOUSEBUTTONDOWN){      
          if(event.button.button == SDL_BUTTON_LEFT)
          {
            SDL_GetMouseState(&mouseX,&mouseY);
            if(mouseX<=128 && mouseX>=0)
            {
              if(mouseY<=128 && mouseY>=0)
              {
                anim2.y = 128;
                SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
              }
              
            }
            
          }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
          SDL_GetMouseState(&mouseX,&mouseY);
          if(mouseX<=128 && mouseX>=0)
          {
            if(mouseY<=128 && mouseY>=0)
            {
              anim2.y = 0;
              done = 1;
            }  
          }
        }
        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if(event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
            case SDLK_LEFT:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
          }
        }
        if (event.type == SDL_KEYUP){
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 0;
              done = 1;
            break;
            case SDLK_LEFT:
              anim2.y = 0;
              done = 1;
            break;
          }
        }

        if(event.type == SDL_MOUSEBUTTONDOWN){  
          if(event.button.button == SDL_BUTTON_LEFT)
          {
            SDL_GetMouseState(&mouseX,&mouseY);
            //Cordenadas para o ARCADE (INICIAR O JOGO)
            if(mouseX<= 575  && mouseX>= 255)
            {
                if(mouseY<= 594 && mouseY>= 284)
                {
                  dest.x = 160;
                  dest.y = 0;
                  done = 0; //Manda pro jogo
                  Mix_HaltMusic();
                  loadContagem = true;
                  score = 0;
                }
            }
            //Cordenadas para o TUTORIAL
            if(mouseX<= 1016 && mouseX>= 695){
              if(mouseY<= 596 && mouseY>= 281)
              {
                done = 6; // MANDA TUTORIAL
              }
            }
          }
        }

      }

      SDL_UpdateRect(screen, 0,0,0,0);
      SDL_BlitSurface(imageMENU, NULL, screen, NULL);
      SDL_BlitSurface(imagePREJOGO,NULL,screen,NULL);
      SDL_BlitSurface(tutorial,NULL,screen,&destTUTOR);
      SDL_BlitSurface(jogar,NULL,screen,&destJOGO);
      SDL_BlitSurface(imageTUTORIAL,&anim12,screen,&destTUTORIAL);
      SDL_BlitSurface(imagePEW[dificuldade],&anim5,screen,&destJOGOBIXU);
      SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
      SDL_UpdateRect(screen, 0,0,0,0);

      fps2 ++;
      if(fps2 == 30){
        aaatual ++;
        fps2 = 0;
        if(aaatual > 11)
        {
          aaatual = 0;
        }
        anim12.y = aaatual * anim12.h;

        atual += 1;

        if(atual > qtdFrame5 - 1)
        {
          atual = 0;
        }
            
        anim5.y = atual * anim5.h;

      }

    }

    //LOOP DO TUTORIAL
    while(done == 6)
    {
      SDL_UpdateRect(screen, 0,0,0,0);

      // Lê a fila de eventos e põe o evento mais antigo em "event"
      while (SDL_PollEvent(&event)) // Loop de eventos
      {
        // Verifica se o evento mais antigo é do tipo SDL_QUIT
        if (event.type == SDL_QUIT){ // Se o usuário clicou para fechar a janela
          done = -1; // Encerre o loop
        }
        //BOTÃO DE VOLTAR
        if(event.type == SDL_MOUSEBUTTONDOWN){      
          if(event.button.button == SDL_BUTTON_LEFT)
          {
            SDL_GetMouseState(&mouseX,&mouseY);
            if(mouseX<=128 && mouseX>=0)
            {
              if(mouseY<=128 && mouseY>=0)
              {
                anim2.y = 128;
                SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
              }
              
            }
            
          }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
          SDL_GetMouseState(&mouseX,&mouseY);
          if(mouseX<=128 && mouseX>=0)
          {
            if(mouseY<=128 && mouseY>=0)
            {
              anim2.y = 0;
              done = 5;
            }  
          }
        }
        // Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
        if(event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        {
          // Verifica qual tecla foi apertada
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
            case SDLK_LEFT:
              anim2.y = 128;
              SDL_BlitSurface(imageVOLTAR,&anim2,screen,&destVOLTAR);
            break;
          }
        }
        if (event.type == SDL_KEYUP){
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              anim2.y = 0;
              done = 5;
            break;
            case SDLK_LEFT:
              anim2.y = 0;
              done = 5;
            break;
          }
        }
      }
      
      SDL_UpdateRect(screen, 0,0,0,0);
      SDL_BlitSurface(imageCONTROLES,NULL,screen,NULL);
      SDL_BlitSurface(imageVOLTAR,&anim2,screen,NULL);
      SDL_UpdateRect(screen, 0,0,0,0);
    }

    //LOOP PARA VERIFICAR SE SALVOU OU NAO
    while(done == 7)
    {
      save = fopen("Arquivo/salvar.txt","a+");
      rewind(save);
      fscanf(save, "%d", &salvar); //Salvar é o numero dentro do arquivo

      if(salvar == 1){
        //BLITA AS IMAGENS
        while(1)
        {
           while (SDL_PollEvent(&event)) // Loop de eventos
          {
            // Verifica se o evento mais antigo é do tipo SDL_QUIT
            if (event.type == SDL_QUIT){ // Se o usuário clicou para fechar a janela
              done = -1; // Encerre o loop
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){  
              if(event.button.button == SDL_BUTTON_LEFT)
              {
                SDL_GetMouseState(&mouseX,&mouseY);
                // SIM
                if(mouseX<= 621  && mouseX>= 491)
                {
                    if(mouseY<= 411 && mouseY>= 344)
                    {
                      fscanf(save, "%s %f %d", username, &score, &dificuldade);
                      fclose(save);
                      done = 0; //INICIA GAME
                      loadContagem = true;
                      dest.x = 160;
                      sprintf(scoreChar, "%.0f", score); // "corverter" float pra char pra na hora de criar o texto
                      SDL_Surface * SCORE = TTF_RenderText_Solid(zx75, scoreChar, colorRED);
                    }
                }
                //NAO
                if(mouseX<= 833 && mouseX>= 690){
                  if(mouseY<= 411 && mouseY>= 329)
                  {
                    fclose(save);
                    save = fopen("Arquivo/salvar.txt","w"); // Zerando o que ta no arquivo
                    fprintf(save,"0");
                    fclose(save);
                    done = 4;
                  }
                }
              }
            }
          }

          if(done!=7){
            break;
          }

          SDL_UpdateRect(screen, 0,0,0,0);
          SDL_BlitSurface(imageMENU, NULL, screen, NULL);
          SDL_BlitSurface(imageCONFIRMA, NULL, screen, NULL);
          SDL_UpdateRect(screen, 0,0,0,0);
        }
      }

      else{
        done = 4;
        break;
      }
    }
  }

  //FECHA O PROGRAMA
  Mix_FreeMusic(musicmenu);
  Mix_CloseAudio();

  for(select=0;select < 3;select++){
    SDL_FreeSurface(imageSTAND[select]);
    SDL_FreeSurface(imageFLY[select]);
    SDL_FreeSurface(imagePEW[select]);
    SDL_FreeSurface(imagePEWFLY[select]);
    Mix_FreeChunk(effect[select]);
  }

  SDL_FreeSurface(imageBCK);
  SDL_FreeSurface(imageMOON);
  SDL_FreeSurface(gameover);
  SDL_FreeSurface(alert);

  SDL_Quit(); // Fecha o SDL

  return 0;
}
