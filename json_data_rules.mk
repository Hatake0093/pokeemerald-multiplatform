# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

# make RANDOM_WILD=1 [WILD_SEED=n] randomizes the wild species on every build
# without touching wild_encounters.json; a plain make restores the originals.
# The mode and seed are kept in WILD_CONFIG, which is only rewritten when they
# change, so the header is regenerated once per build instead of on every
# make restart. Only the top-level make owns it: the parse-time "make generated"
# sub-make doesn't see RANDOM_WILD, so the header isn't in AUTO_GEN_TARGETS.
WILD_CONFIG := $(BUILD_DIR)/wild_encounters.cfg
ifeq ($(RANDOM_WILD),1)
  ifeq ($(WILD_SEED),)
    ifeq ($(MAKELEVEL)$(MAKE_RESTARTS),0)
      WILD_SEED := $(shell perl -e 'print int(rand(2**31))')
    else
      WILD_SEED := $(shell sed -n 's/^random //p' $(WILD_CONFIG) 2>/dev/null)
    endif
  endif
  WILD_CONFIG_TEXT := random $(WILD_SEED)
else
  WILD_CONFIG_TEXT := vanilla
endif
ifeq ($(MAKELEVEL),0)
$(shell mkdir -p $(BUILD_DIR); [ "$$(cat $(WILD_CONFIG) 2>/dev/null)" = "$(WILD_CONFIG_TEXT)" ] || echo "$(WILD_CONFIG_TEXT)" > $(WILD_CONFIG))
endif

$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt $(WILD_CONFIG) tools/randomize_wild.pl
ifeq ($(RANDOM_WILD),1)
	perl tools/randomize_wild.pl $< $(BUILD_DIR)/wild_encounters_random.json $(WILD_SEED)
	@echo "$$(date '+%Y-%m-%d %H:%M:%S') seed $(WILD_SEED)" >> random_builds.log
	$(JSONPROC) $(BUILD_DIR)/wild_encounters_random.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt $@
else
	$(JSONPROC) $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt $@
endif

$(C_BUILDDIR)/wild_encounter.o: c_dep += $(DATA_SRC_SUBDIR)/wild_encounters.h

# The species of the fixed wild encounters (Kecleon, Voltorb) come from the same seed
# The header has to exist before the dependency scan of fixed_encounters.c, so on the first
# build it is made here, in the current mode; the rule below keeps it up to date afterwards.
FIXED_ENCOUNTERS_H := $(DATA_SRC_SUBDIR)/fixed_encounters.h
ifeq ($(MAKELEVEL),0)
ifeq ($(RANDOM_WILD),1)
$(shell [ -f $(FIXED_ENCOUNTERS_H) ] || perl tools/randomize_wild.pl $(DATA_SRC_SUBDIR)/wild_encounters.json $(BUILD_DIR)/wild_encounters_fixed_tmp.json $(WILD_SEED) $(FIXED_ENCOUNTERS_H) > /dev/null)
else
$(shell [ -f $(FIXED_ENCOUNTERS_H) ] || perl tools/randomize_wild.pl --vanilla $(FIXED_ENCOUNTERS_H))
endif
endif
$(DATA_SRC_SUBDIR)/fixed_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(WILD_CONFIG) tools/randomize_wild.pl
ifeq ($(RANDOM_WILD),1)
	perl tools/randomize_wild.pl $< $(BUILD_DIR)/wild_encounters_fixed_tmp.json $(WILD_SEED) $@
else
	perl tools/randomize_wild.pl --vanilla $@
endif

$(C_BUILDDIR)/fixed_encounters.o: c_dep += $(DATA_SRC_SUBDIR)/fixed_encounters.h

AUTO_GEN_TARGETS += include/constants/wild_encounter.h
include/constants/wild_encounter.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.constants.json.txt
	$(JSONPROC) $^ $@

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/region_map/region_map_entries.h
$(DATA_SRC_SUBDIR)/region_map/region_map_entries.h: $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/region_map.o: c_dep += $(DATA_SRC_SUBDIR)/region_map/region_map_entries.h

AUTO_GEN_TARGETS += include/constants/region_map_sections.h
include/constants/region_map_sections.h: $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json $(DATA_SRC_SUBDIR)/region_map/region_map_sections.constants.json.txt
	$(JSONPROC) $^ $@

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/heal_locations.h
$(DATA_SRC_SUBDIR)/heal_locations.h: $(DATA_SRC_SUBDIR)/heal_locations.json $(DATA_SRC_SUBDIR)/heal_locations.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/heal_location.o: c_dep += $(DATA_SRC_SUBDIR)/heal_locations.h

AUTO_GEN_TARGETS += include/constants/heal_locations.h
include/constants/heal_locations.h: $(DATA_SRC_SUBDIR)/heal_locations.json $(DATA_SRC_SUBDIR)/heal_locations.constants.json.txt
	$(JSONPROC) $^ $@
