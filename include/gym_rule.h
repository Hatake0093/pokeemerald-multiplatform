#ifndef GUARD_GYM_RULE_H
#define GUARD_GYM_RULE_H

// Jazz: inside a gym, a Pokemon that has fought against a trainer cannot be used against the next
// trainer or the Gym Leader of the same gym. The rule is dropped when no other Pokemon can fight.

bool8 GymRule_IsMonBlocked(struct Pokemon *mon);
void GymRule_MarkBattlerSentIn(u8 battler);
void GymRule_PrepareLead(void);
void GymRule_EndOfBattle(void);
void GymRule_OnMapLoaded(void);

#endif // GUARD_GYM_RULE_H
