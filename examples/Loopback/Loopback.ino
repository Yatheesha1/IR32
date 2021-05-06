#define TX_PIN 25
#define RX_PIN 26

#include <IRSend.h>
#include <IRRecv.h>
#include <Ticker.h>

IRSend remote1;
IRRecv remote2;
Ticker tkSend;

void sendKey() {
  remote1.send(0xE1419999);
}

void setup() {
  Serial.begin(115200);
  remote1.start(TX_PIN);   //remote1.start(&LG32_timing, TX_PIN);
  remote2.start(RX_PIN);   //remote2.start(&LG32_timing, RX_PIN);
  tkSend.attach(2, sendKey); 
}

void loop() { 
  while(remote2.available()){
    char* rcvGroup;
    uint32_t result = remote2.read(rcvGroup);
    if (result) {
        Serial.printf("Received: %s/0x%x\n", rcvGroup, result);
    }
  }  
  delay(100);
}
