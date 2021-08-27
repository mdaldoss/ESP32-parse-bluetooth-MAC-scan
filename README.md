# ESP32-parse-bluetooth-MAC-scan
This repo shows how to parse a string in Arduino e.g. the mac address at the output of a bluetooth classic scan on a ESP32

## Info
This sofware shows how to extract and filter a MAC adress based on string match. 
The list of mac adress can be provided e.g. from a scan of bluetooth classic coming ESP32


## Example

From the following input string: 
>    "Found a device asynchronously: Name: CPDANDREA, Address: 70:cf:49:30:e0:66, cod: 27527, rssi: -59"
    
It will extract the following mac adress splitted in 6 element byte array:
>   0x70 0xCF 0x49 0x30 0xE0 0x66"

## Author:
 [Marco Daldoss](https://www.linkedin.com/in/marcodaldoss/)
