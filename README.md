## Ports Library for MSP432

### What is it?
This is a port manipulation library for the Texas Instruments MSP432 development board. It gives the user the ability to access entire ports, rather than just single pins.

### How does it work?
The following is documentation on the constants and methods that can be called. Note that the MSP432 is a 16-bit micro-controller, so while the ports are 16 bits wide in code, the physical ports only cover the 8 least significant bits.
  
	Constants:
		PORT_P1
		PORT_P2
		PORT_P3
		PORT_P4
		PORT_P5
		PORT_P6
		PORT_P7
		PORT_P8
		PORT_P9
		PORT_P10
		
	Methods:
		void PORT_setAsOutput(<Port Name>)
		void PORT_setAsInput(<Port Name>)
		void PORT_setAsInputWithPullUp(<Port Name>)
		void PORT_setAsInputWithPullDown(<Port Name>)
		void PORT_setBits(<Port Name>, <Hex Data>)
		void PORT_toggleBits(<Port Name>)              // Invert each bit of the output
		void PORT_andBits(<Port Name>, <Hex Data>)
		void PORT_orBits(<Port Name>, <Hex Data>)
		void PORT_xorBits(<Port Name>, <Hex Data>)
		unsigned_int PORT_getOutputBits(<Port Name>)   // Get the data curently on the output
		unsigned_int PORT_getInputBits(<Port Name>)    // Get the input readings
		
##### Note:
This library can be added to Energia by copying the entire folder into your "Documents/Energia/libraries/"  

From there it can be imported into any project using "#include <ports.h>" at the begining of the projects main .ino file. 
