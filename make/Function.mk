comma := ,
empty :=
space := ${empty} ${empty}
foo := a b c
bar := ${subst ${space},${comma},${foo}}

e_var := a.c.c b.c d.c
all_fun:
	@echo ${bar}
	@echo ${patsubst %.c,%.o,a.c.c b.c d.c}
	@echo ${subst c,o,a.c.c b.c d.c}
	@echo ${e_var:c=C}
	@echo ${e_var:%.c=%.C}
	@echo ${findstring a,abc}
	@echo ${if a,a.o,b.o}

ifneq ($(findstring a,abc),)
	@echo '"a" found'
else
	@echo '"a" not found'
endif