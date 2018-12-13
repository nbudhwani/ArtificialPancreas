set terminal pngcairo transparent enhanced size 1600, 600 font "Verdana, 12"
set title "Insulin Graph"
set xlabel "Date\nTime"
set timefmt "%s"
set xdata time
set yrange [0:*]
set format x "%a/%H:%M"
set ylabel "Concentration\nmg/dl"
set xtics rotate by -45
set tics front
unset key
plot '< cat -' using 1:2 with boxes lc rgb "goldenrod" fill transparent solid 0.75