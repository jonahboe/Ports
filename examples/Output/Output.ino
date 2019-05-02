#include <ports.h>;

void setup() {

  // Set up the serial output.
  Serial.begin(9600);
  delay(1000);
  
  // Set port 4 as an output. 
  PORT_setAsOutput(PORT_P4);

  // Initialize the port to binary 10101010.
  PORT_setBits(PORT_P4, 0xAA);
  printBin(PORT_getOutputBits(PORT_P4));

  // And with 10100000 to get 10100000
  PORT_andBits(PORT_P4, 0xA0);
  printBin(PORT_getOutputBits(PORT_P4));

  // Or with 11000001 to get 11100001
  PORT_orBits(PORT_P4, B11000001);
  printBin(PORT_getOutputBits(PORT_P4));

  // Xor with 10000111 to get 01100110
  PORT_xorBits(PORT_P4, B10000111);
  printBin(PORT_getOutputBits(PORT_P4));

  // And something a little more advanced to get 00110100.
  PORT_setBits(PORT_P4, (PORT_getOutputBits(PORT_P4) >> 1) + 1);
  printBin(PORT_getOutputBits(PORT_P4));
  
}

void loop() {
  
}

void printBin(unsigned data){
  for(byte mask = 0x80; mask; mask >>= 1){
    if(mask & data)
      Serial.print('1');
    else
      Serial.print('0');
  }
  Serial.println();
}
