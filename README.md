# v2.0
## Kodo veikimas
**Mano sukurtos maišos funkcijos veikimo principas yra toks:**
- Visų pirma, susigalvojau sukurti nuskaityto string *išskirtinį skaičių* (kiekvienas elementas, esantis string eilutėje, atitinka savo skaitinę vertę. String eilutėje esančius elementus skaičiuoju į bendrą sumą - vieną prie sumos pridedu, kitą atimu, vieną pridedu, kita atimu ir t.t.). Tokiu būdu, nors ir du string skirtųsi vos tik vienu elementu, jų *išskirtinis skaičius* nebus vienodas.
- Tuomet į sukurtą string įdedu nuskaityto tekstinio failo pirmos (o vėliau antrą, trečią ir t.t.) simbolio skaitinės reikšmės, *išskirtinio skaičiaus* ir raidės, atitinkančios *išskirtinio skaičiaus* paskutinį skaitmenį, sumą. Su kitais, tekstiniame faile esančias, simboliais atlieku tą pačią operaciją, tik po kiekvienos operacijos *išskirtinis skaičius* pastoviai kinta.
- Jei hash'o string ima viršyti mano nustatytą ilgio limitą (t.y. 32 simboliai), tuomet string'o elementai yra palaipsniui perrašomi, atliekant tą pačią hash'avimo operaciją.

## Eksperimentinio tyrimo analizė
- 1, 2 punktai: Visi bandymai sėkmingai pavyko, hash'ai gavosi vienodo ilgio. Tačiau, lygindamas du failus sudarytus iš atsitiktinių simbolių, kurie skiriasi tik vienu simboliu, pastebėjau, jog vienas hash'as su kitu turi apie 8 (iš 32) vienodus simbolius, esančius tose pačiose pozicijose.
- 3 punktas: Mano hash'avimo funkcija failą konstitucija.txt suhashavo per ~0.22 s
- 4, 5 punktai: Šiam punktui įvykdyti sukūriau atsitiktinių eilučių generatorių bei programą, kuri patikrintu, ar iš tų sugeneruotų hash'ų nėra nei vieno vienodo. Su 10, 100, 500 ir 1000 ilgio simbolių porų - vienodų hash'ų neradau.
- 6 punktas: Palyginus bit'ų lygmenyje pastebėjau, jog skirtingumo procentai yra tokie: max - 35.9%, min - 0.391%, average - 9.39% ; palyginus hex'ų lygmenyje: max - 71.9%, min - 1.56%, average - 8.6%
## Išvados
Naudojant mano sukurtą hash'avimo funkciją, duomenų eilutės hash'as kiekvieną kartą hash'uojant visada bus gaunamas toks pat, tad ši funkcija yra *deterministinė*. Visų mano darytų testų metu, nė karto neradau vienodų hash'ų, tačiau, lyginant tiek bit'ų, tiek hex'ų lygmenyje, skirtingumo procentai nėra dideli.
