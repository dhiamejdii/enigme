#ifndef ENIGMEE_H_
#define ENIGMEE_H_
int main()
{
char solution;
int r=-1,res,k,x,a=0,b=0,done=1;
Enigme e;

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
// Creation screen

screen=SDL_SetVideoMode(1200,628,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

// Ajouter background

  background=IMG_Load("background.png");
    positionbackground.x=10;
    positionbackground.y=10;


// image passed

    passed=IMG_Load("passs.png");
   position_passed.x=740;
   position_passed.y=350;


// image failed

    failed=IMG_Load("fail1.png");
   position_failed.x=740;
   position_failed.y=350;

optemizedbackground=SDL_DisplayFormat(background);
optemizedpassed=SDL_DisplayFormat(passed);
optemizedfailed=SDL_DisplayFormat(failed);
SDL_WM_SetCaption( "SOLVE IT ", NULL );

SDL_FreeSurface(background);
SDL_FreeSurface(passed);
SDL_FreeSurface(failed);

genererEnigme ("fichier1.txt",&e);


while(done)
  {
    if(e.gameover==1)
    {
      done=0;
    }
    SDL_Event event;

    SDL_BlitSurface(optemizedbackground,NULL,screen,&positionbackground);


     e=afficherEnigme (e,screen);



while(SDL_PollEvent(&event))
{
  switch(event.type)
  {
case SDL_QUIT:
  {
       done=0;
        break;
  }

case SDL_KEYDOWN:
{

if(event.key.keysym.sym==SDLK_ESCAPE)
{
      done=0;
}
      break;
}


case SDL_MOUSEBUTTONDOWN:
             {
              a=event.button.x;
              b=event.button.y ;
              r=resolutionEnigme (e,screen,a,b);

              break;
             }

}

if(r==0)

{

SDL_BlitSurface(optemizedfailed,&positionbackground,screen,&position_failed);
SDL_Delay(150);
done=0;
}


else if (r==1)

{

SDL_BlitSurface(optemizedpassed,&positionbackground,screen,&position_passed);
SDL_Delay(150);
done=0;

}
else if (r==2)
	{
		done=0;
    }
SDL_Flip(screen);

}
}

// Liberation mémoire

SDL_FreeSurface(optemizedbackground);
SDL_FreeSurface(optemizedpassed);
SDL_FreeSurface(optemizedfailed);

SDL_Quit();
}
