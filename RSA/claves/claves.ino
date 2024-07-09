void setup() {
  Serial.begin(9600);

  int p = 4057;
  int q = 1811;
  unsigned long tiempoInicial = millis();
  int n = p * q;
  int phiN = (p - 1) * (q - 1);
  int e = BuscarE(phiN);
  int d = BuscarD(e,phiN);

  unsigned long tiempoFinal = millis();

  Serial.print("Clave pública = ");Serial.print(e);Serial.print(" ");Serial.println(n);
  Serial.print("Clave privada = ");Serial.print(d);Serial.print(" ");Serial.println(n);
  Serial.print("Tiempo transcurrido = ");Serial.print(tiempoFinal-tiempoInicial);Serial.println("ms");
  Serial.println("--------------------------------------------------");
}

void loop() {



}

 

int calcularMCD(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}


int BuscarD(int e,int phiN){
  int d=1;
  bool cumple = false;
  do{    
    if ((d*e-1)%phiN == 0){
      cumple = true;
    }
    else{
      d++;
    }
  }while(!cumple);

  return d;
}


int BuscarE(int phiN){
  int e;
  bool cumple = false;
  randomSeed(analogRead(A0));
  do{
    e = random(100,phiN-1);
    if (calcularMCD(phiN, e) == 1){
      cumple = true;
    }
  }while(!cumple);
  return e;
}

