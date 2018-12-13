set terminal pngcairo transparent enhanced size 1600, 600 font "Verdana, 14"
set xlabel "Date\nTime"
set timefmt "%s"
set xdata time
set format x "%a/%H:%M"
set xtics rotate by -45
set tics front
unset key
plot '< cat -' using 1:2 with filledcurves x1