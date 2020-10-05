#include <stdlib.h>
#include<cstdio>
#include <SDL/SDL.h>
#include <ctime>
#include <cmath>
#include <SDL/SDL_ttf.h>
#include <fmodex/fmod.h>
#define pp  10000000

int lose(SDL_Rect position[100],int p)
{
           int m=0,j;
           for(j=1;j<p;j++)
           {
                if(position[j].x==position[0].x  && position[j].y==position[0].y)
                      m=1;
           }
           return m;
}


//LA FONCTION MAIN
int main (int argc,char *argv[])
{
     SDL_Surface *ecran=NULL,*imagefond=NULL,*imagen=NULL,*imagec=NULL,*imagec0=NULL,*imagec1=NULL,*imagec2=NULL,*ima=NULL,*txt=NULL;
     SDL_Surface *rectangle[100],*rectangle1=NULL,*rectangle2=NULL,*rectangle3=NULL;
     SDL_Rect position[100],positionfond,positionn,positionc,positionm,positiont;
     positionfond.x=0;
     positionfond.y=0;
     positionn.x=0;
     positionn.y=0;
      positionc.x=50;
      positionc.y=50;
      positionm.x=0;
      positionm.y=310;
      TTF_Font *police = NULL;
      SDL_Color couleurNoire = {0,250, 0};
      positiont.x=20;
      positiont.y=320;
     int k;
     for(k=0;k<100;k++)
     {
     rectangle[k]=NULL;
     position[k].x = 0;
     position[k].y = 0;
     }
     position[0].x = 100;
     position[0].y = 100;
     int a,b;
     SDL_Rect position1;
     srand(time(NULL));
     a=(rand()%440)/10;
     b=(rand()%300)/10;
     position1.x =a*10;
     position1.y =b*10;
     SDL_Rect position2;
     position2.x = 0;
     position2.y = 300;

     SDL_Event event,event1;
     int i=1,j,p=10,c1,c2,c3,c4,c=1,m=1,q=1,z=1,o=1,l=1;
     int tempsPrecedent=0,tempsActuel=0,t=0;

     SDL_Init( SDL_INIT_VIDEO);
     TTF_Init();
     ecran=SDL_SetVideoMode(440,440,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
     SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 250, 250,250));
     SDL_WM_SetIcon(SDL_LoadBMP("image.bmp"), NULL);

     imagefond = SDL_LoadBMP("serpent.bmp");
     SDL_BlitSurface(imagefond, NULL, ecran, &positionfond);
     imagen=SDL_LoadBMP("play.bmp");
     SDL_BlitSurface(imagen, NULL, ecran, &positionn);
     SDL_Flip(ecran);
     FMOD_SYSTEM *system;
     FMOD_SOUND *tir = NULL;
     FMOD_RESULT resultat;
      FMOD_System_Create(&system);
      FMOD_System_Init(system,32,FMOD_INIT_NORMAL, NULL);
      resultat=FMOD_System_CreateSound(system, "eat.wav",FMOD_CREATESAMPLE,0,&tir);
           if (resultat != FMOD_OK)
           {
               fprintf(stderr, "Impossible de lire pan.wav\n");
               exit(EXIT_FAILURE);
            }

     while(q==1)
     {
           char ch[5]="0";
           int co=0;

           SDL_PollEvent(&event);
           switch(event.type)
           {
            case SDL_QUIT:
                  return EXIT_SUCCESS;
            break;
            case SDL_MOUSEBUTTONUP:
                 if(event.button.button == SDL_BUTTON_LEFT && event.button.x<100 && event.button.y<100)
                 q=0;
            break;
            }
            if(q==0)
            {
               i=1;
               ecran=SDL_SetVideoMode(440,440,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
               SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 250, 250,250));
               police = TTF_OpenFont("police.ttf",10);
               txt=TTF_RenderText_Blended(police,ch,couleurNoire);
                ima=SDL_LoadBMP("ima.bmp");
               imagec=SDL_LoadBMP("c.bmp");
               imagec0=SDL_LoadBMP("c0.bmp");
               imagec1=SDL_LoadBMP("c1.bmp");
               imagec2=SDL_LoadBMP("c2.bmp");
               SDL_BlitSurface(imagec1, NULL, ecran, &position1);
               SDL_BlitSurface(imagec2, NULL, ecran, &position2);
               SDL_BlitSurface(imagec0, NULL, ecran, &position[0]);
               SDL_BlitSurface(ima, NULL, ecran,&positionm);
               SDL_BlitSurface(txt, NULL, ecran, &positiont);
               SDL_Flip(ecran);
            while (i)
            {

               if(t==1)
               {
                if(position[0].x+10!=440)
                  {
                    c1=position[0].x;
                    c3=position[0].y;
                    position[0].x=position[0].x+10;
                      if(lose(position,p)==0)
                         {
                           for(j=1;j<100;j++)
                            {
                              c2=position[j].x;
                              position[j].x=c1;
                              c1=c2;
                              c4=position[j].y;
                               position[j].y=c3;
                               c3=c4;
                            }
                          }
                      else i=0 ;
                    }
                  else
                   {
                      c1=position[0].x;
                      c3=position[0].y;
                      position[0].x=0;
                      if(lose(position,p)==0)
                        {
                            for(j=1;j<100;j++)
                             {
                              c2=position[j].x;
                              position[j].x=c1;
                              c1=c2;
                              c4=position[j].y;
                              position[j].y=c3;
                              c3=c4;
                              }
                        }
                      else i=0 ;
                     }
                   if(position[0].x==position1.x && position[0].y==position1.y)
                  {
                    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                    while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                    p++;
                    co=co+5;
                  }


                    SDL_BlitSurface(imagec0, NULL, ecran, &position[0]);
                for(j=1;j<p;j++)
                {
                       SDL_BlitSurface(imagec, NULL, ecran, &position[j]);
                }
                 rectangle[p] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0,0,0,0);
                SDL_FillRect(rectangle[p], NULL, SDL_MapRGB(ecran->format,250,250,250));
                SDL_BlitSurface(rectangle[p], NULL,ecran,&position[p]);
                SDL_BlitSurface(imagec1, NULL, ecran, &position1);
                SDL_BlitSurface(ima, NULL, ecran,&positionm);
                sprintf(ch,"%d",co);
                txt=TTF_RenderText_Blended(police,ch,couleurNoire);
                SDL_BlitSurface(txt, NULL, ecran, &positiont);
                SDL_Flip(ecran);
               }


                        if(t==2)
              {

                      if(position[0].x-10>=0)
                      {
                        c1=position[0].x;
                        c3=position[0].y;
                         position[0].x=position[0].x-10;
                           if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].x;
                        position[j].x=c1;
                        c1=c2;
                        c4=position[j].y;
                        position[j].y=c3;
                        c3=c4;
                        }
                        }
                        else i=0 ;
                      }
                      else
                      {
                            c1=position[0].x;
                        c3=position[0].y;
                         position[0].x=430;
                           if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].x;
                        position[j].x=c1;
                        c1=c2;
                        c4=position[j].y;
                        position[j].y=c3;
                        c3=c4;
                        }
                        }
                        else i=0 ;
                      }
                      if(position[0].x==position1.x && position[0].y==position1.y)
                              {
                                 FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                                         co=co+5;
                                 while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                    SDL_BlitSurface(imagec0, NULL, ecran, &position[0]);
                for(j=1;j<p;j++)
                {
                       SDL_BlitSurface(imagec, NULL, ecran, &position[j]);
                }
                rectangle[p] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0,0,0,0);
                SDL_FillRect(rectangle[p], NULL, SDL_MapRGB(ecran->format,250,250,250));
                SDL_BlitSurface(rectangle[p], NULL,ecran,&position[p]);
                SDL_BlitSurface(imagec1, NULL, ecran, &position1);
                 SDL_BlitSurface(ima, NULL, ecran,&positionm);
                 sprintf(ch,"%d",co);
                 txt=TTF_RenderText_Blended(police,ch,couleurNoire);
                 SDL_BlitSurface(txt, NULL, ecran, &positiont);
                SDL_Flip(ecran);
               }
                                   if(t==3)
              {

                      if(position[0].y-10>=0)
                      {
                        c1=position[0].y;
                        c3=position[0].x;
                        position[0].y= position[0].y-10;
                          if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                      }
                        }
                        else i=0;
                      }
                      else
                      {
                        c1=position[0].y;
                        c3=position[0].x;
                        position[0].y=290;
                          if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                        }
                        }
                        else i=0 ;
                      }
                       if(position[0].x==position1.x && position[0].y==position1.y)
                               {
                      FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                                  co=co+5;
                             while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                    SDL_BlitSurface(imagec0, NULL, ecran, &position[0]);
                for(j=1;j<p;j++)
                {
                       SDL_BlitSurface(imagec, NULL, ecran, &position[j]);
                }
               rectangle[p] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0,0,0,0);
                SDL_FillRect(rectangle[p], NULL, SDL_MapRGB(ecran->format,250,250,250));
                SDL_BlitSurface(rectangle[p], NULL,ecran,&position[p]);
                SDL_BlitSurface(imagec1, NULL, ecran, &position1);
                 SDL_BlitSurface(ima, NULL, ecran,&positionm);
                 sprintf(ch,"%d",co);
                 txt=TTF_RenderText_Blended(police,ch,couleurNoire);
               SDL_BlitSurface(txt, NULL, ecran, &positiont);
                SDL_Flip(ecran);
               }
                                   if(t==4)
              {

                 if(position[0].y+10!=300)
                 {
                       c1=position[0].y;
                       c3=position[0].x;
                       position[0].y= position[0].y+10;
                         if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                        }
                        }
                        else i=0;
                        }
                         else
                      {
                         if(lose(position,p)==0)
                        {
                        c1=position[0].y;
                        c3=position[0].x;
                        position[0].y=0;
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                        }
                        }
                        else i=0 ;
                      }
                      if(position[0].x==position1.x && position[0].y==position1.y)
                            {
                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                                       co=co+5;
                               while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                    SDL_BlitSurface(imagec0, NULL, ecran, &position[0]);
                for(j=1;j<p;j++)
                {
                       SDL_BlitSurface(imagec, NULL, ecran, &position[j]);
                }
               rectangle[p] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0,0,0,0);
                SDL_FillRect(rectangle[p], NULL, SDL_MapRGB(ecran->format,250,250,250));
                SDL_BlitSurface(rectangle[p], NULL,ecran,&position[p]);
                SDL_BlitSurface(imagec1, NULL, ecran, &position1);
                 SDL_BlitSurface(ima, NULL, ecran,&positionm);
                 sprintf(ch,"%d",co);
                 txt=TTF_RenderText_Blended(police,ch,couleurNoire);
               SDL_BlitSurface(txt, NULL, ecran, &positiont);
                SDL_Flip(ecran);
               }
            SDL_PollEvent(&event);
            switch(event.type)
           {
             case SDL_QUIT:
             return EXIT_SUCCESS;
             break;
             case SDL_KEYDOWN:
               switch (event.key.keysym.sym)
               {
                case SDLK_SPACE:
              // SDL_EnableKeyRepeat(10,10);
                 break;

                case SDLK_RIGHT:
                      if(position[0].x+10!=position[1].x && position[0].y!=position[1].y)
                                 {
                     if(position[0].x+10!=440)
           {
                        c1=position[0].x;
                        c3=position[0].y;
                        position[0].x=position[0].x+10;
                          if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].x;
                        position[j].x=c1;
                        c1=c2;
                        c4=position[j].y;
                        position[j].y=c3;
                        c3=c4;
                        }
                        }
                        else
                         i=0;
           }
           else
           {
                        c1=position[0].x;
                        c3=position[0].y;
                        position[0].x=0;
                        if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].x;
                        position[j].x=c1;
                        c1=c2;
                        c4=position[j].y;
                        position[j].y=c3;
                        c3=c4;
                        }
                        }
                        else i=0;

           }
                            if(position[0].x==position1.x && position[0].y==position1.y)
                               {
                      FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                      co=co+5;
                      while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                        t=1;
                                 }
                 break;

                 case SDLK_LEFT:
                      if(position[0].x-10!=position[1].x && position[0].y!=position[1].y)
                      {

                         if(position[0].x-10>=0)
                      {
                        c1=position[0].x;
                        c3=position[0].y;
                         position[0].x=position[0].x-10;
                          if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].x;
                        position[j].x=c1;
                        c1=c2;
                        c4=position[j].y;
                        position[j].y=c3;
                        c3=c4;
                        }
                        }
                        else i=0;
                      }
                      else
                      {
                            c1=position[0].x;
                        c3=position[0].y;
                         position[0].x=430;
                          if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].x;
                        position[j].x=c1;
                        c1=c2;
                        c4=position[j].y;
                        position[j].y=c3;
                        c3=c4;
                        }
                        }
                        else i=0;
                      }
                       if(position[0].x==position1.x && position[0].y==position1.y)
                              {
                          FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                                 co=co+5;
                             while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                        t=2;
                      }
                 break;

                 case SDLK_UP:
                      if(position[0].x!=position[1].x && position[0].y-10!=position[1].y)
                   {
                      if(position[0].y-10>=0)
                      {
                        c1=position[0].y;
                        c3=position[0].x;
                        position[0].y= position[0].y-10;
                         if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                      }
                        }
                        else i=0;

                      }
                      else
                      {
                        c1=position[0].y;
                        c3=position[0].x;
                        position[0].y=290;
                         if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                        }
                        }
                        else i=0;
                      }
                      if(position[0].x==position1.x && position[0].y==position1.y)
                               {
                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                         co=co+5;
                           while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                      t=3;
                   }
                 break;

                 case SDLK_DOWN:
                      if(position[0].x!=position[1].x && position[0].y+10!=position[1].y)
                      {
                   if(position[0].y+10!=300)
                 {
                       c1=position[0].y;
                       c3=position[0].x;
                       position[0].y= position[0].y+10;
                            if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                        }
                        }
                        else i=0;
                        }
                         else
                      {
                        c1=position[0].y;
                        c3=position[0].x;
                        position[0].y=0;
                         if(lose(position,p)==0)
                        {
                        for(j=1;j<100;j++)
                        {
                        c2=position[j].y;
                        position[j].y=c1;
                        c1=c2;
                        c4=position[j].x;
                        position[j].x=c3;
                        c3=c4;
                        }
                        }
                        else i=0;
                      }
                       if(position[0].x==position1.x && position[0].y==position1.y)
                            {
                          FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0,NULL);
                                 co=co+5;
                             while(o)
                    {
                    a=(rand()%440)/10;
                    b=(rand()%300)/10;
                    position1.x =a*10;
                    position1.y =b*10;
                    for(k=0;k<p;k++)
                    {
                        if(position1.x==position[k].x && position1.y==position[k].y)
                                 l=0;
                    }
                    if(l==1)
                     o=0;
                     l=1;
                    }
                    o=1;
                           p++;
                            }
                        t=4;
                      }
                break;
               }
                    SDL_BlitSurface(imagec0, NULL, ecran, &position[0]);
                for(j=1;j<p;j++)
                {
                       SDL_BlitSurface(imagec, NULL, ecran, &position[j]);
                }
                rectangle[p] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0,0,0,0);
                SDL_FillRect(rectangle[p], NULL, SDL_MapRGB(ecran->format,250,250,250));
                SDL_BlitSurface(rectangle[p], NULL,ecran,&position[p]);
                SDL_BlitSurface(imagec1, NULL, ecran, &position1);
                 SDL_BlitSurface(ima, NULL, ecran,&positionm);
                 sprintf(ch,"%d",co);
                 txt=TTF_RenderText_Blended(police,ch,couleurNoire);
                 SDL_BlitSurface(txt, NULL, ecran, &positiont);
                SDL_Flip(ecran);
           break;
           }
           SDL_Delay(62);
           c=0;
           if(i==0)
         {
             z=0;
             q=1;
         }
         }
     }

    if(q==0)
    {
        q=1;
        z=0;
    }

     if(i==0 && z==0)
     {
        SDL_Delay(500);
       for(j=0;j<p+1;j++)
       SDL_FreeSurface(rectangle[j]);
       imagefond = SDL_LoadBMP("serpent1.bmp");
       SDL_BlitSurface(imagefond, NULL, ecran, &positionfond);
       SDL_Flip(ecran);
       t=0;
       for(k=0;k<100;k++)
       {
       rectangle[k]=NULL;
       position[k].x = 0;
       position[k].y = 0;
       }
       position[0].x = 100;
       position[0].y = 100;
       p=10;
       z=1;
     }
}
     TTF_CloseFont(police);
     TTF_Quit();
     SDL_Quit();
     FMOD_Sound_Release(tir);
     FMOD_System_Close(system);
     FMOD_System_Release(system);
    return EXIT_SUCCESS;
}

