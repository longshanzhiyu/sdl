# sdl
sdl development demos

本库是关于慕课ffmpeg学习的相关内容及demo

rtmp截图 是用nginx+rtmp搭建推、拉流服务器的配置信息

firstsdl.c 是渲染了一个窗口 中间出现了问题 代码编译没问题 但是只调用了终端 并未渲染出问题 解决方法 采用添加事件解决 
另外注意 编译的时候 头文件找不到可以使用 clang -g -o firstsdl firstsdl.c `pkg-config --cflags --libs sdl2`  添加了--cflags 

	pkg-config --cflags --libs sdl2 命令可以查找头文件
	pkg-config --libs sdl2 命令可以查找库


SDL事件处理
	SDL_PollEvent 轮询事件处理 问题：1.处理不及时；2需要等待，只要不等待，cpu就会飙升
	SDL_WaitEvent 可以不用等待的及时处理事件 问题：线程处理不好，在等待线程，事件被阻塞，或线程处理不好，后入的事件就会被
	一直阻塞，而造成线程阻塞，从而内存泄漏。


播放音频的基本原则
	1. 声卡向你要数据而不是你主动推给声卡
	2. 数据的多少由音频参数决定的

音视频同步 注意时间戳顺序
	在没有B帧的情况下，PTS和DTS相等，反之，不同。

时间基：
	1.tbr：帧率；2.tbn：time base of stream；3.tbc：time base of codec。

音视频的方式：
	1.视频同步到音频（常见）；2.音频同步到视频（难，涉及丢包或者补包）；3.音频和视频都同步到系统时钟。

视频同步到音频的思路：
	一般的做法，展示第一帧视频后，获得要显示的下一个视频帧的PTS，然后设置一个定时器，当定时器超时后，刷新
新的视频帧，如此反复操作。
	每次对音频帧的PTS与当前音频帧的PTS做一个diff，如果音频帧在前，设置定时器，定时播放视频帧，如果音频帧滞后，丢弃音频帧。相等直接播放视频帧。

由于音频的时长确定，采样率确定。播放时长就确定。所以把视频同步到音频上容易实现。

⚠️：音频包的时长为10ms


从哪儿获得PTS：
	AVPacket中的PTS；AVFrame中的PTS；av_frame_get_best_effort_timestamp().
