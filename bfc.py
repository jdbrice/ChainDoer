from subprocess import call
from sys import argv
import os


if len( argv ) < 5 :
	exit()

print "exe :", argv[0]
print "chain Opts :", argv[1]
print "inFile: ", argv[2]
print "jobIndex:", argv[3]
print "jobName: ", argv[4]

chain = argv[1]
infile = argv[2]
jobIndex = int(argv[3])
jobName = argv[4]

if len( argv ) >= 6 :
	splitBy = int(argv[5])
else :
	splitBy = 10

print "splitBy", splitBy

evMin = jobIndex * splitBy
evMax = (jobIndex + 1 ) * splitBy - 1

outfile = "out_" + jobName + "_{a}_{b}".format( a=evMin, b=evMax )
logfile = "log_" + jobName + "_{a}_{b}.log".format( a=evMin, b=evMax )

command = "\'$STAR/StRoot/macros/bfc.C({a}, {b}, \"{chain}\", \"{inf}\", \"{outf}\")\'".format( a=evMin, b=evMax, chain=chain, inf=infile, outf=outfile )

os.system( " root4star -b -q -l " + command )




