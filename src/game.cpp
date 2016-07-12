#include "game.h"
#include "lib/key.h"
#include "lib/oled.h"
#include "lib/frame.h"
#include "panel.h"
#include "score.h"
#include "anime.h"
#include "sprite.h"

//---------------------------------------------------------------------------
ST_GAME Game;


//---------------------------------------------------------------------------
void GameInit(void)
{
	_Memset(&Game, 0x00, sizeof(ST_GAME));
}
//---------------------------------------------------------------------------
void GameLoop(void)
{
	switch(Game.act)
	{
		case GAME_EXEC_RESET: GameExecReset(); break;
		case GAME_EXEC_ANIME: GameExecAnime(); break;
		case GAME_EXEC_PLAY:  GameExecPlay();  break;
		case GAME_EXEC_JUDGE: GameExecJudge(); break;
		case GAME_EXEC_OVER:  GameExecOver();  break;

		default:
			_SystemError("[Game act=%x]", Game.act);
			break;
	}

//	OledDrawStr(0, 4, "%03d %x", FrameGetCpuPercentMax(), FrameGetCnt());
}
//---------------------------------------------------------------------------
void GameExecReset(void)
{
	AnimeInit();

	PanelInit();
	ScoreInit();
	SpriteInit();

	PanelMakeCell();
	PanelMakeCell();
//	PanelDebug();

	GameSetAct(GAME_EXEC_ANIME);
}
//---------------------------------------------------------------------------
void GameExecAnime(void)
{
	PanelDraw();
	ScoreDraw();
	SpriteDraw();


	AnimeExec();

	if(AnimeIsEnd() == FALSE)
	{
		return;
	}

	if(ScoreIs10() == TRUE || PanelIsGameOver() == TRUE)
	{
		GameSetAct(GAME_EXEC_OVER);
	}
	else
	{
		GameSetAct(GAME_EXEC_PLAY);
	}
}
//---------------------------------------------------------------------------
void GameExecPlay(void)
{
	PanelDraw();
	ScoreDraw();
	SpriteDraw();


	u8 trg = KeyGetTrg();
	u8 cnt = KeyGetCnt();

	if(trg & KEY_U)
	{
		PanelMoveUp();
		GameSetAct(GAME_EXEC_JUDGE);
	}
	else if(trg & KEY_R)
	{
		PanelMoveRight();
		GameSetAct(GAME_EXEC_JUDGE);
	}
	else if(trg & KEY_D)
	{
		PanelMoveDown();
		GameSetAct(GAME_EXEC_JUDGE);
	}
	else if(trg & KEY_L)
	{
		PanelMoveLeft();
		GameSetAct(GAME_EXEC_JUDGE);
	}

	if(cnt & KEY_A && cnt & KEY_B)
	{
		ScoreSaveBest();
		GameSetAct(GAME_EXEC_RESET);
	}
}
//---------------------------------------------------------------------------
void GameExecJudge(void)
{
	PanelDraw();
	ScoreDraw();
	SpriteDraw();


	if(AnimeIsDispOnly() == FALSE)
	{
		PanelMakeCell();
	}

	GameSetAct(GAME_EXEC_ANIME);
}
//---------------------------------------------------------------------------
void GameExecOver(void)
{
	PanelDraw();
	ScoreDraw();
	SpriteDraw();


	OledDrawStr(0, 6, "GAME");

	if(ScoreIs10() == TRUE)
	{
		OledDrawStr(0, 7, "CLEAR");
	}
	else
	{
		OledDrawStr(0, 7, "OVER");
	}

	if(KeyGetTrg() & KEY_B)
	{
		ScoreSaveBest();
		GameSetAct(GAME_EXEC_RESET);
	}
}
//---------------------------------------------------------------------------
void GameSetAct(u8 act)
{
	Game.act = act;
}
