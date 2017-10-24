make

echo -n > file1.dat
echo -n > file2.dat
echo -n > temp1.dat
echo -n > temp2.dat
echo -n > plot1.dat
echo -n > plot2.dat

n=1
for((i = 10; i <= 1009; i++))
do
	 echo "$i" >> temp1.dat
	./graph "$i" "$n" >> file1.dat
done 

sort -n file1.dat > temp2.dat
paste temp1.dat temp2.dat >> plot1.dat

# gnuplot -persist <<-EOFMarker
#     set title "Artificial Intelligence- HomeWork 1" font ",14" textcolor rgbcolor "royalblue"
#     set timefmt "%y/%m/%d"
#     set xlabel "Number of nodes"
#     set ylabel "Time taken for execution (in msec)"
#     set pointsize 1
#     plot "plot.dat" using 1:2 with lines
# EOFMarker

echo -n > temp1.dat
echo -n > temp2.dat

n=2
for((i = 10; i <= 1009; i++))
do
	 echo "$i" >> temp1.dat
	./graph "$i" "$n" >> file2.dat
done 

sort -n file2.dat > temp2.dat
paste temp1.dat temp2.dat >> plot2.dat

gnuplot -persist <<-EOFMarker
    set title "Artificial Intelligence- HomeWork 1" font ",14" textcolor rgbcolor "royalblue"
    set timefmt "%y/%m/%d"
    set xlabel "Number of Nodes"
    set ylabel "Time taken for execution (in msec)"
    set pointsize 1
    plot "plot1.dat" using 1:2 with lines title "Dijkstra's Algorithm", \
         "plot2.dat" using 1:2 with lines title "Heuristic Search"

EOFMarker