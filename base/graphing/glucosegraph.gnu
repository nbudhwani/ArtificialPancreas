set terminal pngcairo transparent enhanced size 1600, 600 font "Verdana, 12"
set title "Glucose Graph"
set xlabel "Date\nTime"
set timefmt "%s"
set yrange [0:*]
set xdata time
set format x "%a/%H:%M"
set ylabel "Concentration\nmg/dl"
set xtics rotate by -45
set tics front
unset key
plot '< cat -' using 1:2 with filledcurves x1 lc rgb "mediumpurple3" fill transparent solid 0.75