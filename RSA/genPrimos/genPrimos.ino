void setup() {
  Serial.begin(9600);

  unsigned long tiempoInicialPrimos;
  tiempoInicialPrimos = millis();

  unsigned long p, q;
  p = GenerarPrimo();

  do{
    q = GenerarPrimo();
  }while(q==p);
  
  
  unsigned long tiempoFinalPrimos = millis();

  Serial.print("p = "), Serial.println(p);
  Serial.print("q = "), Serial.println(q);
  Serial.print("tiempo trascurrido en encontrar primos = "), Serial.print(tiempoFinalPrimos-tiempoInicialPrimos);Serial.println(" ms");
  Serial.println("--------------------------------------------------");





}






void loop() {
  // put your main code here, to run repeatedly:

}



long GenerarPrimo(){
  unsigned long numRandom;
  do{
    numRandom = NumeroRandom();
  }while(!EsPrimo(numRandom));
  return numRandom;
}



bool EsPrimo(unsigned long numero) {
    // Los números menores o iguales a 1 no son primos
    if (numero <= 1) {
        return false;
    }
    // 2 y 3 son primos
    if (numero <= 3) {
        return true;
    }
    // Eliminar los múltiplos de 2 y 3
    if (numero % 2 == 0 || numero % 3 == 0) {
        return false;
    }
    // Solo comprobar hasta la raíz cuadrada del número
    for (unsigned long i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

long NumeroRandom(){
  randomSeed(analogRead((A0)+analogRead(A1)+analogRead(A2))*4); //Semilla aleatoria basade en medida de señales analógicas
  long r = random(327675,2147483647);
  int r2 = r % 32767;//Escalado a la longitud de un int
  randomSeed(r2);
  unsigned long random2 = random(1000,2147483647) + random(100,2147483647);
  return random2;
}