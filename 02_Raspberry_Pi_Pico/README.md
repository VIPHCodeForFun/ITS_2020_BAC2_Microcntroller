# Setup
A Raspberrypi 4B (RPI) is used for programming the Pico.
The RPI is connected to the Windows PC via SSH using VisualStudioCode with the remote extention. The SSH connection runs over the WLAN so that the RPI has internet access.

# For the startup of the RPI we use the manual .
https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

## The setup of the toolchain can be done in chapter 1 Quick Pico Setup.
## For setting up a new project on the RPI due to instructions getting-started-with-pico.pdf Chapter 8 Follow.
check also 2.1 for the SDK if needed
workspace   ->pico-sdk
            ->myprojekt     -> mymain.c
                            -> build/ 


## Compiling the project Chapter 3. blinking an LED in C

