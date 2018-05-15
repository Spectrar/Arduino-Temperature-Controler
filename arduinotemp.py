import serial
import subprocess

#opens port for comunication with arduino
ser = serial.Serial('/dev/ttyACM0',9600)
s = [0,1]

counter = 0

#opens a process allowing me to use the command line to open gnuplot
proc = subprocess.Popen(['gnuplot'],
                        stdin=subprocess.PIPE,
                        )
while True:
        #saves data to file
        f=open('data.dat','a+')
	s[0] = str(ser.readline())
	print s[0] 
	f.write(str(counter)+" " + s[0])
	f.close
	counter = counter + 1
	#uses command line to plot with gnuplot
	proc.stdin.write('set xrange [%d:%d]\n' % (counter-100, counter+100))
	proc.stdin.write('set yrange [0:100]\n')
	proc.stdin.write('set xlabel "Time (Sec)"\n')
	proc.stdin.write('set ylabel "Temperature (Degrees)"\n')
	proc.stdin.write('plot "data.dat" u 1:2 t "One" with line lw 2, "data.dat" u 1:3 t "Two" with line lw 2, "data.dat" u 1:4 t "Three" with line lw 2\n')
	
	
	

