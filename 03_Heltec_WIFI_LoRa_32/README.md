# Get Started heltec wifi lora 32 with (ESP32)

# Get Driver for UART to USB for Win

-> Check device manager
	= CP2102 USB to UART Bridge Controller

https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers
-> CP210x Universal Windows Driver
/* END Driver */

# Arduino
https://www.youtube.com/watch?v=dk-01OpKYuQ

├── file
│ 	└── preferences
https://docs.heltec.org/en/node/esp32/quick_start.html#via-arduino-board-manager

## Boardmanager
├── Tools                   
│   └── Board 
│   	└── Boardmanager
│			└── heltec esp32 Series Dev-boards (for the WiFi LoRa 32 use V0.0.1!)
          
## Lib
├── Lib Manager                   
│   └── Heltec ESP32 Dev-Boards 

## Examples
├── File                   
│   └── Examples 
│   	└── Heltec ESP32 Boards...

## Test
OK

# Git
https://github.com/HelTecAutomation/Heltec_ESP32
/* END Arduino */


# VSCode with Espressif IDF Extention for ESP32 development 
Video:
	https://www.youtube.com/watch?v=XDDcS7HQNlI

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/

https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md

ESP-IDF directory (IDF_PARTH)
	C:\Users\User\esp\esp-idf
ESP-IDF directory
	C:\Users\User\.espressif

## First Steps Guide
https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/basic_use.md

1) Create BLINK Example Projekt
2) edit code
	// #define BLINK_GPIO CONFIG_BLINK_GPIO
	#define BLINK_GPIO 23

	// vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
	 for (int i = 0; i < 10000000; i++) { }
	
   ESP-IDF: Build your project
   ESP-IDF: Flash (UART) your project
	note: 	CONFIG_ESP_CONSOLE_UART_BAUDRATE=115200
		used COM10

## Test
OK

## ESP-IDF Comands Strg+Shift+P

1	ESP-IDF: Show Examples Projects	
2	ESP-IDF: SDK Configuration editor
3	ESP-IDF: Build your project
4	ESP-IDF: Size analysis of the binaries
5	ESP-IDF: Select port to use
6	ESP-IDF: Flash your project
		ESP-IDF: Flash (UART) your project
		ESP-IDF: Flash (with JTag)
	ESP-IDF: Monitor your device
	
# Create a new Project
> https://www.youtube.com/watch?v=oHHOCdmLiII










