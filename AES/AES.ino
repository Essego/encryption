#include <AESLib.h>

void setup() {
  Serial.begin(9600);
  uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  char data[] = "0123456789012345"; //16 chars == 16 bytes

  unsigned long initEncriptTime = millis();
  for(int i=0;i<1000;i++){aes128_enc_single(key, data);}
  unsigned long endEncriptTime = millis();
  
  String encript = data;

  unsigned long initDesencriptTime = millis();
  for(int i=0;i<1000;i++){aes128_dec_single(key, data);}
  unsigned long endtDesencriptTime = millis();



  Serial.println("");
  Serial.print("Tiempo de cifrado: ");
  Serial.print(endEncriptTime-initEncriptTime);
  Serial.println(" ms");
  Serial.print("Tiempo de descifrado: ");
  Serial.print(endtDesencriptTime-initDesencriptTime);
  Serial.println(" ms");

  Serial.print("encrypted: ");
  Serial.println(encript);
  Serial.print("decrypted: ");
  Serial.println(data);

}

void loop() {
  // put your main code here, to run repeatedly:

}
