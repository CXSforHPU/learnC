# 项目介绍

* `./src` 存放项目源代码
* `./include` 存放项目头文件
* `./update_code.py` 转换cmake项目中utf8编写的源文件与头文件 为 gbk编写的dev c++项目
* `learn_ds.dev` dev c++项目

# 注意

* 在使用dev工程时候，需要在项目属性添加本文件夹里面的include与src文件夹
* 需要在编译时添加 `-std=c99`