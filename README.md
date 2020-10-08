# v1.0
## Kodo veikimas
**Mano sukurtos maišos funkcijos veikimo principas yra toks:**
- Visų pirma, susigalvojau sukurti nuskaityto string *išskirtinį skaičių* (kiekvienas elementas, esantis string eilutėje, atitinka savo skaitinę vertę. String eilutėje esančius elementus skaičiuoju į bendrą sumą - vieną prie sumos pridedu, kitą atimu, vieną pridedu, kita atimu ir t.t.). Tokiu būdu, nors ir du string skirtųsi vos tik vienu elementu, jų *išskirtinis skaičius* nebus vienodas.
-

## Eksperimentinio tyrimo analizė
- 1, 2 punktai: Visi bandymai sėkmingai pavyko, hash'ai gavosi vienodo ilgio. Tačiau, lygindamas du failus sudarytus iš atsitiktinių simbolių, kurie skiriasi tik vienu simboliu, pastebėjau, jog vienas hash'as su kitu turi apie 8 (iš 32) vienodus simbolius, esančius tose pačiose pozicijose.
- 4, 5 punktai: Šiam punktui įvykdyti sukūriau atsitiktinių eilučių generatorių bei programą, kuri patikrintu, ar iš tų sugeneruotų hash'ų nėra nei vieno vienodo. Su 10, 100, 500 ir 1000 ilgio simbolių porų - vienodų hash'ų neradau.
