# sdl
sdl development demos

本库是关于慕课ffmpeg学习的相关内容及demo

rtmp截图 是用nginx+rtmp搭建推、拉流服务器的配置信息

firstsdl.c 是渲染了一个窗口 中间出现了问题 代码编译没问题 但是只调用了终端 并未渲染出问题 解决方法 采用添加事件解决 
另外注意 编译的时候 头文件找不到可以使用 clang -g -o firstsdl firstsdl.c `pkg-config --cflags --libs sdl2`  添加了--cflags 

	pkg-config --cflags --libs sdl2 命令可以查找头文件
	pkg-config --libs sdl2 命令可以查找库
