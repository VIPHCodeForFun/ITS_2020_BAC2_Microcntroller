#LED Blink

#RP2040 Datasheet p.20 List of Registers

The Bus Fabric registers start at a base address of 0x40030000 (defined as BUSCTRL_BASE in SDK).

Offset 	Name 				Info
0x00 		BUS_PRIORITY 		Set the priority of each master for bus arbitration.
....


# Address Map Summary p.24
ROM					0x00000000
XIP					0x10000000
SRAM 					0x20000000
APB Peripherals 			0x40000000
AHB-Lite Peripherals		0x50000000
IOPORT Registers 			0xd0000000
Cortex-M0+ internal registers 0xe0000000


Output registers, GPIO_OUT and GPIO_HI_OUT, are used to set the output level of the GPIO (1/0 for high/low)

Output enable registers, GPIO_OE and GPIO_HI_OE, are used to enable the output driver. 0 for high-impedance, 1 for drive high/low based on GPIO_OUT and GPIO_HI_OUT.

Input registers, GPIO_IN and GPIO_HI_IN, allow the processor to sample the current state of the GPIOs


The SDK starts by defining a structure to represent the registers of IO bank 0, the User IO bank. Each IO has a status
register, followed by a control register. There are 30 IOs, so the structure containing a status and control register is
instantiated as io[30] to repeat it 30 times.

The User Bank IO registers start at a base address of 0x40014000 (defined as IO_BANK0_BASE in SDK).

Offset 	Name 				Info
0x000 	GPIO0_STATUS 		GPIO status
0x004 	GPIO0_CTRL 			GPIO control including function select and overrides.
0x008 	GPIO1_STATUS 		GPIO status
0x00c 	GPIO1_CTRL 			GPIO control including function select and overrides.
0x010 	GPIO2_STATUS 		GPIO status
0x014 	GPIO2_CTRL 			GPIO control including function select and overrides.
0x018 	GPIO3_STATUS 		GPIO status
0x01c 	GPIO3_CTRL 			GPIO control including function select and overrides.
0x020 	GPIO4_STATUS 		GPIO status
... USW