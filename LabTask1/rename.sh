#!/bin/tcsh                                                                    

echo -n "Change from: "
set changefrom = $<

if ($changefrom =~ "") then
    echo "ERROR... nothing entered"
    exit
endif

echo -n "Change to: "
set changeto = $<

if ($changeto =~ "") then
    echo "ERROR... nothing entered"
    exit
endif

foreach file (*.$changefrom)
    if (-r $file && -w $file) then
	mv $file `echo $file | sed s/$changefrom/$changeto/`
    else
	echo "ERROR... $file : no read and/or write permissions"
	exit
    endif
end

echo all .$changefrom files are now .$changeto
ls *.$changeto
