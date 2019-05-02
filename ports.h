/*
 * -------------------------------------------
 *    MSP432 PortsLib - v1_00
 * -------------------------------------------
 *
 * --COPYRIGHT--
 * Copyright (c) 2019, Jonah Boe
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __PORTS_H__
#define __PORTS_H__

/*****************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
    
#include <msp.h>
#include <stdint.h>
    
#define PORT_P1                                                          1
#define PORT_P2                                                          2
#define PORT_P3                                                          3
#define PORT_P4                                                          4
#define PORT_P5                                                          5
#define PORT_P6                                                          6
#define PORT_P7                                                          7
#define PORT_P8                                                          8
#define PORT_P9                                                          9
#define PORT_P10                                                         10
    
/*****************************************************************************
 *
 * For configuring selected port as output
 *
 *****************************************************************************/
extern void PORT_setAsOutput(uint_fast8_t selectedPort);

/*****************************************************************************
 *
 * For configuring selected port as input
 *
 *****************************************************************************/
extern void PORT_setAsInput(uint_fast8_t selectedPort);
    
/*****************************************************************************
 *
 * For configuring selected port as input with a pull up resistor
 *
 *****************************************************************************/
extern void PORT_setAsInputWithPullUp(uint_fast8_t selectedPort);
    
/*****************************************************************************
 *
 * For configuring selected port as input with a pull down resistor
 *
 *****************************************************************************/
extern void PORT_setAsInputWithPullDown(uint_fast8_t selectedPort);

/*****************************************************************************
 *
 * For setting the bits to new data
 *
 *****************************************************************************/
extern void PORT_setBits(uint_fast8_t selectedPort, uint_fast16_t data);
    
/*****************************************************************************
 *
 * For flipping the bits of the selected port
 *
 *****************************************************************************/
extern void PORT_toggleBits(uint_fast8_t selectedPort);
    
/*****************************************************************************
 *
 * For anding the bits with the new data
 *
 *****************************************************************************/
extern void PORT_andBits(uint_fast8_t selectedPort, uint_fast16_t data);
    
/*****************************************************************************
 *
 * For oring the bits with the new data
 *
 *****************************************************************************/
extern void PORT_orBits(uint_fast8_t selectedPort, uint_fast16_t data);
    
/*****************************************************************************
 *
 * For xoring the bits with the new data
 *
 *****************************************************************************/
extern void PORT_xorBits(uint_fast8_t selectedPort, uint_fast16_t data);
    
/*****************************************************************************
 *
 * For getting the current data on the pin
 *
 *****************************************************************************/
extern uint16_t PORT_getOutputBits(uint_fast8_t selectedPort);
    
/*****************************************************************************
 *
 * For getting the current input on the pin
 *
 *****************************************************************************/
extern uint16_t PORT_getInputBits(uint_fast8_t selectedPort);

#ifdef __cplusplus
}
#endif

#endif // __PORTS_H__
