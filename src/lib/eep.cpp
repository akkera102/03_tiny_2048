#include <avr/eeprom.h>
#include "eep.h"

//---------------------------------------------------------------------------
ST_EEP Eep;


//---------------------------------------------------------------------------
void EepInit(void)
{
	_Memset(&Eep, 0x00, sizeof(ST_EEP));
}
//---------------------------------------------------------------------------
void EepSeek(u16 adr)
{
	Eep.adr = (u8*)adr;
}
//---------------------------------------------------------------------------
u8 EepRead8(void)
{
	eeprom_busy_wait();
	return eeprom_read_byte(EEP_START_OFFSET + Eep.adr++);
}
//---------------------------------------------------------------------------
u16 EepRead16(void)
{
	u16 ret = 0;

	ret |= EepRead8();
	ret |= EepRead8() << 8;

	return ret;
}
//---------------------------------------------------------------------------
u32 EepRead32(void)
{
	u32 ret = 0;

	ret |= (u32)EepRead8();
	ret |= (u32)EepRead8() <<  8;
	ret |= (u32)EepRead8() << 16;
	ret |= (u32)EepRead8() << 24;

	return ret;
}
//---------------------------------------------------------------------------
void EepWrite8(u8 data)
{
	eeprom_busy_wait();
	eeprom_write_byte(EEP_START_OFFSET + Eep.adr++, data);
}
//---------------------------------------------------------------------------
void EepWrite16(u16 data)
{
	EepWrite8(data & 0xff);
	EepWrite8(data >> 8);
}
//---------------------------------------------------------------------------
void EepWrite32(u32 data)
{
	EepWrite8((data      ) & 0xff);
	EepWrite8((data >>  8) & 0xff);
	EepWrite8((data >> 16) & 0xff);
	EepWrite8((data >> 24) & 0xff);
}
