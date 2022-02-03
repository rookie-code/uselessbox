
#include <Servo.h>
#include <ezButton.h>

void sequanceMotion(int pos);
void servoUpdate(int y, int x);
void getSequanceButton();
void servoMove(Servo s, int initPos, int finalPos);



Servo servoX;                     // Object ServoX
Servo servoY;                    // Object ServoY
const int pinServoX = 9;          // Pin Servo X
const int pinServoY = 10;         // Pin Servo Y
int posX = 0;                     // Posizione iniziale del ServoX
int posY = 150;                   // Posizione iniziale del ServoY
int allOff = 0;

ezButton btn1(2);           // Pin Button 1
ezButton btn2(3);           // Pin Button 2
ezButton btn3(4);           // Pin Button 3
ezButton btn4(5);           // Pin Button 4
ezButton btn5(6);           // Pin Button 5

ezButton btnArray[] = {btn1, btn2, btn3, btn4, btn5};

void setup() {

  Serial.begin(9600);

  // -
  servoY.write(50);                     // |
  servoY.attach(pinServoY);             // |
  delay(1000);                          // |
  servoX.write(posX);                   // |
  servoX.attach(pinServoX);             // | ------>  Inizializzazione dei servomotori
  delay(1000);                          // |
  servoY.write(posY);                   // |
  servoY.attach(pinServoY);             // |
  delay(1000);                          // |
  // -

  for (int i = 0; i <= 4; i ++) {
    btnArray[i].setDebounceTime(50);    // Set debounce time for all buttons
  }


}

void loop() {


  for (int j = 0; j <= 4; j++) {
    int temp = 1;
    for (int i = 0; i <= 4; i ++) {
      btnArray[i].loop();
    }
    temp *= btnArray[j].getState();
    int tState = btnArray[j].getState();
    if (!tState) {
      sequanceMotion(j);

    }
    if(temp){
      sequanceMotion(5);
      }
  }

}



int hightPos = 50;
int lowPos = 83;

void sequanceMotion(int pos) {

  switch (pos) {
    case 0:      
      servoUpdate(servoY, hightPos);
      servoUpdate(servoX, 58);
      servoUpdate(servoY, lowPos);
      servoUpdate(servoY, hightPos);
      break;
    case 1:
      servoUpdate(servoY, hightPos);
      servoUpdate(servoX, 73);
      servoUpdate(servoY, lowPos);
      servoUpdate(servoY, hightPos);
      break;
    case 2:
      servoUpdate(servoY, hightPos);
      servoUpdate(servoX, 90);
      servoUpdate(servoY, lowPos);
      servoUpdate(servoY, hightPos);
      break;
    case 3:
      servoUpdate(servoY, hightPos);
      servoUpdate(servoX, 110);
      servoUpdate(servoY, 90);
      servoUpdate(servoY, hightPos);
      break;
    case 4:
      servoUpdate(servoY, hightPos);
      servoUpdate(servoX, 130);
      servoUpdate(servoY, lowPos);
      servoUpdate(servoY, hightPos);
    case 5:
      
      servoUpdate(servoX, 0);
      servoUpdate(servoY, 150);
      break;
      //    default:
      //      break;
  }

}

void servoUpdate(Servo s, int value) {
  s.write(value);
  delay(700);
}
