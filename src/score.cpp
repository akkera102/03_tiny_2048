#include "score.h"
#include "lib/eep.h"
#include "lib/rnd.h"
#include "lib/oled.h"

//---------------------------------------------------------------------------
ST_SCORE Score;


//---------------------------------------------------------------------------
void ScoreInit(void)
{
	_Memset(&Score, 0x00, sizeof(ST_SCORE));

	ScoreInitRnd();
	ScoreLoadBest();
}
//---------------------------------------------------------------------------
void ScoreInitRnd(void)
{
	EepSeek(0x10);
	u32 r = EepRead32();

	if(r != 0)
	{
		RndInitSeed(r);
	}

	EepSeek(0x10);
	EepWrite32(Rnd32());
}
//---------------------------------------------------------------------------
void ScoreDraw(void)
{
	OledDrawStr(16, 1, "%5d", Score.now);
	OledDrawStr(16, 3, "%5d", Score.best);
}
//---------------------------------------------------------------------------
void ScoreSaveBest(void)
{
	if(Score.best > Score.now)
	{
		return;
	}
	Score.best = Score.now;


	EepSeek(0);

	EepWrite8('2');
	EepWrite8('0');
	EepWrite8('4');
	EepWrite8('8');

	EepWrite16(Score.best);
}
//---------------------------------------------------------------------------
void ScoreLoadBest(void)
{
	Score.best = 0;


	EepSeek(0);

	if(EepRead8() != '2') return;
	if(EepRead8() != '0') return;
	if(EepRead8() != '4') return;
	if(EepRead8() != '8') return;

	Score.best = EepRead16();
}
//---------------------------------------------------------------------------
void ScoreAddNow(u8 num)
{
	if(num >= 10)
	{
		Score.is10 = TRUE;
	}

	Score.now += num;
}
//---------------------------------------------------------------------------
bool ScoreIs10(void)
{
	return Score.is10;
}
//---------------------------------------------------------------------------
void ScoreDebug(void)
{
	EepSeek(0);
	EepWrite16(0);

	EepSeek(0x10);
	EepWrite32(0);
}
