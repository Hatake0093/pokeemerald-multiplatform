RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "¿Quieres ser CAMPEÓN?\p"
	.string "No soy ENTRENADOR, pero te doy\n"
	.string "consejos.\p"
	.string "ROXANNE usa POKéMON de tipo ROCA:\n"
	.string "resistentes, pero débiles a\l"
	.string "AGUA y PLANTA.\p"
	.string "Vuelve a verme si la vences.$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "¡Qué victoria!\p"
	.string "Mira tu TARJETA DE ENTRENADOR:\n"
	.string "ya tiene la MEDALLA ROCA.\p"
	.string "¡Primer paso hacia el CAMPEONATO!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "¡No subestimes a los ENTRENADORES\n"
	.string "del GIMNASIO!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Eres demasiado fuerte…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Aún no viste el terrible poder\n"
	.string "del tipo ROCA.$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si no me vences, no podrás con\n"
	.string "ROXANNE.$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "¡Tienes potencial!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE es mucho más fuerte que yo.\n"
	.string "¡Cuidado!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "¿En medio del pueblo? ¡Mis POKéMON\n"
	.string "ROCA necesitan espacio para rugir!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "¡Vaya! ¡Qué rival tan peleón!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Mi LÍDER eligió el tipo ROCA siendo\n"
	.string "muy joven. Qué astucia.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Soy ROXANNE, LÍDER del GIMNASIO\n"
	.string "de RUSTBORO.\p"
	.string "Aplico en combate lo que aprendí\n"
	.string "en la ESCUELA.\p"
	.string "¿Me muestras cómo combates?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Perdí…\n"
	.string "Aún tengo mucho que aprender.\p"
	.string "Según la LIGA POKéMON, esto es\n"
	.string "tuyo: la MEDALLA ROCA oficial.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} recibió la MEDALLA ROCA\n"
	.string "de ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "La MEDALLA ROCA sube el ATAQUE de\n"
	.string "tus POKéMON y permite usar CORTE\l"
	.string "fuera de combate.\p"
	.string "Llévate esto también.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "La MT 39 contiene TUMBA ROCAS:\n"
	.string "daña y baja la VELOCIDAD.\p"
	.string "Una MT se usa una sola vez,\n"
	.string "¡piénsalo bien!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Eres fuerte. Desafía a otros\n"
	.string "LÍDERES: aprenderás mucho.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE RUSTBORO CITY$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE RUSTBORO CITY\p"
	.string "CERTIFICADOS POR ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: ¿{PLAYER}?\n"
	.string "Soy ROXANNE, de RUSTBORO CITY.\p"
	.string "BRAWLY me dijo que mejoras\n"
	.string "rapidísimo.\p"
	.string "Mejoraré mi GIMNASIO para que nos\n"
	.string "desafíes de nuevo. ¡Te espero!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "LÍDER ROXANNE registrada\n"
	.string "en el POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: ¡Qué gusto verte!\p"
	.string "Hemos combatido mucho desde\n"
	.string "entonces. ¡Veamos cuánto mejoramos!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Perdí otra vez…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Aún tengo mucho que\n"
	.string "aprender.\p"
	.string "¡Eso me hace amar más los\n"
	.string "combates!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: ¡Qué gusto verte!\p"
	.string "Oh…\n"
	.string "¿Solo traes un POKéMON?\p"
	.string "Vuelve con al menos uno más.$"
