@ Jazz: the Battle Frontier move tutors (plus the egg moves Dragon Dance, Recover, Wish and Curse)
@ taught in the Battle Tents for money. Every Pokemon can learn any of them, as many times as wanted.

JazzTutor_Declined::
	msgbox JazzTutor_Text_Bye, MSGBOX_DEFAULT
	release
	end

JazzTutor_NoMoney::
	msgbox JazzTutor_Text_NoMoney, MSGBOX_DEFAULT
	release
	end

@ STR_VAR_1 = move name, VAR_0x8006 = tutor move id
JazzTutor_Tier1600::
	msgbox JazzTutor_Text_Confirm1600, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JazzTutor_Declined
	checkmoney 1600
	goto_if_eq VAR_RESULT, FALSE, JazzTutor_NoMoney
	msgbox JazzTutor_Text_WhichMon, MSGBOX_DEFAULT
	copyvar VAR_0x8005, VAR_0x8006
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, JazzTutor_Declined
	removemoney 1600
	msgbox JazzTutor_Text_Taught, MSGBOX_DEFAULT
	release
	end

@ STR_VAR_1 = move name, VAR_0x8006 = tutor move id
JazzTutor_Tier2400::
	msgbox JazzTutor_Text_Confirm2400, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JazzTutor_Declined
	checkmoney 2400
	goto_if_eq VAR_RESULT, FALSE, JazzTutor_NoMoney
	msgbox JazzTutor_Text_WhichMon, MSGBOX_DEFAULT
	copyvar VAR_0x8005, VAR_0x8006
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, JazzTutor_Declined
	removemoney 2400
	msgbox JazzTutor_Text_Taught, MSGBOX_DEFAULT
	release
	end

@ STR_VAR_1 = move name, VAR_0x8006 = tutor move id
JazzTutor_Tier4800::
	msgbox JazzTutor_Text_Confirm4800, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JazzTutor_Declined
	checkmoney 4800
	goto_if_eq VAR_RESULT, FALSE, JazzTutor_NoMoney
	msgbox JazzTutor_Text_WhichMon, MSGBOX_DEFAULT
	copyvar VAR_0x8005, VAR_0x8006
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, JazzTutor_Declined
	removemoney 4800
	msgbox JazzTutor_Text_Taught, MSGBOX_DEFAULT
	release
	end

JazzTutor_VerdanturfTown_TutorA::
	lock
	faceplayer
	msgbox JazzTutor_Text_Welcome, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_JAZZ_TUTOR_1, FALSE
	switch VAR_RESULT
	case 0, JazzTutor_VerdanturfTown_TutorA_Move0
	case 1, JazzTutor_VerdanturfTown_TutorA_Move1
	case 2, JazzTutor_VerdanturfTown_TutorA_Move2
	case 3, JazzTutor_VerdanturfTown_TutorA_Move3
	case 4, JazzTutor_VerdanturfTown_TutorA_Move4
	case 5, JazzTutor_VerdanturfTown_TutorA_Move5
	goto JazzTutor_Declined
	end

JazzTutor_VerdanturfTown_TutorA_Move0::
	buffermovename STR_VAR_1, MOVE_FIRE_PUNCH
	setvar VAR_0x8006, TUTOR_MOVE_FIRE_PUNCH
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorA_Move1::
	buffermovename STR_VAR_1, MOVE_ICE_PUNCH
	setvar VAR_0x8006, TUTOR_MOVE_ICE_PUNCH
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorA_Move2::
	buffermovename STR_VAR_1, MOVE_THUNDER_PUNCH
	setvar VAR_0x8006, TUTOR_MOVE_THUNDER_PUNCH
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorA_Move3::
	buffermovename STR_VAR_1, MOVE_DRAGON_DANCE
	setvar VAR_0x8006, TUTOR_MOVE_DRAGON_DANCE
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorA_Move4::
	buffermovename STR_VAR_1, MOVE_SPORE
	setvar VAR_0x8006, TUTOR_MOVE_SPORE
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorA_Move5::
	buffermovename STR_VAR_1, MOVE_BATON_PASS
	setvar VAR_0x8006, TUTOR_MOVE_BATON_PASS
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorB::
	lock
	faceplayer
	msgbox JazzTutor_Text_Welcome, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_JAZZ_TUTOR_2, FALSE
	switch VAR_RESULT
	case 0, JazzTutor_VerdanturfTown_TutorB_Move0
	case 1, JazzTutor_VerdanturfTown_TutorB_Move1
	case 2, JazzTutor_VerdanturfTown_TutorB_Move2
	case 3, JazzTutor_VerdanturfTown_TutorB_Move3
	case 4, JazzTutor_VerdanturfTown_TutorB_Move4
	case 5, JazzTutor_VerdanturfTown_TutorB_Move5
	goto JazzTutor_Declined
	end

JazzTutor_VerdanturfTown_TutorB_Move0::
	buffermovename STR_VAR_1, MOVE_MEGA_PUNCH
	setvar VAR_0x8006, TUTOR_MOVE_MEGA_PUNCH
	goto JazzTutor_Tier2400
	end

JazzTutor_VerdanturfTown_TutorB_Move1::
	buffermovename STR_VAR_1, MOVE_MEGA_KICK
	setvar VAR_0x8006, TUTOR_MOVE_MEGA_KICK
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorB_Move2::
	buffermovename STR_VAR_1, MOVE_BODY_SLAM
	setvar VAR_0x8006, TUTOR_MOVE_BODY_SLAM
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorB_Move3::
	buffermovename STR_VAR_1, MOVE_RECOVER
	setvar VAR_0x8006, TUTOR_MOVE_RECOVER
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorB_Move4::
	buffermovename STR_VAR_1, MOVE_LEECH_SEED
	setvar VAR_0x8006, TUTOR_MOVE_LEECH_SEED
	goto JazzTutor_Tier4800
	end

JazzTutor_VerdanturfTown_TutorB_Move5::
	buffermovename STR_VAR_1, MOVE_BELLY_DRUM
	setvar VAR_0x8006, TUTOR_MOVE_BELLY_DRUM
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorA::
	lock
	faceplayer
	msgbox JazzTutor_Text_Welcome, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_JAZZ_TUTOR_3, FALSE
	switch VAR_RESULT
	case 0, JazzTutor_SlateportCity_TutorA_Move0
	case 1, JazzTutor_SlateportCity_TutorA_Move1
	case 2, JazzTutor_SlateportCity_TutorA_Move2
	case 3, JazzTutor_SlateportCity_TutorA_Move3
	case 4, JazzTutor_SlateportCity_TutorA_Move4
	case 5, JazzTutor_SlateportCity_TutorA_Move5
	goto JazzTutor_Declined
	end

JazzTutor_SlateportCity_TutorA_Move0::
	buffermovename STR_VAR_1, MOVE_SEISMIC_TOSS
	setvar VAR_0x8006, TUTOR_MOVE_SEISMIC_TOSS
	goto JazzTutor_Tier2400
	end

JazzTutor_SlateportCity_TutorA_Move1::
	buffermovename STR_VAR_1, MOVE_COUNTER
	setvar VAR_0x8006, TUTOR_MOVE_COUNTER
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorA_Move2::
	buffermovename STR_VAR_1, MOVE_ROCK_SLIDE
	setvar VAR_0x8006, TUTOR_MOVE_ROCK_SLIDE
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorA_Move3::
	buffermovename STR_VAR_1, MOVE_SWIFT
	setvar VAR_0x8006, TUTOR_MOVE_SWIFT
	goto JazzTutor_Tier2400
	end

JazzTutor_SlateportCity_TutorA_Move4::
	buffermovename STR_VAR_1, MOVE_ENCORE
	setvar VAR_0x8006, TUTOR_MOVE_ENCORE
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorA_Move5::
	buffermovename STR_VAR_1, MOVE_WILL_O_WISP
	setvar VAR_0x8006, TUTOR_MOVE_WILL_O_WISP
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorB::
	lock
	faceplayer
	msgbox JazzTutor_Text_Welcome, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_JAZZ_TUTOR_4, FALSE
	switch VAR_RESULT
	case 0, JazzTutor_SlateportCity_TutorB_Move0
	case 1, JazzTutor_SlateportCity_TutorB_Move1
	case 2, JazzTutor_SlateportCity_TutorB_Move2
	case 3, JazzTutor_SlateportCity_TutorB_Move3
	case 4, JazzTutor_SlateportCity_TutorB_Move4
	goto JazzTutor_Declined
	end

JazzTutor_SlateportCity_TutorB_Move0::
	buffermovename STR_VAR_1, MOVE_THUNDER_WAVE
	setvar VAR_0x8006, TUTOR_MOVE_THUNDER_WAVE
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorB_Move1::
	buffermovename STR_VAR_1, MOVE_SWORDS_DANCE
	setvar VAR_0x8006, TUTOR_MOVE_SWORDS_DANCE
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorB_Move2::
	buffermovename STR_VAR_1, MOVE_WISH
	setvar VAR_0x8006, TUTOR_MOVE_WISH
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorB_Move3::
	buffermovename STR_VAR_1, MOVE_ENDURE
	setvar VAR_0x8006, TUTOR_MOVE_ENDURE
	goto JazzTutor_Tier4800
	end

JazzTutor_SlateportCity_TutorB_Move4::
	buffermovename STR_VAR_1, MOVE_YAWN
	setvar VAR_0x8006, TUTOR_MOVE_YAWN
	goto JazzTutor_Tier4800
	end

JazzTutor_FallarborTown_TutorA::
	lock
	faceplayer
	msgbox JazzTutor_Text_Welcome, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_JAZZ_TUTOR_5, FALSE
	switch VAR_RESULT
	case 0, JazzTutor_FallarborTown_TutorA_Move0
	case 1, JazzTutor_FallarborTown_TutorA_Move1
	case 2, JazzTutor_FallarborTown_TutorA_Move2
	case 3, JazzTutor_FallarborTown_TutorA_Move3
	case 4, JazzTutor_FallarborTown_TutorA_Move4
	goto JazzTutor_Declined
	end

JazzTutor_FallarborTown_TutorA_Move0::
	buffermovename STR_VAR_1, MOVE_SOFT_BOILED
	setvar VAR_0x8006, TUTOR_MOVE_SOFT_BOILED
	goto JazzTutor_Tier1600
	end

JazzTutor_FallarborTown_TutorA_Move1::
	buffermovename STR_VAR_1, MOVE_DREAM_EATER
	setvar VAR_0x8006, TUTOR_MOVE_DREAM_EATER
	goto JazzTutor_Tier2400
	end

JazzTutor_FallarborTown_TutorA_Move2::
	buffermovename STR_VAR_1, MOVE_PSYCH_UP
	setvar VAR_0x8006, TUTOR_MOVE_PSYCH_UP
	goto JazzTutor_Tier4800
	end

JazzTutor_FallarborTown_TutorA_Move3::
	buffermovename STR_VAR_1, MOVE_CURSE
	setvar VAR_0x8006, TUTOR_MOVE_CURSE
	goto JazzTutor_Tier4800
	end

JazzTutor_FallarborTown_TutorA_Move4::
	buffermovename STR_VAR_1, MOVE_EXTREME_SPEED
	setvar VAR_0x8006, TUTOR_MOVE_EXTREME_SPEED
	goto JazzTutor_Tier4800
	end

JazzTutor_FallarborTown_TutorB::
	lock
	faceplayer
	msgbox JazzTutor_Text_Welcome, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_JAZZ_TUTOR_6, FALSE
	switch VAR_RESULT
	case 0, JazzTutor_FallarborTown_TutorB_Move0
	case 1, JazzTutor_FallarborTown_TutorB_Move1
	case 2, JazzTutor_FallarborTown_TutorB_Move2
	case 3, JazzTutor_FallarborTown_TutorB_Move3
	case 4, JazzTutor_FallarborTown_TutorB_Move4
	goto JazzTutor_Declined
	end

JazzTutor_FallarborTown_TutorB_Move0::
	buffermovename STR_VAR_1, MOVE_FALSE_SWIPE
	setvar VAR_0x8006, TUTOR_MOVE_FALSE_SWIPE
	goto JazzTutor_Tier2400
	end

JazzTutor_FallarborTown_TutorB_Move1::
	buffermovename STR_VAR_1, MOVE_SNORE
	setvar VAR_0x8006, TUTOR_MOVE_SNORE
	goto JazzTutor_Tier2400
	end

JazzTutor_FallarborTown_TutorB_Move2::
	buffermovename STR_VAR_1, MOVE_MUD_SLAP
	setvar VAR_0x8006, TUTOR_MOVE_MUD_SLAP
	goto JazzTutor_Tier2400
	end

JazzTutor_FallarborTown_TutorB_Move3::
	buffermovename STR_VAR_1, MOVE_ICY_WIND
	setvar VAR_0x8006, TUTOR_MOVE_ICY_WIND
	goto JazzTutor_Tier2400
	end

JazzTutor_FallarborTown_TutorB_Move4::
	buffermovename STR_VAR_1, MOVE_MEGAHORN
	setvar VAR_0x8006, TUTOR_MOVE_MEGAHORN
	goto JazzTutor_Tier4800
	end

JazzTutor_Text_Welcome:
	.string "Enseño movimientos por dinero.\n"
	.string "¿Cuál quieres?$"

JazzTutor_Text_Confirm1600:
	.string "¿Enseñar {STR_VAR_1}\n"
	.string "por ¥1.600?$"

JazzTutor_Text_Confirm2400:
	.string "¿Enseñar {STR_VAR_1}\n"
	.string "por ¥2.400?$"

JazzTutor_Text_Confirm4800:
	.string "¿Enseñar {STR_VAR_1}\n"
	.string "por ¥4.800?$"

JazzTutor_Text_WhichMon:
	.string "¿A qué POKéMON se lo enseño?$"

JazzTutor_Text_NoMoney:
	.string "No tienes suficiente dinero.$"

JazzTutor_Text_Taught:
	.string "¡Hecho! Vuelve cuando quieras.$"

JazzTutor_Text_Bye:
	.string "¡Hasta pronto!$"
