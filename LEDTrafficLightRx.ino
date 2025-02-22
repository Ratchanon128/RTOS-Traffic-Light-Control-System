#define LIGHT_1_RED 2
#define LIGHT_1_YELLOW 3
#define LIGHT_1_GREEN 4

#define LIGHT_2_RED 5
#define LIGHT_2_YELLOW 6
#define LIGHT_2_GREEN 7

#define LIGHT_3_RED 8
#define LIGHT_3_YELLOW 9
#define LIGHT_3_GREEN 10

#define LIGHT_4_RED 11
#define LIGHT_4_YELLOW 12
#define LIGHT_4_GREEN 13

#define GREEN_LIGHT_1 0
#define YELLOW_LIGHT_1 1

#define GREEN_LIGHT_2 2
#define YELLOW_LIGHT_2 3

#define GREEN_LIGHT_3 4
#define YELLOW_LIGHT_3 5

#define GREEN_LIGHT_4 6
#define YELLOW_LIGHT_4 7
//switch
#define SW1 A0
#define SW2 A1
#define SW3 A2
#define SW4 A3

unsigned long GREEN_1_SET_TIME = 1000;
unsigned long GREEN_2_SET_TIME = 1000;
unsigned long GREEN_3_SET_TIME = 1000;
unsigned long GREEN_4_SET_TIME = 1000;
unsigned long YELLOW_SET_TIME = 1000;

unsigned long Timer_1 = 0;

unsigned short Set_Time[8] = {GREEN_1_SET_TIME, YELLOW_SET_TIME,
                              GREEN_2_SET_TIME, YELLOW_SET_TIME, 
                              GREEN_3_SET_TIME, YELLOW_SET_TIME,
                              GREEN_4_SET_TIME, YELLOW_SET_TIME};

short Light_Index = GREEN_LIGHT_1;

String receivedData;

void setup() {
  Serial.begin(9600);

  pinMode(LIGHT_1_GREEN, OUTPUT);
  pinMode(LIGHT_1_YELLOW, OUTPUT);
  pinMode(LIGHT_1_RED, OUTPUT);

  pinMode(LIGHT_2_GREEN, OUTPUT);
  pinMode(LIGHT_2_YELLOW, OUTPUT);
  pinMode(LIGHT_2_RED, OUTPUT);

  pinMode(LIGHT_3_GREEN, OUTPUT);
  pinMode(LIGHT_3_YELLOW, OUTPUT);
  pinMode(LIGHT_3_RED, OUTPUT);

  pinMode(LIGHT_4_GREEN, OUTPUT);
  pinMode(LIGHT_4_YELLOW, OUTPUT);
  pinMode(LIGHT_4_RED, OUTPUT);
//แก้
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  pinMode(SW4,INPUT_PULLUP);

  Serial.println("Rx");

  Traffic_GREEN_1();


  Timer_1 = millis();
}

void loop() {

  condition1();

  if((millis()-Timer_1) >= Set_Time[Light_Index])
  {
    Serial.println(Light_Index);
    Serial.println(Set_Time[Light_Index]);
    Light_Index++;

    if(Light_Index > 7)
    {
      Light_Index = GREEN_LIGHT_1;
    }

    Timer_1 = millis();

    if(Light_Index == GREEN_LIGHT_1)
    {
      Traffic_GREEN_1();
    }
    else if(Light_Index == YELLOW_LIGHT_1)
    {
      Traffic_YELLOW_1();
    }
    
    else if(Light_Index == GREEN_LIGHT_2)
    {
      Traffic_GREEN_2();
    }
    else if(Light_Index == YELLOW_LIGHT_2)
    {
      Traffic_YELLOW_2();
      
    }
    
    else if(Light_Index == GREEN_LIGHT_3)
    {
      Traffic_GREEN_3();
    }
    else if(Light_Index == YELLOW_LIGHT_3)
    {
      Traffic_YELLOW_3();
    }

    else if(Light_Index == GREEN_LIGHT_4)
    {
      Traffic_GREEN_4();
    }
    else if(Light_Index == YELLOW_LIGHT_4)
    {
      Traffic_YELLOW_4();
    }
  }

  //switch
  if(digitalRead(SW1) == LOW)
  {
     digitalWrite(LIGHT_1_RED,LOW);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,HIGH);
     digitalWrite(LIGHT_2_RED,HIGH);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,LOW);
     digitalWrite(LIGHT_3_RED,HIGH);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,LOW);
     digitalWrite(LIGHT_4_RED,HIGH);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,LOW);
  }
  if(digitalRead(SW2) == LOW)
  {
     digitalWrite(LIGHT_1_RED,HIGH);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,LOW);
     digitalWrite(LIGHT_2_RED,LOW);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,HIGH);
     digitalWrite(LIGHT_3_RED,HIGH);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,LOW);
     digitalWrite(LIGHT_4_RED,HIGH);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,LOW);
  }
  if(digitalRead(SW3) == LOW)
  {
     digitalWrite(LIGHT_1_RED,HIGH);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,LOW);
     digitalWrite(LIGHT_2_RED,HIGH);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,LOW);
     digitalWrite(LIGHT_3_RED,LOW);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,HIGH);
     digitalWrite(LIGHT_4_RED,HIGH);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,LOW);
  }
  if(digitalRead(SW4) == LOW)
  {
     digitalWrite(LIGHT_1_RED,HIGH);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,LOW);
     digitalWrite(LIGHT_2_RED,HIGH);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,LOW);
     digitalWrite(LIGHT_3_RED,HIGH);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,LOW);
     digitalWrite(LIGHT_4_RED,LOW);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,HIGH);
  }
}

void condition1(){
  if(Serial.available() > 0){
    receivedData = Serial.readStringUntil('\n');
    //Serial.println(receivedData);
    int Time_Divider = Calculate_Time(receivedData.toInt(), Light_Index);
    Set_Time[0] = Set_Time[2] = Set_Time[4] = Set_Time[6] = Time_Divider;
    //Serial.println(Time_Divider);
  }
}

int Calculate_Time(int time, short index){
  int max = 5000;
  int min = 1000;
  int round = 0;
  int time_distance = 0;
  int yellow_time = 0;
  //Serial.println(time);
  Serial.println(index);
  switch(index){
    case 0:
      round = 4;
      break;
    case 1:
       yellow_time+=1000;
      round = 3;
      break;
    case 2:
      round = 3;
      break;
    case 3:
       yellow_time+=1000;
      round = 2;
      break;
    case 4:
      round = 2;
      break;
    case 5:
       yellow_time+=1000;
      round = 1;
      break;
    case 6:
      round = 5;
      break;
    case 7:
      yellow_time+=1000;
      round = 4;
      break;
  }

  yellow_time = yellow_time + (round * 1000);

  while(true){
    /*if(((time - yellow_time)/round) + time_distance > max){
      round+=4;
      yellow_time+=3000;
    }else{
      int new_time = (time - yellow_time)/round + time_distance;
      Serial.println(new_time);
      return new_time;
    }*/
    int new_time = (time - yellow_time)/round + time_distance;
    //Serial.println(new_time);
    return new_time;
  }
}

void Traffic_GREEN_1(){
  digitalWrite(LIGHT_1_GREEN, HIGH);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, LOW);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_GREEN_2(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, HIGH);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, LOW);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_GREEN_3(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, HIGH);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, LOW);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_GREEN_4(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, HIGH);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, LOW);
}

void Traffic_YELLOW_1(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, HIGH);
  digitalWrite(LIGHT_1_RED, LOW);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_YELLOW_2(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, HIGH);
  digitalWrite(LIGHT_2_RED, LOW);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_YELLOW_3(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, HIGH);
  digitalWrite(LIGHT_3_RED, LOW);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_YELLOW_4(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, HIGH);
  digitalWrite(LIGHT_4_RED, LOW);
}
