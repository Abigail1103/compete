#include <BluetoothSerial.h>
BluetoothSerial BT;
int p1LED[] = {26,25};
int p2LED[] = {32,33};
int p1_score,p2_score;
int hint;

void setup()
{
 Serial.begin(115200);
 BT.begin("rrrr"); // 設定和 HC-06 通訊的速度 (預設 9600)
 pinMode(p1LED[0], OUTPUT);
 pinMode(p1LED[1], OUTPUT); 
 pinMode(p2LED[0], OUTPUT); 
 pinMode(p2LED[1], OUTPUT);   
}
void loop()
{
 //讀取藍芽模組訊息，並傳送到電腦
 if (BT.available()){
    hint = BT.read();
    Serial.println(hint);
    if(hint == 1){
      p1_score += 1;  
    }
    else if(hint == 2){
      p2_score += 1;  
    }
    else if(hint == 0){
      p1_score = p2_score = 0;  
    }
 }
 //判斷LED開關條件
 switch (p1_score){ 
  case '1':
  digitalWrite(p1LED[0],HIGH);
  break;
  case '2':
  digitalWrite(p1LED[0],HIGH);
  digitalWrite(p1LED[1],HIGH);
  break;
  case '0':
  digitalWrite(p1LED[0],LOW);
  digitalWrite(p1LED[1],LOW);
  break;
 }
 switch (p2_score){ 
  case '1':
  digitalWrite(p2LED[0],HIGH);
  break;
  case '2':
  digitalWrite(p2LED[0],HIGH);
  digitalWrite(p2LED[1],HIGH);
  break;
  case '0':
  digitalWrite(p2LED[0],LOW);
  digitalWrite(p2LED[1],LOW);
  break;
 }
}
