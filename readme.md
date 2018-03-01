ChainDoer


Usage 
make a list file of daq files:
```bash
 ls /star/data03/daq/2018/056/*/st_epd*.daq > list.lis
```

edit submit.xml
1. change paths to point to your local directory
2. change output paths to point to your PWG space etc.
3. change Chain Options 

```bash
star-submit submit.xml
```


Usage of bfc.py
```bash
python bfc.py "{chain opts}" "{infile}" {jobIndex} "{outfilename}"
```
