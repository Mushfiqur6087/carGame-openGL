#include"iGraphics.h"
#include<string.h>


int player_car_x=505,player_car_y=0,player_car_width=90,player_car_height=170,speed=25;
int height=750, width=1500;


/*
	function iDraw() is called again and again by the system.
*/
typedef struct Car
{
    int x;
    int y=750;
    int width=90;
    int height=170;
    int speed=7;
}Car;
Car Car1={460};
Car Car2={560};
Car Car3={260};
Car Car4={360};
Car Car5={180};

char lives[100];
char scores[1000];
char player_name[1000];
int index_number=0;
int score=0; //
int inc=7;   //

typedef struct Obstacle
{
    int x;
    int y=750;
    int width=170;
    int height=120;
    int speed=7;
}Obstacle;

typedef struct Heart
{
    int x;
    int y=750;
    int width=30;
    int height=30;
    int speed=7;
}Heart;
Heart heart1={521};

struct highscore
{
	char name[30];
	int score;
}highscore[1000];
int m=7;

int index=0;

Obstacle Obstacle1={346};
Obstacle Obstacle2={395};
Obstacle Obstacle3={500};

int grids[10]={180,273,375,378,548,606,696,789};
void updateleaderboard();

bool car1=true,car2=false,car3=false,car4=false,car5=false,obstacle1=false,obstacle2=false,obstacle3=false;
bool HEART=false;
int counter[10]={0};
int car_index[5]={0,1,2,3,4};
int obstacle_index[3]={0,1,2};

char homemenu[10][20]={"intro.bmp","help.bmp","settings.bmp","ovr.bmp","high_score.bmp","game_name.bmp","pause_menu.bmp","image.bmp"};
char car_obstacle[10][20]={"blue car.bmp","green car.bmp","red car.bmp","black car.bmp","yellow car.bmp","white car.bmp","red car 2.bmp"};
char player_car[6][20]={"car1.bmp","car2.bmp","car3.bmp"};
char road[4][20]={"road.bmp","road night.bmp"};
char life[4][22]={"heart.bmp"};
char o_bstacle[6][20]={"obstacle1.bmp","obstacle2.bmp","obstacle3.bmp"};
int homemenu_state=1;
int x=0,y=0;
bool introIndex =false;
bool settings_index=false;
int sd=0,ny=10; //
int mn=0;
int count=3; //

bool car_menu=false;
bool help_index=false;
bool music=false;
bool settings_index_soundoff=false;
bool game_over=false;
bool high_score=false;
bool game_name=true;
bool pause_menu=false;

void collision_check();
void car_speed_change(Car *CAR);
void obstacle_speed_change(Obstacle *OBSTACLE);
void car_reset();
void readleaderboard();
void showleaderboard();
void sortleaderboard();
void iDraw()
{

    iClear();
    if(introIndex)
    {
        iShowBMP(0,0,homemenu[0]);
    }
    if(help_index)
    {
        iShowBMP(0,0,homemenu[1]);
    }
    if(settings_index)
    {
        iShowBMP(0,0,homemenu[2]);
    }

    if(game_name)
    {
        iShowBMP(0,0,homemenu[5]);
        iSetColor(0,0,0);
        iText(1210,210,"click anywhere",GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if(car_menu)
    {
   iShowBMP(1100,0,homemenu[7]);

   iShowBMP(0,0,road[y]);
   iShowBMP(0,height-710-sd,road[y]);
   iShowBMP(0,height-650-sd,road[y]);
   iShowBMP(0,height-sd-450,road[y]);
   iShowBMP(0,height-sd-300,road[y]);
   iShowBMP(0,height-sd-50,road[y]);
   iShowBMP(0,height-sd,road[y]);




   iShowBMP2(player_car_x,player_car_y,player_car[x],0);
   iShowBMP2(Car1.x,Car1.y,car_obstacle[car_index[0]],0);
   iShowBMP2(Car2.x,Car2.y,car_obstacle[car_index[1]],0);
   iShowBMP2(Car3.x,Car3.y,car_obstacle[car_index[2]],0);
   iShowBMP2(Car4.x,Car4.y,car_obstacle[car_index[3]],0);
   iShowBMP2(Car5.x,Car5.y,car_obstacle[car_index[4]],0);
   iShowBMP2(Obstacle1.x,Obstacle1.y,o_bstacle[obstacle_index[0]],0);
   iShowBMP2(Obstacle2.x,Obstacle2.y,o_bstacle[obstacle_index[1]],0);
   iShowBMP2(Obstacle3.x,Obstacle3.y,o_bstacle[obstacle_index[2]],0);
   iShowBMP2(heart1.x,heart1.y,life[0],0);

   iSetColor(255,255,255);
   iText(1200,660,"WELCOME TO",GLUT_BITMAP_TIMES_ROMAN_24);
   iText(1210,610,"Racing Simulation",GLUT_BITMAP_TIMES_ROMAN_24);
   iText(1210,500,"Lives: ",GLUT_BITMAP_TIMES_ROMAN_24);
   itoa(count,lives,10);
   iText(1300,500,lives,GLUT_BITMAP_TIMES_ROMAN_24);
   iText(1210,400,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
   itoa(score,scores,10);
   iText(1300,400,scores,GLUT_BITMAP_TIMES_ROMAN_24);
   iText(1200,300,"click p to pause",GLUT_BITMAP_TIMES_ROMAN_24);

}

if(game_over)
{
    iShowBMP(0,0,homemenu[3]);
    iText(770,369,scores,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(770,317,player_name,GLUT_BITMAP_TIMES_ROMAN_24);
}

if(high_score)
{
    iShowBMP(0,0,homemenu[4]);
    showleaderboard();

}
if(pause_menu)
{
    iShowBMP(0,0,homemenu[6]);
    iText(910,210,"press r to go back to the game",GLUT_BITMAP_TIMES_ROMAN_24);

}

   // printf("%d %s \n",highscore[0].name,highscore[0].score);

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(game_name)
    {
        if((mx>=0 && mx<=1500) && (my>=0 && my<=750))
        {
            introIndex=true;
            game_name=false;
        }
    }
        if(introIndex)
        {
            if((mx>=45 && mx<=355) && (my>=592 && my<=672))
            {
                introIndex=false;
                car_menu=true;
            }
            if((mx>=45 && mx<=360) && (my>=468 && my<=548))
            {
                introIndex=false;
                help_index=true;
            }
            if((mx>=45 && mx<=358) && (my>=100 && my<=180))
            {
                exit(0);
            }
            if((mx>=45 && mx<=358)  && (my>=210 && my<=290))
            {
                introIndex=false;
                settings_index=true;
            }
            if((mx>=45 && mx<=355) && (my>=335 && my<=415))
            {
                introIndex=false;
                high_score=true;
                readleaderboard();
                sortleaderboard();


            }

        }
        if(settings_index)
        {
            if((mx>=620 && mx<=620+120) && (my>=545 && my<=545+58))
            {
                x=0;
            }
            if((mx>=620 && mx<=620+120) && (my>=480 && my<=480+58))
            {
                x=1;
            }
            if((mx>=620 && mx<=620+120) && (my>=420 && my<=420+58))
            {
                x=2;
            }
            if((mx>=800 && mx<=800+100) && (my>=90 && my<=90+50))
            {
                y=0;
            }
            if((mx>=800 && mx<=800+100) && (my>=30 && my<=30+50))
            {
                y=1;
            }
            if((mx>=75 && mx<=75+193) && (my>=18 && my<=83))
            {
                settings_index=false;
                introIndex=true;
            }

            if((mx>=0 && mx<=60) && (my>=690 && my<=690+60))
            {
                if(!music)
                {
                    music=true;
                    PlaySound("car racing music.wav", NULL, SND_ASYNC | SND_LOOP);
                }
            }
            if((mx>=65 && mx<=65+60) && (my>=690 && my<=690+60))
            {
                if(music)
                {
                    music=false;
                    PlaySound(0,0,0);
                }

            }


        }
        if(help_index)
        {
            if((mx>=0 && mx<=195) && (my>=700 && my<=750))
            {
                help_index=false;
                introIndex=true;
            }

        }
        if(high_score)
        {
            if((mx>=0 && mx<=195) && (my>=700 && my<=750))
            {
                high_score=false;
                introIndex=true;
            }
        }

    }






    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

    if(car_menu)
    {

     if(key== 'w')
    {
    player_car_y+=speed;
    if(player_car_y>=height-player_car_height)
    {
        player_car_y-=speed;
    }
    }

    if(key== 's')
    {
    player_car_y-=speed;
    if(player_car_y<=-10)
    {
        player_car_y+=speed;
    }
    }
    if(key== 'a')
    {
        player_car_x-=speed;
        if(player_car_x<170)
        {
            player_car_x+=speed;
        }
    }

     if(key== 'd')
    {
        player_car_x+=speed;
        if(player_car_x>930-player_car_width)
        {
            player_car_x-=speed;
        }
    }

    }
    if(key == 'm')
    {
        if(music)
        {
            music=false;
            PlaySound(0,0,0);
        }
        else
        {
            music=true;
            PlaySound("car racing music.wav", NULL, SND_ASYNC | SND_LOOP);
        }
    }

    if(game_over)
    {
        if(key!='\b')
        {
            player_name[index_number]=key;
            player_name[index_number+1]='\0';
            index_number++;

        }
        else
        {
            if(index_number >= 0)
            {
                player_name[index_number]='\0';
                index_number--;
                if(index_number <0)
            {
                index_number=0;
            }
        }
        }
        }

        if(car_menu)
        {
            if(key=='p')
            {
                iPauseTimer(0);
                iPauseTimer(0);
                iPauseTimer(0);
                iPauseTimer(0);
                iPauseTimer(0);
                pause_menu=true;
                car_menu=false;

            }
        }
        if(pause_menu)
        {
            if(key=='r')
            {
                iResumeTimer(0);
                iResumeTimer(0);
                iResumeTimer(0);
                iResumeTimer(0);
                car_menu=true;
                pause_menu=false;
            }
        }




}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(car_menu)
    {

     if(key== GLUT_KEY_UP)
    {
    player_car_y+=speed;
    if(player_car_y>=height-player_car_height)
    {
        player_car_y-=speed;
    }
    }

    if(key== GLUT_KEY_DOWN)
    {
    player_car_y-=speed;
    if(player_car_y<=-10)
    {
        player_car_y+=speed;
    }
    }
    if(key== GLUT_KEY_LEFT)
    {
        player_car_x-=speed;
        if(player_car_x<170)
        {
            player_car_x+=speed;
        }
    }

     if(key== GLUT_KEY_RIGHT)
    {
        player_car_x+=speed;
        if(player_car_x>930-player_car_width)
        {
            player_car_x-=speed;
        }
    }

    }

    if(key== GLUT_KEY_HOME)
    {
        if(help_index)
        {
            introIndex=true;
            help_index=false;
        }
        if(settings_index)
        {
            introIndex=true;
            settings_index=false;
        }
        if(high_score)
        {
            introIndex=true;
            high_score=false;
        }


    }

    if(key== GLUT_KEY_END)
    {
        if(game_over)
        {
            strcpy(highscore[0].name,player_name);
            highscore[0].score=score;
            updateleaderboard();
            exit(0);
        }
    }
    if(key==GLUT_KEY_F1)

        if(game_over)
        {
            strcpy(highscore[0].name,player_name);
            highscore[0].score=score;
            updateleaderboard();
            score=0;
            count=3;
            car_reset();
            player_car_x=505;
            player_car_y=0;
            introIndex=true;
            game_over=false;
        }
        //player name stays the same when f1 is pressed and game is played again ..if you want to change player name ..remove it using backspace





    //place your codes for other keys here
}
int Randoms(int lower, int upper)
{
   int num = (rand() % (upper - lower + 1)) + lower;
   return num;

}


void change()
{
    if(car_menu)
    {

    counter[0]++;
    if(car1)
    {
    car_speed_change(&Car1);
    if(Car1.y==height)
    {
        car_index[0]=rand()%7;
        car1=false;
    }
    }
    if(counter[0]==200)
    {
        Car1.x=Randoms(grids[0],grids[1]);
        car1=true;
        counter[0]=0;
    }

    counter[4]++;

    if(obstacle1)
    {
        obstacle_speed_change(&Obstacle1);

    if(Obstacle1.y==height)
    {
        obstacle_index[0]=rand()%3;
        Obstacle1.x=Randoms(grids[2],grids[3]);

        obstacle1=false;
    }
    }

    if(counter[4]==134*2)
    {
        obstacle1=true;
        counter[4]=0;
    }

    counter[5]=counter[5]+2;

    if(obstacle2)
    {
    obstacle_speed_change(&Obstacle2);
    if(Obstacle2.y==height)
    {
        obstacle_index[1]=rand()%3;
        Obstacle2.x=Randoms(grids[2],grids[3]);
        obstacle2=false;
    }
    }

    if(counter[5]==374)
    {
        obstacle2=true;
        counter[5]=0;
    }

     counter[6]++;

    if(obstacle3)
    {
    obstacle_speed_change(&Obstacle3);
    if(Obstacle3.y==height)
    {
        obstacle_index[2]=rand()%3;
        Obstacle3.x=Randoms(grids[2],grids[3]);
        obstacle3=false;
    }
    }

    if(counter[6]==215)
    {
        obstacle3=true;
        counter[6]=0;
    }


   counter[1]++;
    if(counter[1]==100)
    {
        car2=true;
    }
    if(car2)
    {
    car_speed_change(&Car2);
    if(Car2.y==height)
    {
        car_index[1]=rand()%7;
        Car2.x=Randoms(grids[4],grids[5]);
        car2=false;
    }
    }
     if(counter[1]==300)
    {
        car2=true;
        counter[1]=100;
    }
    //


    mn++;
    if(mn==160)
    {
        HEART=true;
    }
    if(HEART)
    {
      heart1.y-=heart1.speed;
    if((heart1.y)<=0)
    {
        heart1.y=height;
    }
    if(heart1.y==height)
    {
        heart1.x=Randoms(grids[6],grids[7]+50);
        HEART=false;
    }
    }
     if(mn==440)
    {
        HEART=true;
        mn=160;
    }

    counter[2]++;
    if(counter[2]==150)
    {
        car3=true;
    }
    if(car3)
    {
    car_speed_change(&Car3);
    if(Car3.y==height)
    {
        car_index[2]=rand()%7;
        Car3.x=Randoms(grids[4],grids[5]);
        car3=false;
    }
    }
     if(counter[2]==450)
    {
        car3=true;
        counter[2]=150;
    }


    counter[3]=counter[3]+2;
    if(counter[3]==90)
    {
        car4=true;
    }
    if(car4)
    {
    car_speed_change(&Car4);
    if(Car4.y<=0)
    {
        Car4.y=height;
    }
    if(Car4.y==height)
    {
        car_index[3]=rand()%7;
        Car4.x=Randoms(grids[0],grids[1]);
        car4=false;
    }
    }
     if(counter[3]==220)
    {
        car4=true;
        counter[3]=90;
    }
    counter[7]++;
    if(counter[7]==15)
    {
        car5=true;
    }
    if(car5)
    {
    car_speed_change(&Car5);
    if(Car5.y<=0)
    {
        Car5.y=height;
    }
    if(Car5.y==height)
    {
        car_index[4]=rand()%7;
        Car5.x=Randoms(grids[6],grids[7]);
        car5=false;
    }
    }
    if(counter[7]==50)
    {
        car5=true;
        counter[7]=10;
    }



    }
}

void car_speed_change(Car *CAR)
{
     CAR->y-=CAR->speed;
    if((CAR->y)<=0)
    {
        CAR->y=height;
    }

}

void obstacle_speed_change(Obstacle *OBSTACLE)
{
     OBSTACLE->y-=OBSTACLE->speed;
    if((OBSTACLE->y)<=0)
    {
        OBSTACLE->y=height;
    }

}









void collision_check()
{
    if(car_menu)
    {

    if(car1)
    {
    if((player_car_x+player_car_width > Car1.x && player_car_x<Car1.x+Car1.width) && (player_car_y+player_car_height > Car1.y && player_car_y<Car1.y+Car1.height))
    {
        car_reset();
        count--;
    }
    }

    if(car2)
    {

    if((player_car_x+player_car_width > Car2.x && player_car_x<Car2.x+Car2.width) && (player_car_y+player_car_height > Car2.y && player_car_y<Car2.y+Car2.height))
    {
        car_reset();
        count--;
    }
    }


    if(car3)
    {
    if((player_car_x+player_car_width > Car3.x && player_car_x<Car3.x+Car3.width) && (player_car_y+player_car_height > Car3.y && player_car_y<Car3.y+Car3.height))
    {
        car_reset();
        count--;
    }
    }

    if(car4)
    {
    if((player_car_x+player_car_width > Car4.x && player_car_x<Car4.x+Car4.width) && (player_car_y+player_car_height > Car4.y && player_car_y<Car4.y+Car4.height))
    {
        car_reset();
        count--;
    }
    }
    if(car5)
    {
    if((player_car_x+player_car_width > Car5.x && player_car_x<Car5.x+Car5.width) && (player_car_y+player_car_height > Car5.y && player_car_y<Car5.y+Car5.height))
    {
        car_reset();
        count--;
    }
    }

    if(obstacle1)
    {
    if((player_car_x+player_car_width > Obstacle1.x && player_car_x<Obstacle1.x+Obstacle1.width) && (player_car_y+player_car_height > Obstacle1.y && player_car_y<Obstacle1.y+Obstacle1.height))
    {
       car_reset();
       count--;
    }
    }

    if(obstacle2)
    {
    if((player_car_x+player_car_width > Obstacle2.x && player_car_x<Obstacle2.x+Obstacle1.width) && (player_car_y+player_car_height > Obstacle2.y && player_car_y<Obstacle2.y+Obstacle2.height))
    {
        car_reset();
        count--;
    }
    }

    if(obstacle3)
    {
    if((player_car_x+player_car_width > Obstacle3.x && player_car_x<Obstacle3.x+Obstacle3.width) && (player_car_y+player_car_height > Obstacle3.y && player_car_y<Obstacle3.y+Obstacle3.height))
    {
        car_reset();
        count--;
    }
    }

    if(HEART)
    {
         if((player_car_x+player_car_width > heart1.x && player_car_x<heart1.x+heart1.width) && (player_car_y+player_car_height > heart1.y && player_car_y<heart1.y+heart1.height))
    {
        mn=0;
        if(count<3)
        count++;
        heart1.y=height;
        HEART=false;
    }

    }


    }



}

void speed_increase()
{
    if(car_menu)
    {
    if(Car1.speed<=33)
    {
        Car1.speed++;
        Car2.speed++;
        Car3.speed++;
        Car4.speed++;
        Car5.speed++;
        Obstacle1.speed++;
        Obstacle2.speed++;
        heart1.speed++;
        Obstacle3.speed++;
        inc++;
    }
    ny=ny+2;
    if(ny==50)
    {
        ny=ny-2;
    }
    score+=inc;
    }
}

void road1()
{
    if(car_menu)
{

    sd=sd+ny;
    if(sd>=height)
    {
        sd=0;
    }

}
}


void car_reset()
{
    counter[0]=0;
    counter[1]=0;
    counter[2]=0;
    counter[3]=0;
    counter[4]=0;
    counter[5]=0;
    counter[6]=0;
    counter[7]=0;
    mn=0;
    car1=true,car2=false,car3=false,car4=false,car5=false,obstacle1=false,obstacle2=false,obstacle3=false,HEART=false;
    Car1.x=460;
    Car2.x=560;
    Car3.x=260;
    Car4.x=360;
    Car5.x=180;
    heart1.x=521;
    Obstacle1.x=346;
    Obstacle2.x=395;
    Obstacle3.x=500;
    Car1.y=height;
    Car2.y=height;
    Car2.y=height;
    Car3.y=height;
    Car4.y=height;
    Car5.y=height;
    heart1.y=height;
    Obstacle1.y=height;
    Obstacle2.y=height;
    Obstacle3.y=height;
    Car1.speed=m;
    Car2.speed=m;
    Car3.speed=m;
    Car4.speed=m;
    Car5.speed=m;
    heart1.speed=m;
    Obstacle1.speed=m;
    Obstacle2.speed=m;
    Obstacle3.speed=m;
    sd=0,ny=10,inc=m;
    if(count>=0)
    {
        grids[0]=grids[0]^grids[6];
        grids[6]=grids[0]^grids[6];
        grids[0]=grids[0]^grids[6];
        grids[1]=grids[1]^grids[7];
        grids[7]=grids[1]^grids[7];
        grids[1]=grids[1]^grids[7];
    }
}

void count_checker()
{
    if(count==0)
    {
        game_over=true;
        car_menu=false;
        count++;
    }



}

void sortleaderboard()
{
	for (int i=0; i<index-1; i++){
		for (int j=i+1;j<index;j++)
    {
			if (highscore[i].score < highscore[j].score)
            {
				int temp;
				temp = highscore[i].score;
				highscore[i].score = highscore[j].score;
				highscore[j].score = temp;
				char temp3[100];
				strcpy(temp3, highscore[i].name);
				strcpy(highscore[i].name, highscore[j].name);
				strcpy(highscore[j].name, temp3);
            }
	}
}
}



void updateleaderboard()
{
	FILE *fp;
	fp = fopen("score.txt", "a");
    fprintf(fp,"%s %d", highscore[0].name,highscore[0].score);
    fprintf(fp,"\n");
	fclose(fp);
	fp=fopen("index.txt","r");
	fscanf(fp,"%d",&index);
	fclose(fp);
	fp=fopen("index.txt","w");
    fprintf(fp,"%d",++index);
    fclose(fp);

}

void readleaderboard()
{
	FILE *fp;
	fp = fopen("index.txt","r");
	fscanf(fp, "%d",&index);
	fclose(fp);
	fp=fopen("score.txt","r");
	for (int i=0;i<index;i++)
    {
		 fscanf(fp,"%s %d",&highscore[i].name, &highscore[i].score);
	}
	fclose(fp);
}


void showleaderboard()
{
		int y = 500,m=1;
		if(index>=10)
        {
            index=10;
        }
		for (int i=0;i<index;i++,y -= 30)
            {
			char temp4[100],temp_X[10];
			itoa(highscore[i].score, temp4, 10);
			itoa(m,temp_X,10);
			static int r=rand()%255;
			static int g=rand()%255;
			static int b=rand()%255;
            iSetColor(r,g,b);
			iText(521,y,temp_X,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(571,y,highscore[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(771,y,temp4,GLUT_BITMAP_TIMES_ROMAN_24);
			m++;
		}
	}



int main()
{

        index_number=strlen(player_name);
        iSetTimer(25,change);
        iSetTimer(25,count_checker);
        iSetTimer(50,road1);
        iSetTimer(25,collision_check);
        iSetTimer(2500,speed_increase);
        if(music)
        {
            PlaySound("car racing music.wav", NULL, SND_ASYNC | SND_LOOP);
        }



    iInitialize(width,height, "Racing Simulation");
    return 0;
}
