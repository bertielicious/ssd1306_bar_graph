/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GB202
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include "mcc_generated_files/mcc.h"
#include "constants.h"
#include "config_SSD1306.h"
#include "clearDisplay.h"
#include "set_Columns.h"
#include "selectDigit.h"
#include "write_command.h"
#include "write_data.h"
#include "set_page.h"
#include "set_Columns.h"
#include <stdbool.h>


/*
                         Main application
 */
int main(void)
{
    SYSTEM_Initialize();
    SPI1_Initialize();
    UART1_Initialize();
    config_SSD1306();
    printf("Hello Phil!\n");
    clearDisplay();
    uint8_t row, col, unzoomedByte, byteBit0, byteBit1, byteBit2, byteBit3, byteBit4, byteBit5, byteBit6, byteBit7, zoomedByte0, zoomedByte1;
   /***********************draw left vertical end of bar graph********/
    write_command(0x22);// set page address
    write_command(0x00);// set page start address 0
    write_command(0x07);// set page end address
    
    write_command(0xb3);// set page 3
    
    write_command(0x21);// set column address
    write_command(0x00);// col starts from 0
    write_command(127); // col ends at 127
    write_command(0x21);// set column address
    write_command(1);// set column address
    write_data(0xff);
    
     /***********************draw horizontal lines connecting both ends*/
    write_command(0xb3);// set page 3
    write_command(0x21);// set column address
    write_command(2);// col starts from 0
    write_command(127); // col ends at 127
    for(col = 2; col < 126; col++)
    {
       write_data(0x81);
    }
    
      /***********************draw right vertical end of bar graph********/
    write_command(0x22);// set page address
    write_command(0x00);// set page start address 0
    write_command(0x07);// set page end address
    
    write_command(0xb3);// set page 3
    
    write_command(0x21);// set column address
    write_command(0x00);// col starts from 0
    write_command(127); // col ends at 127
    write_command(0x21);// set column address
    write_command(126);// set column address
    write_data(0xff);
   /*****************************************************************************/ 
   
   
    while (1)
    {
        
    }
}
/**
 End of File
*/

