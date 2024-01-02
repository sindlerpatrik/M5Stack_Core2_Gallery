#include <M5Core2.h>

char *gallery[] = {"/GALERIE/1.jpg", "/GALERIE/2.jpg","/GALERIE/3.jpg","/GALERIE/4.jpg","/GALERIE/5.jpg",
"/GALERIE/6.jpg","/GALERIE/7.jpg","/GALERIE/8.jpg","/GALERIE/9.jpg","/GALERIE/10.jpg",
"/GALERIE/11.jpg","/GALERIE/12.jpg","/GALERIE/13.jpg","/GALERIE/14.jpg","/GALERIE/15.jpg"};
/*"/GALERIE/16.jpg","/GALERIE/17.jpg","/GALERIE/18.jpg","/GALERIE/19.jpg","/GALERIE/20.jpg",
"/GALERIE/21.jpg","/GALERIE/22.jpg","/GALERIE/23.jpg","/GALERIE/24.jpg","/GALERIE/25.jpg",
"/GALERIE/26.jpg","/GALERIE/27.jpg","/GALERIE/28.jpg","/GALERIE/29.jpg","/GALERIE/30.jpg",
"/GALERIE/31.jpg","/GALERIE/32.jpg","/GALERIE/33.jpg","/GALERIE/34.jpg","/GALERIE/35.jpg",
"/GALERIE/36.jpg","/GALERIE/37.jpg","/GALERIE/38.jpg","/GALERIE/39.jpg","/GALERIE/40.jpg",
"/GALERIE/41.jpg","/GALERIE/42.jpg","/GALERIE/43.jpg","/GALERIE/44.jpg","/GALERIE/45.jpg",
"/GALERIE/46.jpg","/GALERIE/47.jpg","/GALERIE/48.jpg","/GALERIE/49.jpg","/GALERIE/50.jpg",
"/GALERIE/51.jpg","/GALERIE/52.jpg","/GALERIE/53.jpg"};*/

int INDEX = 0;
int LENGHT = sizeof(gallery)/sizeof(gallery[0]);

void setup() {
  // put your setup code here, to run once:
M5.begin();
M5.Lcd.drawJpgFile(SD, gallery[INDEX], 0, 0);
M5.Lcd.setBrightness(255);
  }

void loop() {
  // put your main code here, to run repeatedly:
if(M5.BtnC.wasPressed()){
  INDEX++;
  if(INDEX == LENGHT){
    INDEX = 0;
    }
  Serial.print(INDEX);
  M5.Lcd.drawJpgFile(SD, gallery[INDEX], 0, 0); 
  }
  
else if(M5.BtnA.wasPressed()){
  INDEX--;
  if(INDEX < 0){
    INDEX = LENGHT - 1;
    }
  Serial.print(INDEX);
  M5.Lcd.drawJpgFile(SD, gallery[INDEX], 0, 0);
  }
  
else if(M5.BtnB.wasPressed()){
  INDEX = 0;
  Serial.print(INDEX);
  M5.Lcd.drawJpgFile(SD, gallery[INDEX], 0, 0);
  }
  M5.update();
}
