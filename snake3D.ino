#define red 0
#define blue 1
#define green 2

#define yellow 3
#define teal 4
#define purple 5

#define white 6

void resetCube(){
  for(int i=2;i<=13;i++){
    pinMode(i,INPUT);
    //Serial.println(i);
  }
  for(int i=22;i<=25;i++){
    pinMode(i,INPUT);
    //Serial.println(i);
  }
  for(int i=2;i<13;i++){
    digitalWrite(i,LOW);
  }
  for(int i=22;i<=25;i++){
    digitalWrite(i,LOW);
  }
}

int layout[3][4][4][4][2]={
  //RED
  {
    //0-th layer
    {
      //0-th row
      {
        //0-th instance
        {24,13},{23,12},{25,11},{22,10}
      },
      {
        {25,12},{22,13},{24,10},{23,11}
      },
      {
        {22,11},{25,10},{23,13},{24,12}
      },
      {
        {23,10},{24,11},{22,12},{25,13}
      }
    },
    {
      {
        {13,6},{12,7},{11,8},{10,9}
      },
      {
        {12,6},{13,7},{10,8},{11,9}
      },
      {
        {11,6},{10,7},{13,8},{12,9}
      },
      {
        {10,6},{11,7},{12,8},{13,9}
      }
    },
    {
      {
        {6,2},{7,2},{8,2},{9,2}
      },
      {
        {6,3},{7,3},{8,3},{9,3}
      },
      {
        {6,4},{7,4},{8,4},{9,4}
      },
      {
        {6,5},{7,5},{8,5},{9,5}
      },
    },
    {
      {
        {2,24},{2,23},{2,25},{2,22}
      },
      {
        {3,25},{3,22},{3,24},{3,23}
      },
      {
        {4,22},{4,25},{4,23},{4,24}
      },
      {
        {5,23},{5,24},{5,22},{5,25}
      }
    }
  },
  //blue
  {
    {
      {
        {6,13},{7,12},{8,11},{9,10}
      },
      {
        {6,12},{7,13},{8,10},{9,11}
      },
      {
        {6,11},{7,10},{8,13},{9,12}
      },
      {
        {6,10},{7,11},{8,12},{9,13}
      }
    },
    {
      {
        {2,6},{2,7},{2,8},{2,9}
      },
      {
        {3,6},{3,7},{3,8},{3,9}
      },
      {
        {4,6},{4,7},{4,8},{4,9}
      },
      {
        {5,6},{5,7},{5,8},{5,9}
      }
    },
    {
      {
        {24,2},{23,2},{25,2},{22,2}
      },
      {
        {25,3},{22,3},{24,3},{23,3}
      },
      {
        {22,4},{25,4},{23,4},{24,4}
      },
      {
        {23,5},{24,5},{22,5},{25,5}
      }
    },
    {
      {
        {13,24},{12,23},{11,25},{10,22}
      },
      {
        {12,25},{13,22},{10,24},{11,23}
      },
      {
        {11,22},{10,25},{13,23},{12,24}
      },
      {
        {10,23},{11,24},{12,22},{13,25}
      }
    }
  },
  //green
  {
    {
      {
        {2,13},{2,12},{2,11},{2,10}
      },
      {
        {3,12},{3,13},{3,10},{3,11}
      },
      {
        {4,11},{4,10},{4,13},{4,12}
      },
      {
        {5,10},{5,11},{5,12},{5,13}
      }
    },
    {
      {
        {24,6},{23,7},{25,8},{22,9}
      },
      {
        {25,6},{22,7},{24,8},{23,9}
      },
      {
        {22,6},{25,7},{23,8},{24,9}
      },
      {
        {23,6},{24,7},{22,8},{25,9}
      }
    },
    {
      {
        {13,2},{12,2},{11,2},{10,2}
      },
      {
        {12,3},{13,3},{10,3},{11,3}
      },
      {
        {11,4},{10,4},{13,4},{12,4}
      },
      {
        {10,5},{11,5},{12,5},{13,5}
      }
    },
    {
      {
        {6,24},{7,23},{8,25},{9,22}
      },
      {
        {6,25},{7,22},{8,24},{9,23}
      },
      {
        {6,22},{7,25},{8,23},{9,24}
      },
      {
        {6,23},{7,24},{8,22},{9,25}
      }
    }
  }
};

void drawLedPrim(int color, int x , int y , int z){
    pinMode(layout[color][z][y][x][0],OUTPUT);
    pinMode(layout[color][z][y][x][1],OUTPUT);
    digitalWrite(layout[color][z][y][x][0],HIGH);
}

void ledReset(int color, int x , int y , int z){
  if(color == 0 or color == 1 or color ==2){
    pinMode(layout[color][z][y][x][0],INPUT);
    pinMode(layout[color][z][y][x][1],INPUT);
    digitalWrite(layout[color][z][y][x][0],LOW);
  }
  else if(color == 3 or color == 4 or color == 5){
    if(color == 3){
      pinMode(layout[red][z][y][x][0],INPUT);
      pinMode(layout[red][z][y][x][1],INPUT);
      pinMode(layout[green][z][y][x][0],INPUT);
      pinMode(layout[green][z][y][x][1],INPUT);
      digitalWrite(layout[red][z][y][x][0],LOW);
      digitalWrite(layout[green][z][y][x][0],LOW);
    }
    else if(color == 4){
      pinMode(layout[blue][z][y][x][0],INPUT);
      pinMode(layout[blue][z][y][x][1],INPUT);
      pinMode(layout[green][z][y][x][0],INPUT);
      pinMode(layout[green][z][y][x][1],INPUT);
      digitalWrite(layout[blue][z][y][x][0],LOW);
      digitalWrite(layout[green][z][y][x][0],LOW);
    }
    else if(color == 5){
      pinMode(layout[red][z][y][x][0],INPUT);
      pinMode(layout[red][z][y][x][1],INPUT);
      pinMode(layout[blue][z][y][x][0],INPUT);
      pinMode(layout[blue][z][y][x][1],INPUT);
      digitalWrite(layout[red][z][y][x][0],LOW);
      digitalWrite(layout[blue][z][y][x][0],LOW);
    }
  }
  else if(color == 6){
    pinMode(layout[red][z][y][x][0],INPUT);
    pinMode(layout[green][z][y][x][0],INPUT);
    pinMode(layout[blue][z][y][x][0],INPUT);
    pinMode(layout[red][z][y][x][1],INPUT);
    pinMode(layout[green][z][y][x][1],INPUT);
    pinMode(layout[blue][z][y][x][1],INPUT);
    digitalWrite(layout[red][z][y][x][0],LOW);
    digitalWrite(layout[green][z][y][x][0],LOW);
    digitalWrite(layout[blue][z][y][x][0],LOW);
  }
}

void drawLed(int color, int x, int y, int z){
  //x-=1;
  //y-=1;
  //z-=1;
  if(color==0 or color==1 or color==2){
    drawLedPrim(color, x , y , z);
    delayMicroseconds(180);
  }
  else if(color == 3 or color == 4 or color == 5){
    if(color == 3){
      drawLedPrim(red, x , y , z);
      drawLedPrim(green, x , y , z);
    }
    else if(color == 4){
      drawLedPrim(blue, x , y , z);
      drawLedPrim(green, x , y , z);
    }
    else if(color == 5){
      drawLedPrim(blue, x , y , z);
      drawLedPrim(red, x , y , z);
    }
    delayMicroseconds(10);
  }
  else if(color == 6){
    drawLedPrim(blue, x , y , z);
    drawLedPrim(red, x , y , z);
    drawLedPrim(green, x , y , z);
  }
}

void fillCube(int color){
  for(int c=0;c<4;c++){
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        drawLed(color,j,i,c);
        //delay(500);
        delayMicroseconds(75);
        ledReset(color,j,i,c);
      }
    }
  }
}

void ledseq(int color,int x, int y, int z){
  drawLed(color,x,y,z);
  delayMicroseconds(75);
  resetCube();
}

int snakeSpeed=2000;
int snakeCor[3];
int snakeBody[64][3];
int snakeLen=0;
int snakeFace[2];//x y z

int food[3];
int target=0;

bool up;
bool down;
bool left;
bool right;


#define xp 0
#define xn 1
#define yp 2
#define yn 3
#define zp 4
#define zn 5



void randomFood(){
  food[0]=random(0,3);
  food[1]=random(0,3);
  food[2]=random(0,3);
}

void setup() {
  resetCube();
  randomSeed(analogRead(A10));
  // randomFood();

  food[0]=2;
  food[1]=0;
  food[2]=0;


  snakeFace[0]=0;
  snakeFace[1]=5;
  snakeCor[0]=0;
  snakeCor[1]=0;
  snakeCor[2]=0;
  // Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

}

// #define x 0
// #define y 1
// #define z 2
// #define fx 3
// #define fy 4
// #define fz 5
int target2;
//add priority to buttons?
void loop() {
  // delay(snakeSpeed);
  resetCube();
  bool flag=true;
  if(flag){
    up=false;
    down=false;
    left=!digitalRead(A0);
    right=!digitalRead(A1);
    flag=false;
    int target2=millis()+1000;
  
    int direction_cpy=snakeFace[0];
    if(up){
      switch(snakeFace[1]){
        case xp:
          snakeFace[0]=xn;
          break;
        case xn:
          snakeFace[0]=xp;
          break;
        case yp:
          snakeFace[0]=yn;
          break;
        case yn:
          snakeFace[0]=yp;
          break;
        case zp:
          snakeFace[0]=zn;
          break;
        case zn:
          snakeFace[0]=zp;
          break;
      }
      switch(direction_cpy){
        case xp:
          snakeFace[1]=xp;
          break;
        case xn:
          snakeFace[1]=xn;
          break;
        case yp:
          snakeFace[1]=yp;
          break;
        case yn:
          snakeFace[1]=yn;
          break;
        case zp:
          snakeFace[1]=zp;
          break;
        case zn:
          snakeFace[1]=zn;
          break;
      }
    }
    else if(down){
      switch(snakeFace[1]){
        case xp:
          snakeFace[0]=xp;
          break;
        case xn:
          snakeFace[0]=xn;
          break;
        case yp:
          snakeFace[0]=yp;
          break;
        case yn:
          snakeFace[0]=yn;
          break;
        case zp:
          snakeFace[0]=zp;
          break;
        case zn:
          snakeFace[0]=zn;
          break;
      }
      switch(direction_cpy){
        case xp:
          snakeFace[1]=xn;
          break;
        case xn:
          snakeFace[1]=xp;
          break;
        case yp:
          snakeFace[1]=yn;
          break;
        case yn:
          snakeFace[1]=yp;
          break;
        case zp:
          snakeFace[1]=zn;
          break;
        case zn:
          snakeFace[1]=zp;
          break;
      }
    }
    else if(left){
      switch(snakeFace[1]){
        case xp:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=zn;
              break;
            case yn:
              snakeFace[0]=zp;
              break;
            case zp:
              snakeFace[0]=yp;
              break;
            case zn:
              snakeFace[0]=yn;
              break;
          }
          break;
        case xn:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=zp;
              break;
            case yn:
              snakeFace[0]=zn;
              break;
            case zp:
              snakeFace[0]=yn;
              break;
            case zn:
              snakeFace[0]=yp;
              break;
          }
          break;
        case yp:
        switch(snakeFace[0]){
            case xp:
              snakeFace[0]=zp;
              break;
            case xn:
              snakeFace[0]=zn;
              break;
            case zp:
              snakeFace[0]=xn;
              break;
            case zn:
              snakeFace[0]=xp;
              break;
          }
          break;
        case yn:
          switch(snakeFace[0]){
            case xp:
              snakeFace[0]=zn;
              break;
            case xn:
              snakeFace[0]=zp;
              break;
            case zp:
              snakeFace[0]=xp;
              break;
            case zn:
              snakeFace[0]=xn;
              break;
          }
          break;
        case zp:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=xp;
              break;
            case yn:
              snakeFace[0]=xn;
              break;
            case xp:
              snakeFace[0]=yn;
              break;
            case xn:
              snakeFace[0]=yp;
              break;
          }
          break;
        case zn:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=xn;
              break;
            case yn:
              snakeFace[0]=xp;
              break;
            case xp:
              snakeFace[0]=yp;
              break;
            case xn:
              snakeFace[0]=yn;
              break;
          }
          break;
      }
    }
    else if(right){
      switch(snakeFace[1]){
        case xp:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=zp;
              break;
            case yn:
              snakeFace[0]=zn;
              break;
            case zp:
              snakeFace[0]=yn;
              break;
            case zn:
              snakeFace[0]=yp;
              break;
          }
          break;
        case xn:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=zn;
              break;
            case yn:
              snakeFace[0]=zp;
              break;
            case zp:
              snakeFace[0]=yp;
              break;
            case zn:
              snakeFace[0]=yn;
              break;
          }
          break;
        case yp:
          switch(snakeFace[0]){
            case xp:
              snakeFace[0]=zn;
              break;
            case xn:
              snakeFace[0]=zp;
              break;
            case zp:
              snakeFace[0]=xp;
              break;
            case zn:
              snakeFace[0]=xn;
              break;
          }
          break;
        case yn:
          switch(snakeFace[0]){
            case xp:
              snakeFace[0]=zp;
              break;
            case xn:
              snakeFace[0]=zn;
              break;
            case zp:
              snakeFace[0]=xn;
              break;
            case zn:
              snakeFace[0]=xp;
              break;
          }
          break;
        case zp:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=xn;
              break;
            case yn:
              snakeFace[0]=xp;
              break;
            case xp:
              snakeFace[0]=yp;
              break;
            case xn:
              snakeFace[0]=yn;
              break;
          }
          break;
        case zn:
          switch(snakeFace[0]){
            case yp:
              snakeFace[0]=xp;
              break;
            case yn:
              snakeFace[0]=xn;
              break;
            case xp:
              snakeFace[0]=yn;
              break;
            case xn:
              snakeFace[0]=yp;
              break;
          }
          break;
      }
    }
    up=false;
    down=false;
    left=false;
    right=false;
  }
  if(millis()>target2){
    flag=true;
  }
  //update snake head
  // for(int i=;i<snakeLen)
  if(millis()>target){
    target=millis()+snakeSpeed;
    if(snakeLen){
      for(int i=snakeLen+2;i>1;i--){
        if(snakeLen==1){
          snakeBody[1][0]=snakeCor[0];
          snakeBody[1][1]=snakeCor[1];
          snakeBody[1][2]=snakeCor[2];
        }
        else{
          snakeBody[snakeLen][0]=snakeBody[snakeLen-1][3];
          snakeBody[snakeLen][1]=snakeBody[snakeLen-1][3];
          snakeBody[snakeLen][2]=snakeBody[snakeLen-1][3];
        }
      }
    }
    switch(snakeFace[0]){
      case xp:
        snakeCor[0]++;
        break;
      case xn:
        snakeCor[0]--;
        break;
      case yp:
        snakeCor[1]++;
        break;
      case yn:
        snakeCor[1]--;
        break;
      case zp:
        snakeCor[2]++;
        break;
      case zn:
        snakeCor[2]--;
        break;
    }
  }
  for(int i=0;i<=snakeLen;i++){
    if(i==0)
      ledseq(red ,snakeCor[0],snakeCor[1],snakeCor[2]);
    else
      ledseq(blue,snakeBody[i][0],snakeBody[i][1],snakeBody[i][2]);
  }


  if(snakeCor[0]<0 || snakeCor[1]<0 || snakeCor[2]<0 || snakeCor[0]>3 || snakeCor[1]>3 || snakeCor[2]>3)
    while(1){
      fillCube(red);
    }
  
  if(snakeCor[0]==food[0] && snakeCor[1]==food[1] && snakeCor[2]==food[2]){
    snakeLen++;
    if(snakeLen==1){
      snakeBody[1][0]=snakeCor[0];
      snakeBody[1][1]=snakeCor[1];
      snakeBody[1][2]=snakeCor[2];
    }
    food[0]=4;
    food[1]=4;
    food[2]=4;
  }

}