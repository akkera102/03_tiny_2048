#ifndef EEP_H
#define EEP_H
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

//---------------------------------------------------------------------------
#define EEP_START_OFFSET				16


//---------------------------------------------------------------------------
typedef struct {
	u8* adr;

} ST_EEP;


//---------------------------------------------------------------------------
void EepInit(void);
void EepSeek(u16 adr);

u8   EepRead8(void);
u16  EepRead16(void);
u32  EepRead32(void);
void EepWrite8(u8 data);
void EepWrite16(u16 data);
void EepWrite32(u32 data);


#ifdef __cplusplus
}
#endif
#endif
