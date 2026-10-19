# Utilidad de las 50 MT

Datos de poder, precisión y tipo leídos de `src/data/battle_moves.h` (revisión del **19 de octubre de 2026**). Las HM no están incluidas.

- **Categoría**: **Daño** (ataca), **Soporte** (estados, clima, estadísticas, pantallas) o **Ambas** (ataca y además tiene un efecto útil).
- **Tier**: valoración subjetiva de utilidad general en la partida: **S** imprescindible, **A** muy buena, **B** útil en casos concretos, **C** situacional, **D** rara vez conviene.
- **Poder**: «—» = no hace daño directo; «var.» = depende de otro valor (felicidad, IV, etc.). **Prec.**: «—» = no falla.

| MT | Nombre | Tipo | Poder | Prec. | Categoría | Descripción breve | Tier |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 01 | Focus Punch | Lucha | 150 | 100 | Daño | Muy potente, pero falla si te golpean antes de atacar. | C |
| 02 | Dragon Claw | Dragón | 80 | 100 | Daño | Ataque Dragón fiable, sin efectos extra. | A |
| 03 | Water Pulse | Agua | 60 | 100 | Ambas | Daño Agua con 20 % de confundir. | C |
| 04 | Calm Mind | Psíquico | — | — | Soporte | Sube Ataque Esp. y Defensa Esp. un nivel. | A |
| 05 | Roar | Normal | — | 100 | Soporte | Obliga al rival a huir y entra otro Pokémon. | C |
| 06 | Toxic | Veneno | — | 85 | Soporte | Envenena gravemente; el daño crece cada turno. | B |
| 07 | Hail | Hielo | — | — | Soporte | Granizo 5 turnos; daña a los que no son de Hielo. | C |
| 08 | Bulk Up | Lucha | — | — | Soporte | Sube Ataque y Defensa un nivel. | A |
| 09 | Bullet Seed | Planta | 10 | 100 | Daño | Golpea de 2 a 5 veces; ideal contra sustitutos. | C |
| 10 | Hidden Power | Normal | var. | 100 | Daño | Tipo y poder según los IV del usuario. | B |
| 11 | Sunny Day | Fuego | — | — | Soporte | Sol 5 turnos; potencia Fuego y Rayo Solar sin carga. | B |
| 12 | Taunt | Siniestro | — | 100 | Soporte | Impide usar movimientos de estado al rival. | B |
| 13 | Ice Beam | Hielo | 95 | 100 | Ambas | Daño Hielo fiable con 10 % de congelar. | S |
| 14 | Blizzard | Hielo | 120 | 70 | Ambas | Muy potente con 10 % de congelar; impreciso salvo con granizo. | B |
| 15 | Hyper Beam | Normal | 150 | 90 | Daño | Enorme daño, pero hay que descansar el turno siguiente. | C |
| 16 | Light Screen | Psíquico | — | — | Soporte | Reduce el daño especial recibido 5 turnos. | B |
| 17 | Protect | Normal | — | — | Soporte | Bloquea cualquier ataque este turno (falla si se repite). | A |
| 18 | Rain Dance | Agua | — | — | Soporte | Lluvia 5 turnos; potencia Agua y Trueno no falla. | B |
| 19 | Giga Drain | Planta | 60 | 100 | Ambas | Daño Planta que cura la mitad del daño hecho. | A |
| 20 | Safeguard | Normal | — | — | Soporte | Protege al equipo de estados alterados 5 turnos. | C |
| 21 | Frustration | Normal | var. | 100 | Daño | Más fuerte cuanta menos felicidad tenga el Pokémon. | D |
| 22 | Solar Beam | Planta | 120 | 100 | Daño | Muy potente, pero necesita un turno de carga (salvo con sol). | B |
| 23 | Iron Tail | Acero | 100 | 75 | Ambas | Daño Acero con 30 % de bajar la Defensa rival. | B |
| 24 | Thunderbolt | Eléctrico | 95 | 100 | Ambas | Daño Eléctrico fiable con 10 % de paralizar. | S |
| 25 | Thunder | Eléctrico | 120 | 70 | Ambas | Muy potente con 30 % de paralizar; no falla bajo la lluvia. | B |
| 26 | Earthquake | Tierra | 100 | 100 | Daño | Golpea también bajo tierra; hace daño doble a quien usa Excavar. | S |
| 27 | Return | Normal | var. | 100 | Daño | Más fuerte cuanta más felicidad tenga el Pokémon (máx. 102). | A |
| 28 | Dig | Tierra | 60 | 100 | Daño | Se oculta bajo tierra un turno y ataca al siguiente; sirve para salir de cuevas. | C |
| 29 | Psychic | Psíquico | 90 | 100 | Ambas | Daño Psíquico con 10 % de bajar la Defensa Esp. | S |
| 30 | Shadow Ball | Fantasma | 80 | 100 | Ambas | Daño Fantasma con 20 % de bajar la Defensa Esp. | S |
| 31 | Brick Break | Lucha | 75 | 100 | Ambas | Daño Lucha que rompe Pantalla de Luz y Reflejo. | A |
| 32 | Double Team | Normal | — | — | Soporte | Sube la Evasión un nivel. | C |
| 33 | Reflect | Psíquico | — | — | Soporte | Reduce el daño físico recibido 5 turnos. | B |
| 34 | Shock Wave | Eléctrico | 60 | — | Daño | Eléctrico que nunca falla. | C |
| 35 | Flamethrower | Fuego | 95 | 100 | Ambas | Daño Fuego fiable con 10 % de quemar. | S |
| 36 | Sludge Bomb | Veneno | 90 | 100 | Ambas | Daño Veneno con 30 % de envenenar. | A |
| 37 | Sandstorm | Roca | — | — | Soporte | Tormenta de arena 5 turnos; daña a quien no sea Roca, Tierra o Acero. | C |
| 38 | Fire Blast | Fuego | 120 | 85 | Ambas | Muy potente con 10 % de quemar. | A |
| 39 | Rock Tomb | Roca | 50 | 80 | Ambas | Daño Roca que baja siempre la Velocidad rival. | B |
| 40 | Aerial Ace | Volador | 60 | — | Daño | Volador que nunca falla. | B |
| 41 | Torment | Siniestro | — | 100 | Soporte | El rival no puede repetir el mismo movimiento. | D |
| 42 | Facade | Normal | 70 | 100 | Daño | Duplica el poder (140) si el usuario está envenenado, quemado o paralizado. | B |
| 43 | Secret Power | Normal | 70 | 100 | Ambas | Daño Normal con 30 % de un efecto según el terreno. | D |
| 44 | Rest | Psíquico | — | — | Soporte | Cura toda la vida y los estados, pero duerme 2 turnos. | A |
| 45 | Attract | Normal | — | 100 | Soporte | Enamora al rival de distinto género; a veces no ataca. | D |
| 46 | Thief | Siniestro | 40 | 100 | Ambas | Daño Siniestro que roba el objeto del rival si no lleva uno. | C |
| 47 | Steel Wing | Acero | 70 | 90 | Ambas | Daño Acero con 10 % de subir la Defensa del usuario. | B |
| 48 | Skill Swap | Psíquico | — | 100 | Soporte | Intercambia la habilidad con la del rival. | D |
| 49 | Snatch | Siniestro | — | 100 | Soporte | Roba el movimiento de apoyo que use el rival ese turno. | D |
| 50 | Overheat | Fuego | 140 | 90 | Ambas | Daño Fuego enorme, pero baja 2 niveles el Ataque Esp. del usuario. | B |
