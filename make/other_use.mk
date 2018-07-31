dir_a = dir_a
dir_b = dir_b
dir_c = dir_c
t_files = ${wildcard dir_d/*.t}
txt_files = ${patsubst dir_d/%.t,dir_c/%.txt,${t_files}}

all_other: create_a create_b ${txt_files}


create_dir_a:
	@if [ ! -d ${dir_a} ]; then echo 'create directory a' && mkdir ${dir_a};fi
	@for i in a b c;do \
	 echo $${i}; \
	 done;

	 @# 可以把shell命令写在Makefile文件的命令区里，但是要有一些规则：
	 @# (1) 一条shell命令必须写成一行（比如上面的if语句）或者用\连接（比如上面的for语句和下面的语句）；
	 @# 上一句定义的变量，下一句不能访问；
	 @# (2)变量赋值等要遵循shell规则，比如=左右不能有空格
	 @# (3)调用变量，必须带上$$
	 var_alone='alone var';
	 @tmp_var=`basename dir_c/*.txt .txt`; \
	 echo $${tmp_var} ${dir_a} ${var_alone} $${var_alone};

create_dir_b:
	@if [ ! -d ${dir_b} ]; then echo 'create directory b' && mkdir ${dir_b};fi

create_dir_c:
	@if [ ! -d ${dir_c} ]; then echo 'create directory c' && mkdir ${dir_c};fi

# 被依赖目标中的"|"是啥意思？
create_a: dir_c/c1.txt create_dir_a
	@echo "target a done";

create_b: create_b1 create_b2

create_b1 create_b2:
	@echo $@;

# 如果模式%存在，那么必须同时存在于目标和被依赖目标。
dir_c/%.txt: dir_d/%.t
	echo $@
	echo $<
	touch $@


clean:
	rm -rf ${dir_a};
	rm -rf ${dir_b};