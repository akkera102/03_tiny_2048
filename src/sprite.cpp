#include "sprite.h"
#include "lib/oled.h"
#include "res.h"

//---------------------------------------------------------------------------
ST_SPRITE Sprite[SPRITE_MAX_CNT];


//---------------------------------------------------------------------------
void SpriteInit(void)
{
	_Memset(&Sprite, 0x00, sizeof(ST_SPRITE) * SPRITE_MAX_CNT);
}
//---------------------------------------------------------------------------
void SpriteReset(void)
{
	u8 i;

	for(i=0; i<SPRITE_MAX_CNT; i++)
	{
		if(Sprite[i].isUse == TRUE)
		{
			Sprite[i].isUse = FALSE;
		}
	}
}
//---------------------------------------------------------------------------
void SpriteDraw(void)
{
	u8 i;

	for(i=0; i<SPRITE_MAX_CNT; i++)
	{
		if(Sprite[i].isUse == TRUE)
		{
			OledDrawBmp(Sprite[i].sx, Sprite[i].sy, Sprite[i].pDat);
		}
	}
}
//---------------------------------------------------------------------------
void SpriteSetPanel(u8 num, s16 fsx, s16 fsy, u8* pDat)
{
	Sprite[num].sx    = FIX2NUM(fsx);
	Sprite[num].sy    = FIX2NUM(fsy);
	Sprite[num].pDat  = pDat;
	Sprite[num].isUse = TRUE;
}
//---------------------------------------------------------------------------
void SpriteSetPanelNormal(u8 num, s16 fsx, s16 fsy, u8 chr)
{
	SpriteSetPanel(num, fsx, fsy, (u8*)ResPanelNormalList[chr]);
}
//---------------------------------------------------------------------------
void SpriteSetPanelReverse(u8 num, s16 fsx, s16 fsy, u8 chr)
{
	SpriteSetPanel(num, fsx, fsy, (u8*)ResPanelReverseList[chr]);
}
//---------------------------------------------------------------------------
void SpriteSetPanelScale(u8 num, s16 fsx, s16 fsy, u8 chr, u8 var)
{
	ASSERT(chr < 2);

	if(chr == 0)
	{
		SpriteSetPanel(num, fsx, fsy, (u8*)ResPanelScale1List[var]);
	}
	else
	{
		SpriteSetPanel(num, fsx, fsy, (u8*)ResPanelScale2List[var]);
	}
}
//---------------------------------------------------------------------------
void SpriteDelPanel(s16 fsx, s16 fsy)
{
	u8 sx = FIX2NUM(fsx);
	u8 sy = FIX2NUM(fsy);
	u8 i;

	for(i=0; i<SPRITE_MAX_CNT; i++)
	{
		if(Sprite[i].isUse == TRUE && Sprite[i].sx == sx && Sprite[i].sy == sy)
		{
			Sprite[i].isUse = FALSE;
		}
	}
}
