/***************************************************
 Copyright (c) 2021 Marco Daldoss
  > This sofware shows how to extract and filter a MAC adress based on string match. 
  The list of mac adress can be provided e.g. from a scan of bluetooth classic coming ESP32

   Date: August 2021 

  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
  Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License

****************************************************/
 
 



#include <string>         // std::string


// Function that print mac adress os serial 
void printMac(uint8_t * mac){
    for (int n = 0; n < 6; n++)
  {
    Serial.print("0x");
    Serial.print(mac[n] < 16 ? "0" : "");
    Serial.print(mac[n], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

int lookForMAC(uint8_t macAdress[], String input_str, String strDelimiter="Address: "){

    // Start looking for strDelimiter pattern match from the end of the sting in order to avoid to be 
    // mislead from Bluetooth names similar to patterns
    int found = input_str.lastIndexOf(strDelimiter);
    if (found== -1){
      // Mac address Not found
      return -1;
    }
    sscanf(input_str.c_str()+found+strlen(strDelimiter.c_str()),"%2x:%2x:%2x:%2x:%2x:%2x",&macAdress[0],&macAdress[1],&macAdress[2],&macAdress[3],&macAdress[4],&macAdress[5]); 
    return 0;    
}

void setup() {
    
    Serial.begin(115200);
    Serial.println("BT mac adress Parser - 2021 Marco Daldoss");
    Serial.println("Parsing Bluetooth mac adress: ");

    // Input sting:
    String bt_result_str="Found a device asynchronously: Name: CPDANDREA, Address: 70:cf:49:30:e0:66, cod: 27527, rssi: -59";

    // Where the mac adress will be placed
    uint8_t * mac = new uint8_t[6];

    // the function whichlook for mac adress
    int ret = lookForMAC(mac, bt_result_str);
    // check return code
    if (ret == 0){
      Serial.println("Mac adress found:");
      printMac(mac);
    }
    else{
      Serial.println("Mac adress not found!");
    }
  
  /* E.g. The outcome becomes on the serial monitor in this case would be:
   
   "BT mac adress Parser - 2021 Marco Daldoss
   Parsing Bluetooth mac adress: 
   Mac adress found:
   0x70 0xCF 0x49 0x30 0xE0 0x66"

 */

}

 
void loop() {
  // put your main code here, to run repeatedly:

}
