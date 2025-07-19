#ifndef GUARD_PLAY_TIME_H
#define GUARD_PLAY_TIME_H

void PlayTimeCounter_Reset(void);
void PlayTimeCounter_Start(void);
void PlayTimeCounter_Stop(void);
void PlayTimeCounter_Update(void);
void PlayTimeCounter_SetToMax(void);

#define MAX_PLAY_TIME_HOURS   9999
#define MAX_PLAY_TIME_MINUTES   60
#define MAX_PLAY_TIME_SECONDS   60
#define MAX_PLAY_TIME_FRAMES    60

#define PT_HOUR_STR_LEN 4

#endif // GUARD_PLAY_TIME_H
