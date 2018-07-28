pwd := $(shell pwd)
make_level := ${MAKELEVEL}

x = variable1
variable2 := Hello
y = $(subst 1,2,$(x))
z = y
a := $($($(z)))


define commond_chunk
echo 'the first commond';
echo 'the second common';
endef


a =
b = ${a}

all_var:
	@echo "present work directory:" ${pwd}
	@echo "make level:" ${make_level}
	@echo $a
	${commond_chunk}
	echo ${CC}

ifdef ($b)
	echo 'yes'
else
	echo 'no'
endif

