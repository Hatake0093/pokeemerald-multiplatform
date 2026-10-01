#!/usr/bin/perl
# Randomizes the species of the gWildMonHeaders group of wild_encounters.json.
# Levels, slots and rates stay the same. For each encounter type
# (land/water/rock_smash/fishing):
#   1. the pool is the list of distinct species of that type, so a species that
#      filled many slots originally (Zubat, Wingull...) is no more likely than any other;
#   2. every species is first placed once in a common slot, so everything that was
#      obtainable before still is, and not only in a 1% slot;
#   3. the remaining slots are filled uniformly at random from the pool;
#   4. a species never appears twice in the same table.
#
# Usage: randomize_wild.pl <in.json> <out.json> [seed]
use strict;
use warnings;

my ($in, $out, $seed) = @ARGV;
die "usage: $0 <in.json> <out.json> [seed]\n" unless defined $out;
$seed = int(rand(2**31)) unless defined $seed && $seed ne '';
srand($seed);

# Species that are obtained some other way (gift, egg) and must never be in the pool
my %excluded = map { $_ => 1 } qw(SPECIES_CASTFORM SPECIES_WYNAUT SPECIES_KECLEON SPECIES_VOLTORB SPECIES_SUDOWOODO SPECIES_UNOWN);

# Slots with an encounter rate of 10% or more, by index in their table
my %commonSlots = (
    land_mons       => [0 .. 5],   # 20 20 10 10 10 10
    water_mons      => [0 .. 1],   # 60 30
    rock_smash_mons => [0 .. 1],   # 60 30
    fishing_mons    => [0 .. 7],   # old 70 30, good 60 20 20, super 40 40 15
);

open(my $fh, '<', $in) or die "$in: $!\n";
my @lines = <$fh>;
close($fh);

# Collect every species line of the Hoenn group, grouped into tables by encounter type
my (%species, %seen, %tables);
my ($inGroup, $type, $table) = (0, '', undef);
for my $i (0 .. $#lines) {
    if ($lines[$i] =~ /"label":\s*"(\w+)"/) {
        $inGroup = ($1 eq 'gWildMonHeaders');
    }
    next unless $inGroup;
    if ($lines[$i] =~ /"(\w+_mons)":\s*\{/) {
        $type = $1;
        $table = { slots => [], has => {} };
        push @{$tables{$type}}, $table;
    }
    if ($lines[$i] =~ /"species":\s*"(\w+)"/) {
        push @{$species{$type}}, $1 unless $excluded{$1} || $seen{$type}{$1}++;
        push @{$table->{slots}}, { line => $i, species => undef };
    }
}

sub shuffle {
    my @list = @_;
    for (my $i = $#list; $i > 0; $i--) {
        my $j = int(rand($i + 1));
        @list[$i, $j] = @list[$j, $i];
    }
    return @list;
}

sub place {
    my ($table, $slot, $species) = @_;
    $slot->{species} = $species;
    $table->{has}{$species} = 1;
    $lines[$slot->{line}] =~ s/("species":\s*")\w+(")/$1$species$2/;
}

for my $t (sort keys %tables) {
    my @pool = @{$species{$t}};

    # Step 2: each species once, in a common slot of a table that doesn't have it yet
    my @common;
    for my $table (@{$tables{$t}}) {
        for my $idx (@{$commonSlots{$t}}) {
            push @common, [$table, $table->{slots}[$idx]] if $idx < @{$table->{slots}};
        }
    }
    @common = shuffle(@common);
    for my $species (shuffle(@pool)) {
        my ($pick) = grep { !defined $_->[1]{species} && !$_->[0]{has}{$species} } @common;
        die "$t: no common slot left for $species\n" unless $pick;
        place(@$pick, $species);
    }

    # Steps 3 and 4: fill the rest uniformly, skipping species already in the table
    my @rest;
    for my $table (@{$tables{$t}}) {
        push @rest, map { [$table, $_] } grep { !defined $_->{species} } @{$table->{slots}};
    }
    for my $pick (shuffle(@rest)) {
        my @choices = grep { !$pick->[0]{has}{$_} } @pool;
        @choices = @pool unless @choices;   # table bigger than the pool
        place(@$pick, $choices[int(rand(@choices))]);
    }
}

open($fh, '>', $out) or die "$out: $!\n";
print $fh @lines;
close($fh);

print "Wild encounters randomized (seed $seed)\n";
