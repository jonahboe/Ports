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
#include <stdint.h>
#include "ports.h"
#include <debug.h>
#include <interrupt.h>
#include "hw_memmap.h"

/* DriverLib internal GPIO register offset for optimized performace */
#define OFS_LIB_PAIN  ((uint32_t)&P1->IN - (uint32_t)P1)
#define OFS_LIB_PAOUT   ((uint32_t)&P1->OUT - (uint32_t)P1)
#define OFS_LIB_PADIR   ((uint32_t)&P1->DIR - (uint32_t)P1)
#define OFS_LIB_PAREN   ((uint32_t)&P1->REN - (uint32_t)P1)
#define OFS_LIB_PADS   ((uint32_t)&P1->DS - (uint32_t)P1)
#define OFS_LIB_PASEL0  ((uint32_t)&P1->SEL0 - (uint32_t)P1)
#define OFS_LIB_PASEL1  ((uint32_t)&P1->SEL1 - (uint32_t)P1)
#define OFS_LIB_PAIE    ((uint32_t)&P1->IE - (uint32_t)P1)
#define OFS_LIB_PAIES   ((uint32_t)&P1->IES - (uint32_t)P1)
#define OFS_LIB_PAIFG   ((uint32_t)&P1->IFG - (uint32_t)P1)
#define OFS_LIB_P1IE    ((uint32_t)&P1->IE - (uint32_t)P1)
#define OFS_LIB_P2IE    ((uint32_t)&P2->IE - (uint32_t)P2)

static uint32_t GPIO_PORT_TO_BASE[] =
{   0x00,
    (uint32_t)P1,
    (uint32_t)P1+1,
    (uint32_t)P3,
    (uint32_t)P3+1,
    (uint32_t)P5,
    (uint32_t)P5+1,
    (uint32_t)P7,
    (uint32_t)P7+1,
    (uint32_t)P9,
    (uint32_t)P9+1,
    (uint32_t)PJ
};

void PORT_setAsOutput(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PASEL0) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PASEL1) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PADIR) = 0xFF;
}

void PORT_setAsInput(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PASEL0) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PASEL1) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PADIR) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PAREN) = 0x00;
}

void PORT_setAsInputWithPullUp(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PASEL0) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PASEL1) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PADIR) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PAREN) = 0xFF;
    HWREG16(baseAddress + OFS_LIB_PAOUT) = 0xFF;
}

void PORT_setAsInputWithPullDown(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PASEL0) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PASEL1) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PADIR) = 0x00;
    HWREG16(baseAddress + OFS_LIB_PAREN) = 0xFF;
    HWREG16(baseAddress + OFS_LIB_PAOUT) = 0x00;
}

void PORT_setBits(uint_fast8_t selectedPort, uint_fast16_t data)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PAOUT) = data;
}

extern void PORT_toggleBits(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PAOUT) ^= 0xFF;
}

extern void PORT_andBits(uint_fast8_t selectedPort, uint_fast16_t data)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PAOUT) &= data;
}

extern void PORT_orBits(uint_fast8_t selectedPort, uint_fast16_t data)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PAOUT) |= data;
}

extern void PORT_xorBits(uint_fast8_t selectedPort, uint_fast16_t data)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    HWREG16(baseAddress + OFS_LIB_PAOUT) ^= data;
}

uint16_t PORT_getOutputBits(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    return HWREG16(baseAddress + OFS_LIB_PAOUT);
}

uint16_t PORT_getInputBits(uint_fast8_t selectedPort)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];
    
    return HWREG16(baseAddress + OFS_LIB_PAIN);
}
