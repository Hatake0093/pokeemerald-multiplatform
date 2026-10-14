SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	buffermovename STR_VAR_1, MOVE_SWAGGER
	setvar VAR_0x8006, TUTOR_MOVE_SWAGGER
	goto JazzTutor_Tier2400
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	buffermovename STR_VAR_1, MOVE_ROLLOUT
	setvar VAR_0x8006, TUTOR_MOVE_ROLLOUT
	goto JazzTutor_Tier1600
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	buffermovename STR_VAR_1, MOVE_FURY_CUTTER
	setvar VAR_0x8006, TUTOR_MOVE_FURY_CUTTER
	goto JazzTutor_Tier1600
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	buffermovename STR_VAR_1, MOVE_MIMIC
	setvar VAR_0x8006, TUTOR_MOVE_MIMIC
	goto JazzTutor_Tier1600
	end

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	buffermovename STR_VAR_1, MOVE_METRONOME
	setvar VAR_0x8006, TUTOR_MOVE_METRONOME
	goto JazzTutor_Tier2400
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	buffermovename STR_VAR_1, MOVE_SLEEP_TALK
	setvar VAR_0x8006, TUTOR_MOVE_SLEEP_TALK
	goto JazzTutor_Tier4800
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	buffermovename STR_VAR_1, MOVE_SUBSTITUTE
	setvar VAR_0x8006, TUTOR_MOVE_SUBSTITUTE
	goto JazzTutor_Tier4800
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	buffermovename STR_VAR_1, MOVE_DYNAMIC_PUNCH
	setvar VAR_0x8006, TUTOR_MOVE_DYNAMIC_PUNCH
	goto JazzTutor_Tier4800
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	buffermovename STR_VAR_1, MOVE_DOUBLE_EDGE
	setvar VAR_0x8006, TUTOR_MOVE_DOUBLE_EDGE
	goto JazzTutor_Tier4800
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	buffermovename STR_VAR_1, MOVE_EXPLOSION
	setvar VAR_0x8006, TUTOR_MOVE_EXPLOSION
	goto JazzTutor_Tier4800
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	lock
	faceplayer
	return
