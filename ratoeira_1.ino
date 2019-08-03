int DC1= 2;
int DC2= 3; 
int tip = 9;
int signalDoor = 10;
int rele = 11;
int led = 13;
int ldr = A0;
int potenciometer = A1;
int estado = 0;


void setup() {
Serial.begin(9600);
pinMode(DC1, OUTPUT);
pinMode(DC2, OUTPUT);
pinMode(tip, OUTPUT);
pinMode(signalDoor, OUTPUT);
pinMode(rele, OUTPUT);
pinMode(led, OUTPUT);
}

void loop() {
  detecta();
}




// aciona a saida 09 estressando o tip e 
//acionando o eletroventilado;
void eletro(){
  digitalWrite(tip, HIGH);
  }

// aciona o relé apagando o led(nf) e acionado a sirene(na)
void AtivaRele(){
 digitalWrite(rele, HIGH);
  
  
  }

// acciona o motor da porta fechando a ratoeira
void portaFecha(){
  digitalWrite(DC1, HIGH);
  digitalWrite(DC2, LOW);
  digitalWrite(signalDoor , HIGH);
  delay(2000);
  }
// acciona o motor da porta abrindo a ratoeira
void portaAbre(){
  digitalWrite(DC2, HIGH);
  digitalWrite(DC1, LOW);
  digitalWrite(signalDoor , HIGH);
  delay(2000);
  
  }



// detecta a presença de luz
void detecta(){
  estado = analogRead(ldr);
  Serial.println(estado);
  if (estado > 1020){
  eletro(); 
  AtivaRele();
  portaFecha();
   
    
    
  }else{
 portaAbre();  
    
  }
    
  
  }