Für den ATmega328PB wird MicrochipStudio unter Windows verwendet.

# Code läuft in MicrochipStudio
! Fehler F_CPU = 16 Hz nicht 8 Hz

# Toolchain läuft nicht unter Linux 

Lösung:
Im MakeFile anstelle von "-c jtag3" soll "-c xplainedmini" beim avrdude verwenden!
 
