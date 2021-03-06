# `nl`

## Трудност за имплементация

*нормална*

## Кратко описание

Номерира редовете.

## Команден ред

    nl [ОПЦИЯ]... [ФАЙЛ]...

## Описание

Командата `nl` извежда всеки ред с пореден номер в началото му, последван от разделител и съдържанието на самия ред.

Командата извежда резултата на стандартния изход.  Ако не са подадени имена на файлове като аргументи, тя чете от стандартния вход.

## Опции

* `-iN`: поредният номер на всеки ред трябва да се увеличава с `N` вместо с `1`.

* `-nFORMAT`: да се спазва форматът `FORMAT` при извеждането на номерата на редовете.  Позволените стойности на `FORMAT` са:
    * `ln`: номерата трябва да са подравнени вляво, последвани от достатъчен брой интервали, за да се запълни ширината на полето за номера (*виж документацията за `-i`*).
    * `rn`: номерата трябва да са подравнени вдясно, предшествани от достатъчен брой интервали, за да се запълни ширината на полето за номера (*виж документацията за `-i`*).
    * `rz`: номерата трябва да са подравнени вдясно, предшествани от достатъчен брой **нули**, за да се запълни ширината на полето за номера (*виж документацията за `-i`*).

    Стойността на `FORMAT` по подразбиране е `rn`.

* `-sSTRING`: разделителят между номера и съдържанието на реда да е `STRING` вместо `  `.

* `-wN`: ширината на полето за номера да е `N` вместо `6`.

## Насоки за имплементация

Разгледайте подробно документацията на `printf(3)`, за да се ориентирате как точно да форматирате номерата.