#Fuse settings
HFUSE = 0xdf 
LFUSE = 0x64
EFUSE = 0xff
FUSES = -U hfuse:w:$(HFUSE)f:m -U lfuse:w:$(LFUSE):m -U efuse:w:$(EFUSE):m
