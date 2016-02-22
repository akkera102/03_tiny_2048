#ifndef SCORE_H
#define SCORE_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

typedef struct {
	u16  now;
	u16  best;
	bool is10;

} ST_SCORE;


//---------------------------------------------------------------------------
void ScoreInit(void);
void ScoreInitRnd(void);
void ScoreDraw(void);

void ScoreSaveBest(void);
void ScoreLoadBest(void);

void ScoreAddNow(u8 num);
bool ScoreIs10(void);
void ScoreDebug(void);


#ifdef __cplusplus
}
#endif
#endif
