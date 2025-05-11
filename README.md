# Changelog (ganz grob)

- Viele Sachen umbennant.
- printError(), clearError()
- Winkel und Geschw. werden nur dann geprintet, wenn ihre Werte sich verändert haben.
  - Winkel und Geschw. werden jetzt in 2 unterschiedlichen Funktionen geprintet.
  - Es kann sein, das sich nur der eine Wert verändert und in dem Fall sollten wir nicht wieder beides ausgeben.
- LED-Funktionen vereinfacht.
  - Manchmal brauchen wir gar keine lokalen Variablen.
  - Da wir beim Set schon das ODR-Register nutzen, müssen wir keine LEDs ausschalten. Wenn sie nicht in der Maske drin sind, werden sie eh ausgeschaltet. ODR =/= BSRR
- Winkel und Geschw. können jetzt negativ sein:
  - Da "count" negativ sein kann, sollten auch Winkel und Geschw. negativ sein können.
  - Hab uint32_f durch int ersetzt. Negativ =/= unsigned, deswegen gab es diesen Fehler mit "Geschwindigkeit: 20000000"

# Known issues

Das ganze Programm funktioniert mehr oder weniger wie erwartet, aber es gibt noch ein Fehler mit der Berechnung der Drehgeschwindigkeit.
- Direkt nachdem ich den Drehgeber-Simulator starte, wird die Drehgeschwindigkeit nur einmal korrekt angezeigt.
- z.B. wenn sie auf 20 G/S auf der Python-GUI gesetzt wurde, dann sehe ich als erste Messung 20.
- Dann ist die Geschwindigkeit immer ~60-80% vom reellen Wert. Z.B.: 16 statt 20. Und es bleibt weiterhin so.
- Vielleicht ist die Zeitmessung einfach zu langsam

Ein anderer Fehler ist, dass die Drehgeschwindigkeit manchmal plötzlich negativ wird.
- z.B. auf dem Bildschirm steht 30, 32, 40, -25, 40, etc.

Der Fehlerzustand tritt außerdem sehr oft auf, und man muss ständig S6 drücken
- Obwohl ich nicht weiß, ob das an der negativen Drehgeschw. liegt oder ob diese zwei Fehler die gleiche Ursache haben.
