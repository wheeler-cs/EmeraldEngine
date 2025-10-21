#ifndef GUARD_TIME_EVENTS_H
#define GUARD_TIME_EVENTS_H

#define EVENT_NIGHT_END 6
#define EVENT_NIGHT_START 20

void UpdateMirageRnd(u16 days);
bool8 IsMirageIslandPresent(void);
void UpdateBirchState(u16 days);
void UpdateNightFlag(void);

#endif // GUARD_TIME_EVENTS_H
