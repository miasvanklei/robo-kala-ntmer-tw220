\_SB
   |-- URS0 ( 0x0A600000) -> usb_0
       |-- USB0
           |-- RHUB
               |-- PRT1
                   |-- _DSD(usb4) -> UBF0.PRT1
               |-- CCVL : UCS0.ECC0
               |-- PHYC -> usb_0_qmpphy
                   |-- Package (0x088EB478; F5, 0x088EBA78; F5)
       |-- UFN0
           |-- RHUB
               |-- PRT1
           |-- CCVL -> UCS0.ECC0
   |-- URS1 (0x0A800000) -> usb_1
       |-- USB1
           |-- RHUB
               |-- PRT1
                   |-- _DSD(usb4) -> UFB1.PRT1
               |-- CCVL : UCS0.ECC1
               |-- PHYC -> usb_1_qmpphy 
                   |-- Package (0x08903A78; F5, 0x08903478; F5)
       |-- UFN0
           |-- RHUB
               |-- PRT1
               |-- CCVL -> UCS0.ECC1
   |-- USB2 (0x0A400000) -> usb_2
       |-- RHUB
           |-- MP0 (_UPC: 3)
           |-- MP1 (_UPC: 3)
           |-- MP2 (_UPC: 0)
           |-- MP3 (_UPC: 0)
   |-- UBF0
       |-- prt0 (0x15640000)
       |-- prt1 (0x15740000)
   |-- UCSI (0x808A0000)
       |-- UCN0
       |-- UCN1
   |-- UCS0 (0x808A0040) -> gpio usb mux
       |-- GpioIo (a6)
       |-- GpioIo (a5)
       |-- GpioIo (a4)
       |-- GpioIo (a7)
       |-- GpioIo (31)
       |-- GpioIo (30)
       |-- GpioIo (2f)
       |-- GpioIo (32)
       |-- GpioIo (1b)
  |-- PEP0
      |-- URS0
          |-- USB0
              |-- PMICREGVOTE (LDO1_C, 1B7740)
              |-- PMICREGVOTE (LDO9_D, DEA80)
              |-- PMICREGVOTE (LDO7_D, 2EE000)
              |-- PMICREGVOTE (LDO4_D, 124F80)
              |-- PMICREGVOTE (LDO6_D, D6D80)
          |-- UFN0
              |-- PMICREGVOTE (LDO1_C, 1B7740)
              |-- PMICREGVOTE (LDO9_D, DEA80)
              |-- PMICREGVOTE (LDO7_D, 2EE000)
              |-- PMICREGVOTE (LDO4_D, 124F80)
              |-- PMICREGVOTE (LDO6_D, D6D80)
      |-- URS1
          |-- USB1
              |-- PMICREGVOTE (LDO1_C, 1B7740)
              |-- PMICREGVOTE (LDO4_B, DEA80)
              |-- PMICREGVOTE (LDO13_C, 2EE000)
              |-- PMICREGVOTE (LDO3_B, 124F80)
              |-- PMICREGVOTE (LDO6_B, D6D80)
          |-- UFN1
              |-- PMICREGVOTE (LDO1_C, 1B7740)
              |-- PMICREGVOTE (LDO4_B, DEA80)
              |-- PMICREGVOTE (LDO13_C, 2EE000)
              |-- PMICREGVOTE (LDO3_B, 124F80)
              |-- PMICREGVOTE (LDO6_B, D6D80)
      |-- USB2
          |-- PMICREGVOTE (LDO1_C, 1B7740)
          |-- PMICREGVOTE (LDO8_C, 1B7740)
          |-- PMICREGVOTE (LDO1_B, DEA80)
          |-- PMICREGVOTE (LDO8_D, DEA80)
          |-- PMICREGVOTE (LD10_D, DEA80)
          |-- PMICREGVOTE (LD2_D, 2EE000)
          |-- PMICREGVOTE (LD7_D, 2EE000)
          |-- PMICREGVOTE (LD4_D, 124F80)
          |-- PMICREGVOTE (LD6_D, D6D80)
          |-- PMICREGVOTE (LD9_D, DEA80)

      |-- UFB0
          |-- PRT0
              |-- PMICREGVOTE (LDO1_C, 1B7740)
              |-- PMICREGVOTE (LDO4_D, 124F80)
              |-- PMICREGVOTE (LDO9_D, DEA80)
              |-- PMICREGVOTE (LDO6_D, D6D80)
              |-- PMICREGVOTE (LDO7_D, 2EE000)
          |-- PRT1
              |-- PMICREGVOTE (LDO1_C, 1B7740)
              |-- PMICREGVOTE (LDO3_B, 124F80)
              |-- PMICREGVOTE (LDO4_B, DEA80)
              |-- PMICREGVOTE (LDO6_B, D6D80)
              |-- PMICREGVOTE (LDO13_C, 2EE000)
